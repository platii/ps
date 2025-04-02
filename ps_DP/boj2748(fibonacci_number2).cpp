#include <iostream>
using namespace std;

typedef long long ll;

int n;
ll d[91];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    d[0]=0LL;
    d[1]=1LL;
    for(int i=2; i<=n; i++){
        d[i]=d[i-1]+d[i-2];
    }
    cout<<d[n];
}

//피보나치수 1문제도 동일한 코드로 해결가능