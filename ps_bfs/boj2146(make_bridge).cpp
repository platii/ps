//1. 모든 board에 대해서 각 구역을 1,2,3----으로 지정하여 색칠함. o(n^2)
//2. 각 구역에 대하여 그 구역의 모든 노드들을 큐에 넣고 bfs 진행하여 거리 체크.->4방향 탐색 시 보드가 0과 해당구역이 아니면서, 방문하지 않은 구역을 만난 경우 종료
//그때의 거리값을 mn=min(mn,dist[cur.x][cur.y])하여 종료. ->o(n^2)
//모든 구역에 대하여 이를 시행. mn값 반환. ==>구역의 개수 * bfs 횟수. 최악의 경우 o((n)^4) n 최대 100, n^2=1만, 1만제곱 = 1억번. 100000000. 1초?

#include <iostream>
#include <utility>
#include <queue>
using namespace std;
#define x first
#define y second
int board[100][100];
int dist[100][100];
int n, color=-1;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void draw(){
    bool vis[100][100]={}; //={}초기화 하는 것 잊지 말것.(지역변수)
    queue<pair<int,int>> q; //정답코드: 어짜피 q는 다 비우므로 전역으로 선언해도 무방.
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(board[i][j]==1){ //정답코드:또는 if(board[i][j]==0||vis[i][j]) continue;로 넣어도됨.->이렇게 하면, 굳이 color를 음의 정수로(맨처음구역을 1로 색칠하면 조건과 겹치므로) 잡지않아도됨.
                q.push({i,j}); //시작점넣음
                vis[i][j]=1;
                while(!q.empty()){
                    auto cur =q.front(); q.pop();
                    board[cur.x][cur.y]=color; //그 구역 색칠 
                    for(int dir=0; dir<4; dir++){
                        int nx=cur.x+dx[dir];
                        int ny=cur.y+dy[dir];
                        if(nx<0||nx>=n||ny<0||ny>=n) continue; //범위체크
                        if(vis[nx][ny]||board[nx][ny]==0) continue; //방문체크, 갈수있는 지 여부체크
                        vis[nx][ny]=true;
                        q.push({nx,ny});
                    }
                }
                color--;
            }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            cin>>board[i][j];
        }
    draw(); //색칠 그리기
    //구역 별로 최단 거리 다리를 체크, mn 갱신
    int mn=10000;
    queue<pair<int,int>> q; //정답코드: 어짜피 q는 다 비우므로 전역으로 선언해도 무방.
    for(int col=-1; col>=color; col--){ //색칠된 구역 별로 가장 가까운 구역에 닫는 최단 거리 탐색
        for(int i=0; i<n; i++) fill(dist[i], dist[i]+n, -1); //거리 초기화
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++){// 동일한 구역 큐에 집어넣음.
                if(board[i][j]==col){//같은 색(구역)체크
                    q.push({i,j}); 
                    dist[i][j]=0; //같은 구역들 큐에 집어넣음.
                }
            }
        bool escape=false;
        while(!q.empty()){ // 정답코드 : while의 조건으로 while(!q.empty() && !escape)로 설정하면 if(escape) break;를 넣어버릴 수 있음
            if(escape) break;
            auto cur = q.front(); q.pop();
            for(int dir=0; dir<4; dir++){
                int nx=cur.x+dx[dir];
                int ny=cur.y+dy[dir];
                if(nx<0||nx>=n||ny<0||ny>=n) continue;
                if(board[nx][ny]!=0&&board[nx][ny]!=col){
                    mn=min(mn, dist[cur.x][cur.y]);
                    escape=true;
                    break;
                }
                if(board[nx][ny]!=0||dist[nx][ny]!=-1)continue;
                dist[nx][ny]=dist[cur.x][cur.y]+1;
                q.push({nx,ny});
            }
        }
        while(!q.empty()) q.pop();
    }
    if(mn==10000) cout<<"0";
    else cout<<mn;
}

//정답코드에선 직접 푼 코드처럼, 동일한 구역의 육지노드를 모두 큐에 집어넣고, 한번에 bfs를 진행시켜 최단거리를 구하는 방식이 아니라
/* 모든 노드에 대하여 for문을 돌려, 육지노드여부를 확인 한후 해당 육지노드에 대하여 bfs거리측정을 진행하도록 하였다.
결국 bfs는 육지에서 가장자리에 해당하는 노드에 대해서만 퍼져나가므로 시간복잡도는 동일하다.
->(정정 : 큐에 육지노드를 한번에 넣는 경우, 최단 거리에 도달하면 탈출하고 종료하기 떄문에 모든 육지노드를 따로 볼떄보다 조금 더 효율적이다.)
직관적으로 이해하기에는 직접 푼코드가 편한데, 이해를 하고 나면 정답코드가 코드 간결성이 더 좋다.
(q를 넣는 for문을 따로 둘필요가 없고, 모든 육지에 대해 반복 한다는 for문을 덮을필요가 없으므로)
취향에 따라 사용할 것.

코드에 따로 표시한 //정답코드: 부분은 모두 기존코드보다 더 간결하고 좋으므로 그렇게 해야할것.
->큐를 전역변수로 선언해도 되는경우 전역변수로 선언**
->if조건 잘 설정하기
->while문 안의 if(조건)break 형식의 코드(조건에 맞으면 반복문 탈출)를.  while(~+if에서 조건 변형 ) 형식으로 압축 가능.***

*/
//bfs를 2번만 사용해 O(n^2) 문제를 풀어내는 풀이가 존재한다고하여. 

//추가로 생각해본 발상 -> 모든 육지 노드 색칠, 모든 육지노드를 큐에 넣고, bfs최단거리 찾기 돌림.
//최단거리를 돌리면서, 만약 bfs4방향 탐색 시== 이미 방문한 지역인데, 색칠된 지역에서 시작해서 방문한 노드가 아니라면(이를 식별하기 위해 vis배열을 int로 만들고 vis배열에 육지의 color값을 대입하여 방문표시함.)
//현재 cur.x, cur.y에서의 dist값과(dist[cur.x][cur.y])위에 조건에 해당하는 nx,ny에서의 dist값 (dist[nx][ny])을 더하여 출력하고 종료한다.
//(어짜피 bfs 최단거리 탐색이므로 가장먼저 위의 조건에 맞는 상황이 나온다면 그때가 가장 최단 거리임. 바로 출력하고 종료한다.)