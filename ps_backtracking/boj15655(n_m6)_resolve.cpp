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
        func(cur+1, i+1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>num[i];
    sort(num, num+n);
    func(0, 0); //입력으로 배열인 num을 받는지, 혹은 자연수만 받는지에 따라 st를 0,1어떤 것을 넣을지 체크해야함
}