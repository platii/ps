#include <iostream>
using namespace std;

int d[1001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    d[1]=1;
    d[2]=3;
    for(int i=3; i<=n; i++){
        d[i]=(d[i-1]+2*d[i-2])%10007;
    }
    cout<<d[n];
}


/*
1. 테이블 정의
d[i]=2*i 직사각형을 1*2,2*1,2*2 블럭으로 채우는 방법의 수

2. 점화식 찾기
d[i]=d[i-1]+2*d[i-2];

첫블럭이 2*1일때 -> 나머지는 d[i-1]
첫블럭이 1*2일때, 2*2일때 ->나머지는 d[i-2]
=>경우의수 두개니까 d[i-2]*2

->바킹독, 2xn타일링 1 문제 풀이 와 동일한 방식

3. 초기값 대입
d[1]=1;
d[2]=3;

*/