#include <iostream>
using namespace std;

int n;
int d[1000001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int nAbs;
    bool isNegative=false;
    if(n<0) {
        nAbs=-n;          //[지식+1], (-1)*n으로 안하고 그냥 -n 이라고 해도 된다.
        isNegative=true;
    }
    else nAbs=n;
    d[0]=0;
    d[1]=1;
    for(int i=2; i<=nAbs; i++){
        d[i]=(d[i-1]+d[i-2])%1000000000;
    }
    if(isNegative && nAbs%2==0) {
        cout<<-1<<'\n'<<d[nAbs];
    }
    else if (nAbs==0) cout<<0<<'\n'<<d[nAbs];
    else cout<<1<<'\n'<<d[nAbs];
}


/*
f(-1)=1
f(-2)=-1
f(-3)=2
f(-4)=-3
f(-5)=5

f(1)=1
f(2)=1
f(3)=2
f(4)=3
f(5)=5

....

양수일때 피보나치수는 그대로고

음수이더라도 피보나치수는
절대값 취하면 서로 동일함.

좀 더 자세히 살펴보면, 확장된 피보나치수는 아래와 같은 규칙을 가짐.
[ n>=0 일때,
n이 짝수면, f(-n) = =f(n)
n이 홀수면, f(-n) = f(n)
]
따라서, 절대값을 취하는 문제의 특성상.
|f(-n)|=f(n)과 동일함.

이를 이용해서 짠 코드가 위의 코드임.

*/

/* [정답코드의 방식]

->n이 음수일 때의 점화식, 양수일 때의 점화식으로 경우를 따로 분리 해주었음.
[n이 음수일떄 d[i] = (d[i-2] - d[i-1])과 같은 점화식을 가짐을 발견하고 그를 적용한 것. ]

  cin >> n;
  d[0] = 0; d[1] = 1;
  if(n >= 0){
    for(int i = 2; i <= n; ++i)
      d[i] = (d[i-1] + d[i-2]) % mod;
  }
  else{
    n = abs(n);
    for(int i = 2; i <= n; ++i)
      d[i] = (d[i-2] - d[i-1]) % mod;
  }
  if(d[n] > 0) cout << "1\n";
  else if(d[n] < 0) cout << "-1\n";
  else cout << "0\n";
  cout << abs(d[n]);

*/