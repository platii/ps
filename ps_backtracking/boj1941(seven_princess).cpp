//bfs배우고 다시 풀이.

#include <iostream>

using namespace std;

char square[5][5];
bool isused[5][5]={};
int cnt=0, yeon=0;

void func(int y, int x, int cur){
    //cout<<"x : "<<x<<" y : "<<y<<" cur : "<<cur<<" pre_yeon : "<<yeon<<'\n';
    if(!isused[y][x]){
        bool flag=false;
        if(square[y][x]=='Y'){
            yeon++;
            flag=true;
        }
        //cout<<"yeon : "<<yeon<<'\n';
        if(yeon>=4){ 
            yeon--;
            return;
        }
        if(cur==6){ //7인것을 최대 4번확인하게됨 -> 6으로 수정. 6이 되었을 때,( y가 4개인지, 중복인지 확인 하고) cnt++
            if(flag) yeon--;
            cnt++;
            return;
        }
        isused[y][x]=true;
        if(x>0)
            func(y,x-1,cur+1);
        if(x<4)
            func(y,x+1,cur+1);
        if(y>0)
            func(y-1,x, cur+1);
        if(y<4)
            func(y+1,x,cur+1);
        if(flag) yeon--; //본 함수 호출 시, Y값 증가시켜주었으면 갈림길로 돌아갈 때 다시 yeon -1 시킴.
        isused[y][x]=false;
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            cin>>square[i][j];
    func(0,1,0);
    //cout<<"finalyeon"<<yeon<<'\n';
    cout<<cnt;
    return 0;
}