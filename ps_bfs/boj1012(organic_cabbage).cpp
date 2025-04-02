#include <iostream>
#include <queue>
using namespace std;
#define x first
#define y second
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    queue<pair<int,int>> q;
    while(t--){
        bool board[50][50]={}; //테스트 케이스 마다 board, vis 다시 초기화.// 할당 용량이 적으므로 문제 x
        bool vis[50][50]={};
        int n,m,k, cnt=0;
        cin>>m>>n>>k;
        while(k--){
            int i,j; //익히 아는. i:x좌표, j:y좌표 
            cin>>i>>j;
            board[j][i]=1; //2차원배열[][]에서 앞에대괄호는 행, 뒤 대괄호는 열. i,j받은 순서와 반대로 되어야함. 실수 주의!
        }
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++){
                if(board[i][j]==0||vis[i][j]==1) continue;
                q.push({i,j});
                vis[i][j]=1;
                cnt++;
                while(!q.empty()){
                    auto cur=q.front(); q.pop();
                    for(int dir=0; dir<4; dir++){
                        int nx=cur.x+dx[dir];
                        int ny=cur.y+dy[dir];
                        if(nx<0||nx>=n||ny<0||ny>=m) continue;
                        if(board[nx][ny]==0||vis[nx][ny]==1) continue;
                        vis[nx][ny]=1;
                        q.push({nx,ny});
                    }
                }
            }
        cout<<cnt<<'\n';
    }

}