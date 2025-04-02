#include <iostream>
#include <queue>
using namespace std;
int dist[100002]; //크기를 10만1로 잡으면 틀림->왜?

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    queue<int> q;
    fill(dist, dist+100001, -1);
    q.push(n);
    dist[n]=0;
    while(!q.empty()){
        auto cur=q.front(); q.pop();
        if(cur==k){
            cout<<dist[cur];
            return 0;
        }
        for(auto nxt : {2*cur, cur-1, cur+1}){
            if(nxt<0||nxt>100001) continue; //범위 체크, 시험결과 범위를 10만으로 잡으면 틀림, 10만 1은 통과.
            if(dist[nxt]!=-1) continue; //방문 체크
            if(nxt==2*cur){
                dist[nxt]=dist[cur];
                q.push(nxt);

            }
            else{
                dist[nxt]=dist[cur]+1;
                q.push(nxt);
            }
        }
    }
}

/* 정답코드 확인
0-1bfs를 사용한 풀이가 있었음.

0-1 bfs : 간선의 가중치가 0과1로만 구성된 그래프의 bfs
deque를 사용. 

*/