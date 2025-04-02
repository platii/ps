#include <iostream>
#include <algorithm>
using namespace std;

int a[3]={1,2,3};
int main(){
    do{
        for (int i=0; i<3; i++)
            cout << a[i];
        cout<<'\n';
    }while(next_permutation(a,a+3));
    }