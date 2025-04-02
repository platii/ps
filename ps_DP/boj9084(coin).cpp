#include<iostream>
using namespace std;

int t, n, m;
int a[21], d[10001]; 
//d[i]=i원 가치를 모을 수 있는 경우의 수.

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        fill(d, d+m+1, 0);
        for(int i=1; i<=n; i++) {
            cin>>a[i];
        }
        cin>>m;
        d[0]=1;
        for(int i=1; i<=n; i++)
            for(int j=a[i]; j<=m; j++){
                d[j]+=d[j-a[i]];
            }

        cout<<d[m]<<'\n';
    }
}

//동전1문제랑 그냥 동일함. 단지 테스트케이스가 여러개 된 것 뿐.