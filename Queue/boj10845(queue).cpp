//원형 큐 써도 되는데 일단강의에서는 선형 큐씀.(원형 큐는 그냥 mx잘 파악해서 코드 짜주면 됨)
#include <iostream>
using namespace std;

const int MX=20000005;
int dat[MX]={};
int head=0, tail=0;

void push(int x){
    dat[tail++]=x;
}

void pop(){
    head++;
}

int front(){
    return dat[head];
}

int back(){
    return dat[tail-1];
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin>>n;
    while(n--){
        cin>>s;
        if(s=="push"){
            int a;
            cin>>a;
            push(a);
        }
        else if(s=="pop"){
            if(tail==head) cout<<"-1"<<'\n';
            else {
                cout<<front()<<'\n';
                pop();
            }
        }
        else if(s=="size")
            cout<<tail-head<<'\n';
        else if(s=="empty")
            if(tail==head) cout<<"1"<<'\n';
            else cout<<"0"<<'\n';
        else if(s=="front")
            if(tail==head) cout<<"-1"<<'\n';
            else cout<<front()<<'\n';
        else if(s=="back")
            if(tail==head) cout<<"-1"<<'\n';
            else cout<<back()<<'\n';
    }

}