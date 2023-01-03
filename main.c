#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void izpisNadstropja(int *trenutnoNadstropje);
void vnos(int *trenutnoNadstropje);
void vnosType(char str[100], int *trenutnoNadstropje);
void konec(int *index);
void izpisPotnikov(int *stPotnikov);
void izstopPotnikov(int *trenutnoNadstropje, int *stPotnikov, int index);

int main(){

    int trenutnnoNadstropje = 0;
    int index = 0;

    //Nakljucno stevilo potnikov 1-9 vkljucno z uporabnikom
    int stPotnikov;
    srand(time(0));
    stPotnikov = (rand() % 9) + 1;

    while (index != 1)
    {
        izpisNadstropja(&trenutnnoNadstropje);
        izpisPotnikov(&stPotnikov);
        vnos(&trenutnnoNadstropje);
        izstopPotnikov(&trenutnnoNadstropje, &stPotnikov, index);
        izpisNadstropja(&trenutnnoNadstropje);
        konec(&index);
    }
    
}

void izpisNadstropja(int *trenutnoNadstropje){
    if(*trenutnoNadstropje == 0){
        printf("Trenutno ste v pritlicju\n");
    }else if (*trenutnoNadstropje == -1)
    {
        printf("Trenutno ste v kleti B3\n");
    }else if (*trenutnoNadstropje == -2)
    {
        printf("Trenutno ste v kleti B2\n");
    }else if (*trenutnoNadstropje == -3)
    {
        printf("Trenutno ste v kleti B1\n");
    }
    
    
    else{
        printf("Trenutno ste na %i. nadstropju\n", *trenutnoNadstropje);
    }
}

void vnos(int *trenutnoNadstropje){
    char input[100];
    printf("Vnesite zazeleno nadstropje (B1, B2, B3, P, 1, 2, 3, 4, 5): ");
    scanf("%s", input);

    

    vnosType(input, trenutnoNadstropje);
    
}

void vnosType(char str[100], int *trenutnoNadstropje){
    int kateri;
    int jeInt = 0, jeChar = 0, jeFloat = 0;
    int intNum = 0;
    char character;
    for (int i = 0; i < strlen(str); i++)
    {
        //Ce je stevilo
        if(((str[i] <= '9'))){
            jeInt++;
        }

        //Ce ni stevilo 
        if(!((str[i] <= '9'))){
            if(str[i] == '.'){
                jeFloat++;
            }else{
                jeChar++;
            }
        }
        
    }
    if ((jeFloat >= 1) || (jeChar > 1) || (jeInt >1))
        {
            printf("Napacen vnos\n");
            vnos(trenutnoNadstropje);

        }else if(jeChar == 1){

            if (jeInt == 1)
            {
                if((str[0] == 'b') || (str[0] == 'B') && (str[1] == '1')){
                    if (str[1] == '1')
                    {
                        *trenutnoNadstropje = -3;
                    }else if (str[1] == '2')
                    {
                        *trenutnoNadstropje = -2;
                    }else if (str[1] == '3')
                    {
                        *trenutnoNadstropje = -1;
                    }else{
                    printf("Napacen vnos\n");
                    vnos(trenutnoNadstropje);
                }
                }else{
                    printf("Napacen vnos\n");
                    vnos(trenutnoNadstropje);
                }
                
            }else{
                character = str[0];

                if((character == 'p') || (character == 'P')){
                    *trenutnoNadstropje = 0;
                }
            
                else{
                    printf("Napacen vnos\n");
                    vnos(trenutnoNadstropje);
                }
            }
        }
        else if (jeInt == 1){

            intNum = atoi(str);

            if ((intNum < 1) || (intNum > 5))
            {
                printf("Napacen vnos\n");
                vnos(trenutnoNadstropje);
            }else{
                *trenutnoNadstropje = intNum;
            }
            
        }
    
}

void konec(int *index){
    char input;
    printf("\n");
    printf("Ali bi zeleli izstopiti? --> (D/N) ");
    scanf("%s", &input);
    if ((input == 'D') || (input == 'd'))
    {
        printf("\n");
        printf("Nasvidenje\n");
        exit(0);
    }else if ((input == 'N') || (input == 'n'))
    {
        *index = 0;
    }else{
        printf("Napacen vnos\n");
        konec(index);
    }
    printf("\n");
    
}

void izpisPotnikov(int *stPotnikov){
    printf("Trenutno stevilo potnikov: %i\n", *stPotnikov);
}

void izstopPotnikov(int *trenutnoNadstropje, int *stPotnikov, int index){
    int st;
    srand(time(0));
    st = (rand() % 2) + 1;

    if (*trenutnoNadstropje != 0)
    {
        if (st == 2)
        {
            
            //Nakljucno nadstropje na kateremu 1 ali vec potnikov izstopi
            int naklNad;
            srand(time(0));
            if (*trenutnoNadstropje < 0)
            {
                naklNad = (rand() % (*trenutnoNadstropje + 1)) + *trenutnoNadstropje;
            }else{
                naklNad = (rand() % (*trenutnoNadstropje + 1));
            }
            printf("\n");

            if (naklNad == -3)
            {
                printf("Ustavili smo se v kleti B1\n");
            }else if (naklNad == -2)
            {
                printf("Ustavili smo se v kleti B2\n");
            }else if (naklNad == -1)
            {
                printf("Ustavili smo se v kleti B3\n");
            }else if (naklNad == 0)
            {
                printf("Ustavili smo se v pritlicju\n");
            }else{
                printf("Ustavili smo se na %i. nadstropju\n", naklNad);
            }

            //Nakljucno stevilo potnikov ki izstopi
            int koliko;
            srand(time(0));
            koliko = (rand() % ((*stPotnikov - 1) - 1 + 1)) + 1;
            *stPotnikov = *stPotnikov - koliko;
            izpisPotnikov(stPotnikov);

            konec(&index);

        }
    }

    
}