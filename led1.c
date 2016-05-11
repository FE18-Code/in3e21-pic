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
const char *text="1234567890";

void putch(char c);

void main(){

    if(sci_Init(9600,SCI_EIGHT)==true){
        /* pb */
    }else{
        
        printf("Hello_world (%s) !\n",text);
        
        for(Attente){
          /* dodo */  
        }
    }/* sci_init() */
    
}/* main */

void putch(char c){
    sci_PutByte(c);
}