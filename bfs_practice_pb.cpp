#include <iostream> //bfs->헤더정의, using std, x/y정의, 보드 정의, vis선언, n(행개수)/m(열개수) 정의, dx/dy정의
#include <utility> //pair 메소드사용
#include <queue>
using namespace std;
#define x first
#define y second
int board[502][502]=
{{1,1,1,0,1,0,0,0,0,0},
{1,0,0,0,1,0,0,0,0,0},
{1,1,1,0,1,0,0,0,0,0},
{1,1,0,0,1,0,0,0,0,0},
{0,1,0,0,1,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0}};
bool vis[502][502]; //방문 여부를 저장
int n=7, m=10; //n은 열의 개수, m은 행의 개수
int dx[4]={1, 0, -1, 0}; //상하좌우 방향.
int dy[4]={0, 1, 0, -1};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int,int>> q; //q선언
    vis[0][0]=1; //시작점 방문처리
    q.push({0,0}); //큐에 시작점 삽입
    while(!q.empty()){ //큐가 빌때까지 반복.
        pair<int,int> cur = q.front(); q.pop(); //front(), pop() 괄호 잊지 말기.
        cout<<'('<<cur.x<<", "<<cur.y<<") -> ";
        for(int dir=0; dir<4; dir++){
            int nx=cur.x+dx[dir];
            int ny=cur.y+dy[dir];
            if(nx<0||nx>n||ny<0||ny>n) continue;
            if(vis[nx][ny]||!board[nx][ny]) continue;
            vis[nx][ny]=1;
            q.push({nx,ny});
        }
    }
}


