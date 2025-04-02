#include <iostream>
#include <queue>
using namespace std;
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<int> q;
    cin>>n;
    for(int i=1; i<=n; i++){
        q.push(i);
    }
    while(q.size()!=1){
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout<<q.front();
}