#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define x first
#define y second
string board[101];
int vis[101][101];
int n;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    queue<pair<int,int>> q;
    char flag;
    //정상인 bfs
    int cnt1=0;
    for(int i=0; i<n; i++) cin>>board[i];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            if(vis[i][j]) continue;
            flag=board[i][j];
            vis[i][j]=1;
            q.push({i,j});
            cnt1++;
            while(!q.empty()){
                auto cur=q.front(); q.pop();
                for(int dir=0; dir<4; dir++){
                    int nx=cur.x+dx[dir];
                    int ny=cur.y+dy[dir];
                    if(nx<0||nx>=n||ny<0||ny>=n) continue;
                    if(vis[nx][ny]==1||board[nx][ny]!=flag) continue;
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
    //적록색약 bfs
    int cnt2=0;
    for(int i=0; i<n; i++) fill(vis[i],vis[i]+n, false);//방문기록 배열 초기화 , fill(vis, vis+n, false); =>[i]안쓰는 실수
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(board[i][j]=='G') board[i][j]='R';
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            if(vis[i][j]) continue;
            flag=board[i][j];
            vis[i][j]=1;
            q.push({i,j});
            cnt2++;
            while(!q.empty()){
                auto cur=q.front(); q.pop();
                for(int dir=0; dir<4; dir++){
                    int nx=cur.x+dx[dir];
                    int ny=cur.y+dy[dir];
                    if(nx<0||nx>=n||ny<0||ny>=n) continue;
                    if(vis[nx][ny]==1||board[nx][ny]!=flag) continue;
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
    cout<<cnt1<<" ";
    cout<<cnt2;
}

//일반, 적록색약 bfs 따로 나눈 후, 적록색약bfs 시, board의 그린을 모두 레드로바꿈.

//정답코드는 bfs함수, area함수(구역 개수 체크)따로 만든 후에, 계산하였음. 적록색약,일반인 구분 방법은 동일하게 하였음.