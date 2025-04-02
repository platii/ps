#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long a,b;
    cin>>a>>b;
    if(a>b) swap(a,b); // swap함수 사용하면 편하게 가능, b가 더 큰수 여야함
    if(a==b) cout<<"0"<<'\n';
    else cout<<b-a-1<<'\n';
    for(long long i=a+1; i<b; i++) cout<<i<<' '; //int형 정수는 -2^15~2^15 까지밖에 표현 불가.
}   //long long은 8바이트, -2^63~2&63까지 표현 가능