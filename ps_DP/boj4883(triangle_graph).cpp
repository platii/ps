#include<iostream>
#include<algorithm>
using namespace std;

int n=-1;
int a[100001][4];
int d[100001][4];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(true){
        cin>>n;
        if(n==0) break;
        for(int i=1; i<=n; i++) 
            for(int j=1; j<=3; j++) cin>>a[i][j];
        //초기값 대입.
        d[1][1]=1001; //불가능한 위치 -> 간단히, 정점의 비용의 최대값보다 큰 값을 대입해서, 선택이 불가능하게 만듦.
        d[1][2]=a[1][2];
        d[1][3]=d[1][2]+a[1][3];
        //d배열 채우기
        for(int i=2; i<=n; i++){
            d[i][1]=min(d[i-1][1], d[i-1][2])+a[i][1];
            d[i][2]=min({d[i-1][1], d[i-1][2], d[i-1][3], d[i][1]})+a[i][2];
            d[i][3]=min({d[i-1][2], d[i-1][3], d[i][2]})+a[i][3];
        }
        cout<<t++<<". "<<d[n][2]<<'\n';
        //t++;
        //[개선]위 코드를 지우고(주석처리하고), 그냥 cout코드줄에서 ++를써줬음.
        //상기) t++의 ++는 그 문장이 끝난 뒤에연산이 일어나므로, 저렇게 써주면 원하는대로 동작함. 
    }

    //->정답코드 본 코드랑 완전 동일함.
    //딱 하나만 다름.
    



}