#include <iostream>
#include <algorithm> //sort 메소드 사용.
using namespace std;

int n,m;
int arr[10], num[10];
//int pre[10];     ->pre굳이 안써도됨.   //prev는 모호함 에러가 뜸,pre로 바꿨더니 이상 없음.(아마 prev가 이미 예약어로 설정되어있는 것으로 추정(std에 있는 것으로 추정))
bool isused[10]; 


void func(int cur){
    if(cur==m){
        for(int i=0; i<m; i++)
            cout<<arr[i]<<' ';
        cout<<'\n';
        return;   //까먹지 말것.
    }

    for(int i=0; i<n; i++){
        if(!isused[i]){
        arr[cur]=num[i];
        isused[i]= true;
        func(cur+1); //재귀 기본 조건. 까먹지 말 것.
        isused[i]=false;
    }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++)
        cin>>num[i];
    sort(num,num+n);   //정렬 까먹지 말 것.
    func(0);
}