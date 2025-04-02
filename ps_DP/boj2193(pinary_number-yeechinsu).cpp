#include <iostream>
using namespace std;

typedef long long ll; //long long을 편하게 쓰기위해 typedef함

ll d[91]; //int의 범위인 약 21~22억정도를 넘어서므로 8byte정수형(2의 63승까지 표현가능) long long사용

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    d[1]=1;
    d[2]=1;
    //이경우 기본으로 int인 1이 자동으로 d[]배열 인자의 자료형인 long long으로 형변환되어 문제없지만
    //그렇지 않은경우, 1LL처럼 표시해줘야함.
    //ex1) d[1]=1LL;
    //ex2) long long x = 10000000000LL; // long long 타입으로 10억을 저장
    for(int i=3; i<=n; i++){
        d[i]=d[i-1]+d[i-2];
    }
    cout<<d[n];
}

/* 문제풀이

1. 테이블 정의
d[i]=i자리수 이친수의 개수

2. 점화식 찾기
d[i]=d[i-1]+d[i-2];

###
=> 왜 이렇게 되는가?
(5자리 이친수 개수 구하기로 예를들면)
맨 끝자리의 수가 0이면 
~ ~ ~ ~ 0 앞의 i-1자리수의 이친수의 개수를 구하는 것과 동일하다.

맨 끝자리의 수가 1이면 앞엔 무조건 0이 와야하므로
~ ~ ~ 0 1 (01)의 앞에 i-2자리수의 이친수의 개수를 구하는 것과 동일하다.

따라서, d[i]는 맨 뒷자리에 0인경우와 1인경우의 두가지경우의수를 합한
d[i]=d[i-1]+d[i-2];이 되는것임.
###

3. 초기값 대입
d[1]=1;
d[2]=1;
*/

/* 정답코드 풀이

 - 정답코드에서는 2차원 배열을 사용하여 맨 끝자리수가 0일때와 1일때로 나누어서 풀었음.
   
   #include <bits/stdc++.h>
    using namespace std;

    typedef long long ll;

    int n;
    ll d[100][2];

    int main(void){
        ios::sync_with_stdio(0);
        cin.tie(0);
        
        cin >> n;
        d[1][1] = 1LL;
        for(int i = 2; i <= n; ++i){
        d[i][0] = d[i-1][0] + d[i-1][1];
        d[i][1] = d[i-1][0];
        }
        cout << d[n][0] + d[n][1];
    }

    - 맨끝이 0일때 = 맨끝이 0인 i-1자리 이친수를 구하는 방법 + // 1인 //
      맨끝이 1일때 = 맨끝이 0인 // (맨끝자리가 1이라 바로 앞에 1이 올수 없으니)
      로 나누어 풀었음.

    - 그래서 d[n][0]+d[n][1] //맨끝이 0인+맨끝이 1인 n자리 이친수의 개수로 합쳐 풀었음.

    이 방법이 좀 더 직관적이기는 한데,
    문제를 제대로 이해해보면 굳이 이렇게 풀 필요는 없음.
    직접푼 코드 처럼 푸는게 더효율적. 

    //아래 정정 체크.
    그러나, 문제의 해법이 떠오르지 않을 때 직관적으로 이렇게 풀 수 있음을 기억하기.
    (기억 => 이차원배열 사용, 맨끝이 0인 이친수, 맨끝이 1인 이친수로 나눠 풀 수 있다.)

    [!!정정, 앞이 0일 때 1일때 로 나눠푸는건 트리형태, 백트래킹 형태가 맞음.
            뒤가 0일때 1일때로 나눠 푸는 방법이 정답코드처럼 가능함.
            그래서 사실 뒤가 0일때 1일때로 나눠푸는것 까지 이해했으면,
            그냥 직접푼코드처럼 푸는게 훨씬 효율적임. 
                                      -정정//사실 앞이 0일때 1일때로 나눠 푸는 방법은 트리형태, 즉 백트래킹 형태가 된다고 생각하여
                                      -정정//불가능하다고 생각했으나
    2차원배열을 채우는 방법으로하면, 단지 동일한 n개크기 배열을 한개 더 채우는거 뿐이므로
    시간복잡도는 거진 비슷함. (총 반복은 동일하게 n번이므로, 똑같이 o(n)임)
    이방법이 가능함을 기억하기
    ]



//문제에서의 point1
//!!!!!!!!!!!!!!!!!!!!!!!!!!
//int 자료형 오버플로우 오류
/*
ㅁ1  n이 49를 넘기면 int의 범위 (약 20억)를 넘어가서 오버플로우가 발생함.
     다른 자료형을 써줘야함.
     이경우 long long 정수형을 써주도록 하자.
     (long long = ll로 표현가능)
     (8byte 정수형으로, 2의 63승 = 9,223,372,036,854,775,808까지 표현 가능 (약 922경=9.22*10^18승))->19자리수.

ㅁ2  typedef long long ll; //long long을 편하게 쓰기위해 typedef함

ㅁ3  d[1]=1;
     d[2]=1;   
     본문 코드의 경우 기본으로 int인 1이 자동으로 d[]배열 인자의 자료형인 long long으로 형변환되어 문제없지만
     //그렇지 않은경우, 1LL처럼 표시해줘야함.(혹은 명시적으로 LL임을 나타내기 위해서 쓰는 경우도 있음.)
     //ex1) d[1]=1LL;
     //ex2) long long x = 10000000000LL; // long long 타입으로 10억을 저장

*/


//point 2
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!
혹시 이 문제를 dp가 아닌, 백트래킹 or dfs로 풀 수 있을까?

- 우선 dfs는 미로찾기처럼, 맵이 주어져있어야 큐에 원할하게 넣을 수 있다.
  만약, 앞자리수가 0일때와 1일때로 나눠 dfs를 하더라도 이는 백트래킹과 큰 차이가 없을 것이다.
  이 경우, 올바르지 않은 경로에 도달하면 자동으로 취소하고 다음 경로를 진행하는 백트래킹이 효율적일 것이다.
  (문제를 많이 풀어보지 않아서 확답할 순 없지만, dfs/bfs 문제의 경우 맵이 주어진 경우 효율적
  bfs의 경우 "1로만들기" 문제처럼 '거리'를 구하는 문제에서 효율적.
  )

- 그럼 백트래킹은 어떨까?
  백트래킹의 경로는 m-way 트리로 나타낼 수 있다.
  따라서 시간복잡도는 o(m^n)이 되고, 해당 문제의 경우 0과1로 m이 2개이므로
  o(2^n)
  2의 n승인경우 n이 10이면 1024번 반복,
  2의 20승은 100만번
  2의 "24"승 부터 1000만번을 넘어간다.(약 1600만번) 즉
  !!!!!!!!!!백트래킹의 경우 n이 24가 될때부터 1초안에 실행하기 힘들다는 소리. !!!!!!!!!!!!!!!!
  (더 예상해보면 25를 넘기는순간부터 1씩 증가할 때마다 알고리즘을 위해 2초, 4초~씩 필요하게 될것임.)
  즉 문제에서 n의 범위가 20 아래인경우 백트래킹으로 풀만하지만

  넉넉히 n이 30을 넘기면 백트래킹으로 풀 수 있는 문제가 아니다.(상당한 시간이 소요되므로)
  즉 이 문제는 n의범위가 0~90이므로 백트래킹으로 풀 수없음.

  따라서 이문제는 dfs,백트래킹,dp 중
  dp를 쓰는 것이 효율적인 문제임.

  문제를 풀 때 어떤 알고리즘을 써야하는지 알기어려움.
  1)따라서 일단 n의 범위를 보고 30 이상이면 ->백트래킹 불가.(보통 백트래킹문제는 입력 범위가 0~10정도.)
  2)맵이 있는 문제는 dfs,bfs가 편리
  3)그러나 이런식으로 범위가 정해지지 않은 문제는 
    dfs나 백트래킹이나 모두 트리형태로 범위가 주어짐.
    -> 이럴 땐 그냥 dp
    (트리형태는 시간복잡도가 높고, 이런식의 문제에선 백트래킹 원치않은 경로는 더이상 가지 않고 다른 경로에 대해 진행하므로
    dfs가 효율적임. 근데 n이 30을 넘기므로 둘다 쓸 수 없는 문제임)

*/