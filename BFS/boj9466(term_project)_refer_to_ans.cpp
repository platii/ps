//O(n) 풀이, 정답보고 개선.
#include <iostream>
using namespace std;
int num[100001];
int t, n, num_notCycle; 
int state[100001];

const int NOT_VISITED=0;
const int VISITED=1;
const int CYCLE_IN=2;
const int NOT_CYCLE_IN=3;

void run(int h){ 
    int cur=h;
    while(true){
        state[cur]=VISITED; //처음 시작 지점을 방문처리하고 들어감.
        cur=num[cur];
        if(state[cur]==CYCLE_IN||state[cur]==NOT_CYCLE_IN){ //1. 사이클을 이루는 학생 또는 사이클을 이루지 못하는 학생을 만난 경우. -> h(출발지점)부터 그지점까지 방문한 학생들을 사이클을 이루지못하는 학생 처리
            cur=h;
            while(state[cur]==VISITED){ 
                //cur=num[cur]가 이자리에 있으면안됨. 아래로 가야함.(실수)
                state[cur]=NOT_CYCLE_IN;
                num_notCycle++;
                cur=num[cur];
            };
            return;
        }
        //아래 조건에서, 시작지점 h는 vis처리를 하지 않기때문에 2번 조건에 걸리지 않고, 3번조건으로 깔끔하게 넘어가게됨.
        if(state[cur]==VISITED && cur!=h){//2. x가 y를 지나고 또다시 y를 만난 경우-> y에서 다시 돌아서, y에 돌아올 때 까지 학생들->사이클에 속한 학생처리 + x에서 y까지 돌아가서 방문한 학생들 사이클에 속하지 않은 학생처리
            while(state[cur]==VISITED){//y부터시작해서 돌면서 방문하는 것들 모두 isCycle 처리.
                //cur=num[cur]가 이자리에 있으면 안됨.
                state[cur]=CYCLE_IN;
                cur=num[cur];//위치 실수 x
            }
            cur=h; ////
            while(state[cur]==VISITED){//x(h)부터 y지점 까지 방문하는 지점 notCycle처리, y지점은 이미 isCycle처리 했으므로 다른 처리를 하면 안됨.
                state[cur]=NOT_CYCLE_IN;
                num_notCycle++;
                cur=num[cur];
            }
            return;
        } 

        if(cur==h){//3. x가 특정된 학생들을 방문하지 않고, 다시 x로 돌아오는 경우->다시 돌아서 x에 돌아올 때까지 -> 학생들 사이클에 속한 학생처리
            while(state[cur]==VISITED){
                state[cur]=CYCLE_IN;
                cur=num[cur];
            }
            return;
        } 
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--){
        //함수 선언 2가지 방법, isCycle,등의 배열을 반복문마다 지역변수로 새로 선언하고, 함수에 배열전달하기 
        //or 배열을 전역변수로 선언해두고 반복문마다 n개까지 만큼 배열0으로 초기화하기. -> 둘다 시간차이 별로 없었음. 편한걸 쓰자.
        num_notCycle=0;
        cin>>n;
        fill(state+1, state+n+1, 0);
        for(int i=1; i<=n; i++){
            cin>>num[i]; //학생인덱스별, 지목한 학생 값 입력 받음.
        }
        for(int i=1; i<=n; i++){
            if(state[i]!=NOT_VISITED) continue;//들어온 h가 이전 run에서 이미 방문한 것이라면 넘어감.
            run(i);
        }
        cout<<num_notCycle<<'\n'; 
    }
}

/*

정답코드 : 동일한 방법의 구현(1,2,3으로 케이스를나누고 run함수 구현)에서,
isCycle, notCycle, vis의 3개 배열을 사용하는 대신 
->state배열 하나를 만든 후에,
not_visited=0, visited=1, cycle_in=2, not_cycle_in=3 의 상수값을 지정하여.
각 노드에서의 상태를 파악할 수있도록 함. 
---->코드 간결 + 메모리 절약 가능 하므로 잘 활용하기

+) run시작시 int cur=x로 초기 시작점을 받고
반복문 시작 시, state[cur]=visited 하여 시작점 방문처리, cur=arr[cur]; 하여 cur을 다음 노드값으로 지정.함
-> 직접 푼 코드는 x를 방문처리하지 않는다는 점에서만 차이가 있음. -> 그러나, 실제로 코드를 작성하여보니 2,3케이스의 경우, x를 따로 방문처리 하지 않았을 떄 조건을
더 깔끔하게 줄 수있었음. 
추가)->>>그런데 if조건을 정답코드처럼 깔끔하게 if(state[cur]==VISTED)로 두려면, 그냥 x부터 시작해서 방문처리 해야함.
->이런류의 방식을 따르려면 정답코드와 동일하게 진행하는 것이 좋을듯 함.
=>run 초기 int cur=x; 지정하고
->cur=arr[cur]로 바로들어가 코드 간결성이 좋아지는 점만 참고하면 될듯함.

방문여부 확인(if state[x]==NOT_VISITED)를 run함수 진입 전(main함수의 for문에서), 진입 후(run함수 시작 시 바로.) 할지는 취향에 따라.
->다시 생각해보니 함수를 호출해서 확인하는 것이 더 비효율적인 듯함. 이왕이면 함수 호출 전에 방문여부나 if조건을 확인하자.
not Cycle의 개수 체크는 직접 푼 방식이 더 효율적. 

*/