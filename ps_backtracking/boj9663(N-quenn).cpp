#include <iostream>

using namespace std;

int n, cnt;
bool isused1[20], isused2[30], isused3[30];

//>>전에는 기억했는데 다시 보니 까먹어서 적은 내용.
//매 반복에서 cur 값이 하나로 정해지므로 가로축 중복은 생기지 않음. 
//isused1 : 세로축 중복 체크
//isused2 : 우상단 좌하단으로의 대각선 중복 체크 (x+y값[i+cur값]이 같으면 같은 대각선에 있음.)[cur이 각 행, i가 각 열을의미]
//isused3 : 좌상단 우하단으로의 대각선 중복 체크 (x-y값이 같으면 같은 대각선에 있음.) 단 n-1을 더해 out of index 방지

void func(int cur){
    if(cur==n){
        cnt++;
        return;
    }
    for(int i=0; i<n; i++){
        if(!isused1[i] && !isused2[i+cur] && !isused3[i-cur+n-1]){
            isused1[i]=true;
            isused2[i+cur]=true;
            isused3[i-cur+n-1]=true;   //n-1을 더하는이유 : out of inex 방지 위함. 번외로, 배열 크기는 최소 2N-1개 필요(최상측, 최우측의 개수(중복 제외))
            func(cur+1);
            isused1[i]=false;
            isused2[i+cur]=false;
            isused3[i-cur+n-1]=false;
        }
        
        
    }


}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    func(0);
    cout<<cnt;
}