//1로만들기1 과 다르게 1로만들기2는 1이 되기까지의 경로도 묻고있음.
#include <iostream>
#include <algorithm>
using namespace std;

int d[1000001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    d[1]=0;
    for(int i=2; i<=n; i++){
        //d[i]=min({d[i/3], d[i/2], d[i-1]})+1; <- 이렇게하면안됨. i/3 에서 i가 4이면, i/3은 1이됨.(나눠 떨어질때만 대입해야됨.)
        d[i]=d[i-1]+1;
        if(i%2==0) d[i]=min(d[i],d[i/2]+1);
        if(i%3==0) d[i]=min(d[i],d[i/3]+1);
        /*오랜만에 풀다보니
        if(i%2==0) d[i]=min(d[i-1],d[i/2])+1;
        if(i%3==0) d[i]=min(d[i-1],d[i/3])+1;
        이런식으로 풀려고 했었음. 근데, 하다가 뭔가 이거보다 더 간단했던 것도 같고, 답도 틀려서 보니,
        위와 같은 코드이면 됐음. d[i]에 값을 대입해서, 차례로 비교.
        주석 코드처럼 하면 매번3개 를 다비교해야 하거나 틀림.
        */
    }
    cout<<d[n]<<'\n';

    //경로계산
    int pos=n; //pos는 현재 위치
    while(pos!=0){ //pos는 1이되면 이후 pos는 0
        cout<<pos<<' ';
        int origin=pos; //원래위치
        //다음위치(pos)설정
        pos-=1;
        if(origin%2==0) pos=d[pos]<d[origin/2]?pos:origin/2;
        if(origin%3==0) pos=d[pos]<d[origin/3]?pos:origin/3;
    }
}

/* 알게된 점.
1) min함수에 인자 여러개_초기화리스트

        d[i]=min({d[i/3], d[i/2], d[i-1]})+1;
        //min함수 : 원래는 인자 2개가 한계 but 초기화 리스트를 통해 전달하면 인자 개수 제한없이 가능.
        //ㄴ 이를 위해서는 <algorithm>헤더를 include해야함.
        //  ㄴ원래는 <initializer_list>와 다른것들도 추가해야하지만 <algorithm>에 다 들어있음.

*/

//시간제한 0.5초, 공간제한 512mb
/*
- 시간복잡도 고려
1초당 대략 1억번 연산가능.
o(n)은 2n, 3n~~을 의미하기도하고(그냥 n이 아니라는 것)
기타 측정불가능한 계산들도 있으므로
1초당 허용 연산횟수 대략 1000만~3000만 으로 잡으면됨.
0.5초면 500만~1500만.
https://velog.io/@jiyaho/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EC%8B%9C%EA%B0%84-%EC%A0%9C%ED%95%9C%EA%B3%BC-%EC%8B%9C%EA%B0%84-%EB%B3%B5%EC%9E%A1%EB%8F%84

1)테이블 채우는 연산 o(n)
2)경로 찾는 연산 o(d[n])) 
(1)+(2) 해도 기껏해야 o(n) n의범위 1~1백만이므로 천만을 넘지않음

- 공간복잡도 고려
int형 변수 100만개, 
int 하나 4바이트, 100개->4백만 바이트
대략 백만 바이트당 1메가바이트. ->4백만바이트=4mb
512메가면 널널함. 

*/