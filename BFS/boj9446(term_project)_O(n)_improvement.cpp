//O(n) 풀이, 정답보고 개선. -> state에 지정한 상수들 대신, h를 넣음. 
#include <iostream>
using namespace std;
int num[100001];
int t, n, in_cycle; 
int state[100001];

const int NOT_VISITED=0;
const int CYCLE_IN = -1;

void run(int h){ 
    int cur=h;
    while(true){
        state[cur]=h; //처음 시작 지점을 방문처리하고 들어감.
        cur=num[cur];
        if(state[cur]==h){ //1. 이번 run함수에서 방문했던 것을 다시 방문한 경우.
            while(state[cur]!=CYCLE_IN){  
                in_cycle++;
                state[cur]=CYCLE_IN;
                cur=num[cur];
            }
            return;
        }
        else if(state[cur]!=NOT_VISITED){//2. 이전 run함수에서 방문했던 것을 방문한 경우.
            return;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--){
        in_cycle=0;
        cin>>n;
        fill(state+1, state+n+1, 0);
        for(int i=1; i<=n; i++){
            cin>>num[i]; //학생인덱스별, 지목한 학생 값 입력 받음.
        }
        for(int i=1; i<=n; i++){
            if(state[i]!=0) continue;//들어온 h가 이전 run에서 이미 방문한 것이라면 넘어감.
            run(i);
        }
        cout<<n-in_cycle<<'\n';
        /* 혹은
        cnt=0;
        for(int i=1; i<n; i++)
            if(state[i]!=CYCLE_IN) cnt++;
        cout<<cnt<<'\n';
        처럼, 사이클에 속하지 못한 노드를 체크하는 방법도 있음.취향에 따라 사용하자
        */
    }
}

/* O(n) 정답 코드
not_cycle_in 상수 선언 없이 코드 작성한 경우.
(방문을 visted대신 시작점 h로 표현한경우)
->정답코드의 경우, visited와 cycle_in 상수만 선언하여 cycle_in만 체크한 후
main문에서 cycle_in이 아닌 노드의 개수를 따로 체크하였음.




-> 직접 작성한 코드.
void run(int h){ 
    int cur=h;
    while(true){
        state[cur]=h; //처음 시작 지점을 방문처리하고 들어감.
        cur=num[cur];
        if(state[cur]!=0 && state[cur]!=h){ //1. 사이클을 이루는 학생 또는 사이클을 이루지 못하는 학생을 만난 경우. -> h(출발지점)부터 그지점까지 방문한 학생들을 사이클을 이루지못하는 학생 처리
            cur=h;         //state[cur]!=h 이면, 이전 run에서 방문한 노드이므로 cycle_in or not_cycle_in임.
            while(state[cur]==h){ 
                //cur=num[cur]가 이자리에 있으면안됨. 아래로 가야함.(실수)
                num_notCycle++;
                cur=num[cur];
            }
            return;
        }
        if(state[cur]==h && cur!=h){//2. x가 y를 지나고 또다시 y를 만난 경우-> y에서 다시 돌아서, y에 돌아올 때 까지 학생들->사이클에 속한 학생처리 + x에서 y까지 돌아가서 방문한 학생들 사이클에 속하지 않은 학생처리
            int tmp=cur; //y지점 저장
            cur=h;
            while(cur!=tmp){//x(h)부터 y지점 까지 방문하는 지점 notCycle처리, y지점은 이미 isCycle처리 했으므로 다른 처리를 하면 안됨.
                num_notCycle++;
                cur=num[cur];
            }
            return;
        } 
        if(cur==h){//3. x가 특정된 학생들을 방문하지 않고, 다시 x로 돌아오는 경우->다시 돌아서 x에 돌아올 때까지 -> 학생들 사이클에 속한 학생처리
            return;
        } 
    }
}

*/