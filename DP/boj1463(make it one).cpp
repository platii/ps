#include <iostream>
using namespace std;

int n;
int d[1000001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    d[1]=0; 
    //dist는 전역으로 선언되었으므로 굳이 또 0을 선언할 필요는 없으나, dp의 형식을 연습하기 위해 작성
    for(int i=2; i<=n; i++){
        d[i]=d[i-1]+1;
        if(i%3==0) d[i]=min(d[i], d[i/3]+1);
        if(i%2==0) d[i]=min(d[i], d[i/2]+1);
    }
    cout<<d[n];
}


/*
dp의 풀이 방식

(1)테이블 정의
(2)점화식 찾기
(3)초기값 대입

직접 풀었던 방식
->
    for(int i=2; i<=n; i++){
        int a,b=1000002;
        a=b;
        if(i%3==0) a=dist[i/3]+1;
        if(i%2==0) b=dist[i/2]+1;
        int c=dist[i-1]+1; //1빼는 것은 언제나 가능, n이 1보다 크거나 같은 수이므로.
        dist[i]=min(min(a, b), c); //min 함수 한번에 3개 비교하는 것 불가능

-> 방향이나 발상의차이는 없으나
구현면에서 정답코드 방식이 더 간단하여 수정하였음. 정답코드의 방식을 익히도록 하기

*/