#include <iostream>
#include <utility>
#include <queue>
using namespace std;
#define x first
#define y second
string board[102];
int dist[102][102];
int n, m;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++)
        cin>>board[i];
    for(int i=0; i<n; i++) fill(dist[i], dist[i]+m, -1); //그냥 이중 for문 돌려도 무방하긴 함. 2차원배열, fill 동작 기억하기. 
    queue<pair<int,int>> q;
    dist[0][0]=0;
    q.push({0,0});
    while(!q.empty()){
        pair<int,int> cur=q.front(); q.pop();
        for(int dir=0; dir<4; dir++){ //dir=0 초기화 안하는 실수. x
            int nx=cur.x+dx[dir];
            int ny=cur.y+dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(dist[nx][ny]>=0||board[nx][ny]!='1') continue; 
            dist[nx][ny]=dist[cur.x][cur.y]+1;
            q.push({nx,ny});
        }
    }
    cout<<dist[n-1][m-1]+1;
}