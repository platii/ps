#include <iostream>

using namespace std;

int n,s, cnt, num[25];

void func(int cur, int tot){
    if(tot==s){
        cnt++;
        return;
    }
    func(cur+1,tot+num[cur+1]);
    func(cur+1,tot);

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>s;
    for(int i=0; i<n; i++)
        cin>>num[i];
    func(0,0);
    cout<<cnt;
}