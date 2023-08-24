//1. 말의 이동 dx,dy | 원숭이 이동 dx,dy 구분.
//(벽뿌수고 이동하기에서 했던  방식 그대로 이용(dist배열을3차원으로 만들어서 벽을 뚫었는지 안뚫었는지 체크, 각각의 상태에서의 dist를 각각의 배열에서 기록함))
//2. 시작지점에서 시작해서 bfs -> dist 배열에 말의이동 횟수를 저장하는 칸 한칸 추카. (3차원배열  사용), tuple 사용 말 이동횟수 까지 큐에 전달
//3. 도착점 도착 시 그 지점에서의 dist 리턴.

#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
#define x first
#define y second
int dist[200][200][30];
int board[200][200];
int n,m,k;
int m_dx[4]={1,0,-1,0};
int m_dy[4]={0,1,0,-1};
int h_dx[8]={1,1,2,2,-1,-1,-2,-2};
int h_dy[8]={2,-2,1,-1,2,-2,1,-1};
bool OOB(int x, int y){
    return x<0 || x>=n || y<0 || y>=m;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>k;
    cin>>m>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>board[i][j];
    for(int i=0; i<n; i++) 
        for(int j=0; j<m; j++) //입력 받을 때 기호 실수. (m,n실수)
            fill(dist[i][j], dist[i][j]+k+1, -1); //dist 초기화, **(가장큰실수_틀린이유) 만약 k가 2라면, k가0, k가1, k가2인 총 3개의 2차원 배열을 초기화시켜야함. 
    queue<tuple<int,int,int>> q;
    dist[0][0][0]=0; dist[0][0][1]=0; //처음 지점에서 k=0, 걷거나, k=1, 점프하거나 둘 중 하나만 가능하므로 2개의 경우만 0으로 초기화.->정정. k=0인경우만 초기화 시키면됨.->맨아래 주석확인
    q.push({0,0,0}); //시작점 넣기
    while(!q.empty()){
        auto cur=q.front(); q.pop(); //정답코드(remind) tie함수 사용하여 각각의 값을 한번에 받아올 수 있음.
        /*
        int curX, curY, hor;
        tie(curX, curY, hor)=q.front();
        q.pop;
        */
        int curX=get<0>(cur);
        int curY=get<1>(cur);
        int hor=get<2>(cur);
        if(curX== n-1 && curY ==m-1){ //도착점 도달 시.
            cout<<dist[curX][curY][hor];
            return 0;
        }
        if(hor<k){ //night
            for(int dir=0; dir<8; dir++){
                int nx=curX+h_dx[dir];
                int ny=curY+h_dy[dir];
                if(OOB(nx,ny)||dist[nx][ny][hor+1]!=-1||board[nx][ny])continue; //범위 체크, 방문체크, 보드 1체크 //(<= 안되면, 또는 방문한 것보다 크기가 더 크면 continue; 더 작으면 통과) 
                dist[nx][ny][hor+1]=dist[curX][curY][hor]+1; //**(실수) 위 if조건 탐색에서 hor+1이 아닌 hor로 두었다가 메모리초과(visited조건이 잘못되어 큐에 너무많은 인자가 들어가게됨.)났음. 조건 잘 설정할것.
                q.push({nx,ny,hor+1});
            }
        }
            //monkey
        for(int dir=0; dir<4; dir++){
            int nx=curX+m_dx[dir];
            int ny=curY+m_dy[dir];
            if(OOB(nx,ny)||dist[nx][ny][hor]!=-1||board[nx][ny])continue; //범위 체크, 방문체크, 보드 1체크 //(<= 안되면, 또는 방문한 것보다 크기가 더 크면 continue; 더 작으면 통과) 
            dist[nx][ny][hor]=dist[curX][curY][hor]+1;
            q.push({nx,ny,hor});
        }
        }
        cout<<-1;
    }

//실수 점검
//실수 요소 -> bfs에서 메모리초과의 경우 대부분은 visited 조건을 잘못 설정하여(visited한 것을 또 큐에 넣게됨.) 큐에 너무많은 인자가 들어가게 된 것
//bfs에서 메모리초과가 나는 경우 visited 조건 혹은 다른 if조건을 잘 살펴보기.
//가장큰 실수 요인 -> dist 초기화 시 k가주어졌으면, k+1까지 초기화 해야함. (만약 k=2라면, k=0, k=1, k=2 일때의 3개의 2차원 배열이 필요하기 때문)

/* 정답코드 분석.
전체적인 발상 동일.(배열 한칸 추가하여 k상태별로 저장. horse이동을 if(hor<k)조건 하에 먼저 실시하고 그 다음에 일반 이동 하는 구조도 동일)
-->(remind)tuple 쓸때는 tie함수 꼭 쓰기. (훨씬 편함)

(1)
정답코드는 while문을 우선 모두 돌려서 k+1개의 배열 모두 도착점에 dist가 채워지도록 하였음.
이후 이 k개 배열의, 도착점에서의 dist값을 모두 비교하여 min값을 구하여 출력하도록 하였음. 
~> 본인이 문제를 풀떄 처음 생각했던 방식이었음. 하지만, bfs(먼저 들어온게 먼저 진행됨)특성상 가장 먼저 도착지점에 도달한것이 최단 거리(동작)일 확률이 높으므로
그냥 본 코드처럼 도착지점에 도달한 dist값을 출력하게 하였음.
[->만약 이런형식의 다른문제들을 풀때, 시간복잡도상으로 문제가 없고, 안정성이 요구된다면(혹시나 반례가 있을 수 있으므로) 이런식으로 하는 것이 좋을듯 하다.]

(2)
dist함수를 -1로 초기화 하지 않고 그대로 사용, (원래 0으로 초기화 되어있는 그상태로 사용)
시작점의 dist는 1을 넣음.
방문여부는if(dist[][]) continue; 로 확인함(0이 아니면 continue;)
이후 나중에 정답을 출력할 때는 저장된 ans에 -1하여
ans-1을 출력하도록 함.
-> 두 방식이 구조적으로 큰차이는 없으나, 
확실히 3차원 배열정도 되면 크기가 커지므로 -1로 초기화할필요가없는 경우에는(테스트케이스가 여러개가 아니라서 dist를 초기화 할 필요 없는 경우 등)
그냥 0으로 초기화된 상태를 그대로 쓰는 것이 좋겠다.
(대신. 방문여부는 if(dist[][]) continue;로 정답은 -1하여 출력하고 문제를 풀면서 dist가 -1이 아닌 모두 0으로 초기화 되어있음을 염두하고 풀 것.)

(3)min의 초기값을 0x7f7f7f7f(2,139,062,143)으로 32비트 컴퓨터 정수의 최대 크기인 2,147,438,648에 가깝게 설정하였음.
나중에 min의 초기값 설정시 참고하면 좋을듯함.(min의 초기값은 클 수록 좋음. 혹시나 min의 초기값이 비교되는 dist의 값보다 작아서 답에 영향을 미치면 안되므로)
[0x에다가 7f 네개 하면 거의 32비트 정수 최대값임 min설정시 활용하자.]

->+ 시작점 넣을때 dist[0][0][0]=0만 해도 됨.
어짜피 dist[?][?][1]의 다음위치값을 갱신할 때도 dist[curX][curY][hor]+1;로 갱신하므로 dist[0][0][0]만 필요함.

*/