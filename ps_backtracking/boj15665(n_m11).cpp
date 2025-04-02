//n과m(7)과 굉장히 유사(주어진 자연수가 중복이 있냐 없냐의 차이)
//n개 원소 가진 리스트 주어짐(리스트안의 원소 중복 가능).n개중 m개 뽑아 순열 만들기, 같은 거 여러개 뽑아도 됨.(원소 중복 뽑기 가능)

#include <iostream>
#include <algorithm> //sort함수

using namespace std;

int n,m;
int arr[10], num[10];

void func(int cur){
    if(cur==m){
        for(int i=0; i<m; i++)
            cout<<arr[i]<<' ';
        cout<<'\n';
        return;           //실수 x
    }
    int pre=0;
    for(int i=0; i<n; i++){
        if(pre!=num[i]){   //for문 내에서 순열 중복 막음.
        arr[cur]=num[i];
        pre=num[i];
        func(cur+1);        //cur+1 들어가야함. 0들어가면 안됨.
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>num[i];
    }
    sort(num, num+n);     //까먹지 말것.
    func(0);
}