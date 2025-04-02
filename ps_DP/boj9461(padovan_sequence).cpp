#include <iostream>
using namespace std;

typedef long long ll;

int n,t;
ll d[101]; //d[i]는 P(i)를 의미
//!!!!!!!int 오류, int하니 오버플로우 남, ll로 교체
//항상 끝값(이문제의 경우 100) 넣어보고 -로 오버플로우 나는 지 확인하는 습관을 가질 것. n의 범위가 1~100으로 적더라도

//P(N)는 문제의 파도반 수열을 N번 진행했을 때, 가장 긴 나선의 변의 길이를 의미

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    //초기값 대입
    d[0]=0LL; //d는 전역에서 선언된 배열이지만, 명시적으로 선언해줌.
    d[1]=1LL;
    d[2]=1LL;
    d[3]=1LL;
    d[4]=2LL;
    //테이블 채우기
    for(int i=5; i<=100; i++){
        d[i]=d[i-1]+d[i-5];
        //파도반 수열 그림을 확인해보면 i-1번째와 i-5번째 삼각형의 변의 길이를 합한것이 i번째 변의길이가 됨을 확인가능
    }
    while(t--){
        cin>>n;
        cout<<d[n]<<'\n';
    }
}

/*
정답 코드 체크
근데 
정답코드는 i-2 + i-3으로 했음..

결론은 i-2 + i-3, i-1 + i-4 둘다 가능함.
*/