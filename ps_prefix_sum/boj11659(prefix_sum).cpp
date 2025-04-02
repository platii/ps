#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m, temp, sum[100001]={};
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>temp;
        sum[i]=sum[i-1]+temp;
    }
    while(m--){
        int i,j;
        cin>>i>>j;
        cout<<sum[j]-sum[i-1]<<'\n';
    }
}