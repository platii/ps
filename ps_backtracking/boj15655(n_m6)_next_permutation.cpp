#include <iostream>
#include <algorithm> //sort 메소드 사용.
#include <vector>
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

    vector<int> a;
    for(int i=0; i<n; i++) a.push_back(i<m?0:1); //조합알고리즘 용 a배열 채우기

    do{
        for(int i=0; i<n; i++) if(a[i]==0) cout<<num[i]<<' '; //실수) for문범위 m까지가 아니라 n까지
        cout<<'\n';
        //실수2) reverse할필요 없음
    }while(next_permutation(a.begin(), a.end()));
}