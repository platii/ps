#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, sum=0;
    string str;
    cin>>t;
    cin>>str;
    for(int i=0; i<t; i++){
        sum+=str[i]-'0'; //char로 저장되어 있기 때문에, '0'을 빼서 int형으로 바꾸어줌
    }
    cout<<sum;
}
