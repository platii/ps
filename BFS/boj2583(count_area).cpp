#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;
#define x first
#define y second
int board[100][100];
bool vis[100][100];
int n,m,k, num_area;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int arr[10000]; //각 영역별 넓이 저장.
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    while(k--){
        int a,b,c,d; //x좌표 y좌표. 맨왼쪽 아래, 맨 오른쪽 위
        cin>>a>>b>>c>>d;
        for(int i=b; i<d; i++) fill(board[i]+a, board[i]+c, true); //보드 색칠, for문 범위 실수. i=0; i=d-b; i++, j=0; j=c-a;j++ 이런식으로 두면 안됨. 무의식적으로 실수
    }                                                              //이런 류 for문 체크할 때 범위 잘 보고 작성할 것.     (실수 1)
    int arr[10000]={}; //area넓이 저장 배열.
    queue<pair<int,int>> q;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(vis[i][j]!=true&&board[i][j]!=true){//방문 안한 것이거나->x(것이면서 and여야함. 실수!!!!!) 색칠 안되어 있으면(실수 2) //if(vis[i][j]==ture||board[i][j]==ture) continue;로도 가능.
                vis[i][j]=true;
                q.push({i,j});        
                int area_cnt=0; //0으로 둬야함. (어짜피 시작점또한 큐에서 빠질 때 개수 체크됨.)
                while(!q.empty()){
                    auto cur=q.front(); q.pop();
                    area_cnt++; //큐에서 나가는 것의 개수 모두 체크.(영역의 넓이)
                    for(int dir=0; dir<4; dir++){
                        int nx=cur.x+dx[dir];
                        int ny=cur.y+dy[dir];
                        if(nx<0||nx>=n||ny<0||ny>=m) continue;
                        if(vis[nx][ny]==true||board[nx][ny]==true) continue;
                        vis[nx][ny]=true;
                        q.push({nx,ny});
                    }
                }
                arr[num_area]=area_cnt; //현재 진행한 색칠되지 않은 영역의 넓이 저장.
                num_area++; //색칠되지 않은 영역의 개수 .
            }
    sort(arr, arr+num_area);
    cout<<num_area<<'\n';
    for(int i=0; i<num_area; i++) cout<<arr[i]<<" ";       
}

//푸는 것은 40분 정도 안에 풀엇는데, 실수 때문에 30분을 더 찾음, 실수 안하도록 주의. 실수1)for문 범위 실수, 실수2) if조건 실수.
//실수 2-> 괜히 if아래 묶어서 하려다가 실수함. 그냥 다음에는 익숙한 or조건 쓰고 continue;로 튕기자. =>if(vis[i][j]==true||board[i][j]==true) continue;