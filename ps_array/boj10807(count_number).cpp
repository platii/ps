#include <iostream>
using namespace std;

//정답 본 풀이
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, v, num[201]={}; //-100부터 100 까지이므로 200개 용량 할당. //정답풀이에서는 [200]을 [201]로 바꾸었더니 맞았음.(실수: 선언시의 []안 값은 원소의 개수를의미..)
    cin>>n;
    for(int i=0; i<n; i++){ //while(n--)를 써도 됨.
        int temp;
        cin>>temp;
        num[temp+100
        ]++; //음수값도 저장하기 위해 +100.
    }
    cin>>v;
    cout<<num[v+100];
}

/* 초기풀이 ->T(2n) ->단순 입력받고, 단순 비교.
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, v, cnt=0, num[100];  //cnt 초기화 안해서 여태까지 틀렸던 것.
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>num[i];
    cin>>v;
    for (int i=0; i<n; i++)
        if(num[i]==v) cnt++;
    cout<<cnt;
}
*/