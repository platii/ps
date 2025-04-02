//1)첫번째방식(출력될 수열이 중복출력되는 것인지 확인)(가장직관적으로 알아낼 수 있는 방식)
#include <iostream>
#include <algorithm> // next_permutation 사용
#include <vector>
using namespace std;
int n,m;
int pre[8];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    vector<int> a; //배열 대신 vector를 사용하는 이유? 크기를 정하지 않고도 사용가능.
    for(int i=1; i<=n; i++) a.push_back(i); //1~n까지 a애 채움.
    do{
        bool flag=false;
        for(int i=0; i<m; i++) if(pre[i]!=a[i]) flag=true; //m개까지의 출력값이 하나라도 다르다면 출력
        if(!flag) continue; //그렇지않으면 출력x
        for(int i=0; i<m; i++){
            cout<<a[i]<<' ';
            pre[i]=a[i]; //출력되는 값 저장
        }
        cout<<'\n';
    }while(next_permutation(a.begin(), a.end()));
}

/*
문제를 해결하는 두가지 방식이 존재함.
기본적으로 둘다 next_permutation으로 a배열 n개를 next_permutation 돌리고(n!), 앞의 m개만 출력하는 방식이나,
ex) 4 2 로 입력이 주어진 경우
1 2 3 4 (출력 : 1 2)
1 2 4 3 (출력 : 1 2)
과 같이 next_permutation 과정에서 중복이 발생함.

이 중복을 해결하기 위해
1) 이전에 출력한 값과 동일한 값은 출력X (pre배열에 출력될 값을 미리 저장하고 후에 출력대기중인 배열을 비교하여 continue 하는 방식)
->가장직관적인 방식
2) next_permutation으로 새로운 수열을 만든 후에 reverse하여 중복을 제거하는 방식
(next_permutation의 동작방식참고: https://yoongrammer.tistory.com/109)
(next_permutation은 주어진 수열을 사전 순서상 다음 순서인 수열로 만들어 놓는데,
예를들어, 1 2 3 4 5가 주어진다면(입력이 5 2로 주어진 경우)
1 2 3 4 5 <- 1 2 출력
1 2 3 5 4
1 2 4 3 5
1 2 4 5 3
1 2 5 3 4
1 2 5 4 3 <-만약, 1 2 3 4 5에서 1 2 출력 후, 3 4 5를 reverse 진행했다면 도달하는 위치.
1 3 2 4 5 <- 바로 1 3 2 4 5수열에 도달하고 1 3 을 출력함(효과적으로 중복제거)
.
.
1 3 5 4 2 <- 2 4 5를 reverse한 형태인 5 4 2가 1 3 ~~형식 수열의 제일 끝순서.
1 4 2 3 5
.
.
.
5 4 3 2 1
즉, 맨처음 오름차순으로 정렬된 수열의 맨 마지막은 주어진 수열을 reverse한 것임을 알 수 있다.
또한, next_permutation은 결국
_ _ _ _ _ 인 것을 next_permutation하면 각 1, 2, 3, 4, 5에대해
1(~5) _ _ _ _ 에서 _ _ _ _을 나머지 2,3,4,5에대해 next_permutation 진행하고
1 2 _ _ _ 에서 _ _ _ 나머지 3,4,5을진행하고
1 2 3 _ _ 에서 _ _ 4, 5을 진행한다.(4 5 -> 5 4)
즉, 이런식으로 어떠한 수열을 next_permutation 진행하게되면.
가장작은 단위의 수열(2개 짜리)부터부터 차례로 next_permutation을 진행하게되고
이때(작은 단위에서의 수열들)의 next_permutation 또한 맨처음 오름차순으로 정렬된 수열을 reverse하면 바로 맨마지막순서의
수열이 된다.
이를 이용하면, 예시에서 화살표로 설명된 것과 같이 바로바로 원하는수열을 출력할 수 있게된다.(중복제거)
)

*/

/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
>>next_pertmutation 정리 (https://rbals0445.tistory.com/96)

1) **n과m(3) 문제처럼 동일한 수를 다시 사용가능한 경우사용힘듦. next_permutation 과정과 거리가 멈.
2) 모든 수를 출력하는 경우 next_permutation 그냥 쓰면 편함.
-> 아닌 경우 본 코드처럼. n!후 m개 추출한 후에 reverse로 중복제거
3) *조합은 0과 1로 배열혹은 벡터 만들어서 풀기(0인경우 출력 1인 경우 출력 x)

4) 숫자가 오름차순으로 정렬되어있어야함. ? ->맨 처음 문제에서 의도한 대로 출력하려면 a배열에 1 2 3 4 5처럼 오름차순으로 되어있어야함.
next_permutation은 이와 관계없이 그냥 주어진 수열의 사전순서상 다음수열을 만들어냄.(정상 동작한다는 의미)

*/