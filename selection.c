#include<stdio.h>
#include<stdlib.h>

int intake(int *p_level)
{
    for(int i=0; i<15; i++)
        printf("###");
    printf("\n\nPLEASE SELECT A DIFFICULTY LEVEL\n");
    printf("1.  EASY\n2.  MEDIUM\n3.  HARD\n");
    for(int i=0; i<15; i++)
        printf("_ _ ");
    printf("\n\n");
    
    scanf("%d", p_level);
    return 0;
}
int callSwitch(int *p_level)
{
    intake(p_level);
    switch(*p_level)
    {
        case 1 : printf("\nChosen mode is EASY\n");
                    break;
        case 2 : printf("\nChosen mode is MEDIUM\n");
                    break;
        case 3 : printf("\nChosen mode is HARD\n");
                    break;
        default : system("cls");
                    printf("\n!!!!! Please enter a valid level !!!!!\n");
                    printf("\n\t     !!!!!  !!!!!\n");
                    callSwitch(p_level);
                    
    }
}


int main()
{
    int level;
    int *p_level = &level;
    callSwitch(p_level);

    printf("\n");
    for(int i=0; i<15; i++)
        printf("###");
    
}