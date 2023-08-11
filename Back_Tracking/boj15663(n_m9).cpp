//n개의 자연수가 들어간 리스트 주어짐// 이때, n개중 m개 뽑아 순열 만들기(단, n개 자연수 중 같은 수가 존재 할 수 있음), 중복된수열은 출력하면 안됨.

//조건 1, for문내에서는 pre가 유효해야함(이전 pre값을 가져야함).
//조건 2, func를 호출하여 하위블록으로 내려갈 때는 pre가 영향을 주지 않아야 함.
//조건 3, for문이 모두 종료되고 나서 다시 상위 갈림길로 올라갔을 때는, 그 상위 갈림길에서의 for문에서의 이전 pre값(이전 for문 실행 시 num[i]값)을 가져야함.
// ->조건3은 pre를 func안에서 선언하면 쉽게 해결됨.
#include <iostream>
#include <algorithm>
using namespace std;

int n,m; //pre를 func안에서 선언하게 바꿈.
int arr[10], num[10];
bool isused[10];

void func(int cur){
    if(cur==m){
        for(int i=0; i<m; i++)
            cout<<arr[i]<<' ';
        cout<<'\n';
        return;
    }
    int pre=0; //func호출하여 들어왔을 시 pre=0 초기화, 단, cur==m이되어 출력하는 경우는 제외.(수정* : pre를 func안에서 선언)
    for(int i=0; i<n; i++){
        if(pre!=num[i] && !isused[i]){ //if문 합치는 것이 더 좋음.
            arr[cur]=num[i];
            pre=num[i];     //for문 내에서는 이전의 pre값이 유효해야함.
            isused[i]=true; 
            func(cur+1);
            isused[i]=false;
            //pre=num[i]; //for문이 종료되고, 상위 갈림길로 돌아갔을 때의, 이전의 pre로 다시 초기화.(*pre를 func안에서 선언하면 적지 않아도됨.)(그런데, 이걸 적으면 8ms, 안적으면 12ms가 나옴. 적을때가 더빠름.?)
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++)
        cin>>num[i];
    sort(num, num+n);
    func(0);
}