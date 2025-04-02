//O(n) 풀이 : 풀이법을 보고나서 구현함.
#include <iostream>
using namespace std;
int num[100001];
int t, n; 
bool isCycle[100001], notCycle[100001], vis[100001];
int num_notCycle;

void run(int h){ //n번안에 자기자신으로 돌아오면 cnt++
    if(isCycle[h]||notCycle[h]) return; //들어온 h가 이전 run에서 이미 방문한 것이라면 종료.
    int nxt=num[h];
    int tmp;
    while(true){
        if(isCycle[nxt]||notCycle[nxt]){ //1. 사이클을 이루는 학생 또는 사이클을 이루지 못하는 학생을 만난 경우. -> h(출발지점)부터 그지점까지 방문한 학생들을 사이클을 이루지못하는 학생 처리
            notCycle[h]=true; //출발지점 부터 그 지점 까지 모두 사이클 속하지 않은 학생 처리
            num_notCycle++;
            tmp=nxt;
            nxt=num[h];
            while(nxt!=tmp){ 
                //nxt=num[nxt]가 이자리에 있으면안됨. 아래로 가야함.
                notCycle[nxt]=true;
                num_notCycle++;
                nxt=num[nxt];
            };
            return;
        }
        //아래 조건에서, 시작지점 h는 vis처리를 하지 않기때문에 2번 조건에 걸리지 않고, 3번조건으로 깔끔하게 넘어가게됨.
        if(vis[nxt]==true){//2. x가 y를 지나고 또다시 y를 만난 경우-> y에서 다시 돌아서, y에 돌아올 때 까지 학생들->사이클에 속한 학생처리 + x에서 y까지 돌아가서 방문한 학생들 사이클에 속하지 않은 학생처리
            isCycle[nxt]=true; //y지점 isCycle처리
            tmp=nxt; //y 지점 따로 저장
            nxt=num[tmp];
            while(nxt!=tmp){//y부터시작해서 돌면서 방문하는 것들 모두 isCycle 처리.
                //nxt=num[nxt]가 이자리에 있으면 안됨.
                isCycle[nxt]=true;
                nxt=num[nxt];//위치 실수 x
            }
            notCycle[h]=true; //h지점 notCycle처리
            num_notCycle++;
            nxt=num[h];
            while(nxt!=tmp){//x(h)부터 y지점 까지 방문하는 지점 notCycle처리, y지점은 이미 isCycle처리 했으므로 다른 처리를 하면 안됨.
                notCycle[nxt]=true;
                num_notCycle++;
                nxt=num[nxt];
            }
            return;
        } 

        if(nxt==h){//3. x가 특정된 학생들을 방문하지 않고, 다시 x로 돌아오는 경우->다시 돌아서 x에 돌아올 때까지 -> 학생들 사이클에 속한 학생처리
            isCycle[h]=true;
            nxt=num[h];
            while(nxt!=h){ //h 이전까지 방문하는 지점 모두 isCycle 처리
                isCycle[nxt]=true;
                nxt=num[nxt];
            }
            return;
        } 
        vis[nxt]=true; //시작 지점 h에 대해서는 방문처리를 하지 않음.
        nxt=num[nxt]; 
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
        //bool isCycle_[100001]={}, notCycle_[100001]={}, vis_[100001]={};
        
        fill(isCycle+1, isCycle+n+1, 0);
        fill(notCycle+1, notCycle+n+1, 0);
        fill(vis, vis+n+1, 0);
        
        for(int i=1; i<=n; i++){
            cin>>num[i]; //학생인덱스별, 지목한 학생 값 입력 받음.
        }
        for(int i=1; i<=n; i++)
            run(i);
        cout<<num_notCycle<<'\n'; 
    }
}