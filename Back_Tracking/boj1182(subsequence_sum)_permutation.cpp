#include <iostream>
#include <algorithm>
using namespace std;

int n,s;
int arr[10];
int tot=0;
int cnt=0;

void func(int cur, int tot){
    do{
    for (int i=0; i<n; i++){
            tot+=arr[i];
        if (tot==s) cnt++;
        }
    }while(next_permutation(arr, arr+n));

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>s;
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    func(0,0);

    cout<<cnt;

}