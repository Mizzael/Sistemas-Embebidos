#include <18F4620.h>
#include <stdio.h>
#include <stdlib.h>
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, /*NOMCLR,*/ STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)

int contadorGlobal1=0;
int contadorGlobal2=0;
int contadorGlobal3=0;
int contadorGlobal4=0;
int contador=1;
int contador2=1;
int contador3=1;
int contador4=1;

   
#INT_TIMER0
void TIMER0(){
   contadorGlobal1++;
   contadorGlobal2++;
   contadorGlobal3++;
   contadorGlobal4++;
   set_timer0(15536);
}

void main(void) {
   set_timer0(15536);
   setup_oscillator(OSC_16MHZ);
   set_tris_a(0x0);
   set_tris_c(0x0);
   set_tris_d(0x0);
   set_tris_b(0x0);
   setup_timer_0(RTCC_INTERNAL | RTCC_DIV_8);
   enable_interrupts(INT_TIMER0);
   enable_interrupts(GLOBAL);
   

   while (TRUE) {
      if(contadorGlobal1 == 2){
         contador*=2;   
         contadorGlobal1 = 0;
      }
   
     if(contador ==256){
         contador=1;
     }
     
     output_a(contador);
     
      if(contadorGlobal2 == 4){
         contador2*=2;   
         contadorGlobal2 = 0;
      }
   
     if(contador2 ==128){
         contador2=1;
     }
     
     output_b(contador2);
     if(contadorGlobal3 == 7){
         contador3*=2;   
         contadorGlobal3 = 0;
      }
   
     if(contador3 ==128){
         contador3=1;
     }
     
     output_c(contador3);
      if(contadorGlobal4 == 10){
         contador4*=2;   
         contadorGlobal4 = 0;
      }
   
     if(contador4 ==128){
         contador4=1;
     }
     output_d(contador4);
   }
}
