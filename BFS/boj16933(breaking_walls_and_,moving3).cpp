#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
string board[1000];
int dist[1000][1000][11][2]; //마지막 칸은 낮,밤.
int n,m,k;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool OOB(int x, int y){
    return x<0 || x>=n || y<0 || y>=m;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=0; i<n; i++) cin>>board[i];
    queue<tuple<int,int,int,int>> q;
    dist[0][0][0][0]=1; //정답코드 : 4차원 배열, 0은 낮, 1은 밤. 
    q.push({0,0,0,0});
    while(!q.empty()){
        auto[curx, cury, w, time]=q.front(); q.pop(); //auto로 묶어서 받는거 c++17에서만 가능한 것 주의하기
        if(curx==n-1&&cury==m-1){//도착점 도달
            cout<<dist[curx][cury][w][time];
            return 0;
        }
        for(int dir=0; dir<4; dir++){
            int nx=curx+dx[dir];
            int ny=cury+dy[dir];
            if(OOB(nx,ny)) continue; //범위체크
            int nw=w;
            if(board[nx][ny]=='1') nw++;
            if(nw>k || dist[nx][ny][nw][!time]) continue; //벽 부수기 횟수 체크, 방문 체크
            if(time && board[nx][ny]=='1'){ // 벽인데, 밤이라서 벽을 못깬다면, 제자리에 머뭄. 제자리 낮 밤 바뀐상태로 dist+1;
                dist[curx][cury][w][!time]=dist[curx][cury][w][time]+1; //-> 방법1 제자리값에 time만 바꿔서 dist+1; 하고 큐 푸쉬.
                q.push({curx,cury,w,!time});                            //단 이렇게하면, 다음 이 인자를 큐에서 뺄 때 4방향 탐색하면서 이 때의nx,ny외에도 벽이 아닌 다른 곳으로 이동하며 큐에 인자를 넣게됨.(불필요하게 큐에 인자가 들어가게됨+불필요한연산) 
            }//방법2 -> dist[nx][ny][nw][time]=dist[curx][cury][w][time]+2; q.push(~) ->정답은 도착지점 값중 min값으로, if방문조건을 nx,ny의 먼저 적혀있던 dist보다 지금 들어가는 dist가 더작으면 방문가능(즉, 크거나 같으면 continue;)
            else{//벽인데, 밤이 아닌경우, 혹은 벽이 아닌경우(낮/밤모두)
                dist[nx][ny][nw][!time]=dist[curx][cury][w][time]+1;
                q.push({nx,ny,nw,!time});
            }
        }
    }
    cout<<-1; //탈출못했으면 -1출력
}

/*진행한 방식, 
기존 틀 자체는 벽부수고 이동하기 2에서 썼던 방식과 동일, 여기에 플러스로 밤이면서 벽일때 케이스를 처리하는 코드를 추가해줌.
통과 => 1556ms,
코드 특성상, dist[1000][1000][11][2]를 모두 탐색하는 경우가 최악의 경우임.
(벽에서 막히는 경우 그 자리에서 +1하고 dist값을업데이트하므로, 그 dist지점부터 다시 4방향으로 dist값을 갱신함.
->(nx,ny)그자리에서 밤에 막힘->curx,cury[time은 반대]의 dist값+1로 갱신, 
1)제자리로 갱신 된 dist
한 턴 쉰 후, 제자리로 갱신되어 넣어진 자리값을 큐에서 뺴고, 다시 4방향 탐색, 
주변의 벽이 아닌 길로, dist를 갱신하면서 감(그자리 낮-> 주변의 자리 밤)

2)그자리 밤에서 벽을 제외한 다른 길로 업데이트를 진행한 dist
주변의 벽이 아닌 길로, dist를 갱신하면서 감(그자리 밤-> 주변의 자리 낮)

=>1)의 케이스와 갱신되는 dist의 낮/밤이 달라서, 제자리로 다시 갱신된 dist는 다시 퍼져나갈 필요가 없음에도 갱신되게됨.
따라서, 최악의 경우, 1000*1000*11*2(물론 벽은 제외하겠지만.) 모두를 탐색.

+) 방법 2로 밤에 벽을 만난 케이스를 처리한다면,
밤인데 벽인 자리(nx,ny)를 dist를 +2하여 업데이트하고 큐에 집어넣음.(따라서 이때, 큐에 넣어지는 것들은 시간 순서대로 집어넣어지지 않음.)
그러므로, 더 늦게 도착해야할 dist값이 더 빨리 도착할 수도있음. 
따라서, dist를 갱신할 떄, 기존 dist값보다 현재 dist값이 더 작다면 방문한 것이더라도 갱신 가능하도록 진행함.
또한, 모든 배열에 대하여 bfs를 다 진행한 후 
모든 배열의 도착지점에서의 최소값을 반환하도록 진행함.
이경우 모든 배열을 bfs를 진행하게 되므로 
확정적으로 n*m*k*2의 시간복잡도를 가지게 됨. 따라서, 방법1보다 시행속도가 더 느림.(방법 1은 더 빠르게 종료될 가능성이 있기때문.)

->개선???

=> 바킹독 정답코드 확인.
발상자체는 본 코드와 동일함. 다만, 큐에서 나온 인자를 검증하는 순서가 조금 다름.
정답코드는 nx,ny에 대하여 우선 nx,ny자리가 0이라면 그냥 dist+1하도록 하고. 다음 인자 nx,ny를 탐색함.
만약 0이 아니라 1(벽)이라면 벽부수기 k 횟수 확인 후, 밤/낮 확인 후 dist+1하여 넣도록함,
(벽인데 밤을 만났을 때 처리방식은 본 코드와 동일.) 
이렇게 한 경우 발상은 동일하나 처리 속도가 1064ms로, 본 코드에 비해 1.5배 더 빨랐음.

정답코드 : http://boj.kr/77063fc182b64ce689f3636e86bd2eef
이유를 분석해 보자면, 정답코드의 경우, 0인경우 그냥 dist+1하고 바로 다음인자를 탐색함.
1을탐색하는 경우, 본 코드와 정답코드 모두 범위체크, 보드체크 이후 k체크하여 걸러내지만,
0을 탐색하는 경우, 정답코드는 바로 dist를 갱신하고 넘어가고, 본 코드는 if를 여러개 더 거치고
(nw>k확인하기, 벽인데 밤인지 확인하기)나서 dist를 갱신함.
이 if를 거치는 횟수가 본코드가 훨씬 더 많으므로 오래 걸린 것으로 추측됨.
코드 가독성의 경우 본 코드가 조금 더 깔끔함.
다만, 인자의 개수는 동일한데 if문 몇개 더 거치는 것으로 시간복잡도가 1.5배 차이나는 것은 의외였음.
if문을 넣어 코드를 짤 때 더 신경쓸 필요가 있겠음.
)
*/