#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin>>n;
    queue<int> q;
    while(n--){
        cin>>s;
        if(s=="push"){
            int a;
            cin>>a;
            q.push(a);
        }
        else if(s=="pop"){
            if(q.empty()) cout<<"-1"<<'\n';
            else {
                cout<<q.front()<<'\n';
                q.pop();
            }
        }
        else if(s=="size")
            cout<<q.size()<<'\n';
        else if(s=="empty")
            cout<<q.empty()<<'\n'; // 안비었으면 0 or 비었으면 1로 출력됨
        else if(s=="front")
            if(q.empty()) cout<<"-1"<<'\n';
            else cout<<q.front()<<'\n';
        else if(s=="back")
            if(q.empty()) cout<<"-1"<<'\n';
            else cout<<q.back()<<'\n';
    }

}