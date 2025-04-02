//(1)큐에서뺀값에대해 *2(텔레포트)값을 미리 다 처리하여 큐에넣고 그다음 -1,+1 진행하기->반복 벙식
#include <iostream>
#include <queue>
using namespace std;
int dist[100002];
int n,k;
queue<int> q;

void teleport(int num){ // num받고, num*2한 것에 대해 (방문체크, 범위체크, 목표도착여부체크) num*2자리에<-num의 dist갱신
    if(!num) return; //num이 0이라면 종료.(2배 해도 계속 0.)
    int nxt=num;
    while(nxt<100001 && !dist[k]){
        if(!dist[nxt]){//방문체크 후 시행.
            dist[nxt]=dist[num];
            q.push(nxt);
        }
        nxt<<=1;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    q.push(n);
    dist[n]=1; // while조건을 아래와 같이 두기위하여 시작점의 dist를 1로 설정함.
    teleport(n);
    while(!dist[k]){ //while 조건을 (!dist[k]) 로 두어. 동생이 있는 위치에 도달하면(동생)(동생이 있는 위치의 dist가 변경되면)while문을 멈추게 하였음. ->if조건 따로 안넣어도 됨 더 간단.
        auto cur=q.front(); q.pop();
        for(auto nxt : {cur-1, cur+1}){
            if(nxt<0||nxt>100001) continue; //범위 체크, 범위를 넓게 잡아봄.
            if(dist[nxt]) continue; //방문 체크
            dist[nxt]=dist[cur]+1;
            q.push(nxt);
            teleport(nxt);
            }
        }
    cout<<dist[k]-1;//출력문을 while 문 밖으로 뺌.
}

/* 

(1)큐에서뺀값에대해 *2(텔레포트)값을 미리 다 처리하여 큐에넣고 그다음 -1,+1 진행하기->반복 벙식

*/