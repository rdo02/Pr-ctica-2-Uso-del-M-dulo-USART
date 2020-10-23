#include <xc.h>
#include<stdio.h>
#define _XTAL_FREQ 8000000

#pragma config FOSC = INTRC_CLKOUT          //COnfiguracion de los fuses
#pragma config WDTE = OFF       
#pragma config PWRTE = ON       
#pragma config MCLRE = ON       
#pragma config CP = OFF         
#pragma config CPD = OFF        
#pragma config IESO = ON        
#pragma config FCMEN = ON       
#pragma config LVP = OFF        


#pragma config BOR4V = BOR40V   
#pragma config WRT = OFF      
unsigned char input;
 
void main(void) {                     
    OSCCONbits.IRCF=0b1110;                        //Configuracion de los resgitros necesarios
    OSCCONbits.SCS=0b00;
    ANSEL=0B00000000;
    ANSELH=0B00000000;
    TRISCbits.TRISC6=0;
    TRISCbits.TRISC7=1;
    INTCON=0B00000000;
    PIE1=0b00000000;
    TXSTA=0b00100110;                             
    BAUDCTL=0b00000000;
    RCSTA=0b10010000;
    SPBRG=12;
    while(1){                               //ciclo de permanencia 
   if(PIR1bits.RCIF==1){
            input=RCREG;                  //Variable input = RCRFG
            while(TXSTAbits.TRMT==0);            //Ciclo de monitoreo
            TXREG=input;
            __delay_ms(10);                      //Delay
        }        
    }
    return;
}