#include <iostream>

using namespace std;

int n, cnt;
bool isused1[20], isused2[30], isused3[30];

void func(int cur){
    if(cur==n){
        cnt++;
        return;
    }
    for(int i=0; i<n; i++){
        if(!isused1[i] && !isused2[i+cur] && !isused3[i-cur+n-1]){
            isused1[i]=true;
            isused2[i+cur]=true;
            isused3[i-cur+n-1]=true;   //n-1을 더하는이유 : out of inex 방지 위함. 번외로, 배열 크기는 최소 2N-1개 필요(최상측, 최우측의 개수(중복 제외))
            func(cur+1);
            isused1[i]=false;
            isused2[i+cur]=false;
            isused3[i-cur+n-1]=false;
        }
        
        
    }


}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    func(0);
    cout<<cnt;
}