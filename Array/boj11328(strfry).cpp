//다른 방식의 코드
#include <iostream>
using namespace std;

int n;
string s1, s2;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    while(n--){
        int a[26]={};
        cin>>s1>>s2;
        bool flag=true;
        for(auto c:s1) a[c-'a']++;
        for(auto c:s2) a[c-'a']--;
        for(int i:a) //바로 for each문 사용하면 됨., for(int i=0; i<26; i++) 쓸 필요 없음.
            if(i!=0){
                cout<<"Impossible"<<'\n';
                flag=false;
                break;
            }
        if(flag==true)
            cout<<"Possible"<<'\n';
    }
    
}
/* 직접 푼 코드
#include <iostream>
using namespace std;

int n;
string s1, s2;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    while(n--){
        int alp1[26]={}, alp2[26]={}; //확인하는 배열을 전역변수로 선언하면 안됨, 결과가 impossible로 나온 이후에는, 다음 시도에서, 배열의 초기값이 틀려짐.
        cin>>s1>>s2;
        bool flag=true;
        for(auto c:s1)
            alp1[c-'a']++;
        for(auto c:s2)
            alp2[c-'a']++;
        for(int i=0; i<26; i++)
            if(alp1[i]!=alp2[i]){
                cout<<"Impossible"<<'\n';
                flag=false;
                break;
            }
        if(flag==true)
            cout<<"Possible"<<'\n';
    }
    
}

*/