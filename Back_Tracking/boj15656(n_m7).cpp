//리스트주어짐 n개중 m개 뽑아 순열만들기, 오름차순, 중복x
#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[10], num[10];

void func(int cur){
    if(cur == m ){
        for (int i=0; i<m; i++)
            cout<<arr[i]<<' ';
        cout<<'\n';
        return;
    }
    for(int i=0; i<n; i++){
        arr[cur]=num[i];       //실수 : arr[i]가아닌 arr[cur]이어야함.
        func(cur+1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++)
        cin>>num[i];
    sort(num,num+n);
    func(0);
}