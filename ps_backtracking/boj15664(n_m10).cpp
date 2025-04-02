//(중복 있는 리스트 주어짐)n개중에 m개 뽑기, 비내림차순, 동일한 결과를 또 출력하면 안됨
//n_m9와 다르게, func 호출 시 이전의 pre가 유효해야함. pre를 전역변수로 선언
//또한, 같은 단계의 for문 에서는 pre가 다음 i에 영향을 주면 안됨.
//정답 코드를 확인함 -> 새로운 발상, func의 인자로 현재상태 st를 전달!(자연스럽게 비내림차순 형성함.)
// + int pre를 함수 내부에선언(전역변수 x)[pre가 func에 영향을 주지 않음]
#include <iostream>
#include <algorithm>

using namespace std;

int arr[10], num[10];
int n,m;

void func(int cur, int st){
    if(cur==m){
        for(int i=0; i<m; i++)
            cout<<arr[i]<<' ';
        cout<<'\n';
        return;
    }
    int pre=0;
    for(int i=st; i<n; i++){
        if(pre!=num[i]){
            arr[cur]=num[i];
            pre=num[i];
            func(cur+1, i+1);
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
    func(0, 0);
}