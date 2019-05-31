#include <18F4620.h>
#include <stdio.h>
#include <stdlib.h>
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, /*NOMCLR,*/ STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)
//Para este nivel no es necesario ingresar ciclos dentro de las interrupciones.

//#define verdadero 1
#define falso 0
#define recibido 1
#define limpio 0
#define MaxBufferRx 30

int flagserial,indicebufferRx=0;
char datoRcv;
char bufferRx[MaxBufferRx];


   #define TX_232        PIN_C6
   #define RX_232        PIN_C7
   #use RS232(BAUD=9600, XMIT=TX_232, BITS=8,PARITY=N, STOP=1,UART1,RCV=RX_232)
   #use fast_io(c)

#int_rda
void isr_rda(void){
   /*datoRcv=getc();
   flagserial=verdadero;
   */
   bufferRx[indicebufferRx]=getc();
   indicebufferRx++;
   flagserial=1;
   if(indicebufferRx>MaxBufferRx){
      indicebufferRx=0;
   }
   
}


void main(void){
set_tris_c(0x80);
enable_interrupts(INT_RDA);
enable_interrupts(GLOBAL);
putc("Ingresa un valor: ");
   while(1){
   swtich(datoRcv){
      case a:
         if(flagserial==verdadero){
            printf("Caracter %c,valor %u,Hexa %x,\r\n",datoRcv,datoRcv+1,datoRcv+1);
            flagserial=falso;
         }
      break;
   }       
  
   /*
         if(flagserial==verdadero){
            printf("Caracter %c,valor %u,Hexa %x,\r\n",datoRcv,datoRcv+1,datoRcv+1);
            flagserial=falso;
         }0
     */       
         if(flagserial==1)
         {
            for(int8 indice_Repetido_bufferRx=0;indice_Repetido_bufferRx<indicebufferRx;indice_Repetido_bufferRx++)
            {
               printf("%c \n",(bufferRx[indice_Repetido_bufferRx]));
            }
            flagserial=limpio;
         }
         
         /*if(flagserial==recibido){
            if(datoRcv==13){
               printf(bufferRx[indicebufferRx]);
            }
         }*/
     /*}*/
}}
