//순열 오름차순 only -> 다른풀이법도 있나 찾아보기
#include <iostream>
using namespace std;
int n,m;
int arr[10];
bool isused[10];

void func(int cur){
    static int prev=0; // prev를 전역변수로 선언하면 ambiguos 오류, func안에선언하면 매번 prev가 일정값으로 초기화 되어버림 ->static으로 선언
    if(cur==m){        // func 내에서 static으로 선언-> 최초 1회 선언 후 메모리 공간에 박힘.
        for(int i=0;i<m;i++)  //todo# ambiguous(모호함)관하여 찾아보기
            cout<<arr[i]<<' ';
        cout<<'\n';
        return;                 //return 까먹지 말기.
    }
    for (int i=1; i<=n; i++){
        if(!isused[i]){
            if(prev>i) continue;
            isused[i]=true;
            arr[cur]=i;
            prev=i;
            func(cur+1);
            isused[i]=false; //의문Q.// prev=0;이 아니라, prev=arr[cur-1]이어야 하지 않을까?(인덱스 오류는 우선 접어두더라도.) 왜 문제없이되는가..
            prev=0;   //prev를 다시 0으로 초기화 해줘야함.// Q고찰 : for문을 돌리는 동안 prev는 그 앞의 수(arr[cur-1]번째 수)로 지정되어있음(prev=i로 지정한후 그 다음 재귀 들어가므로.)
        }             //for문을 다 돌고, base condition만족하여 return하고, 다시 갈림길로 돌아가면, prev=0초기화되어, 그 다음i입력됨.
    }                 //이떄, n=4, m=3일떄, 1 4 2같은 것이 출력되고 나서 prev=0이 되어버리니 1 4 3이 출력 됨을 우려했는데,
}                     //애초에, 1 4 2는 prev=4인 for문에서 걸러짐.(func가 실행되지 않으므로 prev=0까지 갈일이 없음.)
                      //또한 prev=0으로 바뀌었다는건 오름차순을 만족한다는 것. 그 이후의 i부터는 어짜피 prev=0이되어도 계속 오름차순을 만족함.
                      //따라서 prev=0;은, 출력-return하고나서, 그다음 i를 원활히 입력하게끔 prev를 가장 작은수로 만들어주는 역할을함.
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>> n >> m;
    func(0);
}