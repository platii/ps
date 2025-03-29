#include <iostream>
using namespace std;

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    string ans=n%2?"SK":"CY";
    //n이 홀수면 상근이, 짝수면 cy가 이김.
    //이전 코드에서 d배열을 출력해보면 위와같이 됨을 알 수있음.
    cout<<ans;
}
