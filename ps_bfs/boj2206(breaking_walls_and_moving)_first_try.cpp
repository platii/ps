#include <iostream>
#include <utility>
#include <queue>
using namespace std;
#define x first
#define y second
string board[1000]; //실수1)붙어서 입력될 때는 꼭 string으로 받아야함.
int dist[1000][1000];
int n,m, mn=1000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void bfs(int i, int j){ //안전 구역 정답코드에서 봤었던 방식 활용.
    queue<pair<int,int>> q; //큐 생성
    for(int k=0; k<n; k++) fill(dist[k], dist[k]+m, -1);//거리초기화 (항상 시작점 넣기 전(dist바꾸기전에)에 작성되어야함.)//중복방지 k를 변수로씀.
    q.push({i,j}); //시작점 넣기
    dist[i][j]=0;  //시작점 방문 처리
    bool isEscape=false;
    while(!q.empty()){ //bfs
        if(isEscape) break;
        auto cur = q.front(); q.pop();
        for(int dir=0; dir<4; dir++){
            int nx=cur.x+dx[dir];
            int ny=cur.y+dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(dist[nx][ny]!=-1||board[nx][ny]=='1') continue;
            dist[nx][ny]=dist[cur.x][cur.y]+1;
            if(nx==n-1 && ny==m-1){ //탈출, 
                isEscape=true;
                mn=min(mn, dist[nx][ny]+1); //그 때의 최단 거리값 반환, 문제특성상 +1해주어 거리 계산
                break;
            }
            q.push({nx,ny});
        }
    }
    //큐는 bfs함수에서 생성된 것이므로, 큐를 비울 필요는 없음.
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>board[i]; //입력받기
    ////
    bfs(0,0); //벽 안없애고 최단거리 계산


 
    if(mn==1000000) cout<<"-1"; //탈출 못했을 시,
    else cout<<mn; //탈출 했을 시 출력
}

   /* 무식하게 1을 하나씩 없애가며 계산 bfs의 최악의 경우 1000*1000=백만, 1 없애는 최악의경우=1이 백만개, ->백만*백만 ->시간초과
    bfs(0,0);
    for(int i=0; i<n; i++) //차례대로 1벽을 하나씩 없애가며 bfs 진행함
        for(int j=0; j<m; j++)
            if(board[i][j]=='1'){
                board[i][j]='0'; //보드내의 임의의 1을 0으로 변경
                bfs(0,0);
                board[i][j]='1'; //bfs 돌리고 난 후에 다시 그자리를 1로 변경해줌.
            }
    */

   //정답코드 확인함
   /*
   아에 새로운 발상.
   dist를 벽을 꺴을때, 안깻을 때 거리 또한 저장하게 만듦. dist[][][2]; 2개->(unbroken:0, broken:1)
   그리고 큐에 {x,y,broken}을 전달, broken이 1이라면 0인것만 방문가능 이런식으로 해서 도착점에 도달했을 때
   dist[nx][ny][broken]을 반환 -> broken이 0이든 1이든 간에 일단 가장 빨리 방문한 것으로 반환되고 종료됨(bfs특성.(거리순으로 도달))
   
   혹시, 이런 경우는 없을까?(가장 가까운 1말고, 후반부에 있는 1을 부셨을 때 더 빠른경우.)
   (코드 상, 진행할 수 있는 가장 가까운 1을 먼저 부수고 dist[][][1]을 채워나갈 텐데...)
   000000000
   111111000
   111110000
   100110111<--여기부수는게 더 빠름.
   000000110
   011111110
   011111110
   000000000<-도착
   코드를 따라가며 생각해보니, 맨처음 초반부 끝쯤에 있는 1을 부수고 나선 broken이 1인 거리배열을 채우며 진행하는 배열과
                             broken이 0인채로 여전히 진행하는 배열이 동시에 진행한다.
                             따라서, broken이 0인채로 진행하는 배열이 후반부 1에 도달하고, 그 1을 부수며 진행이 가능하다.(가장 빠른 경로)
   또, 잘 생각해보면, 코드상 broken이 0인 배열이 출발지점까지 막힘없이 진행이가능하다면, broken 0짜리 배열은 
   진행과정에서 계속, 벽을 부셨을 때 의 거리값을 갱신할 수 있다.
   이때, 후반부에서 1벽을 부섰을 때 dist값이, 전반부에 1을 부신 케이스보다 더 작다면, 즉 더 빨리 그 자리에 도착했다는 것이므로,
   (전반부에 1을 부신 더 느린 배열은 더빠른 배열이 이미 dist[][][1]을 채워 놓았으므로 더이상 그자리를 방문하지 못한다.)
   후반부에서 1을 부신 배열이 더빨리 도착점에 도달하고 최단거리dist값을 반환한다.
   즉 어느점에서 1을 부시던간에, 더빨리 도착하는 경로의 도착점 최단거리값이 반환되고 종료된다.
   시간복잡도는 동일한 유형의 bfs문제처럼 o(nm)을 갖게된다. 무식하게 bruteforce한경우는 o((nm)^2)];

   정리 : broken 여부에 따라 벽을 부수고 방문하여(broken배열을 채울지), 그대로 방문할지 판단하게 하고. 진행함. 

   -=====>하나의 추가 조건(벽을 부술지 말지)이 주어지는 케이스에서는 다음과같이 배열을 하나 더 추가하여 풀어볼 수 있다.
   */