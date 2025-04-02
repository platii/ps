#include <iostream>
#include <algorithm>
using namespace std;

int arr[9],arr3[7], sum, comp,a,b;
bool arr2[101];
int main(){
    ios::sync_with_stdio(0);
    for(int i=0; i<9; i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    int n=sum-100;
    for(int i=0; i<9; i++){
        if(arr2[arr[i]]==1){
            a=arr[i]; b=n-arr[i];
            break;
        }
        comp=n-arr[i];
        arr2[comp]=true;

    }
    for(int i=0; i<9; i++){
        if(arr[i]==a||arr[i]==b) continue;
        for(int j=0; j<7; j++){
            if(arr3[j]) continue;
            arr3[j]=arr[i];
            break;
        }
    }
    sort(arr3, arr3+7);
    for(int i=0; i<7; i++) cout<<arr3[i]<<'\n';

    

}   