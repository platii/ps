#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num, mx=0, mx_pos;
    for(int i=1; i<=9; i++){
        cin>>num;
        if(num>mx){
            mx=num;
            mx_pos=i;
        }
    }
    cout<<mx<<'\n'<<mx_pos;
}

//max_element : 배열의 원소중 최대값이 있는 곳의 주소 반환. 를 사용할 수도 있음.
/*

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a[9]={};
    for(int i=0; i<9; i++) cin>>a[i];
    cout<<*max_element(a, a+9)<<'\n';
    cout<<max_element(a, a+9) - a + 1;  
}

*/