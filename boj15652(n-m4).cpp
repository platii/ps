//비내림차순(오름차순과 동일한개념에서 + 인접한 두수가 같을 수도 있음), 중복가능
#include <iostream>
using namespace std;

int n, m;
int arr[10];

void func(int cur){
    static int prev=0; //오름차순 순열 고르는 문제에서 썼던 풀이법 그대로 사용.
    if(cur==m){
        for(int i=0; i<m; i++)
            cout<<arr[i]<<' ';
        cout<<'\n';
        return;               //재귀사용시 base condition 에서 , return 꼭 빼먹지 말기.
    }

    for(int i=1; i<=n; i++){ //for문 int 1부터 시작하는 거 주의.
        if(prev>i) continue;
        arr[cur]=i;
        prev=i;
        func(cur+1);              //->segmentation fault 에러. prev=0으로 인한 오류?->prev=0은 관계없음. 다른이유?-> 0이 아니라 cur+1을 넣어야함... 이런 실수 x
        prev=0;              //func종료 후, prev를 다시 초기화.
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n >> m;
    func(0);
}