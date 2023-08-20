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

/* 정답코드 확인

정답코드도 전반적인 풀이 자체는 비슷했음. 
무한루프 while(true)를 돌리고
그 안에서
빙산 녹이기
vis배열 초기화
빙산 덩어리 개수 체크
순으로 진행함.
다만, 정답코드는 빙산 녹이는 과정 또한 함수로 만들어서 진행했음.

차이점은
빙산 녹이기 과정에서 : 
(변화가 실시간으로 적용되면 안되므로)pboard로 board의 변화값을 받는 것 대신, 

4방향 탐색에서 주변의 0의 개수를 모두세서 zero[][]라는 배열에 (그위치에서의 주변의 0의 개수를) 저장하고.
bfs가 모두 끝나면 board[i][j]=max(0, board[i][j]-zero[i][j]); 코드를 for문돌려서, 녹고나서의 빙산의 상태를 저장하도록 했음.
(max함수를 활용하여 0체크 또한 한번에 진행하였음.)
=> 이렇게 하니 코드가 훨씬 간결함.(시간복잡도는 큰 차이 없는 듯함), **현재board의 값을 변화시키지 않고(board의 값이 실시간으로 변하지 않고)나중에 처리해야할 때**
이방식을 사용하자.

빙산 덩어리 개수 체크 과정에서 : 
for문에서 board가 0이 아니라면 bfs를 실행하며 영역체크하고, 다시 for문을 반복하며 구역의 개수를 체크하는 방식 대신,

우선 for문을 통해 0이 아닌 보드(노드)의 개수를 cnt1에 저장하고, if문을 통과한 지점 i,j에 대해 x=i, y=j로 그값을 저장해둠.
후에 다음, for문에서 , 이전 for문의 마지막 지점인 x,y부터 다시 시작해서, 그 지점에 인접한 0이 아닌 영역의 개수를 세서 cnt2에 저장
이 후, cnt1과 cnt2의 크기가 같다면 빙산이 분리되지 않았다는 것, cnt1과 cnt2의 크기가 다르다면 빙산이 분리된 것이므로 이를 통해 빙산의 상태 파악함.
이 방식은 직접 푼 방식과 코드 간결성, 시간복잡도, 공간효율면에서 큰 차이는 없는듯 함.

다만, cnt1을 체크할 때 cnt1==0이라면 빙산이 다 녹음을 바로 체크할 수 있으므로 코드 압축성에는 좋은 듯하다.(빙산이 다녹은 것을 체크하는 코드를 따로 작성할 필요 x)
->그렇지만, 직접 푼 코드는 큐와 while문 조건을 통해 빙산이 다 녹음을 파악하게 했으므로 이또한 큰 차이는 없는듯함.(하지만 다른데서 쓰일 수도 있으므로 발상 기억해두기.)

-->함수를 나눠서 작성하니 보기에는 더 편하다. 함수를 나눠서 작성하는 습관을 기르자.

*/