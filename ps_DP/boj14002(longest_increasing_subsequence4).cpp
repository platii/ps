//가장 긴 증가하는 부분수열1과 차이점은
//가장 긴 증가하는 부분수열1은 수열의 길이,
//4는 해당하는 수열을 출력하게끔 했음.(즉 경로를 저장해야함.)
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[1001], d[1001]; //d[i]=i번째 위치에서 가장 긴 증가하는 부분 수열
int pre[1001]; //경로 저장
int ans[1001]; //정답 경로 저장용 배열

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cin>>n;
   //입력 받기
   for(int i=0; i<n; i++) cin>>a[i];
   //d배열 모든 칸 1로 초기화 (모든 각 숫자는 최소 1의 길이를 가지므로)
   fill(d, d+n, 1);
   fill(pre, pre+n, -1); //0번 인덱스와 구분하기 위해, -1로 초기화
   //점화식, d/pre배열 채우기
   for(int i=0; i<n; i++){
      for(int j=0; j<i; j++){
         if(a[j]<a[i] && d[i] < d[j]+1) {
            d[i]=d[j]+1;
            pre[i]=j; //i의 이전 인덱스 저장(경로 저장)
         }
      }
   }

   //길이가 max인 index 찾기
   int mx=0;
   for(int i=1; i<n; i++){
      mx=d[mx]>d[i]?mx:i;
   }

   //테스트
   cout<<mx<<'\n';

   //정답출력 부분
   int max_l=d[mx];
   cout<<max_l<<'\n'; //최대 길이 출력
   //경로 출력 부분
   int k=mx; 
   //경로를 배열에 따로 저장(경로의 인덱스를 작은 수 부터 오름차순으로 정렬되도록 하기 위함.)
   while(k!=-1){
      for(int i=max_l; i>=1; i--){
         ans[i]=a[k];
         k=pre[k];
      }
   }
   for(int i=1; i<=max_l; i++) cout<<ans[i]<<" ";
}

/* 풀이

- 우선, 기존 가장 긴 증가수열 1 방식을 그대로 사용하여 가장 긴 증가수열의 길이를 구했음.

- 이후, pre배열을 사용하여 경로를 저장함. 이때, 저장 기준은 if(a[j]<a[i] && d[i] < d[j]+1) 로 하였음.
   [d[j]+1이 더 클 때 d[i]를 그걸로 업데이트하고, i이전의 숫자를 j로 즉, 경로를 저장해줌. pre[i]=j;
- 이후, 길이가 최대인 지점의 인덱스를 mx로 지정하고,
   우선 가장큰 증가수열의 길이를 먼저 출력,
- 이후, mx인덱스부터 경로를 재배열하기 위해 ans배열을 사용하여 다시, 가장 긴 증가하는 부분 수열의 첫 인덱스부터
  오름차순으로 정렬되도록 재배열함.
- 이후, for문을 사용하여 ans배열의 있는 인자를 1부터 max_l(최대 길이)만큼 까지 출력

*/

/*정답코드 분석
->디큐(deque)를 사용함.

그러나 역시 전반적인 방법은 비슷하고(max_l과 max_index를 구한 뒤에 그걸로 pre경로를 추적하는 방식)

**arr대신 deque를 사용하여 코드를 간단히 함.
deque의 push_front함수를 사용하면 max_index자리의 인자는 점점 뒤로 가고, 
앞자리에는 점점 초기 경로의 인자 값이 놓이게 됨.
즉 자연스럽게 경로 순서대로 디큐에 인자들이 배열되게 됨.
(의문? -> 그냥 queue를 쓸 순 없었나? 어짜피, 순서대로 fifo로 배열할 뿐인데?)
->안됨. 큐를 쓰면 큐의 top(head)엔 max_index의 값이 남고,
큐의 tail에는 가장 긴 증가하는 부분수열의 맨 처음 부분이 남음
즉, top부터 읽기 시작 하는 큐 특성상 
reverse 과정이 추가로 필요하다는 이야기 가됨.
이때문에 그냥 deque를 먼저 쓰는게 효율적임.
(push_front함수로 채운 deque의 경우 그냥 for each문을 단순히 쓰면 차례대로 출력됨.)

*/