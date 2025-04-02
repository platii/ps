#include <iostream>
#include <utility>
#include <queue>
using namespace std;
#define x first
#define y second
int board[100][100];
bool vis[100][100];
int n, max_height, max_security;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            cin>>board[i][j]; //보드 입력 받기
            max_height=max(max_height, board[i][j]);
        }
    queue<pair<int,int>> q;
    for(int rain=0; rain<=max_height; rain++){
        for(int i=0; i<n; i++) fill(vis[i], vis[i]+n, false); // vis판 초기화
        int num_security=0;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++){
                if(vis[i][j]==true||board[i][j]<=rain) continue;
                q.push({i,j});
                vis[i][j]=true;
                num_security++;
                while(!q.empty()){
                    auto cur=q.front(); q.pop();
                    for(int dir=0; dir<4; dir++){
                        int nx=cur.x+dx[dir];
                        int ny=cur.y+dy[dir];
                        if(nx<0||nx>=n||ny<0||ny>=n) continue;
                        if(vis[nx][ny]==true||board[nx][ny]<=rain)continue;
                        q.push({nx,ny}); //push에 i,j를 집어넣으면안됨. 실수.(집중해서 작성하기)
                        vis[nx][ny]=true;
                    }
                }
                
            }
        max_security=max(max_security, num_security);
    }
    cout<<max_security;
}

//첫 트라이-> 메모리 초과
/*
메모리초과가 나는이유?
배열의 용량? int형 변수의 용량 4byte
2차원배열 board[100][100]의 용량 = 100*100*4=4만 바이트. 대략 40키로바이트 (1메가바이트=1024키로바이트) 제한용량:128메가.
vis[100][100]의 용량 bool하나는 1바이트-> 총 1만 바이트. 대략 10키로바이트
용량은 차고넘침.

스택오버플로우.->함수가 너무 많이 호출될 때 발생.

--->push에 nx,ny가 아닌 i,j를 넣어서 발생한 실수.

*/