#define Attente ;;
#include <htc.h>

/* bits de configuration */
__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_OFF & LVP_OFF & CPD_OFF & WRT_OFF & CP_OFF);

unsigned char Compteur;
void interrupt Timer_Overflow();

void main(){
    Compteur=0;
    TRISB=0xFE;/* sens du port */
    RB0=0;/* bit 0 à 0 */
    OPTION_REG=0x7;
    TMR0=0;
    
    /* interrupts */
    INTCON=0X20;
    GIE=1;
    
    for(Attente){
      /* dodo */  
    }
    
}/* main */

void interrupt Timer_Overflow(){
    if(T0IF){/* test flag timer 0 */
        T0IF=0;/* reset du flag */
        Compteur++;
        if(Compteur==4){
            Compteur=0;
            RB0=~RB0;/* complémenter RB0 */
            TMR0=0;
        }
    }
}