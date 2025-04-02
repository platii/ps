#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=0; j<n-i; j++) cout<<" ";
        for(int j=0; j<i; j++) cout<<"*";
    cout<<'\n';
    }
}

/*
    이렇게 j를 이어받아서 출력도 가능.
    int j=0;
    for(; j<n-i; j++) cout<<" ";
    for(; j<n; j++) cout<<"*";
*/