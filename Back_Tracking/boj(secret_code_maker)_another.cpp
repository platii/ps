//출력 전(cur==l)에서 모음, 자음 체크.
#include <iostream>
#include <algorithm>
using namespace std;

int l,c;
char alp[15], code[15];
char vowel[]={'a','e', 'i', 'o', 'u'}; 

bool aeiou(char c){
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}

void func(int cur, int st){
    if(cur==l){
        int cnt1=0, cnt2=0;
        bool flag=false;
        for(int i=0; i<l; i++) //모음, 자음 개수 확인
            if(aeiou(code[i])) cnt1++;
            else cnt2++;
        if(cnt1>=1&&cnt2>=2) flag=true; //모음 자음 개수 조건에 맞을 경우.
        if(flag){ //출력.
            for(int i=0; i<l; i++)
                cout<<code[i];
            cout<<'\n';
        }
        return;
    }
    for(int i=st; i<c; i++){
        code[cur]=alp[i]; //code[] 대괄호 안에 cur 넣어야함. 실수 x
        func(cur+1, i+1); //실수, i+1이 들어가야함. (st+1 아님.)
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>l>>c;
    for(int i=0; i<c; i++)
        cin>>alp[i];
    sort(alp, alp+c);
    func(0,0);
}