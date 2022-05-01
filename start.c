#include "start.h"

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
    // 맨처음 카드 2장 드로우 //
    for(int i=0; i<2; ++i) {
        D.Dealer[i] = DECK[choiceCard(DeckCardCount)]; // 덱의 남은카드개수를 인자값으로 choiceCard()를 호출
        DeckCardCount--; // 한개의 카드를 나누어주었기때문에 최종 덱카드 갯수 1 감소
        D.Player[i] = DECK[choiceCard(DeckCardCount)]; // 랜덤번호 배열의 인덱스값에 있는 DECK의 값을 배열로 넘겨줌
        DeckCardCount--;
    } // index 0, 1에 카드 2장 저
    // ... //

    /*          여기까지가 맨 처음 게임세팅             */

    /*      이제부터 한장씩 드로우 or 스테이 정하기       */
    Point.Dealer = 2; // 딜러의 index 위치
    Point.Player = 2; // 플레이어의 index 위치
    int isDrawOrStay;

    while(1) {
        printGame(DeckCardCount, Point.Dealer, Point.Player); // 게임화면 출력
        isDrawOrStay = 0;

        // 플레이어 선택 //
        while (isDrawOrStay != 1 || isDrawOrStay != 2) {
            printf("Draw(1) or Stay(2) ");
            scanf("%d", &isDrawOrStay);

            if (isDrawOrStay == 1) {
                Point.Player++; // 플레이어의 인덱스 포인터 1 증가
                D.Player[Point.Player] = DECK[choiceCard(DeckCardCount)];
            }
            else break;
        }

        // 딜러 선택 //
        while (isDrawOrStay != 1 || isDrawOrStay != 2) {
            printf("Draw(1) or Stay(2) ");
            scanf("%d", &isDrawOrStay);

            if (isDrawOrStay == 1) {
                Point.Dealer++; // 딜러의 인덱스 포인터 1 증가
                D.Dealer[i] = DECK[choiceCard(DeckCardCount)];
            }
            else break;
        }

        printGame()

    }// 게임 무한루프 종료
}