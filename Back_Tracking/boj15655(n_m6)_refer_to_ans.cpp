//n개 중 m개 뽑아 순열 만들기, 오름차순, 중복 x //정답코드 참고
#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[10], num[10];

void func(int cur){
    if(cur==m){
        for(int i=0; i<m; i++)
            cout<<num[arr[i]]<<' '; //arr에서 차례대로 인덱스를 꺼내고 그 인덱스에 해당하는 num값을 출력
        cout<<'\n';
        return;
    }
    //
    int st=0; //num배열로 받아서 진행하므로 st=1부터 시작하면안됨. st=0부터
    if(cur!=0) st=arr[cur-1]+1;
    //
    for(int i=st; i<n; i++){
        arr[cur]=i; //위 두줄의 방식을 사용하기 위해, arr[cur]에 인덱스값인 i를 저장.
        //arr[cur]에 num[i]를 저장하면, st=arr[cur-1]+1;에 인덱스가아닌 큰 수가 들어갈 수 있음. 이렇게되면 st는 for문에서 의도한대로 동작하지 않게됨.
        func(cur+1);       
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n ;i++)
        cin>>num[i];
    sort(num, num+n);
    func(0);
}