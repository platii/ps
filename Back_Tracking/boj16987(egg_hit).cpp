//정답 확인 후. 거의 동일, 몇개만 바뀜.
#include <iostream>
using namespace std;

int n, ans=0, brk=0;
int s[8], w[8];

void func(int cur){
    if(cur==n){ 
        ans=max(ans,brk);
        return;
    }
    if(s[cur]<=0 || brk==n-1){//집은(현재) 계란이 깨졌거나, 계란을 들기전에, 이미 다른 계란이 모두 깨져있다면 다음 계란으로.[if문 통합]
        func(cur+1);
        return; 
    }
    for(int i=0; i<n; i++){
        if(s[i]>0 && cur!=i){ //치려는 계란이 깨지지 않았다면, 중복 방지
            s[cur]-=w[i]; //현재 계란의 내구도 감소
            s[i]-=w[cur]; //맞은 계란의 내구도 감소
            if(s[cur]<=0) brk++;
            if(s[i]<=0) brk++;
            func(cur+1);
            if(s[cur]<=0) brk--; //====>flag를 따로 둘 필요 없이, 갈림길로 돌아갔을 때의 상태에서, 꺠짐여부(<=0 여부)에 따라 brk다시 복구.
            if(s[i]<=0) brk--;   //----->또한, 이렇게 하면, brk를 굳이 func의 매개변수 인자로 두지 않고, 전역변수로 두어도 무방.
            s[cur]+=w[i];        //----->갈림길로 돌아갈 때 brk의 값을 매번 복구 해주기 때문.
            s[i]+=w[cur]; //====>temp변수 따로 선언하는 것보다 역시, 이게 더 간단한 듯함.
        }
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>s[i]>>w[i];
    func(0);
    cout<<ans;
}

/* 직접 푼 코드.
void func(int cur, int brk){
    if(cur==n){ 
        ans=max(ans,brk);
        return;
    }
    if(s[cur]<=0){
        func(cur+1,brk);
        return; //집은(현재) 계란이 깨졌다면 다음 계란으로 넘김.
    }
    if(brk==n-1){//계란을 들기전에, 이미 다른 계란이 모두 깨져있다면 func(cur+1) return;
        func(cur+1,brk);
        return;
    }
    for(int i=0; i<n; i++){
        if(s[i]>0 && cur!=i){ //치려는 계란이 깨지지 않았다면, 중복 방지
            int temp1=s[cur];
            int temp2=s[i];
            bool flag1=false;
            bool flag2=false;
            s[cur]-=w[i]; //현재 계란의 내구도 감소
            s[i]-=w[cur]; //맞은 계란의 내구도 감소
            if(s[cur]<=0) { //brk 증가시켰으면 func 종료 후 다시 돌려줌. ->정답보고 수정 "="추가. 정답.
                brk++;
                flag1=true;
            }
            if(s[i]<=0) {
                brk++;
                flag2=true;
            }
            func(cur+1,brk);
            s[cur]=temp1;
            s[i]=temp2;
            if(flag1) brk--;
            if(flag2) brk--;
        }
    }

}
*/