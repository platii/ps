//정답코드의 방식
//같은 수를 여러번 골라도 되므로, 만약 주어진 배열이 1 7 9 9와 같이 주어졌다면, 
//1 7 9의 중복없는 배열을 가지고 출력한 결과와 1 7 9 9를 가지고 출력한 결과가 동일함
//따라서 처음 입력받을 때 배열을 모두 중복이 없게끔 만들어 두고 이전에 했던 것과 같이 백트래킹 진행.
//->직접푼코드방식으로 진행하면 매번 백트래킹과정에서 결과의 중복막기 위해 이전 값과 동일한 값이 출력되는지 확인하는 과정을 거치지만,
// 이경우 중복을 이미 걸러내었으므로 그러한 과정이 생략되어 시간복잡도가 더 좋아질 여지가 있다.
//하지만 구조적으로 엄청난 차이가 있는 것은 아니므로 상황에 따라 취향껏 사용.
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
    for(int i=0; i<n; i++){
        arr[cur]=num[i];
        func(cur+1);        //cur+1 들어가야함. 0들어가면 안됨.
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    int idx=0;
    bool chk[10001]; //입력되는 수는 1만보다 작거나 같은 자연수
    while(n--){
        cin>>num[idx];
        if(chk[num[idx]]) continue; //이미 num에 추가된 것이면 넘김.
        chk[num[idx]]=1;
        idx++;
    }
    n=idx; // 기존의 backtracking 형식과 동일한 형태로 맞춰주기 위해 n=idx로 설정
    sort(num, num+n);     //까먹지 말것.
    func(0);
}