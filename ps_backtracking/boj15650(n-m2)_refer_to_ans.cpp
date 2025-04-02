//오름차순 //정답코드 방식, st를 func 함수에 전달하는 방식이 아니라면..
#include <iostream>
using namespace std;

int n,m;
int arr[10];
bool isused[10];

void func(int cur){
    if(cur==m){
        for(int i=0; i<m; i++)
            cout<<arr[i]<<' ';
        cout<<'\n';
    }
    //요 아래 두줄 기억해두기. out of range 오류가 나지 않으면서, arr[k-1]값을 사용하도록 하는 발상.
    int st=1; //cur=0일 때의 초기 st값
    if(cur!=0) st=arr[cur-1]+1; //이전에 있는 값보다 더 큰 값부터 비교하도록 만듦.
    //
    
    for(int i=st; i<=n; i++){
        if(isused[i])continue;//중복체크
        isused[i]=true;
        arr[cur]=i;
        func(cur+1);
        isused[i]=false;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    func(0);
}