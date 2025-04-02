#include<iostream>
using namespace std;

int n;
int d[1000001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    d[1]=1;
    d[2]=2;
    for(int i=3; i<=n; i++){
        d[i]=(d[i-1]+d[i-2])%15746;
    }
    cout<<d[n];
}

//그냥 2*n문제 접근법이랑 동일함. [맨앞이 1일때 나머지 d[i-1], 맨앞이 00일때 나머지는 d[i-2], 즉 두가지 경우의 수를 더하면 됨.]