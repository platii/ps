//사전순으로 출력. n개중에 6개 뽑기,(6개 수는 모두 서로 다른 수), 원소중복불가
#include <iostream>

using namespace std;

int n, num[20], arr[10];

void func(int cur, int st){
    if(cur==6){
        for(int i=0; i<6; i++)
            cout<<arr[i]<<' ';
        cout<<'\n';
    }
    for(int i=st; i<n; i++){
        arr[cur]=num[i]; //대괄호 안에 cur 넣는거 i로 착각하지 말기.
        func(cur+1, i+1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //이 아래에서
    cin>>n; //최초 n입력 받음.
    while(n!=0){ 
        for (int i=0; i<n; i++)
            cin>>num[i];
        func(0,0); 
        cout<<'\n'; //테스트케이스 출력 이후 줄바꿈표 한줄.
        cin>>n; //다시 다음줄 입력 받음.
    }
    //여기까지 부분은 코드 아래 주석과 같은 식으로 바꾸어 쓸 수도 있음.
    return 0;
}


/*
while(true또는1){
    cin>>n;
    if(n==0) break;
    for (int i=0; i<n; i++)
        cin>>num[i];
    func(0,0); 
    cout<<'\n'; 
}
이렇게 쓰는게 조금더 간결한것 같긴하다. */