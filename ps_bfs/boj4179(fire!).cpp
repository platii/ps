//틀린 것 고치고 최종.
#include<iostream>
#include<utility>
#include<queue>
using namespace std;
#define x first
#define y second
char board[1000][1000];
int fire[1001][1001];
int jihoon[1001][1001];
int n,m;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    queue<pair<int,int>> q;
    for(int i=0; i<n; i++) fill(fire[i], fire[i]+m, -1); //주어진 크기의 배열을 모두 -1로 초기화.
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin>>board[i][j];
            if(board[i][j]=='F'){
                q.push({i,j});
                fire[i][j]=0;
            }
        }
    //불에 대한 bfs
    while(!q.empty()){ //!q.empty(), !붙여줘야함 실수 x
        pair<int,int> cur= q.front(); q.pop();
        for(int dir=0; dir<4; dir++){
            int nx=cur.x+dx[dir];
            int ny=cur.y+dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(fire[nx][ny]>=0||board[nx][ny]!='.') continue; //방문하지 않으면서, board값이 . 인것만 방문하도록 함.->#인경우 방문안하는 것으로 수정(fire가 j위치에서의 dist를 저장하지 않는 경우 -1로 고정됨. J이동을 계산할 때 문제가 생김)
            fire[nx][ny]=fire[cur.x][cur.y]+1;                //다시 생각해보니, 어짜피 J의 bfs에서는 방문한 것은 다시 방문하지 않음. !="."으로 두어도 상관 없음.
            q.push({nx,ny});
        }
    }
    //지훈에 대한 bfs
    for(int i=0; i<n; i++) fill(jihoon[i], jihoon[i]+m, -1);
    for(int i=0; i<n; i++)
        for(int j=0; j<m;j++)
            if(board[i][j]=='J'){
                q.push({i,j});
                jihoon[i][j]=0;
                break; 
            }
    int minimum=100000000;
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        if(cur.x==0||cur.x==n-1||cur.y==0||cur.y==m-1) minimum=min(jihoon[cur.x][cur.y], minimum); //min으로 묶어서 반환해야함. 그냥 min=(jihoon[nx][ny], minimum)하고 괄호만묶으면안됨. 실수 x
        for(int dir=0; dir<4; dir++){
            int nx=cur.x+dx[dir];
            int ny=cur.y+dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(jihoon[nx][ny]>=0||board[nx][ny]!='.') continue;
            if(fire[nx][ny]!=-1&&jihoon[cur.x][cur.y]+1>=fire[nx][ny]) continue; //J의 움직임의 경우, 어짜피 F가 있는 곳은 방문 불가함(.인곳만방문하게 해도상관 x)그러나통일성을 위해 ==#으로 수정.
            //->틀린 핵심 원인(1), 입력으로 F가 주어지지 않으면 모든 fire[i][j]는 -1이됨. 따라서 jihoon이 아에 움직이지 못하게 됨.
            //불이 -1이라는 것은, 불이 전파되지 않은 것이므로 지훈이 이동가능해야함. 따라서 조건에 불이 -1이 아닐때만, 불전파시간과 지훈의 도착 시간을 비교한 후에 방문가능여부를 처리해야함.
            //if(jihoon[nx][ny]>=fire[nx][ny]) continue;
            //틀린 핵심원인(2), 이 위치에서 if(nx==0||nx==n-1||ny==0||ny==m-1) minimum=min(jihoon[nx][ny], minimum); 코드로 minimum을 판별하면, J가 가장자리에서 주어졌을 때, nx,ny를 받지못함(범위에서 벗어나서 continue하게되므로)
            jihoon[nx][ny]=jihoon[cur.x][cur.y]+1; //통과되기전 것들도 dist값이 변경되게 두었다가 통과한 것만 dist값이 변경되게 바꿈. ->상관없이 틀림(다시 해보니 이부분은 크게 상관 없음)
            q.push({nx,ny});
        }
    }
    
    if(minimum==100000000)
        cout<<"IMPOSSIBLE";
    else
        cout<<minimum+1; //지훈이 처음 시작한 지점부터 +1로 시간을 잼.


    }
        

        //1. 불 위치 큐에 집어놓고 불 퍼지는 일자 다 적어두기
        //2. J가 움직일 때 불이 퍼진 시간이 j가 도달 한 시간보다 작으면 cont
        //3. 가장자리에 도달한 시간 체크. 1)
        //4. 가장자리에 도달하지 못하는 경우 체크. 2)
        //->체크하는방법 두가지 1) 큐에서 탐색할때(4방향탐색할 때(큐에 넣을때)) 체크하는경우
        //                    2) 큐 bfs모두끝낸 후 jihoon의 가장자리 중 min값을 체크하는 경우