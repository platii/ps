#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b,c;
    cin>>a>>b>>c;
    int mod=a*b*c;
    int d[10]={};   //의문. c++은 다른 처리가 없다면(ex, d[10])배열을 모두 0으로 초기화하는 것으로 알고있는데, 
    //왜 ={}초기화 했을때와, 그냥 기본으로 뒀을때의 결과가 다른가? 
    while(mod>0){
        d[mod%10]++;
        mod/=10;
    }
    for(int i=0;i<10; i++)
        cout<<d[i]<<'\n';
    return 0;
}