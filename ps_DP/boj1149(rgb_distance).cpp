#include<iostream>
using namespace std;

int d[1001][3]; 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int r, g, b;
    for(int i=0; i<=2; i++) d[0][i]=0; //초기값 대입
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>r>>g>>b;
        for(int j=0; j<=2; j++){
            if(j==0) d[i][j]=min(d[i-1][1]+r, d[i-1][2]+r); //선택한 색이 red일 때
            else if (j==1) d[i][j]=min(d[i-1][0]+g, d[i-1][2]+g); //green
            else d[i][j]=min(d[i-1][0]+b, d[i-1][1]+b); //blue
        }
    }
    cout<<min(d[n][0], min(d[n][1], d[n][2]));
}


/*
1. 테이블 정의하기
d[i][j] = i거리에서, j색을 택했을 때 비용의 최소값

2. 점화식 찾기
d[i][j]=min(d[i-1][not j_1]+ith_j_color_cost, d[i-1][not j_2]+ith_j_color_cost)

3. 초기값 대입 (color : r=0, g=1, b=2)
d[0][0]=0, d[0][1]=0, d[0][2]=0;

(값은 N이 주어졌을 때 그때그때 계산을 하는 것보다 
미리 다 구해놓은 후에
그 값을 반환하는게 효율적.)
*/

/*
ㅁ 정답코드와의 비교

문제 풀이 방식은 거의 동일하였음.(r, g, b로 나누어 2차원 배열 사용함)

알게된 점. -> 최소값을 찾는데 두가지 방식을 제공함.
  cout << *min_element(d[n], d[n]+3);
  // cout << min({d[n][0], d[n][1], d[n][2]}); 도 가능

1) min_element(); : 괄호안의 주소 범위에서 최소값인 것의 주소(정확히는 반복자를)를 반환(그래서 *로 주소내의 값을 받은 뒤에 반환한것.)
    =>min_element(first, last) 함수는 [first, last)범위에서 비교
     주의!!!!!!!!!!! (last인자의 앞 인자까지만 범위로 받음. )
2) min함수의 인자로 중괄호의 형태로 주면, 3개 이상도 min 비교 가능.
    (부가설명)
    기본적인 std::min은 두 개의 값만 비교함.
    하지만 std::initializer_list를 사용하는 std::min은 여러 개의 값을 {}를 사용해 비교할 수 있음.
    C++11 이상에서 가능하며, 편리한 다중 값 비교 방식.

*/

/* 
시간복잡도 : o(n)
- n개의 칸, 0,1,2 3개의색 
-> for문 3n번 돌림.

공간복잡도 : o(n)
-> d[1001][3] //cost 저장 배열, o(n)..

*/

/*문제풀이 rule
1) 문제풀기
2) 내가 푼 풀이와 정답풀이와 비교
3) 정답풀이가 더 나은 부분 체크하고 file에 주석으로 적기
4) 시간복잡도, 공간복잡도 분석
+시간이 남으면) 혹시나 더 나은 다른풀이 없나 고민해보기

[만약 문제가 안풀리면]
- 대략 1시간 이내까지 고민해보기.
- 안되면 그냥 정답코드 보기(애드혹일 확률이 높음.)
- 정답코드 보고 이해한 뒤에, 다시 재구성해서 문제 풀기
- 정답코드에서 사용된 발상을 적어두고 외우기.

*/