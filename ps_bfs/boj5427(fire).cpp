#include <iostream>
#include <utility>
#include <queue>
using namespace std;
#define x first
#define y second
string board[1000];
int dist1[1000][1000]; //불
int dist2[1000][1000]; //사람
int n,m;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        queue<pair<int,int>> q1; //불
        queue<pair<int,int>> q2; //사람
        cin>>m>>n; //이런 류 문제 항상 m,n 잘 확인해야함.
        for(int i=0; i<n; i++) cin>>board[i];
        for(int i=0; i<n; i++) { //fill 빼먹지 말기, fill은 큐에 인자를 넣기전에 초기화 해야함.(dist에 0넣고 다시 -1로 초기화해버리는 실수 일어남.)
            fill(dist1[i], dist1[i]+m, -1);
            fill(dist2[i], dist2[i]+m ,-1);
        }
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++){ 
                if(board[i][j]=='*'){
                    q1.push({i,j});
                    dist1[i][j]=0;
                }
                if(board[i][j]=='@'){
                    q2.push({i,j});
                    dist2[i][j]=0;
                }
            }
        //불 bfs
        while(!q1.empty()){
            auto cur=q1.front(); q1.pop();
            for(int dir=0; dir<4; dir++){
                int nx=cur.x+dx[dir];
                int ny=cur.y+dy[dir];
                if(nx<0||nx>=n||ny<0||ny>=m) continue;
                if(dist1[nx][ny]>=0||board[nx][ny]=='#') continue;
                dist1[nx][ny]=dist1[cur.x][cur.y]+1;
                q1.push({nx,ny});
            }
        }
        //사람 bfs
        bool exit_flag=false;
        while(!q2.empty()){
            auto cur=q2.front(); q2.pop();
            for(int dir=0; dir<4; dir++){
                int nx=cur.x+dx[dir];
                int ny=cur.y+dy[dir];
                if(nx<0||nx>=n||ny<0||ny>=m){
                    cout<<dist2[cur.x][cur.y]+1<<'\n';
                    exit_flag=true;
                    break;
                }
                if(dist2[nx][ny]>=0||board[nx][ny]=='#') continue;
                if(dist1[nx][ny]!=-1&&dist2[cur.x][cur.y]+1>=dist1[nx][ny]) continue;
                dist2[nx][ny]=dist2[cur.x][cur.y]+1;
                q2.push({nx,ny});
            }
            if(exit_flag) break;
        }
        if(!exit_flag) cout<<"IMPOSSIBLE"<<'\n';
    }
}


//실수:
//1) fill 빼먹지 말기, 
//2) fill은 큐에 인자를 넣기전에 초기화 해야함.(dist에 0넣고 다시 -1로 초기화해버리는 실수 일어남.)