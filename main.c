#define Attente ;;
#define clear_screen printf("\033\143")

#include <htc.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include "sci.h"
#include "adc.h"

#define ADC_CHANNEL (unsigned char) 0

/* bits de configuration */
__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_OFF & LVP_OFF & CPD_OFF & WRT_OFF & CP_OFF);

unsigned char i;
const char *text="0000";

void putch(char c);

void main(){

    init_a2d();/* init adc */
    
    if(sci_Init(9600,SCI_EIGHT)==true){/* init usart */
        /* pb */
    }else{
        
        clear_screen;
        printf("Hello_world (%s) adc=%uc !\n",text,read_a2d(ADC_CHANNEL));
        
        for(Attente){
          /* dodo */  
        }
    }/* sci_init() */
    
}/* main */

void putch(char c){
    sci_PutByte(c);
}