#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n=3;
    int yut=0;
    while(n--){
        int m=4;
        int bae=0;
        while(m--){
            cin>>yut;
            if(yut==0) bae++;
        }
        if(bae==1) cout<<"A"<<'\n';
        else if(bae==2) cout<<"B"<<'\n';
        else if(bae==3) cout<<"C"<<'\n';
        else if(bae==4) cout<<"D"<<'\n';
        else cout<<"E"<<'\n';
    }
}