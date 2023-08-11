#include <iostream>

using namespace std;

int n,s, num[25];
int cnt=0;

void func(int cur, int tot){
    if(cur==n){
        if(tot==s)
            cnt++;
            return;
        }
        func(cur+1, tot);
        func(cur+1, tot+num[cur]);
    }


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>s;
    for(int i=0; i<n; i++)
        cin>>num[i];
    func(0,0);
    if(s==0) cnt--;
    cout<<cnt;
}