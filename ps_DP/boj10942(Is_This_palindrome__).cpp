//팰린드롬? 문제.
#include <iostream>
using namespace std;

int n, t;
int a[2001];
bool d[2001][2001]; //d[i][j]=> s=i고, e=j일떄 팰린드롬 여부를 기록.

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    cin>>t;
    for(int diff=0; diff<=n-1; diff++){
        for(int i=1; i+diff<=n; i++){
            if(diff==0){ //diff=0이면 모두 1 ->사실 diff-for문전에 미리 채워놓는게 시간복잡도면에선 좋으나(남은 diff에서도 모두 if문을 검사해야하니)
                                            // 안에 넣는게 코드가 더 간결해져서 넣음.
                d[i][i+diff]=1;
                continue;
            }
            if(a[i]==a[i+diff]) { //diff=1이면, a[i]와 a[i+diff]만 비교 =>diff=1일때도 위와 같은 이유로 for문안에넣음.
                if(d[i+1][i+diff-1])d[i][i+diff]=1;
                else if(diff==1) d[i][i+diff]=1;
            }
            //else d[i][i+1]=0; //초기값이 이미 0이므로 굳이 작성할 필요 없음.
        }
    }
    int s, e;
    while(t--){
        cin>>s>>e;
        cout<<d[s][e]<<'\n';
    }
}



/* [풀이]

->a[i]==a[i+diff]를 체크한 후에
그 범위의 한칸 안에 있는 것이 팰린드롬이면
i~i+diff또한 팰린드롬임을 사용한 것.

ex)
1 2 1 3 1 2 1
이고
s,e가
2,6이면
우선 a[2]=2, a[6]=2로 같고
그사이인 3~5가 팰린드롬이므로,
2~6은 팰린드롬임.

이것을 이용하여 dp를 채워간것.
*/

//정답코드 -> 그냥 동일함.
/*

단지, 본문코드에 쓴 대로
diff=0일때, diff=1일때를 for문밖으로 뺀 것뿐.

  for (int i = 1; i <= n; ++i) {
    d[i][i] = 1;
    if (a[i - 1] == a[i]) d[i - 1][i] = 1;
  }

  for (int gap = 2; gap < n; ++gap) {
    for (int i = 1; i <= n - gap; ++i) {
      int s = i, e = i + gap;
      if (a[s] == a[e] && d[s + 1][e - 1]) d[s][e] = 1;
    }
  }


*/