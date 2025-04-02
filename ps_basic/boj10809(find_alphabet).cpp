#include <iostream> //iostream라이브러리, cout, cin과 같은 키워드 사용위함
using namespace std; //std namespace(패키지처럼 생각해서, 패키지마다 변수명함수명 겹치니까, 패키지별로 분류해둔거)를 사용한걸로 하겠다.
                    //원래는 std::cout 이런식으로 하나하나 써줘야함.

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //* 소문자a의 ascii코드는 97, 알파벳 총 개수는26개
    string s;
    cin>>s;
    int fp[26]; //firstPos
    fill(fp, fp+26, -1); //fp를 -1로 채움
    //+) fill함수는 fill(첫위치, 마지막위치, 채울값) 인데, 마지막위치값은 원하는위치에서 +1해줘야함. (내가 준 값에서 -1한 걸 마지막위치로 쓰기 때문)
    int i=0; //단어 내에서의 위치
    for(char a : s){
        int d=a-97; //a의 아스키코드값을 뺌.
        if(fp[d]== -1) fp[d]=i; //-1이면(수정 안되었으면) fp값 대입
        i++;
    }
    for(int pos : fp){
        cout<<pos<<" ";
    }
}