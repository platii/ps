#include <iostream>
#include <tuple> //tuple 사용위함. pair는 <utility>헤더 이용.
#include <queue>
using namespace std;
#define x first
#define y second
int board[100][100][100];
int dist[100][100][100];
int n,m,h;
int dx[6]={1,0,0,-1,0,0};   
int dy[6]={0,1,0,0,-1,0};
int dz[6]={0,0,1,0,0,-1};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>m>>n>>h;
    queue<tuple<int,int,int>> q;
    for(int i=0; i<h; i++)
        for(int j=0; j<n; j++)
            for(int k=0; k<m; k++){
                cin>>board[i][j][k];
                if(board[i][j][k]==1){
                    q.push({i,j,k});
                    // dist[i][j][k]=1;
                }
                if(board[i][j][k]==0){
                    dist[i][j][k]=-1;
                }
            }
    while(!q.empty()){
        auto cur=q.front(); q.pop();
        for(int dir=0; dir<6; dir++){
            int nx=get<0>(cur)+dx[dir];
            int ny=get<1>(cur)+dy[dir];
            int nz=get<2>(cur)+dz[dir];
            if(nx<0||nx>=h||ny<0||ny>=n||nz<0||nz>=m) continue;
            if(dist[nx][ny][nz]>=0||board[nx][ny][nz]==-1) continue;
            dist[nx][ny][nz]=dist[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
            q.push({nx,ny,nz});
        }
    }
    int mx=0;
    for(int i=0; i<h; i++)
        for(int j=0; j<n; j++)
            for(int k=0; k<m; k++){
                if(dist[i][j][k]==-1){ //if(board[i][j][k]!=-1&&dist[i][j][k]==0)
                    cout<<"-1";
                    return 0;
                }
                mx=max(mx,dist[i][j][k]);
            }
    cout<<mx; //mx-1
}

/* 전에 풀었던 코드 다시 확인(2차원 배열 토마토)

익은 토마토가 있는 자리의 dist를 1로 초기화 하고, 모두 익어으면 나중에 mx-1로 출력하는 방법이 아니라(+익지않은 토마토 탐색시, 보드가 -1인가 여부를 파악하지 않고)
그냥 .//익지않은 토마토의 dist는 -1로 초기화 하고//. if에서는 dist가 -1인가 여부만 파악하게 했음. 나중엔 mx만 출력 

*/