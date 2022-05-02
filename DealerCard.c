// start.c //
// Dealer pick card algorithm //
// 우선 남은카드를 하나로 모으는 작업 //
#include "start.h"
double SumCard(char *sortDeck, int count) {
    int i;
    int CardSum;

    CardSum = 0;
    for(i=0; i<count; ++i) { // 덱의 남은 카드의 합을 구해서 리턴
        if(sortDeck[i] == '0') CardSum += 10;
        if(sortDeck[i] == '1') CardSum += 1;
        if(sortDeck[i] == '2') CardSum += 2;
        if(sortDeck[i] == '3') CardSum += 3;
        if(sortDeck[i] == '4') CardSum += 4;
        if(sortDeck[i] == '5') CardSum += 5;
        if(sortDeck[i] == '6') CardSum += 6;
        if(sortDeck[i] == '7') CardSum += 7;
        if(sortDeck[i] == '8') CardSum += 8;
        if(sortDeck[i] == '9') CardSum += 9;
        if(sortDeck[i] == 'K') CardSum += 10;
        if(sortDeck[i] == 'Q') CardSum += 10;
        if(sortDeck[i] == 'J') CardSum += 10;
        if(sortDeck[i] == 'A') CardSum += 11;
    }
    //printf("\n총합: %d, 갯수: %d\n", CardSum, count);

    return CardSum;
}

int DealerCard(char *DECK, int DeckCardCount, int DealerPoint, int PlayerFirstNum) {

    int i, count;
    int CardSum = 0;
    int DealerSum = 0;
    char sortDeck[53];

    memset(sortDeck, 0, sizeof(sortDeck[0])); // 배열 초기화
    count = 0; // 카운트 초기화
    DealerSum = 0;

    printf("\n");
    for(i=0; i<SIZE; ++i) {
        if(D.Check[i] == 1) {
            sortDeck[count] = DECK[i];
            count++;
        }
    }

    for(i=0; i<Point.Dealer; ++i) {
        DealerSum += D.Dealer[i];
    }

    int TotalSum_Dealer = 0;
    int TotalSum_Player = 0;
    double Everage_Deck = 0;

    Everage_Deck = SumCard(sortDeck, count) / (double)count; // 덱의 평균
    TotalSum_Dealer = SumCard(D.Dealer, Point.Dealer); // 딜러의 카드 합
    TotalSum_Player = SumCard(D.Player, Point.Player); // 플레이어의 카드 합

    if( (21 - TotalSum_Dealer) > Everage_Deck ){ // 딜러가 카드를 뽑았을 때 21을 넘지않을 확률
        return 1;
    }
    else {
        printf("[딜러는 카드를 뽑지 않았습니다.]\n");
        return 0;
    }
    //if( (TotalSum_Dealer + Everage_Deck) > TotalSum_Player ) // 딜러가 카드를 한장 뽑았을때 플레이어의 숫자보다 높을 확률


}
// 덱의 남은카드를 다 더해서 나오는 평균값을 리턴해줌 //