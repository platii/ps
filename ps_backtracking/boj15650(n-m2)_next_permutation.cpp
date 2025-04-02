#include <iostream>
#include <algorithm> // next_permutation 사용
#include <vector>
using namespace std;
int n,m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    vector<int> a; //배열 대신 vector를 사용하는 이유? 크기를 정하지 않고도 사용가능.
    for(int i=0; i<n; i++) a.push_back(i<m?0:1); //m개 만큼 0채움, 나머지는 1로 채움. 조합을 활용한 방식
    do{
        for(int i=0; i<n; i++){
            if(a[i]==0) cout<<i+1<<' ';
        }
        cout<<'\n';
    }while(next_permutation(a.begin(), a.end()));
}

//next_permutation(배열 처음지점, 배열 나중지점) -> algorithm헤더에 존재
//주어진 배열을 사전순서상 다음 순서의 배열로 만들어 둠. 이후 true를 반환, 더이상 사전순서상 다음 수열을 만들 수 없으면 false를 반환
//함수의 성질 상 do~while문을 활용하는 것이 좋음.

//-> 본코드에서의 방식은 조합을 활용한 방식. (0 0 1 1 1)
/*
next_permutation진행 순서.
(1 2 3 4 5)
0 0 1 1 1 (1 2)
0 1 0 1 1 (1 3)
0 1 1 0 1 (1 4)
0 1 1 1 0 (1 5)
1 0 0 1 1
1 0 1 0 1
1 0 1 1 0
1 1 0 0 1
1 1 0 1 0
1 1 1 0 0

다만, 이러한 방식 특성상(조합이므로)
동일한 순열이 여러개 나오는 경우 (1 2 , 2 1 처럼.)
에는 사용불가 이경우 n과m 1의 방식을 사용해야함.
*/