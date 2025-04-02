//유형 1 : 거리 측정 
#include <iostream> //cout, cin(입출력) 사용
#include <utility>  // pair(두개의 자료형을 묶어서 사용할 수 있음, t=(first, second), t.first, t.second로도 호출 가능) 사용
#include <queue>
#define x first     //t.x, t.y 처럼 사용하기 위해 x,y를 define
#define y second
using namespace std;
string board[502];
bool vis[502][502];
int dist[502][502]; //지점별 거리 저장
int n,m;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++)
        cin>>board[i];
    queue<pair<int,int>> q;
    int cnt=1; //cnt=1 선언
    vis[0][0]=1;
    q.push({0,0});
    pair<int,int> pre={0,0}; //시작점을 pre에 저장해둠.
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        if(dist[cur.x][cur.y]!=dist[pre.x][pre.y])//맨처음시작점을 큐에서 꺼낼때는 증가x
            cnt++; //큐에서 뺄 때, cnt++;(단, 이전값과 dist가 다를때)
        pre=cur;
        for(int dir=0; dir<4; dir++){
            int nx=cur.x+dx[dir];
            int ny=cur.y+dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m) continue; //nx,ny 'nx >n ', 'ny>m' ~> 으로 되어있던것 등호 붙여서 (정답보고수정.)(실수)
            if(vis[nx][ny]||board[nx][ny]!='1') continue; //string이므로 (!board[nx][ny])로 작성할 수 없음!. char형 비교 사용.(정답보고수정)(실수)
            vis[nx][ny]=1;
            q.push({nx,ny});
            dist[nx][ny]=cnt; //그 지점에서의 dist(출발점부터 그지점까지 거리)
        }
    }
    cout<<dist[n-1][m-1]+1; //정답보고 수정, dist 측정 방식 특성상 +1해줘야 함.(실수)
}

/*정답 확인 후,
cin, 스트링형 배열로 받음.(어짜피 스트링은 char형배열이므로, 2차원배열 쓰듯이 코드 작성 가능.)
[입력되는 board가 붙여서 입력될 경우, string으로 전달 받기.]

vis배열 사용 안했음.
dist배열을 모두(board선언된 만큼만(n*m)) -1로 초기화함.(fill 사용)
이렇게 되면 dist[x][y]의 크기가 0보다 크거나 같다면 방문하지 않은 것(dist를 수정하지 않음.)이므로 vis배열 없이 방문여부 파악 가능
[dist를 계산하는 이런 방식의 경우 vis를 사용하지 않아도 된다.]

cnt변수를 사용하지 않고, 36번째 줄의 코드를 간단히 dist[nx][ny]=dist[cur.x][cur.y]+1
                                                꺼낸 pair(좌표)의 인접한 좌표는, 기존 좌표의 dist +1 을 해주면 됨.

세방식 모두 더 효율적임. 이 방식으로 기억할 것.

*/
