//주어진 n개의 자연수 중 m개 뽑아 순열 만들기(자연수는 모두 서로다름), 사전순으로 증가하는 순서로 출력.
#include <iostream>
#include <algorithm> //-> sort함수 라이브러리
using namespace std;

int n,m;
int arr[10];
int num[10];

void func(int cur){
    static int prev=0;
    if(cur==m){
        for(int i=0; i<m; i++)
            cout<<arr[i]<<' ';
        cout<<'\n';
        return; //return <<- 재귀에서 빼먹으면 안됨.
    }
    for(int i=0; i<n; i++){ //n개 자연수 차례로 비교하며 arr[]에 넣고 func재귀.
        if(prev==num[i]) continue; //중복 체크
        arr[cur]=num[i];
        prev=num[i];
        func(cur+1);
        prev=arr[cur-1];           //prev=0이면 안됨.
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++)
        cin>>num[i];  //스페이스는 알아서 띄어서 받나?
    sort(num, num+n);
    func(0);
}