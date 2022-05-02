// 덱의 남은 카드리스트중 랜덤 숫자를 리턴 //
// start.c //
#include "start.h"

int choiceCard(){ // 덱의 남은카드를 매개변수로 받음
    int RandNum;
    while(1) {
        RandNum = rand() % SIZE; // 0 ~ 51까지의 난수 생성
        if(D.Check[RandNum] == 1) { // 해당 랜덤값의 카드가 플레이어/딜러에게 나눠지지 않았을 때만 나눠준다.
            D.Check[RandNum] = 0; // 나누어 줬으니 0으로 초기화
            return RandNum;
        }
    }
    printf("\n");
}