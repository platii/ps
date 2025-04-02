//n개 리스트 주어짐(리스트 원소 중복 가능), n개중 m개뽑아 순열 만들기, 같은 수 여러번뽑기가능(원소 중복 뽑기 가능), 비내림차순
#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int arr[10], num[10];

void func(int cur, int st){
    if(cur==m){
        for(int i=0; i<m; i++)
            cout<<arr[i]<<' ';
        cout<<'\n';
        return;
    }
    int pre=0; //본 문제 조건에서 st를 사용하면, 굳이 pre를 전역변수로 사용하지 않아도 됨.
    for(int i=st; i<n; i++){
        if(pre!=num[i]){
            arr[cur]=num[i];
            pre=num[i];
            func(cur+1, i); //원소 중복이 가능해야하므로, 최초 자기자신의 위치를 st로 보냄(중복이 불가하면 i+1로 보냄)
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++)
        cin>>num[i];
    sort(num, num+n); //빼먹지 말기.
    func(0,0);
}