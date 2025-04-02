#include <iostream>
using namespace std;

int n;
bool d[1001]; //d[i]=돌이 i개있을 때 돌게임을 무조건 이길 수 있는 사람. 0=sk, 1=cy 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    d[1]=0;
    d[2]=1;
    d[3]=0;
    d[4]=1;
    for(int i=5; i<=n; i++){
        d[i]=d[i-4];
    }
    cout<<(d[n]?"CY":"SK");
    /* 아래 코드 두줄에서 위 코드로 개선.
    !!!!!!기억하기!!!!!
    원래 소괄호 안치면, 제대로 반영안되는데, 소괄호치면 반영됨. !
    string ans=d[n]?"CY":"SK";
    cout<<ans;
    */
}

/*
잘 생각해보면
돌게임 돌 개수가 n개면
n-4번째 돌을 먼저 차지하는 사람이 이기는게임.
ex) n=10
6을 선점하면,
상대는 7or9밖에 안됨.
어느 경우의수든 6을 선점한사람이 다음 순서에 10을 먹을 수있음.

마치 써리원(31)게임과 메커니즘 거의 동일.
*/