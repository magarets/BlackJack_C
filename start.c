#include "start.h"

int max(x, y) {
    if(x>y) return 1;
    else return 0;
}

int ExitGame() {
    int dCardSum;
    int pCardSum;

    dCardSum = SumCard(D.Dealer, Point.Dealer);
    pCardSum = SumCard(D.Player, Point.Player);


    printf("---최종 점수---\n");
    printf("딜러 : %d\n", dCardSum);
    printf("플레이어 : %d\n", pCardSum);
    if(max(dCardSum, pCardSum)) printf("딜러 승!");
    else printf("플레이어 승!");
    return 1;

}

int Over21Check() {
    int dCardSum;
    int pCardSum;

    dCardSum = SumCard(D.Dealer, Point.Dealer);
    pCardSum = SumCard(D.Player, Point.Player);
    if(pCardSum > 21) return 1;
    if(dCardSum > 21) return 2;
    else return 0;
}

void start(char *DECK){

    srand((unsigned)time(NULL));

    int sum_d = 0, sum_p = 0;
    int Round = 1, round_D = 1, round_P = 1, is_Stand = 0, result = 0;
    int DeckCardCount; // 지역변수. 덱의 남은 카드의 갯수를 나타냄.

    // 카드 체크배열 초기화 //
    for(int i=0; i<SIZE; ++i){
        D.Check[i] = 1; //해당 카드가 사용됬는지 확인
    }

    DeckCardCount = SIZE; // 덱에 남은 카드갯수

    // 게임시작 //
    Point.Dealer = 0; // 딜러의 index 위치
    Point.Player = 0; // 플레이어의 index 위치
    // 맨처음 카드 2장 드로우 //
    for(int i=0; i<2; ++i) {
        D.Dealer[Point.Dealer++] = DECK[choiceCard(--DeckCardCount)]; // 덱의 남은카드개수를 인자값으로 choiceCard()를 호출-
        D.Player[Point.Player++] = DECK[choiceCard(--DeckCardCount)]; // 랜덤번호 배열의 인덱스값에 있는 DECK의 값을 배열로 넘겨줌
    } // index 0, 1에 카드 2장 저
    // ... //

    /*          여기까지가 맨 처음 게임세팅             */

    /*      이제부터 한장씩 드로우 or 스테이 정하기       */

    int isDrawOrStay; // 플레이어의 선택을 저장하는 변수
    int isDealerPick; // 딜러의 선택을 저장하는 변수
    int isPlayerPick;
    int checkDealerPick = 0; // 한번만 저장. 딜러가 선택을 하지 않았다면 플레이어가 선택하지 않을때까지 플레이어는 선택가능
    isDealerPick = 0;
    isPlayerPick = 0;

    while(1) {
    printGame(DeckCardCount, Point.Dealer, Point.Player); // 게임화면 출력
    isDrawOrStay = 0;

        if(Over21Check() == 1) {
            printf("\nPlayer Deck OverFlow 21!");
            printf("\n딜러 승리!");
        }
        if(Over21Check() == 2) {
            printf("\nDealer Deck OverFlow 21!");
            printf("\n플레이어 승리!");
        }


        // 플레이어 선택 //
        if(isPlayerPick == 0) {
            while (1) {
                printf("\n[Player] Draw(1) or Stay(2) ");
                scanf("%d", &isDrawOrStay);

                if (isDrawOrStay == 1) {
                    printf("[플레이어 카드 드로우]\n");
                    D.Player[Point.Player++] = DECK[choiceCard(--DeckCardCount)];
                    break;
                }
                if (isDrawOrStay == 2) {
                    isPlayerPick = 1;
                    break;
                }
            }
        }
        else if(checkDealerPick == 1) {
            if(ExitGame()) break;
        }
        // 딜러 선택 //
        // 직접 선택이 아닌, 인공지능 알고리즘 구현 //

        isDealerPick = 0; // 초기화
        if(checkDealerPick == 0) // 딜러가 카드를 안받는다 하기 전까지
            isDealerPick = DealerCard(DECK, DeckCardCount, Point.Dealer, D.Player[0]); // 딜러가 카드를 선택하는 알고리즘

        if(isDealerPick == 1) {
                printf("[딜러 카드 드로우]\n");
                D.Dealer[Point.Dealer++] = DECK[choiceCard(--DeckCardCount)];
                continue;
        }
        else {
            checkDealerPick = 1; // 한번만 체크하는 변수. 딜러가 카드를 안받는다하면 다음부터는 카드를 받을 수 없음.
            continue;
        }

    }// 게임 무한루프 종료
}