//정답코드 확인 후
#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
char board[30][30][30];
int dist[30][30][30];
int n,m,h;
int dx[6]={1,0,0,-1,0,0};
int dy[6]={0,1,0,0,-1,0};
int dz[6]={0,0,1,0,0,-1};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        bool isEscape=false;
        cin>>h>>n>>m;
        if(h==0 && n==0 && m==0) break;
        queue<tuple<int,int,int>> q; // 큐생성(1)
        for(int i=0; i<h; i++)
            for(int j=0; j<n; j++)  fill(dist[i][j], dist[i][j]+m, -1); // 거리 -1로 초기화(2)
        for(int i=0; i<h; i++)
            for(int j=0; j<n; j++)
                for(int k=0; k<m; k++){
                    cin>>board[i][j][k];
                    if(board[i][j][k]=='S'){
                        q.push({i,j,k});
                        dist[i][j][k]=0; //조건에 맞게 시작점 넣기 + 거리 0 삽입.(3) //번외. 구역찾기 문제인 경우 시작점삽입 후에 반복문내에서 바로 bfs
                    }
                }
        //bfs(4)
        while(!q.empty()){
            if(isEscape) break;
            auto cur=q.front(); q.pop(); //큐 빼기
            int curX, curY, curH;
            tie(curX, curY, curH)=cur;
            for(int dir=0; dir<6; dir++){
                int nx=curX+dx[dir];
                int ny=curY+dy[dir];
                int nz=curH+dz[dir];
                if(nx<0||nx>=h||ny<0||ny>=m||nz<0||nz>=m) continue; // 편의상 순서대로 x,y,z를 h,n,m과 대응하여 둠 문제별로 잘 보고 작성해야함 
                if(dist[nx][ny][nz]!=-1||board[nx][ny][nz]=='#') continue;
                dist[nx][ny][nz]=dist[curX][curY][curH]+1;
                if(board[nx][ny][nz]=='E'){
                    cout<<"Escaped in "<<dist[nx][ny][nz]<<" minute(s)."<<'\n';
                    isEscape=true;
                    break;
                }
                q.push({nx,ny,nz});
            }
        }
        while(!q.empty()) q.pop();
        if(!isEscape) cout<<"Trapped!"<<'\n';
    }

}