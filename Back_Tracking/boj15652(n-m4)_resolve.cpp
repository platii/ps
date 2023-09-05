//백트래킹 익숙해지고 다시 푼 방식
#include <iostream>
using namespace std;

int n,m;
int arr[8];

void func(int cur, int st){
    if(cur==m){
        for(int i=0; i<m; i++) cout<<arr[i]<<' ';
        cout<<'\n';
        return;
    }
    for(int i=st; i<=n; i++){
        arr[cur]=i;
        func(cur+1, i);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    func(0, 1);
}