#include <iostream>
using namespace std;

int n,x,num;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>x;
    for (int i=0; i<n; i++){
        cin>>num;
        if(num<x) cout<<num<<' ';
    }
    return 0;
}