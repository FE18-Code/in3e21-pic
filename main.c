#define i2c_addr_capteur_temp 0x9A

#define adc_VREF (float)5.0
#define adc_max_val 256

#define clear_screen printf("\033\143")

#include <htc.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include "sci.h"
#include "adc.h"
#include "i2c.h"

#define ADC_CHANNEL (unsigned char) 0

/* bits de configuration */
__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_OFF & LVP_OFF & CPD_OFF & WRT_OFF & CP_OFF);

bool loop=true;
unsigned char userIn;
float tension;

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
                    tension=(adc_VREF*(float)read_a2d(ADC_CHANNEL))/((float)adc_max_val);
                    printf("La tension est :  adc=%1.2f !\n",tension);
                    break;

                case '2' :
                    i2c_ReadFrom(i2c_addr_capteur_temp);
                    printf("La T° du capteur est : %d !\n",i2c_GetByte(I2C_MORE));
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

