//O(n^2) 풀이
#include <iostream>
using namespace std;
int num[100001];
int t, n, cnt; 

void run(int h){ //n번안에 자기자신으로 돌아오면 cnt++
    int nxt=num[h];
    int k=n;
    while(k--){
        if(nxt==h){
            cnt++; //사이클을 이루는 인원의 수 +1
            return;
        }
        nxt=num[nxt];
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--){
        cnt=0; //cnt 초기화
        cin>>n;
        for(int i=1; i<=n; i++){
            cin>>num[i]; //학생인덱스별, 지목한 학생 값 입력 받음.
        }
        for(int i=1; i<=n; i++)
            run(i);
        cout<<n-cnt<<'\n'; //전체 수 - 사이클을 이룬 인원 수 =사이클을 이루지 못한 인원 수
    }
}