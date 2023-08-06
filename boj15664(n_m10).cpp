//(중복 있는 리스트 주어짐)n개중에 m개 뽑기, 비내림차순, 동일한 결과를 또 출력하면 안됨
//n_m9와 다르게, func 호출 시 이전의 pre가 유효해야함. pre를 전역변수로 선언
//또한, 같은 단계의 for문 에서는 pre가 다음 i에 영향을 주면 안됨.
#include <iostream>
#include <algorithm>

using namespace std;

int arr[10], num[10];
int n,m, pre;
bool isused[10];

void func(int cur){
    if(cur==m){
        for(int i=0; i<m; i++)
            cout<<arr[i]<<' ';
        cout<<'\n';
        return;
    }
    for(int i=0; i<n; i++){
        if(pre<num[i] && !isused[i]){
            arr[cur]=num[i]; //arr 대괄호 안에 i넣지 말기
            pre=num[i];
            isused[i]=true;
            func(cur+1);
            isused[i]=false;
            pre=num[i];
        }
    }

}

int main(){
    ios::sync_with_stdio(0); //Q:괄호안에 false, null, 0들어갈때 각각의 차이가 뭔가? , cin.tie, cout.tie도 마찬가지
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++)
        cin>>num[i];
    sort(num,num+n); //sort 까먹지 말기.
    func(0);
}