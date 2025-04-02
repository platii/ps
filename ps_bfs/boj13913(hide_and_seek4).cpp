#include <iostream>
#include <queue>
using namespace std;
const int MX=100002;
int dist[MX], prepos[MX], arr[MX]; //dist 저장, 이전위치 저장, 답 입력할 배열

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    queue<int> q;
    q.push(n);//실수) 시작점 n 푸쉬안한 실수
    dist[n]=1;
    while(!dist[k]){
        int cur=q.front(); q.pop();
        for(int nxt : {2*cur, cur-1, cur+1}){
            if(nxt<0||nxt>100001) continue; //범위체크
            if(dist[nxt]) continue; //방문체크
            dist[nxt]=dist[cur]+1;
            q.push(nxt);
            prepos[nxt]=cur; //다음위치의 prepos로 현재 위치 값 저장.
        }
    }
    cout<<dist[k]-1<<'\n'; //dist 출력.
    /* 직접푼 코드
    int i=1, num=k;
    arr[0]=k;
    while(num!=n){ //초기값에 도달할 때까지
        arr[i]=prepos[num];
        num=arr[i]; //num의 이전값
        i++;
    }
    while(i--){
        cout<<arr[i]<<' ';
    }
    */
    deque<int> track={k};
    while(track.front()!=n){ //track의 front에는 도착지점k부터 시작하여 prepos의 지점이 저장이됨.
        track.push_front(prepos[track.front()]);
    }
    for(int p : track) cout<<p<<' ';
}

//정답코드 확인 -> 발상(prepos에 이전 자리 값 저장하고, 출력 시, 다시 도착지점부터출발지점까지의 인자들을 저장하여 출력)은 동일.
//다만, 출력 할 때 deque를 사용하여 쉽게 출력하도록 함.
//deque에 k를 저장한 후, k의 prepos부터 차례로 deque의 front에 저장(push_front)
//다 저장 한 후에, for-each문, for(p : deque) cout<< p << ' ';로 쉽게 출력
/*정답코드 출력 부분.

deque<int> track={k};
while(track.front()!=k){ //track의 front에는 도착지점k부터 시작하여 prepos의 지점이 저장이됨.
    track.push_front(prepos[track.front()]);
}
for(int p : track) cout<<p<<' ';

->큐를 사용하면 안되나?
큐는 처음 저장한 값이 front 이후 저장되는 값이 rear위치에서 계속 갱신됨.
for-each문을 적용하기 애매함.

->배열을 사용하면?
배열은 크기를 정해두고 사용해야하고 push_front같은 함수가 없으므로 dq가 편의성, 공간효율면에서 더 좋음

*/