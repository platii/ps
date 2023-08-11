#include <iostream>
#include <algorithm> //min함수 사용
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a=7, sum=0, minimum=100;
    bool flag =true;
    while(a--){
        int num;
        cin>>num;
        if(num%2){ //(num%2==1)로 안해도됨.
            sum+=num;
            minimum=min(num,minimum);
            flag=false;
        }
    }
    if(flag) cout<<"-1";
    else cout<<sum<<'\n'<<minimum;
}