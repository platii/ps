//연습문제 3.(1차원 배열 문제풀이)
#include <iostream>
using namespace std;

int s[301]; // stair 보관.
int d[301];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,sm=0;
    cin>>n;
    for(int i=1; i<=n; i++) {
        cin>>s[i];
        sm+=s[i]; //계단의 값의 총 합
    }
    if(n==1){ //d[-1]에 접근하는 것이 불가하므로 n==1일때 s[1]출력하고 종료하도록 함.
        cout<<s[1]; 
        return 0;
    }
    /*정답코드 
    if(n<=2){
        cout<<sm;
        return 0;
    }
    (직접 코드를 풀 때에는, n==1일때는 s[1]출력, n==2일때는 s[1]+s[2]출력 따로 해야한다고 생각했는데, 잘생각해보니
    정답코드 처럼 작성하면 되었음.)
    */
    d[0]=0; //코드의 편의성 위해 d[0](시작점)=0 으로 설정, //정답코드에선 d[3]를 정의하는 방식을 사용.
    d[1]=s[1]; // 초기값 대입
    d[2]=s[2];
    //정답코드 d[3]=s[3]; (d[0]=0; 대신 추가함)
    for(int i=3; i<=n; i++){ //정답코드 : (3까지정의했으니) i=4부터 시작하게함, (체크할만 한 것)!!!!범위는 n-1까지만 하면됨!!!.
        d[i]=min(d[i-2], d[i-3])+s[i]; //d[3]일 때는 자연히, s[1], s[2]를 밟고 s[3]를 밟지 않는 것이 선택됨.
    }
    cout<<sm-min(d[n-1], d[n-2]);
}

/* n이 충분히 작다면 2^n의 시간복잡도로 백트래킹으로 풀 수있음.
하지만 지금처럼 n이 300으로 주어진 경우 불가능.

교안.확인하여 테이블 구성 확인함.
1. 테이블 구성
d[i]=i번째 계단에 도달하는데, 밟지 않은 계단의 합의 최소값, 단, i번째 계단은항상 밟지 않는 계단 이어야함.

2. 점화식 설정.
d[i]=min(d[i-2]+s[i], d[i-3]+s[i])

3. 초기값 대입.
d[1]=s[1]
d[2]=s[2]
d[3]=s[3]
or
d[3]=s[3] 대신, d[0]=0; 작성. 이 경우 for문은 3부터 시작(직접푼 코드)
*/

/* 정답코드정리

정답코드는 초기값을 0,1,2 // for문을 3부터 시작 이아닌
초기값을 1,2,3 // for문을 4부터 시작 하였음. 
->*대신 예외를 n<=2일 경우 cout<<tot;(sm대신 tot사용하자.)return 0; 하였음
(합을 나타내는 변수를 쓸 때는 tot를 쓰자-> sum은 에약어, sm보다는 tot가 더 나은듯함)

*for문 범위는 i=~부터 n-1까지만 두면됨, d[n]은 답을 내는데 필요하지 않음.

*점화식[min(d[i-2]+s[i], d[i-3]+s[i])]로 두는 것 보다 min(d[i-2], d[i-3])+s[i]로 두는 것이 편함

*/

/* 정답코드
// http://boj.kr/e93e56bb850a46378cf8f53486233cdc
#include <bits/stdc++.h>
using namespace std;

int s[305];
int n;
int d[305];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int tot = 0;
  for(int i = 1; i <= n; i++){
    cin >> s[i];
    tot += s[i];
  }
  if(n <= 2){
    cout << tot;
    return 0;
  }
  d[1] = s[1];
  d[2] = s[2];
  d[3] = s[3];
  for(int i = 4; i <= n-1; i++) d[i] = min(d[i-2],d[i-3])+s[i];
  cout << tot - min(d[n-1],d[n-2]);
}
*/