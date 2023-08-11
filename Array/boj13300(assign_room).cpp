#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k, room=0;
    int human[2][6]={};
    cin>>n>>k;
    while(n--){
        int a,b;
        cin>>a>>b;
        human[a][b-1]++;
    }
    for(int i=0; i<2; i++)
        for(int j=0; j<6; j++)
            if(human[i][j]){
                room+=(human[i][j]+k-1)/k; //올림해서 계산.
            }
    cout<<room;
}