#define Attente ;;
#define clear_screen printf("\033\143")

#include <htc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include "sci.h"
#include "adc.h"

#define ADC_CHANNEL (unsigned char) 0

/* bits de configuration */
__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_OFF & LVP_OFF & CPD_OFF & WRT_OFF & CP_OFF);

unsigned char i;
bool loop=true;
unsigned char userIn;
const char *text="000000000000000";

void putch(char c);
char getch();

void main(){

    init_a2d();/* init adc */
    
    if(sci_Init(9600,SCI_EIGHT)==true){/* init usart */
        /* pb */
    }else{
        
        while(loop==true){                  
            userIn=getch();
            
            clear_screen;
            printf("veuillez faire votre choix:  \n Tapez 1 pour la tension \n Tapez 2 pour la T° \n");
            
            switch(userIn){

                case '1' :
                    printf("La tension est :  adc=%u !\n",read_a2d(ADC_CHANNEL));
                    break;

                case '2' :
                    printf("La T° du capteur est :  adc=%u !\n",read_a2d(ADC_CHANNEL));
                    break;

                case '3' :
                    printf("Quitter\n");
                    loop=false;
                    break;

                default :
                    printf("erreur, veuillez faire votre choix:  \n Tapez 1 pour la tension \n Tapez 2 pour la T° \n");
                    break;
            }
        }
    }/* sci_init() */
    
}/* main */

void putch(char c){
    sci_PutByte(c);
}

char getch(){
    return sci_GetByte();
}

