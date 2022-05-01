// start.c //
#include "start.h"

int printGame(int DeckCardCount, int DealerPoint, int PlayerPoint){
    int i;

    printf("----print----\n");

    // 딜러 출력 //
    printf("Dealer : ");
    printf("%c ", D.Dealer[0]);
    for(i=1; i<DealerPoint; ++i)
        printf("? ");
    printf("\n");
    // ... //

    // 플레이어 출력 //
    printf("Player : ");
    for(i=0; i<PlayerPoint; ++i)
        printf("%c ", D.Player[i]);
    // ... //
}
