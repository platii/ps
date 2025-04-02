//n과 m(5)와완전히 동일
#include <iostream>
#include <algorithm> //sort 메소드 사용.
using namespace std;

int n,m;
int num[10];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++)
        cin>>num[i];
    sort(num,num+n);   //정렬 까먹지 말 것.
    do{
        for(int i=0; i<m; i++) cout<<num[i]<<' ';
        cout<<'\n';
        reverse(num+m, num+n);
    }while(next_permutation(num, num+n));
}
