#include <stdio.h>

int main(){
    int a;
    scanf("%d", &a);
    printf("%c", "FFFFFFDCBAA"[a/10]); //printf함수에서 []안의 값을 인덱스 위치로 하여, 배열(여기선 문자열)안의 인덱스 위치의 값을 반환하는걸로 추측
}