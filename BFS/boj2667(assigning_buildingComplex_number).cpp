#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;
#define x first
#define y second
string board[25];
bool vis[25][25];
int n;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int arr[625];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    queue<pair<int,int>> q;
    int num_complex=0;
    for(int i=0; i<n; i++) //보드 채우기
        cin>>board[i]; //실수 3) string이므로 board[i][j] 이런식으로 저장하면 안됨
        
    for(int i=0; i<n; i++) 
        for(int j=0; j<n; j++){
            if(board[i][j]=='1'&&vis[i][j]!=1){
                vis[i][j]=1;
                q.push({i,j});
                int cnt=0;
                while(!q.empty()){
                    cnt++;
                    auto cur=q.front(); q.pop();
                    for(int dir=0; dir<4; dir++){
                        int nx=cur.x+dx[dir];
                        int ny=cur.y+dy[dir];
                        if(nx<0||nx>=n||ny<0||ny>=n) continue;
                        if(vis[nx][ny]==1||board[nx][ny]=='0') continue;
                        vis[nx][ny]=1;
                        q.push({nx,ny});
                    }
                }
                arr[num_complex]=cnt; //실수 2) num_complex를 증가하기 전에 배열에 저장을 먼저 해야함.
                num_complex++;
            }
  
        }
        sort(arr,arr+num_complex); //문제 잘 읽고 코드 쓰기, 오름차순으로 제출해야하므로 정렬해서 출력해야함.
        cout<<num_complex<<'\n';
        for(int i=0; i<num_complex; i++) cout<<arr[i]<<'\n'; //실수1) for문 범위 n이 아니라 num_complex(단지의 개수)적어야함. 습관적으로 n 적지 말기.
}