//1. 높이가 0이아닌 빙산 큐에 넣고, 근처에 0 개수만큼 감산, 큐가 빌 때까지 진행 ->o(nm)
//2. 구역의 개수 체크. ->o(nm)
//3. 구역의 개수가 2개 이상이 될 때 까지 while문돌리기. -> 전부다 녹았다면, 0출력.  (최대 10번 이하)

#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define x first
#define y second
int board[300][300];
int pboard[300][300]; //post_board
int n,m,time;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool check(){ //덩어리의 개수 체크
    int cnt=0;
    queue<pair<int,int>> a;
    bool vis[300][300]={};
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(board[i][j]!=0&&!vis[i][j]){ // 실수)&&조건 ||조건 조심 묶는건 &&, 튕기는건 ||
                a.push({i,j});
                vis[i][j]=true;
                cnt++;
                if(cnt>=2) return true; //cnt 체크
                while(!a.empty()){
                auto cur=a.front(); a.pop();
                    for(int dir=0; dir<4; dir++){
                        int nx=cur.x+dx[dir];
                        int ny=cur.y+dy[dir];
                        if(nx<0||nx>=n||ny<0||ny>=m) continue;
                        if(board[nx][ny]==0||vis[nx][ny]) continue;
                        a.push({nx,ny});
                        vis[nx][ny]=true;
                    }
                }
            }
    return false;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    queue<pair<int,int>> q;
    queue<pair<int,int>> q2;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            cin>>board[i][j];
            if(board[i][j]!=0) q.push({i,j}); //초기빙산 위치 입력
        }
    while(!q.empty()){ //빙산이 모두 녹기전까지 혹은 빙산이 두덩이로 나뉘기 까지 시행.
        if(check()==true){ //현재 보드의 빙산들의 상태 체크.
            cout<<time;
            return 0;
        };
        time++;
        while(!q.empty()){ //1. 빙산 녹는 것 체크
            auto cur=q.front(); q.pop(); //빙산 큐에서 꺼냄.
            int post=board[cur.x][cur.y]; //꺼낸 빙산의 상태 체크할 변수 post
            for(int dir=0; dir<4; dir++){ //4방향 탐색 후 빙산 녹음 체크
                int nx=cur.x+dx[dir];
                int ny=cur.y+dy[dir];
                if(nx<0||nx>=n||ny<0||ny>=m) continue; //범위 체크
                if(board[nx][ny]!=0) continue; //주변이 바닷물(0)이 아니라면 튕김.
                post--;
            }
            if(post<0) post=0; //post 음수되면, 0으로 변경.
            pboard[cur.x][cur.y]=post; //bfs진행중엔 board의 값이 바뀌지 않도록, pboard에 변경된 값 저장.
            if(post!=0){
                q2.push({cur.x,cur.y}); //q2에 0이되지 않은 빙산의 위치 넣음. 
            }
        }
        while(!q2.empty()){ //1-1. 큐2에 저장된 0이아닌 남아있는 빙산의 위치 다시 q에 넣음.
            q.push(q2.front()); q2.pop();
        }
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                board[i][j]=pboard[i][j]; //1-2. board를 pboard 상태로 변경.
        /*
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
                cout<<board[i][j]<<' ';
        cout<<'\n';
        }
        */
    }
    
    cout<<"0";
}