#include <iostream>
#include <utility>
#include <queue>
using namespace std;
#define x first
#define y second

int board[502][502];
bool vis[502][502];
int n,m;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int mx, num;//그림 최대 넓이, 그림개수

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++) //보드 입력 받음.
        for(int j=0; j<m; j++)
            cin>>board[i][j];
    queue<pair<int,int>> q;
    for(int i=0; i<n*m; i++){  //모든 보드에 대하여 bfs 검증. 시행.
        int area=0;
        int x=i/m, y=i%m; //요 형식 외우기.(i,x,y모두 0부터 시작하므로)
        if(vis[x][y] || !board[x][y]) continue; //시작보드가 방문보드거나, 0이면 넘어감.
        vis[x][y]=1; //시작보드 방문 처리
        q.push({x,y}); //시작보드 큐에 삽입.
        area++; //시작보드 넓이 +1해줌.
        while(!q.empty()){
            //area++; 정답에서의 위치 ?
            pair<int,int> cur = q.front(); q.pop();
            for(int dir=0; dir<4; dir++){
                int nx=cur.x+dx[dir];
                int ny=cur.y+dy[dir];
                if(nx<0||nx>n||ny<0||ny>m) continue;
                if(vis[nx][ny]||!board[nx][ny]) continue;
                area++; //넓이 체크 (큐에삽입->그림에포함된다는 것이므로.)
                vis[nx][ny]=1; //방문처리
                q.push({nx,ny}); // 큐에 삽입
            }
        }
        mx=max(area,mx);
        num++; //그림 개수 세기, 맨처음 if를 통과했다면, 그림이 있다는 것이므로.
    }
    cout<<num<<'\n'<<mx;
}

/*정답 코드 확인
 mx, num을 전역이 아닌 지역변수로 선언해도됨.->상관은 없음.
 num을 for문 아래가 아닌, 앞에서 증가시킴(정확히는 초기if검증 후). -> 결과는 동일함
 area를 while문 시작할 떄 증가시킴.(즉, q에서 꺼낼 때 증가시킴.)
 나는, q에 넣을 때 증가시켰음.
 결국 -> 결과는 동일함.
 for문 좌표 전달 할 때 -> 굳이 i%M으로 하지 않고, 그냥 이중 for문으로 해도 됨. 이게 더 간단한 듯함.
 */
