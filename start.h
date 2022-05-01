#ifndef BLACKJACK_ASSIGNMENT_START_H
#define BLACKJACK_ASSIGNMENT_START_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define SIZE 52


struct DECK {

    int Check[53]; // 해당카드가 사용됬는지 확인하기위한 배
    char Dealer[20]; // 딜러의 카드리스트
    char Player[20]; // 플레이어의 카드리스트

}D;

struct indexpointer {
    int Dealer;
    int Player;
}Point;

void start(char *DECK);
int choiceCard(int Num);
int printGame(int DeckCardCount, int DealerPoint, int PlayerPoint);
int DealerCard(char *DECK, int DeckCardCount, int DealerPoint, int PlayerFirstNum);



#endif //BLACKJACK_ASSIGNMENT_START_H
