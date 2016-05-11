#define Attente ;;
#include <htc.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include "sci.h"

/* bits de configuration */
__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_OFF & LVP_OFF & CPD_OFF & WRT_OFF & CP_OFF);

unsigned char i;
void interrupt Timer_Overflow();

const char *text="1234567890";

void main(){

    if(sci_Init(9600,SCI_EIGHT)==true){
        /* pb */
    }else{  
        for(i=0;i<strlen(text);i++){
            sci_PutByte(text[i]);
        }

        for(Attente){
          /* dodo */  
        }
    }/* sci_init() */
    
}/* main */
