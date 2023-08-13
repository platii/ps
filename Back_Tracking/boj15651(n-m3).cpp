//중복가능 -> isused검사를 뺌.
#include <iostream>   //cout, cin(입출력)
using namespace std;  // std-> cout, cin 등
int n, m;
int arr[10];

void func(int cur){
    if(cur==m){
        for(int i=0; i<m; i++)
            cout<<arr[i]<<' ';
        cout<<'\n';
        return; //return 까먹지 말기.
    }
    for(int i=1; i<=n; i++){
        arr[cur]=i;
        func(cur+1);
        }
    }   

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0);
}