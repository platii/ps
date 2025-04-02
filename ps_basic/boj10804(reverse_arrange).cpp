#include <iostream>
using namespace std;

int num[21];
int n=10,m, a, b;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=1; i<=20; i++) num[i]=i;
   while(n--){
        cin>>a>>b;
        while(a<b) swap(num[a++], num[b--]); // ex)58 67 76(a>b)->(짝수), 59 68 77(a==b)(홀수)
   }
   for(int i=1; i<=20; i++) cout<<num[i]<<' ';
}


/* reverse함수 쓴 풀이

#include <iostream>
#include <algorithm>
using namespace std;

int num[21];
int n=10,m, a, b;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=1; i<=20; i++) num[i]=i;
   while(n--){
        cin>>a>>b;
        reverse(num+a, num+b+1);
   }
   for(int i=1; i<=20; i++) cout<<num[i]<<' ';
}

*/