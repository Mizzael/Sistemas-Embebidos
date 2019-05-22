#include <18F4620.h>
#include <stdio.h>
#include <stdlib.h>
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, /*NOMCLR,*/ STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)

#define verdadero 1
#define falso 0
#define recibido 1
#define limpio 0

#define MaxBufferRx 30

int flagserial,indicebufferRx=0;
char datoRcv;
char bufferRx[MaxBufferRx];

#define __DEBUG_SERIAL__
#ifdef __DEBUG_SERIAL__
   #define TX_232        PIN_C6
   #define RX_232        PIN_C7
   #use RS232(BAUD=9600, XMIT=TX_232, BITS=8,PARITY=N, STOP=1,UART1,RCV=RX_232)
   #use fast_io(c)
#endif

#int_rda
void isr_rda(void){
   datoRcv=getc();
   flagserial=verdadero;
   
   bufferRx[indicebufferRx]=getc();
   indicebufferRx++;
//   flagserial=Recibido;
   if(indicebufferRx>MaxBufferRx){
      indicebufferRx=0;
   }
   
}


void main(void){
enable_interrupts(GLOBAL|INT_RDA);
   putc(datoRcv);
   while(1){
   datoRcv=getc();
      if(flagserial==verdadero){
         printf("Caracter %c,valor %u,Hexa %x,\r\n",datoRcv+1,datoRcv+1,datoRcv+1);
         flagserial=falso;
      }
         
      if(flagserial==recibido){
         for(int8 indicebufferRx=0;indicebufferRx<indicebufferRx;indicebufferRx++){
            putc(bufferRx[indicebufferRx]);
         }
         flagserial=limpio;
      }
      }  
   
}
