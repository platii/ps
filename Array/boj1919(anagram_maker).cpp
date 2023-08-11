#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s1,s2;
    int ans=0, a[26]={}; //지역변수 선언시, 초기화 꼭 잊지말것.
    cin>>s1>>s2;
    for(auto c:s1) a[c-'a']++;
    for(auto c:s2) a[c-'a']--;
    for(int i=0; i<26; i++)
        ans+=abs(a[i]);
    cout<<ans;
}