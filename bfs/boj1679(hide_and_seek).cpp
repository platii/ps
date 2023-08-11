#include<iostream>
#include<queue>
using namespace std;

int dist[100002]; //dist[100001]로 두면 틀림. 왜?
int n,k;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    queue<int> q;
    fill(dist, dist+100001, -1); 
    dist[n]=0;
    q.push(n);
    while(dist[k]==-1){ //while 조건 자체를 이렇게 설정하면 굳이 아래의 if문을 넣을 필요 없음.
        auto cur = q.front(); q.pop();
        for(int nxt : {cur-1, cur+1, 2*cur}){ //(range based for) 사용 // 이 아래 구현은 정답 참고하였음.- for each 문을사용함. 이런식의 문제에 다음에도 활용하기.(dx,dy를 쓰지 않는, 반복의 형태가 변칙적인 문제)
            if(nxt<0||nxt>100000) continue; //0,100000을 벗어나면 어짜피 가장 작은 거리값이 아님. -> 다만 다른문제에서는 범위가 0~10만이 아니라 20만까지도 넘어갈 수 있음. 이점에 유의하여 다른 문제를 풀 것.
            if(dist[nxt]!=-1)continue; // 방문한 곳은 또 방문 불가
            dist[nxt]=dist[cur]+1;
            q.push(nxt);
            /*
            if(dist[k]!=-1){
                cout<<dist[k];
                return 0;
            }
            */
        }
        
    }
    cout<<dist[k];

}