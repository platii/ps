#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num=0;
    int d[10]={};
    cin>>num;
    while(num>0){ //수 추출
        d[num%10]++;
        num/=10;
    }
    int maximum=0;
    for(int i=0; i<10; i++){
        if(i==6 || i==9) continue;
        maximum=max(maximum, d[i]);
    }
    maximum=max(maximum, (d[6]+d[9]+1)/2); //x/y의 올림공식, (x+y-1)/y
    cout<<maximum;
}