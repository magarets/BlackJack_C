// start.c //
// Dealer pick card algorithm //
// 우선 남은카드를 하나로 모으는 작업 //
#include "start.h"

int DealerCard(char *DECK, int DeckCardCount, int DealerPoint, int PlayerFirstNum) {

    int i, count;
    char sortDeck[53];


    count = 0;
    printf("\n");
    for(i=0; i<DeckCardCount; ++i) {
        if(D.Check[i] == 1) {
            count++;
            sortDeck[count] = DECK[i];
        }
        printf("%c ", DECK[i]);
    }

    /*
    for(i=0; i<count; ++i) {
        printf("%c ", sortDeck[i]);
    }
    */
    printf("\n");
}