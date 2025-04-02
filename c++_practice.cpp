#include <iostream>
using namespace std;

int d[1001][1001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;

    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        cout<<s<<"<----s "<<'\n';
        for(int j = 0; j < m; ++j)
            d[i][j] = s[j];
    }
    
    //d배열 출력
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cout<<d[i][j];
        cout<<'\n';
    }
    int a,b;
    a='0';
    b='1';
    cout<<a<<" "<<b;
}

