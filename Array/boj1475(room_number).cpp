#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num=0;
    int d[10]={};
    cin>>num;
    while(num>0){
        if(num%10==9)
            d[6]++;
        else
            d[num%10]++;
        num/=10;
    }
    d[6]=(d[6]+2-1)/2; //2나누고 올림. //올림하는거 기억.x/y올림은 => x+y-1/y
    int maximum=0;
    for(int i=0; i<10; i++){
        maximum=max(maximum, d[i]);
    }
    cout<<maximum;
}