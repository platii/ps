#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n=5, sum=0;
    while(n--){
        int a;
        cin>>a;
        sum+=a*a;
    }
    cout<<sum%10;
}