#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    int i; //해당 위치의 점수 저장.
    while(t--){
        string str;
        cin>>str;
        int score=0;
        int score_sum=0;
        for(int i=0; i<str.length(); i++){
            char ox=str[i];
            if(ox=='X') {
                score=0;
                continue;
            }
            else { //O라면
                score++;
                score_sum+=score; //점수의합
            }
            
        }
        cout<<score_sum<<'\n';
    }
}

/*알게된 점

1) length()함수 사용시 그 문자열의 길이를 알 수 있다.

예시 : 문자열.length()

*/
