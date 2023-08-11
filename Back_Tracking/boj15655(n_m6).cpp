//n개 중 m개 뽑아 순열 만들기, 오름차순, 중복 x
#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[10], num[10];
int pre;

void func(int cur){
    if(cur==m){
        for(int i=0; i<m; i++)
            cout<<arr[i]<<' ';
        cout<<'\n';
        return;
    }
    for(int i=0; i<n; i++){
        if(pre>=num[i]) continue; //>=가 아닌, >으로하였더니 오류(중복은, 체크 못했으므로) 고침.
        arr[cur]=num[i];
        pre=num[i];
        func(cur+1);
        pre=0;        
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n ;i++)
        cin>>num[i];
    sort(num, num+n);
    func(0);
}