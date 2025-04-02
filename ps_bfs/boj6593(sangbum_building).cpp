#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
int h, n ,m;
string board[30][30]; //스트링 2차원배열에서 char 3차원 배열로 바꾸어봄.
int dist[30][30][30]; //전역변수위치에서 ->메인함수 변수 위치로 옮겨봄
int dx[6]={1,0,0,-1,0,0};
int dy[6]={0,1,0,0,-1,0};
int dz[6]={0,0,1,0,0,-1};
int ext[3];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(true){
        cin>>h>>n>>m;
        if(n==0&&m==0&&h==0) break; //종료 조건.
        queue<tuple<int,int,int>> q;
        for(int i=0; i<h; i++) //!!!!!!(실수)!!!!!!!!!! i++해야할 걸 h++ 해놓아서 계속 오류(타임아웃) 났던것. 
            for(int j=0; j<n; j++)
                fill(dist[i][j], dist[i][j]+m,-1); //거리 -1 초기화
        for(int i=0; i<h; i++)  //!!!!!!(실수.주의)!!!!!!!!!! i++해야할 걸 h++ 해놓아서 계속 오류(타임아웃) 났던것
            for(int j=0; j<n; j++){
                cin>>board[i][j]; //보드 입력
                for(int k=0; k<m; k++){
                    if(board[i][j][k]=='S'){
                        q.push({i,j,k});
                        dist[i][j][k]=0; //출발점 거리 0.
                    }
                    else if(board[i][j][k]=='E'){
                        ext[0]=i; ext[1]=j; ext[2]=k; //h,n,m 출구좌표저장.
                    }
                } 
            }
        while(!q.empty()){
            auto cur=q.front(); q.pop();
            for(int dir=0; dir<6; dir++){
                int nx=get<0>(cur)+dx[dir];
                int ny=get<1>(cur)+dy[dir];
                int nz=get<2>(cur)+dz[dir];
                if(nx<0||nx>=h||ny<0||ny>=n||nz<0||nz>=m)continue; //범위 벗어나면 continue; 여기서는 간단히 nx,ny,nz를 h,n,m과 대응하여 간단하게 푼다.
                if(dist[nx][ny][nz]!=-1||board[nx][ny][nz]=='#')continue; //-1이 아니라 1이라고 적는 실수.
                dist[nx][ny][nz]=dist[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
                q.push({nx,ny,nz});
            }
        }
        if(dist[ext[0]][ext[1]][ext[2]]==-1) cout<<"Trapped!"<<'\n';
        else cout<<"Escaped in "<<dist[ext[0]][ext[1]][ext[2]]<<" minute(s)."<<'\n';
    }
}

/*

//시간초과. 이유 추측 1) while 무한루프로인한 오류 2)코드 시간복잡도 때문.
/*for문에서 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 for(int i=0; i<h; i++)//// char3차원배열 형태의 맞게 입력 받음. i++가 아니라 h++했던거 수정.
            for(int j=0; j<n; j++){
                for(int k=0; k<m; k++){
                    를 i++자리에 h++ 해놓아서!!!!!!!!!!!!!!!!!!! 계속 무한 로딩 걸렸던 것.
                    + k자리에 j넣는 등 실수.

=>>>>>>>>>>>>>>>>>>>>>for문 작성시 변수 설정, 변수의 제한범위 설정 조심하자....
*/
/* 오류 있었던 코드
        for(int i=0; i<h; h++) <-------------------이부분 오류
            for(int j=0; j<n; j++){
                cin>>board[i][j]; //보드 입력
                for(int k=0; k<m; k++){
                    if(board[i][j][k]=='S'){
                        q.push({i,j,k});
                        dist[i][j][k]=0; //출발점 거리 0.
                    }
                    else if(board[i][j][k]=='E'){
                        ext[0]=i; ext[1]=j; ext[2]=k; //h,n,m 출구좌표저장.
                    }
                } 
            }
*/

/* 정답코드 확인
board, dist의 크기를 MX=31로 따로 둔 후 board[MX][MX][MX] 이런식으로 할당하였음. 
---->##수의 크기가 크고, MX를 자주 변경해야할 때 이렇게 하면 좋을듯.

또한, 전역변수가 아니라 WHILE 루프 안에서 선언하여 지역변수로 선언하였음. 
-> 어짜피 루프마다 DIST거리를 -1로 초기화하므로 굳이 이렇게 안해도 될듯.

DIST를 -1이 아닌 0으로 초기화하였음. 그리고, 보드를 입력받을 때, board=='.'인 부분을 dist=-1로 설정한 후
bfs에서방문여부 확인을 위해, dist>0크면 continue;로 하였음.
->이부분은 굳이 바꾸지 않아도 될듯함.(직접 푼 코드와 큰 차이가 없음.) 
->게다가. 굳이 보드가 '.'인 부분을 -1로 처리하지 않아도 정답내는데는 문제없는 걸 확인함.

(필수)###!!! bfs에서, cur(3개 좌표가 들어가있는 tuple형태)을 큐에서 빼낸 후에, 
int curH, int curX, int curY; 를 선언한 후
tie(curH, curX, curY) = cur 를 통해 세 개의 변수로 다시 나눠 받음. //tie함수 : pair,tule을 다시 여러 변수로 나눠 받을 수 있음.
그래서, get<0>(cur)대신, curH변수를 사용하게 하였음.
->코드가 굉장히 간단해지고 가독성이 좋아짐. 꼭 사용할 것.

일단 BFS를 다 돌리고 나중에 E(출구)가 저장된 좌표의 DIST를 반환하여 판단하는 방법이 아니라.(직접 푼 방식)
BFS 진행 중에 방문한 좌표의 BOARD 값이 E라면 isEscape변수를 true로 바꾸어 탈출여부를 판단하고, 현재좌표에서의 거리와 탈출 출력문을 출력함. 
이후, bfs의 while 문에서 큐를 빼기전에 if(isEscape)break;를 통해 반복문 나가게하고,
while(!q.empty()) q.pop;를 통해 큐에 남은 인자를 모두 뺌.
이후, if(!isEscape) 탈출못한 출력문 출력.
코드를 작성하여 마무리함.
-> 이런류의 문제를 처음 접했을 때 내가 푼방식인데, 그 다시 문제의 정답은 현재 직접 푼 방식이라서 오히려 이 방식을 참조하여 풀었었음.
-> 때의 맞추어 성능이 필요하다면, 즉각 탈출하는 방식을, 그렇지 않다면 현재 이 문제를 직접푼 방식을 사용해도 될듯함.
->정답 코드 방식대로 풀 때의 유의점은 : isEscape 변수를 잘 설정해야하고, 탈출 출력문 출력시, dist값이 변경된 후에 출력해도록 해야한다는 것.
                                     꼭!!!!! while문을 탈출 한 후에는 큐가 비었는지 확인 하고 큐의 인자를 모두 제거해야한다는것
                                     while문이 끝난 후에는 탈출여부를 판단하여, 탈출못했을 시 출력문을 출력할지 말지 판단해야 한다는 것.


*/