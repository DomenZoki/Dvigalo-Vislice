#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int str_dolzina(char str[]);
void izpis(char beseda[], int dolzina);
void update(int stPoskusov, char napacne[]); 
void vnos(int *stPoskusov, char napacne[], char beseda[], int dolzinaBesede, char *vnesenaCrka, int *napacenVnos);

int main(){

    printf("\n");
    printf("VISLICE\n");
    printf("\n");

    int steviloPoskusov = 9;

    char besede[10][10] = {"sova", "radio", "zgodovina", "drevo", "bizon", "nafta", "navada", "premog", "cvet", "orel"};

    char napacne[10];

    //Nakljucna beseda
    int index;
    srand(time(NULL));
    index = rand() % 10;

    int dolzina = str_dolzina(besede[index]);
    printf("Dolzina besede: %i\n", dolzina);


    char beseda[dolzina];
    for (int i = 0; i < dolzina; i++)
    {
        beseda[i] = '_';
    }

    izpis(beseda, dolzina);

    int x;
    int napacenVnos = 0;

    while(x != 0){

        x = 0;

        char vnesenaCrka;
        vnos(&steviloPoskusov, napacne, besede[index], dolzina, &vnesenaCrka, &napacenVnos);

        update(steviloPoskusov, napacne);

        for (int i = 0; i < dolzina; i++)
        {
            if (besede[index][i] == vnesenaCrka){
                beseda[i] = vnesenaCrka;
            }
        }

        izpis(beseda, dolzina);
        
        while((getchar()) != '\n');

        //Preverimo, ce je uporabnik izpolnil vsa polja
        for (int i = 0; i < dolzina; i++)
        {
            if(beseda[i] == '_'){
                x++;
            }
        }
        if (x == 0)
        {
            printf("\nCestitke\n");
        }else if (steviloPoskusov == 0) 
        {
            printf("\nZgubili ste, beseda je bila: %s\n", besede[index]);
            x = 0;
        }
        
        
        
    }
    

}

int str_dolzina(char str[]) {
    int count; 
    
    for (count = 0; str[count] != '\0'; ++count);
    
    return count; 
}

void izpis(char beseda[], int dolzina){
    printf("\n");


    for (int i = 0; i < dolzina; i++)
    {
        
        printf("%c ", beseda[i]);
        
    }
    printf("\n");
    printf("\n");
    
}

void update(int stPoskusov, char napacne[]){
    printf("\n");
    

    printf("Stevilo poskusov: %i\n", stPoskusov);
    printf("Napacne crke: ");

    int velikostPolja = str_dolzina(napacne);

    for (int i = 0; i < velikostPolja; i++)
    {
        printf("%c ", napacne[i]);
    }
    printf("\n");

    printf("\n");
}

void vnos(int *stPoskusov, char napacne[], char beseda[], int dolzinaBesede, char *vnesenaCrka, int *napacenVnos){

    char input;

    printf("Vpisite crko: ");
    scanf("%c", &input);

    if (isalpha(input) == 0)
    {
        printf("\nNapacen vnos\n");
        *napacenVnos = 1;
    }else{
    
    

    int pravilno = 0;

    for (int i = 0; i < dolzinaBesede; i++)
    {

        if (beseda[i] == input)
        {
            pravilno++;
            *vnesenaCrka = input;
        }
               
    }

    if (pravilno == 0)
    {
        printf("Napacno\n");
        strncat(napacne, &input, 1);
        *stPoskusov = *stPoskusov - 1;
    }else{
        printf("Pravilno\n");
    }
    
    printf("\n");
    }
}
