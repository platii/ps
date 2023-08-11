#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s; //string으로 문자 받음(char형 배열의 형태)
    int a[26]={}; //지역변수는 쓰레기값으로 초기화되므로, 별도로 {}(0)으로 초기화
                  //전역변수는 자동으로 0으로 초기화됨.
    cin>>s;
    for(auto c:s) //c++ for each문 사용. 
        a[c-'a']++; // 'a'아스키코드 값 빼줌.
    for(int i=0; i<26; i++)
        cout<<a[i]<<' ';
}