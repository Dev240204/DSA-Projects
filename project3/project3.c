#include <stdio.h>
#include "project3.h"
#include <stdlib.h>

int main() {
    system("cls");
    printf("Hello everyone, welcome to Rappozior Club...\n");
    printf("Please remain calm we are opening soon...\n\n");
    
    Sleep(5000);

    printf("We are now open !!!\n\n");
    printf("Everyone look at your passes and write down your Name, Number and the Priority as mentioned in the pass...");
    // DataInput();

    system("cls");

    printf("\nNow we will arrange you as per your priority");
    Check();

    printf("\nAll members arranged");
    printf("\n\nGet in a queue as per the display\n");
    Display();
return 0;
}