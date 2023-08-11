//백트래킹 과정에서 모음을 체크.
#include <iostream>
#include <algorithm>
using namespace std;

int l,c;
char alp[15], code[15];
char vowel[]={'a','e', 'i', 'o', 'u'}; 

void func(int cur, int st, int numVowel){
    if(cur==l){
        if(numVowel<1||l-numVowel<2) return; //모음의 수 1보다 작거나, 자음의 수가 2개보다 작으면 출력하지 않고 종료.
        for(int i=0; i<l; i++)
            cout<<code[i];
        cout<<'\n';
        return;
    }
    for(int i=st; i<c; i++){
        bool flag=false; //for문 안에서 선언되어야 함.
        for(int j=0; j<5; j++) //현재 문자 모음인지 체크.
            if(alp[i]==vowel[j]){ 
                numVowel++; //입력된 문자가 모음이면, 모음카운트 +1
                flag=true;
                break;
            }
        code[cur]=alp[i]; //code[] 대괄호 안에 cur 넣어야함. 실수 x
        func(cur+1, i+1, numVowel); //실수, i+1이 들어가야함. (st+1 아님.)
        if(flag) numVowel--; //다음 반복으로 넘어가기전에, 이번의 문자가 모음이었다면, 다시 -1하여 돌려줌.ex) 자음 모음(numVowel=1)-> 자음 자음(numVowel이 다시 0이되록 하기 위함.) 
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>l>>c;
    for(int i=0; i<c; i++)
        cin>>alp[i];
    sort(alp, alp+c);
    func(0,0,0);
}