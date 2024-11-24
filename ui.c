#include<stdio.h>
#include<stdlib.h>  //for system("cls")

void clearScreen() {
#ifdef _WIN32
    system("cls");  // For Windows
#else
    system("clear"); // For Linux/Mac/WSL
#endif
}


int main()
{
    for(int i=0; i<7; i++)
        printf("__ _ __ ");

    printf("\n        _     _     _     _     _     _     _  \n");
    printf("       / \\   / \\   / \\   / \\   / \\   / \\   / \\ \n");
    printf("      ( H ) ( A ) ( N ) ( G ) ( M ) ( A ) ( N )\n");
    printf("       \\_/   \\_/   \\_/   \\_/   \\_/   \\_/   \\_/  \n");
    
    printf("\n         !!! WELCOME TO THE HANGMAN GAME !!!        \n\n");
    printf("BY : RISHU   ---   MOHIT   ---    AYUSH   ---   KARTIK\n");
    //printf("     BB1032  ---   CH1023  ---    CH1088  ---   CI8177\n");
    for(int i=0; i<7; i++)
        printf("__ _ __ ");
    printf("\n\nPress ENTER key to continue .......");
    getchar();
    clearScreen();
}