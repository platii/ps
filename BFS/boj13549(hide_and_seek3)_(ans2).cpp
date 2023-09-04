//방법 (2), 0-1dfs, 가중치가 0과 1만 존재하는 그래프의 bfs.
//텔레포트하는 경우 dq의 프론트에 push dist는 num의 값 그대로 갱신,
// 걷기 하는 경우 dq의 back에 push dist는 num의 값+1 하여 갱신.
#include <iostream>
#include <deque> 
using namespace std;
const int MX=100001;
int board[MX];
int dist[MX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    deque<int> dq;
    dq.push_front(n);//시작점 디큐에 삽입.
    dist[n]=1;
    while(!dist[k]){
        int cur=dq.front(); dq.pop_front(); //디큐 front값 가져오고 삭제.
        for(int nxt : {2*cur, cur-1, cur+1}){
            if(nxt<0||nxt>MX) continue; //범위체크
            if(dist[nxt]) continue; //방문체크
            if(nxt==2*cur){ //텔레포트
                dist[nxt]=dist[cur];
                dq.push_front(nxt);
            }
            else{ //걷기
                dist[nxt]=dist[cur]+1;
                dq.push_back(nxt);
            }
        }
    }
    

    cout<<dist[k]-1;

}

//정답코드는 dist를 -1로 초기화 한 후, 방문여부를 dist[nxt]==-1로 체크, 마지막으로 cout<<dist[k]; 하도록 하였음.
//-> 큰 차이는 없음.