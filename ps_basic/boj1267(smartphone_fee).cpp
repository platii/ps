#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int num, y=0, m=0;
    while(n--){
        cin>>num;
        y+=(num/30+1)*10;
        m+=(num/60+1)*15;
    }
    int ans=0;
    if(y<=m) {
        cout<<"Y"<<' ';
        ans=y;
    }
    if(m<=y) {
        cout<<"M"<<' ';
        ans=m;
    }
    cout<<ans;
}