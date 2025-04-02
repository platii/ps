//중복가능, 비내림차순(오름차순+인접한 수 서로 동일해도됨)
#include <iostream>
using namespace std;

int n,m;
int arr[10];


void func(int cur){
    if(cur==m){
        for(int i=0; i<m; i++)
            cout<<arr[i]<<' ';
        cout<<'\n';
    for(int i=1; i<=n; i++){
        arr[cur]=i;
        func(cur+1);
    }

    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    func(0);
}