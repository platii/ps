#include <iostream>
using namespace std;

int num[100000];
bool hash_map[2000000];      //이경우에는 그냥 bool로 체크하는 것이 좋음.(수정), 100만넘겼을 때의 예외처리를 하기 귀찮아서 그냥 200만 할당함.

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x,comp, cnt=0;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>num[i];
    cin>>x; //입력받기 끝.
    for(int i=0; i<n; i++){
        comp=x-num[i];
        if(hash_map[num[i]]) cnt++;
        if(comp>0) hash_map[comp]=1;      //comp가(예외처리!!!) !!!!!음수가 되는경우!!!!(num[i]가 x보다 큰경우)의 out of bounds를 고려하지 못했음!
    }
    cout<<cnt;
}
//-> 시간복잡도 n
/*방식을 조금 바꾸면(정답지 풀이.)
    for(int i=0; i<n; i++){
        comp=x-num[i];
        if(comp>0 && hash_map[comp]) cnt++; //혹은 comp를 따로 정의하지않고 그대로 x-num[i]로 넣어도 됨.
        hash_map[num[i]]=true;
    }



/*  (시간초과 난 코드.) ->시간복잡도 n제곱
    int n,x, cnt=0;
    cin>>n;
    int num[100000];
    for(int i=0; i<n; i++)
        cin>>num[i];
    cin>>x;
    for(int i=0; i<n; i++)
        for(int j=i; j<n; j++)
            if(num[i]+num[j]==x) cnt++;
    cout<<cnt;
*/