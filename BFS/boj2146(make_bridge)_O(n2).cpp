//bfs를 2번만 사용해 O(n^2) 문제를 풀어내는 풀이가 존재한다고하여. 
//추가로 생각해본 발상 -> 모든 육지 노드 색칠, 모든 육지노드를 큐에 넣고, bfs최단거리 찾기 돌림.
//최단거리를 돌리면서, 만약 bfs4방향 탐색 시== 이미 방문한 지역인데, 색칠된 지역에서 시작해서 방문한 노드가 아니라면(이를 식별하기 위해 vis배열을 int로 만들고 vis배열에 육지의 color값을 대입하여 방문표시함.)
//현재 cur.x, cur.y에서의 dist값과(dist[cur.x][cur.y])위에 조건에 해당하는 nx,ny에서의 dist값 (dist[nx][ny])을 더하여 출력하고 종료한다.
//(어짜피 bfs 최단거리 탐색이므로 가장먼저 위의 조건에 맞는 상황이 나온다면 그때가 가장 최단 거리임. 바로 출력하고 종료한다.)
#include <iostream>
#include <utility>
#include <queue>
using namespace std;
#define x first
#define y second
int board[1040][100];
int dist[100][100];
int vis_col[100][100];
int n, color=1, mn=10000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void draw(){
    bool vis[100][100]={}; //={}초기화 하는 것 잊지 말것.(지역변수)
    queue<pair<int,int>> q; //정답코드: 어짜피 q는 다 비우므로 전역으로 선언해도 무방.
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(board[i][j]!=0&&!vis[i][j]){ //정답코드:또는 if(board[i][j]==0||vis[i][j]) continue;로 넣어도됨.->이렇게 하면, 굳이 color를 음의 정수로(맨처음구역을 1로 색칠하면 조건과 겹치므로) 잡지않아도됨.
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
                color++;
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
    queue<pair<int,int>> q; //정답코드: 어짜피 q는 다 비우므로 전역으로 선언해도 무방.
    for(int i=0; i<n; i++) fill(dist[i], dist[i]+n, -1); //거리 초기화
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){// 동일한 구역 큐에 집어넣음.
            if(board[i][j]!=0){//모든 육지노드를 큐에 집어넣음
                q.push({i,j}); 
                dist[i][j]=0; //dist 0처리
                vis_col[i][j]=board[i][j]; //vis_col각 색깔로 채움.
                }
            }
    //bool escape=false;
    while(!q.empty() /*&& !escape*/ ){ 
        auto cur = q.front(); q.pop();
        for(int dir=0; dir<4; dir++){
            int nx=cur.x+dx[dir];
            int ny=cur.y+dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=n) continue; //범위 체크
            if(dist[nx][ny]!=-1 && vis_col[nx][ny]!=vis_col[cur.x][cur.y]){//방문한 것인데, 같은 육지에서 방문한게 아니라면
                mn=min(mn,dist[nx][ny]+dist[cur.x][cur.y]);
                //escape=true;
                //return 0;

            }
            if(dist[nx][ny]!=-1)continue; //방문여부(같은 육지노드가 방문한 것) 확인,  
            vis_col[nx][ny]=vis_col[cur.x][cur.y]; //색깔 전파.
            dist[nx][ny]=dist[cur.x][cur.y]+1; //dist 업데이트
            q.push({nx,ny});
            }
        }
    cout<<mn;
}

//본 코드(mn 적용 안한 코드) 체점 75퍼에서 틀렸습니다. 출력됨.
//정답보고 mn(큐가 빌때 까지 bfs 돌리고 가장 작은 mn값을 받아냄.) 적용하니 정답처리됨. ->왜?
/*
고민해보니.
발상대로 코드를 적용할 때 까지는, 그냥 
-> if(dist[nx][ny]!=-1 && vis_col[nx][ny]!=vis_col[cur.x][cur.y]){//방문한 것인데, 같은 육지에서 방문한게 아니라면
이 조건에 맞는 것이라면, 바로 가장 작은 다리 길이가 출력될 것이라 생각하였음.(bfs 특성상 거리순서대로 dist를 업데이트 하며 진행되므로.)
가장 먼저 만나게 되는 것은 당연히 가장 작은 거리에서 만나게 되는 것이라 판단하였음. 

하지만,
다음과 같은 입력의 경우
5
1 0 0 0 1
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 1 0 0 1
결과로 '3'이 출력된다.
그 이유는 bfs가 진행되며 dist를 업데이트 하다보면
(bfs 1순회애서 dist와 vis_col)
0 1 0 1 0 
1 0 0 0 1
0 0 0 0 0
0 1 0 0 1
1 0 1 1 0(dist)

1 1 0 2 2
1 0 0 0 2
0 0 0 0 0
0 3 0 0 4
3 3 3 4 4(vis_col)
(bfs 2순회 )-> 여기서 의도와 다르게 진행됨.
bfs알고리즘은 board의 윗부분에서 부터 진행되므로.
(x, y) : (0,1)에서 dist와 vis_col이 퍼져나가면, (0,2)의 dist vis_col이 차게되고, 이후 그 다음~~순서인 (0,3)에서 bfs 4방향 탐색 시 인접한 (0,2)가
dist!=-1이면서(방문한 것이면서), vis_col[nx][ny]!=vis_col[cur.x][cur.y](같은 육지에서 뻗어나간 것이 아님) 조건을 만족하게 되므로 
두개의 거리값을 합한 값을 출력하고 프로그램을 종료한다.

즉, 분명 출력 값이 더 큰 값이 나옴에도 불구하고, 각 bfs의 진행 거리가 같게 겹치면서(위 예시의 경우 둘다 bfs dist 두번째 순서),
큐의 앞에 위치하기 때문에 조건을 일찍 만족하고 값을 출력하게 된다. 

따라서, 이러한 경우를 보완하려면 mn값을 도입하여 매번 min함수를 통해 mn값을 업데이트 하여 가져갸야 한다.
*/

/* O(n2)방식 정답코드와 비교,

육지노드를 한번에 큐에 넣고 bfs를 돌리는 것, 육지노드의 색깔값을 다른 노드로 전파하는 것. 발상자체는 동일하였음.
단, 정답코드는 vis_col배열을 만들지 않고 board배열을 그대로 사용하였음.(생각해보면, 굳이 vis_col배열을 만들지 않아도됨.)
그래서, if조건 또한 더 깔끔하게 줄 수 있었음.

###<정답코드 IF 조건>
      if(OOB(nx,ny) || board[nx][ny] == board[cur.X][cur.Y]) // OOB거나 인접한 곳이 같은 섬일 경우
        continue;
      if(board[nx][ny] != 0){ // 인접한 곳이 다른 섬일 경우
        ans = min(ans,dist[nx][ny]+dist[cur.X][cur.Y]); // cur와 (nx, ny) 각각이 육지로부터 떨어진 거리를 합하면 된다.
      }
      else{ // 바다일 경우
        board[nx][ny] = board[cur.X][cur.Y];
        dist[nx][ny] = dist[cur.X][cur.Y]+1;
        Q.push({nx,ny});
###

둘을 비교하면
정답코드 if필터(vis_col을 사용하지 않고 board를 그대로 사용)
1. 범위체크, nx,ny보드==cur.x,cur.y보드(같은 육지 노드에서 방문한 것인지 체크)
   continue;
-> least.
(1)같은 육지노드에서 방문한 것이 아닌 것(다른 육지노드에서 전파된 것) 
(2)방문하지 않은 것(바다)

2.nx,ny보드가 0이 아니라면,(바다가아니라면) 위 (1),(2)중 (1)에 해당 
ans 갱신

3. else -> (2)만남음(바다)
dist갱신
board전파
큐에 푸쉬.

nx,ny가 들어오면
1, 2, 3,조건 중 하나만 해당되고 시행.
----------------------------------------
직접 푼 코드 if 필터
1. 범위 체크 ->continue;

2. dist가 -1이 아니면서(방문체크), vis_col이 같지 않다면->(다른 육지노드에서 방문한 것이면)
-> mn(ans) 갱신 

=>least
(1) 방문한 것인데, 같은 육지노드에서 방문한 경우 + 다른 육지노드에서 방문한 경우.
(2) 방문하지 않은 경우(바다)

3. 보드가 0이 아니거나, dist가 -1이 아니면 continue;
(육지에 닿았거나) (방문한것이면(같은,다른 통틀어))  
filting - (1)같은 육지노드에서 방문한 것.

=>least (2) 바다인경우

4 for문의 나머지
dist갱신
vis_col갱신
큐 푸쉬. 

->nx,ny가 들어오면,
1조건 필팅, (least 범위 안의 데이터)
2조건 맞으면 시행 
3조건 필팅 (least 방문하지 않은 것이면서 육지노드가 아닌 것->바다)
남은 for문 시행 을 거침.

>>>IF조건을 분석한 후에 직접푼 코드의 IF조건을 개선하면 

1)3번 조건에서 BOARD!=0(육지노드에 닿았는지)을 확인할필요 X->이미 육지노드는 방문처리를 하기때문에.
2)기존 코드처럼 조건 흐름을 두지 말고 정답코드의 흐름을 참고하면.
            if(nx<0||nx>=n||ny<0||ny>=n) continue; //범위 체크
          ////->least (1)방문한 것(1-1. 같은 육지노드에서 방문한 것. 1-2. 다른 육지노드에서 방문한 것)(혹은 같은/다른육지노드)
          ////        (2)방문하지 않은 것(바다)
            if(vis_col[nx][ny]==vis_col[cur.x][cur.y]) coninue; //같은 육지노드에서 방문한것 filting
          ////->least (1)다른 육지노드에서 방문한 것.(혹은 다른 육지노드)
          ////        (2)방문하지 않은 것(바다)
            if(dist[nx][ny]!=-1){//방문여부확인->다른 육지노드에서 방문한 것이 이 조건에 걸림.
                mn=min(mn,dist[nx][ny]+dist[cur.x][cur.y]); //mn갱신
            }
          ////->least (1)방문하지 않은 것(바다)
            else{  //dist, vis_col갱신, 큐 푸쉬 시행 
                vis_col[nx][ny]=vis_col[cur.x][cur.y]; //색깔 전파.
                ist[nx][ny]=dist[cur.x][cur.y]+1; //dist 업데이트
                q.push({nx,ny});
            }
이와 같이 개선 가능.
~~~>(1) if조건을 설정할 때, if에서 걸러지는 것을 먼저 continue;하고 나머지 조건에서 if,else조건을 잘 걸고 시행하면 깔금하게 작성가능.
    (2) if 조건 작성시 걸러지는 것과 남는 것을 잘 체크하고 적어놓으면, 깔끔한 조건 작성 가능.
    (3) board를 그대로 사용할 수있는 경우 그대로 사용하기.

*/