//정답 참고 코드
#include <iostream>
#include <queue>
using namespace std;
#define x first
#define y second
string board[1002]; 
int fire[1002][1002]; //정답에서는 그냥 fire는 dist1으로, jihoon은 dist2로 표현함
int jihoon[1002][1002]; //fire,jihoon으로 쓸 경우 어떤 배열인지 분별이 쉽고, dist1,2로 쓸경우 간단히 적을 수 있음, 취향에 따라 쓰면 될 듯 함.
int n,m;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    queue<pair<int,int>> q1, q2;
    for(int i=0; i<n; i++) {
        fill(fire[i], fire[i]+m, -1); //n*m 만큼 fire를 -1로 초기화
        fill(jihoon[i], jihoon[i]+m, -1);
    }
    for(int i=0; i<n; i++) cin>>board[i];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            //cin>>board[i][j]; //스트링이 아닌 char board[1002][1002]로 받는 경우 이런식으로 여기서 바로 입력 받으면 됨.
            if(board[i][j]=='F'){ //F를 찾았으면 큐에 삽입, FIRE[I][J]의 dist를 0으로 처리
                fire[i][j]=0;
                q1.push({i,j});
            }
            if(board[i][j]=='J'){ //q하나만 사용해도 상관없지만, q1,q2로 나눠받으면, 메모리를 조금 더 쓰는 대신, 나중에 j를 다시 찾아 q에 넣기위해 for문을 또 돌리지 않아도됨
                jihoon[i][j]=0;
                q2.push({i,j});
            }
        }
    //불에 대한 bfs
    while(!q1.empty()){
        auto cur = q1.front(); q1.pop();
        for(int dir=0; dir<4; dir++){
            int nx=cur.x+dx[dir];
            int ny=cur.y+dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(fire[nx][ny]!=-1||board[nx][ny]=='#') continue; //확실히 (!='.'으로 두는 것보다 =='#'으로 두는 것이 더 안전하고 깔끔함)
            fire[nx][ny]=fire[cur.x][cur.y]+1;
            q1.push({nx,ny});
        }
    }
    
    //지훈에 대한 bfs
    while(!q2.empty()){
        auto cur=q2.front(); q2.pop();
        for(int dir=0; dir<4; dir++){
            int nx=cur.x+dx[dir];
            int ny=cur.y+dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m){
                cout<<jihoon[cur.x][cur.y]+1;
                return 0;
            }
            if(jihoon[nx][ny]!=-1||board[nx][ny]=='#')continue;
            if(fire[nx][ny]!=-1&&jihoon[cur.x][cur.y]+1>=fire[nx][ny]) continue;
            jihoon[nx][ny]=jihoon[cur.x][cur.y]+1;
            q2.push({nx,ny});
        }

    }
    cout<<"IMPOSSIBLE";
}
