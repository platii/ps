//next_permutation을 사용해서는 정답이 될 수 없음. -> 그렇지만 기록용.
#include <iostream>
#include <algorithm> //sort 메소드 사용.
#include <vector>
using namespace std;

int n,m;
int num[10], pre[10];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++)
        cin>>num[i];
    sort(num,num+n);   //정렬 까먹지 말 것.

    vector<int> a;
    for(int i=0; i<n; i++) a.push_back(i<m?0:1); //조합알고리즘 용 a배열 채우기

    do{
        bool flag=false;
        for(int i=0, j=0; i<n; i++) if(a[i]==0){
            if(pre[j]!=num[i]) { //이전출력값과 비교
                flag=true;
            }
            j++; //실수) if조건 두개 묶으면 j가 의도한대로 증가안함
        }
        if(!flag) continue;
        for(int i=0, j=0; i<n; i++) if(a[i]==0){
            cout<<num[i]<<' ';
            pre[j]=num[i];//이전 출력 값 저장.
            j++;
        }
        cout<<'\n';
    }while(next_permutation(a.begin(), a.end()));
}
//틀림 
/*

틀린 이유,     
5 3
4 4 6 9 9
와 같은 입력이 들어가게 되면,

4 4 6 
4 4 9
4 6 9 <--
4 9 9
4 6 9 <--
4 9 9
6 9 9
와 같은 출력이 나온다.

pre로 이전 출력을 걸러냈음에도 
화살표와 같이 중복이 표시되는 이유는,
pre는 직전에 출력된 값만 저장하고 그 이전에 출력된 값은 보관하고 있지 못한다.
즉, 이러한 유형의 문제(배열을 사용하며, 배열에 숫자가 중복되어서 들어가는 경우)에 pre의 방식을 사용하기 위해서는 
모든 출력값을 저장하는 pre를 만들어 놓아야 한다는 것이다.
이는 메모리 면에서 굉장히 비효율적이며 어느정도의 입력이 들어올지 모르므로 코드로 작성하기 난감하다.

인터넷에서 확인해보니 n과m 10번문제의 경우 next_permutation으로 푼 경우는 찾지 못했다.

next_permutation은 수열 혹은 조합을 사용하여 순열을 표기해야 할 때, 주어진 배열의 중복을 허용하지 않을 때만
사용해야할 것 같다.
*/