//2초-> 8000만번 연산. 
//point!!! -> 정수형변환시 48인 char형 '0'를 빼주면 제값이 나옴(char->int 변환방법)*/
#include <iostream>
#include <queue>
#define x first
#define y second
using namespace std; 
int const MAX=1000;
char board[MAX][MAX]; //Q?) char로 해도 int 인 정수값 1~들 받고 코드 구동하는데 문제 없나? ([n][m]) //실수 int로하면 .못받음 ->char되나? 안됨 ->string
//int s_num[MAX][MAX]; //각 위치에서의 남은 s[i]값 들 저장
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int s[10]; // s_i저장 (int는 2^31밖(32bit, 1bit는 부호비트) 에 저장못함. -> 확인해보니 10^10까지는 커버가능)
int n,m,p;
queue<pair<int,int>> cas1[10], cas2[10]; //플레이어 별로 초기 위치 저장할 큐 생성. (p플레이어의 수를 편하게 맞추기위해+1)

bool all_q_empty(){ //2p개의 큐가 전부 비었는지 체크.
    bool flag=true;
    for(int i=1; i<=p; i++){
        if(!cas1[i].empty()||!cas2[i].empty()){; //큐 cas가 main함수에 선언된 지역변수임, main함수 밖이므로 cas를 불러올 수 없음, cas를 어떻게 놓아야? ->cas를 전역으로 선언
            flag=false;
            break;
        }
    }
    return flag;
}

//큐, 스택, 배열등의 자료구조에 ---> (1~9)(그 각 플레이어의 수에 {i,j}들을 넣는다.)
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>p;
    int num_cas[p+1]={0,}; //플레이어 별 성의 개수 저장할 배열 생성
    for(int i=1; i<=p; i++) cin>>s[i];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) {
            cin>>board[i][j];
            if(board[i][j]!='.'&& board[i][j]!='#') {
                //s_num[i][j]=s[board[i][j]-'0'];//s_num에, 그 좌표에서의 보드값(플레이어값)에 해당하는 s_i값을 저장(초기 s_i지정)
                cas1[board[i][j]-'0'].push({i,j}); 
                /*!!!!!!!!!!!!오류, board[i][j]의 값은 char형값임 ->즉, 정수형으로변환하면 49라는 이야기(그래서 세그먼테이션 폴트 오류난것)
                따라서 정수형변환시 48인 char형 '0'를 빼주면 제값이 나옴(char->int 변환방법)*/
                /*각 플레이어의 성의 초기 위치들 저장(처음엔배열쓰려했음)
                (더 가독성좋은 코드는? 배열 안에{i,j}를 저장가능한 배열(자료구조라던지))
                ->각 플레이어의 위치값을 저장하는 큐를p+1개 생성하여 해결.*/
            }
        }
    }//입력모두 받음(플레이어 스캔 끝남)
    
    //s_i 고민해봄. (bfs용 큐를 덱으로 생성하고, s[i]남은 횟수만큼 인자를 덱의 맨앞에 푸쉬하여 해결.)

    //bfs
    
    while(!all_q_empty()){
        for(int player=1; player<=p; player++){//1~p까지 모두 bfs 돌림
            int s_i=0; //bfs를 시행한 횟수(한칸씩 이동한 횟수) 초기값. 
            //ㄴ+)변수명 s 로 하면 안됨.-> int로써의 s, s[i]의 첫항의 주소를 나타내는 s로//모호함 발생
            while(s_i<s[player]  && !(cas1[player].empty() && cas2[player].empty())){ //이동횟수가 남았다면,+(10의9승번 진행하지 않기위해, 두개의 큐 모두 빈 경우 탈출 )
                s_i++; //이동한 횟수 +1;
                //q1, q2중 비어있지 않은 것을 cas(bfs를돌릴 큐)로 설정
                //-> queue* 포인터가 있지 않을까하고, 적용해봤지만 불가능, 그럼:1,2를 구분한 뒤에 if만 사용해서 이를 구분해야함. 
                //-> queue형포인터를 사용하는 방법을 찾지 못했음. 그냥, bfs 함수를 따로 설정하는 것으로 해결.
                //->재재수정) 생각해보니, 그냥 큐가 아니라 queue<pair<int,int>>였음. 다시 수정->됨.
                //(cas1일때의 bfs, cas2일때의 bfs)

                queue<pair<int,int>> *cas;
                bool flag1=false, flag2=false; //어떤걸로 bfs를 돌릴지
                if(!cas1[player].empty()) {
                    flag1=true;
                    cas = &cas1[player];
                    //cout<<"초기 flag1 안빔: "<<'\n'; (test)
                }
                else if(!cas2[player].empty()){
                    flag2=true;
                    cas = &cas2[player];
                    //cout<<"초기 flag2 안빔: "<<'\n'; (test)
                }
                else  /*둘다 비어있다면*/ continue;
                while(!(cas->empty())){ //해당 큐가 빌때까지 bfs 실행 
                    auto cur=cas->front(); cas->pop();
                    //cout<<cur.x<<' '<<cur.y<<' '<<"board : "<<board[cur.x][cur.y]<<'\n';////test
                    for(int i=0; i<4; i++){
                        int nx=cur.x+dx[i];
                        int ny=cur.y+dy[i];
                        if(nx<0||nx>=n||ny<0||ny>=m) continue; //외곽체크
                        if(board[nx][ny]!='.')continue; // 보드 벽, 성 체크 (중복체크도 겸하게 되는 것)
                        /*
                        (이전의 시도 : dq를 사용하던 방식)
                        if(s_num[cur.x][cur.y]>1) { // 0일때 원하는동작x, 1로 바꿔봄
                            q.push({nx,ny}); //s_i 횟수가 남아있으면 디큐의 앞에 푸쉬. <-----안됨.
                            s_num[nx][ny]=s_num[cur.x][cur.y]-1; //갱신한 위치의 s_i값을 꺼낸 인자의 s_i값 -1로 설정
                        }
                        */
                        if(flag1) {
                            cas2[player].push({nx,ny});
                            //cout<<"test : flag1 true"<<'\n';(test)
                        }
                        else if(flag2) {
                            cas1[player].push({nx,ny});
                            //cout<<"test : flag1 true"<<'\n';(test)
                        }

                        board[nx][ny]=board[cur.x][cur.y]; //이전 보드의 값을 .자리에 갱신.
                    }
                }
            }
        }
        //cout<<"all_q_empty(): "<<all_q_empty()<<'\n'; //test.............
    }
    //전체 보드의 각 플레이어 별 성의 개수 체크.(배열에 저장.) 
    /*(또는 bfs용디큐에서 인자를 꺼낼때마다 그 좌표(cur.x,cur.y)의 보드값을 체크하여 플레이어별 성의 개수 를 늘려주면됨.)
    ->단 이경우, 맨처음 각 플레이어의 보드에서의 성의 위치를 탐색할 때도 성의 개수를 업데이트해주어야함.*/

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            if(board[i][j]!='.'&& board[i][j]!='#'){//해당 위치의 보드가 숫자라면.
                num_cas[board[i][j]-'0']++; //char->int 변환 
            }
        }
    //출력.
    for(int i=1; i<=p; i++){
        cout<<num_cas[i]<<' ';
    }
    /*
    //test 보드출력
    cout<<'\n'<<"board"<<'\n';
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<board[i][j]<<' ';
        }
        cout<<'\n';
    }
    //
    ///test s_num출력
    cout<<'\n'<<"s_num"<<'\n';
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<s_num[i][j]<<' ';
        }
        cout<<'\n';
    }
    */
}

/*입력 받고, (격자판 크기 행개수(n), 열개수(m), 플레이어수p)
(s1, s2~) for(p~)
보드에 차례로 받기(플레이어의 성 1~p, 비어있는 것., 벽#)
출력->가지고있는 성의 수 차례대로 (플레이어 최대 9), n,m 최대1000, si 최대 10의 9승



bfs진행(큐 생성, 비즈에 맨처음값 1로 초기화(처음 시작 위치), 큐에 현재 값 푸쉬, 
while(큐가 빌때까지(!q.empty()))
for(int i=0; i<4; i++) 4방향탐색(dx,dy){방문여부체크, 벽여부 체크, 1-2여부 체크 등 하고, 조건만족한 원소를 큐에 푸쉬, 비즈 업데이트}
+(범위체크)

*/

/* 
알게된 것 (char형 -> int변환 -'0'을해준다.)

시행착오(s_i를 적용하는 방식)
try 1) s_num배열을 통해, 그 지점의 성의 주인의 초기 s_i값을 저장하게하고
       for4방향 탐색 돌고 nx,ny로 거쳐나올때, cur.x,cur.y의 s_num값이 1보다 크면 
       dq의 앞에 push하도록 하였음.
       -> 실패, 이경우, 초기 플레이어의 성이 두개 이상이면, 
       (이해를 위해 1번플레이어의 성이2개이고 그둘을 a성 b성이라하면) 맨처음 a번성이 bfs를 돌고 그것의 <nx,ny> pair가 b번성보다 앞에 와서
       그 성이 또 bfs를 돌게됨. 순서가 엇나감.
       -->푸쉬할때, 1플레이어의 이전것들 보다는 뒤로, 2플레이어것보다는 앞에 놓이도록 해야함.
       ->생각해본것, dq.(배열처럼 몇번째 자리에 놓이게 할 수 있는 함수) 사용하기. ->but 큐 안에 든 인자의 개수 수시로 바뀜 그걸 다 계산하는건 힘듦.

    2)초기에 만들어둔, 플레이어별 초기 좌표 저장용 큐를 활용하기  
      ㅁ 맨처음 1플레이어의 큐에서 s_i번만큼 bfs를 돌림. 이후 또 2플레이어의 큐에서 동일한 작업을 수행. -> p플레이어까지 반복.
        while()
        auto cur=q.front(); q.pop();
        cout<<cur.x<<' '<<cur.y<<' '<<"board : "<<board[cur.x][cur.y]<<'\n';////test
        for(int i=0; i<4; i++){
            int nx=cur.x+dx[i];
            int ny=cur.y+dy[i];
            if(nx<0||nx>=n||ny<0||ny>=m) continue; //외곽체크
            if(board[nx][ny]!='.')continue; // 보드 벽, 성 체크 (중복체크도 겸하게 되는 것)
            /*
            if(s_num[cur.x][cur.y]>1) { // 0일때 원하는동작x, 1로 바꿔봄
                q.push({nx,ny}); //s_i 횟수가 남아있으면 디큐의 앞에 푸쉬. <-----안됨.
                s_num[nx][ny]=s_num[cur.x][cur.y]-1; //갱신한 위치의 s_i값을 꺼낸 인자의 s_i값 -1로 설정.
            }
            else q.push({nx,ny});
            board[nx][ny]=board[cur.x][cur.y]; //이전 보드의 값을 .자리에 갱신.
        }
      
      ㅁ 다시, 1플레이어의 큐로 돌아가서 위의 작업을 반복.
      ㅁ 종결조건 : 모든 큐가 다 비면 bfs 마침

      (p개의 성의 대하여, p개의 큐를 각 2개씩 (2p개)생성(p_1, p_2)
      각 성의 초기 좌표들을 각 큐 p_1에 푸쉬,
      우선 처음 bfs는 p_1에서 진행하는데, 이때, p_1에서 if 필터를 통과한 인자들은
      p_1이 아닌 p_2로 푸쉬됨.
      bfs를 진행하며, q_1(첫번째 큐)이 비면 첫 bfs종료.
      이후 -> s_i가 남아있는지 확인 s_i가 남아있다면. q_2에서 bfs를 진행하고 이때, 마찬가지로 필팅된 인자들은 q_1에 푸쉬함
      s_i를 체크하며 이를 반복.
      s_i횟수가 0이면 다음 성의 큐로 넘어감.
      (매 bfs를돌릴때, 주의점 : 스위치하여, q_2에 인자가 남아있으면, q_1이 아닌 q_2로 bfs시작하도록 해야함.)
      ->스위치 구현? : 매 bfs를 돌리기 전, 큐에 인자가 있는 것만 돌리도록 함.

      모든 2p개의 큐가 비어있다면 종료.(즉, 큰 큐로 하나, 작은큐로 하나 : 이중반복문.)
      
      ->시간초과. 
      잘 생각해보니, s_i의 범위가 10의 9승(10억 : 2초의 연산 최대 횟수를 뛰어넘음. 이걸 잘 조정해줘야한다.)
        
        while(s_i<s[player])을
        while(s_i<s[player]  && !(cas1[player].empty() && cas2[player].empty()))로 변경하여
        해결!!!


    3)우선순위 큐?
*/


//bfs의 구조및 문제 분석.
/*

queue생성
큐에 시작위치 push
while(!q.empty())
->{4방향 탐색, 4방향 중 거를것 거르고 나머지 통과, 통과 된것을 보드 혹은 vis처리 후 큐에 삽입 }
큐가 전부 빌때까지 반복

->일반적인 bfs와 이 문제와의 차이점?
=>s_i를 고려해야한다는 것
(일반적인 bfs가 큐가 빌때까지 한번 돌면 끝인것과는 다르게)
(s_i횟수만큼, 단계별로 bfs를 여러번 진행하여야함.)
어떻게 할것인가? -> 위의 try에 기록함.

*/