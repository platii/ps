#include <iostream>
using namespace std;

int n, m;
int arr[10];
bool isused[10];

void func(int cur){
    if (cur==m){
        for(int i=0; i<m; i++)
            cout << arr[i] << ' ';                  //->for문 중괄호 실수하지 말기.
        cout<<'\n';                                 //endl; -> 버퍼 비우는데 시간 걸림, \n사용하기.
        return;                                     //return; 잊지말고적을 것.
        
    }

    for(int i=1; i<=n; i++){
        if(!isused[i]){
            arr[cur]=i;
            isused[i]=1;
            func(cur+1);
            isused[i]=0;
        }

    }

}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  func(0);
}