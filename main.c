#include "start.h"

char DECK[52] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K'}; //스(0~12)다(13~25)하(26~38)클(39~51)

void printMain() {

    printf("┏┓ ┏┓                  \n");
    printf("┃┃ ┃┃      ┏┓        ┏┓    \n");
    printf("┃┗━┫┃┏━━┳━━┫┃┏┳┳━━┳━━┫┃┏┓\n");
    printf("┃┏┓┃┃┃┏┓┃┏━┫┗┛┃┃┏┓┃┏━┫┗┛┛\n");
    printf("┃┗┛┃┗┫┏┓┃┗━┫┏┓┃┃┏┓┃┗━┫┏┓┓\n");
    printf("┗━━┻━┻┛┗┻━━┻┛┗┫┣┛┗┻━━┻┛┗┛\n");
    printf("             ┏┛┃         \n");
    printf("             ┗━┛         \n");
    printf(" 1. Start \n");
    printf(" 2. End   \n");
    printf(" input Number : ");
}

int main() {
    char n;

    printMain();

    while(1){
        scanf("%c", &n);
        if (n == '1') {
            start(DECK);
        }
        if (n == '2') {
            return 0;
        }
        else {
            printf("try again!\n");
        }
    }
    printf("end");
}