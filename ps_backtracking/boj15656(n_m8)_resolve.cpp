//백트래킹 익숙해지고 다시 푼 코드, //8부터는 정답코드도 이런 방식으로 풀기 시작함(st를 다음 함수의 인자로 전달하는 방식)
#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[8], num[8];

void func(int cur, int st){
    if(cur==m){
        for(int i=0; i<m; i++) cout<<arr[i]<<' ';
        cout<<'\n';
        return;
    }
    for(int i=st; i<n; i++){
        arr[cur]=num[i];
        func(cur+1, i);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>num[i];
    sort(num, num+n);
    func(0, 0);
}