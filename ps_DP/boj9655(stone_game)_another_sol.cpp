#include <iostream>
using namespace std;

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    //n이 홀수면 상근이, 짝수면 cy가 이김.
    //이전 코드에서 d배열을 출력해보면 위와같이 됨을 알 수있음.
    cout<<(n%2?"SK":"CY");

}

 /* [더 정확한 설명 : 정답코드 인용]
  홀수 + 홀수 = 짝수, 짝수 + 홀수 = 홀수이므로 가져간 돌의 총 합이 n이 됐을 때 게임을 이긴다고 하면
  돌을 몇 개를 가져가든 n이 홀수일 때는 상근이, 짝수일 때는 창영이가 무조건 이김을 알 수 있다.
*/
