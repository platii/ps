#include <iostream>
#include <utility>
#include <queue>
using namespace std;
#define x first
#define y second
int dist[302][302];
int dx[8]={1,1,2,2,-1,-1,-2,-2};
int dy[8]={2,-2,1,-1,2,-2,1,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,a,b,c,d;
        cin>>n; //판의 크기
        cin>>a>>b; //나이트가 현재 있는 칸(x,y)
        cin>>c>>d; //나이트가 도착하기 원하는 칸(x,y)
        for(int i=0; i<n; i++) fill(dist[i], dist[i]+n, -1);
        queue<pair<int,int>> q;
        q.push({a,b}); //x,y
        dist[a][b]=0; //행의개수(행 위치), 열의 개수(열 위치) [y], [x], 2차원 배열에 넣을 때만 x,y 꼬아서 넣어줌.
        while(!q.empty()){
            auto cur=q.front(); q.pop();
            if(cur.x==c&&cur.y==d) { // 실수 : 큐에 넣을 때 도착여부를 검사하면, 최초위치=원하는위치로 주어졌을 때(ex 최초1,1 / 원하는위치1,1)체크불가능 큐에 뺄때 검사해야함 
                    cout<<dist[cur.x][cur.y]<<'\n'; //답 출력할 때 꼭#### 테스트 케이스별로'\n'####줄바꿔서 나오도록.
                    //리턴 하면 안됨. 실수 x return 0;
                    break;
                }
            for(int dir=0; dir<8; dir++){
                int nx=cur.x+dx[dir];
                int ny=cur.y+dy[dir];
                if(nx<0||nx>=n||ny<0||ny>=n) continue;
                if(dist[nx][ny]>=0) continue; //방문한 곳 재방문 x, 2차원배열 dist의 좌표에 맞게 nx,ny 넣어줌.
                dist[nx][ny]=dist[cur.x][cur.y]+1;
                q.push({nx,ny});
            }
        }
    }

}

//#######실수!!!!###########
//실수, 반복문 안에 출력 후에 return(종료)하면안됨->break 써야하는 거 return 쓰지 말자.
//실수 2, 출력할 때 '\n' 꼭 붙여야함. ->이런 실수는 그냥 제출로는 왜 틀린지 알수가없음. 잘 주의해야함.
//실수3 조건검사 위치. : 큐에 넣을 때 조건검사하면 맨처음 큐에 들어간 인자는 조건검사가 안됨. 조건검사는 그냥 큐에서 뺄때 할 것.

/* 정답코드 확인
그냥, 테스트케이스 별로, bfs while문 끝에 cout<<dist[c][d]<<'\n'; 를 출력하도록 하였음. 이게훨씬 간단한 듯함.
그런데 코드 효율자체는 저렇게, 목표 도달 후 빠져나오는 것이 더 좋음.
정답코드는 dist에 nx, ny를 바꾸지 않았음-?본 코드도, nx,ny 그냥 넣어도 똑같은 답이 나옴. -> n by n 배열이기 때문인가?
(n*n이기 때문으로 생각->이래서 앞의것이 x인지,y인지 제대로 알려주지 않은 듯함. )

*/