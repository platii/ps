//사전순으로 출력. n개중에 6개 뽑기,(6개 수는 모두 서로 다른 수), 원소중복불가
//next_permutation 사용
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, num[20], arr[10];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    vector<int> a;
    while(true){ 
        cin>>n;
        if(n==0) break;
        for (int i=0; i<n; i++)
            cin>>num[i]; //배열 입력 받음.
        for(int i=0; i<n; i++) a.push_back(i<6?0:1); //조합알고리즘용 배열 a (1)
        do{ //(2) do~while문 작성
            for(int i=0; i<n; i++){
                if(a[i]==0) cout<<num[i]<<' '; //(3)a[i]가 0이면 출력
            }
            cout<<'\n';
        }while(next_permutation(a.begin(),a.end())); //(4)next_permutation
        //실수1) 괄호에, a(조합알고리즘용 0, 1들어간 배열)가아닌 num을 넣음.
        //실수2)vector인데, a, a+n으로 입력함. 
    cout<<'\n'; //하나의 테스트케이스에 대해 출력 후 줄바꿈 한줄 더. 
    a.clear(); //다음 테스트케이스를 위해 vector초기화
    }
    return 0;
}
