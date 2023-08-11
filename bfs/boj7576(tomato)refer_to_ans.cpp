//정답 코드 참고하여 푼 코드
#include <iostream>
#include <utility>
#include <queue>
using namespace std;
#define x first
#define y second
int board[1000][1000];
int dist[1000][1000];
int n,m;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,-0,-1};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>m>>n; //m:열 개수, n:행 개수.
    queue<pair<int,int>> q;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            cin>>board[i][j];
            if(board[i][j]==1)
                q.push({i,j});
            if(board[i][j]==0)
                dist[i][j]=-1;
        }

    int maxday=0; //모두 익는데 걸리는 시간 측정.
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir=0; dir<4; dir++){
            int nx=cur.x+dx[dir];
            int ny=cur.y+dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(dist[nx][ny]>=0) continue;
            dist[nx][ny]=dist[cur.x][cur.y]+1;
            q.push({nx,ny}); 
            maxday=max(dist[nx][ny],maxday); //걸리는 시간 업데이트
        }
    }
    for(int i=0; i<n; i++) //남아있는 토마토 중 익지않은 토마토가 있는지 체크
        for(int j=0; j<m; j++)
            if(dist[i][j]==-1){ //익지않은 토마토가 있다면
                cout<<"-1";  //-1을 출력하고 종료
                return 0;
            }
    cout<<maxday; //그렇지 않다면 maxday(토마토가 다익는데 걸린 시간)를 출력
}

/* 정답 코드 확인

**day라는 표현 대신 dist라는 표현을 사용함. (어짜피 의미자체는 동일하기 때문)
->이런식의 코드를 작성할때는 그냥 편하게 dist로 통일하여 사용하자.

**for문으로 board를 입력받을 때,(따로 for문으로 빼지 않고) 익은 토마토의 좌표를 큐에 넣음.
~> 사실, 시간복잡도 면에서는 큰 차이는 없음. 다만 정답코드처럼 쓰는 것이 더 간략하므로 앞으로 이렇게 사용하자.

**또, 이때 익지않은 토마토(if(board[i][j])==0)는 dist를 -1으로 설정. (vis배열을 쓰지 않고도, 방문해야하는 토마토를 파악하기 위함.)
                                                                (추후, dist가 0보다 크거나 같다면 방문하지않도록 설정하였기 때문.(dist=-1일때만[익지않은 토마토일때만]방문))
                                                                (맨 처음, dist는 모두 0으로 초기화 되어있음(전역변수이므로, 자동으로 0으로 초기화))
  
for문 4방향 탐색시, **dist가 0보다 크거나 같으면 넘어가도록(방문하지 않도록) 설정함.
(board가 -1(벽이거나), 1(이미 익어서 큐에 넣어진 경우)인 경우는 방문할 필요 없기 때문에)

코드 간결성, board를 건드리지 않아도 된다는 점에서 dist를 사용하여 방문여부를 파악하는 것이 더 좋음. 
~> 앞으로는 이런식의 문제에선
dist를 활용하여 방문여부를 파악하자, 
이때, 방문한 노드는 0보다 크거나 같게하고. 4방향 탐색에서 dist가 0보다 크거나 같으면 넘어가도록 하는게 일반적이다.(방문하는 노드는 dist값이 바뀌므로)
또한, 이를 위해 n,m범위의 dist를 모두 -1로 초기화 하는 등의 방법을 사용한다.

익지않은 토마토가 남아있는 경우를 탐색하는 코드는 내가 푼 코드와 거의 유사한데,
특이점은, 정답 코드는 maxday의 값을 이때, 탐색했다.
->두 방식 모두 결과를 도출하는데에 큰 차이는 없으나
내가 푼 코드는, 큐에 노드를 넣을 때만 동작하므로, 연산을 덜 할 수 있다.
즉, 굳이 정답의 방식을 따를 필욘 없겠다.

*/