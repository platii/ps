//연습문제 1.
//dp로 간단하게 풀 수 있는 문제이나 우선 bfs로 풀어본경우.
#include <iostream>
#include <queue>
using namespace std;

const int MX=1000001;
int dist[MX];
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    queue<int> q;
    q.push(1);
    dist[1]=1;
    while(!dist[n]){
        auto cur = q.front(); q.pop();
        for(int nxt : {3*cur, 2*cur, cur+1}){
            if(nxt>MX || nxt<0) continue; //범위체크
            if(dist[nxt])continue;
            q.push(nxt);
            dist[nxt]=dist[cur]+1;
        }
    }
    cout<<dist[n]-1;
}
/*
우선
bfs로 시도.

1) dist[n]=1, q.push(n) 로 시작하여 cur/3, cur/2, cur-1로 1에 접근하면 종료하도록 함.
->틀림
#############
#include <iostream>
#include <queue>
using namespace std;

int dist[1000001];
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    queue<int> q;
    q.push(n);
    dist[n]=1;
    while(!dist[1]){
        auto cur = q.front(); q.pop();
        if(cur%3==0){ //3으로 나누어진다면
            if(dist[cur/3]) continue; //방문체크
            q.push(cur/3);
            dist[cur/3]=dist[cur]+1;
        }
        if(cur%2==0){ //2로 나누어진다면
            if(dist[cur/2]) continue; //방문체크
            q.push(cur/2);
            dist[cur/2]=dist[cur]+1;
        }
        //1을 빼기.
        if(dist[cur-1] || cur-1<0)continue;
        q.push(cur-1);
        dist[cur-1]=dist[cur]+1;
    }
    cout<<dist[1]-1;
}
##########

-> 교안에 있는대로 1부터 시작해서 *3, *2, +1로 n에 도달하면 종료하도록 바꾸어봄.
-> 정답.
*/