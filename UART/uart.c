#include<reg51.h>

void uart_init();
void uart_txchar(char);
void uart_sendstring(char *str);

void uart_init()
{
	TMOD = 0x20; //Timer 1, Mode 2
	TH1 = 0xFD; //9600 baud rate
	SCON = 0x50; // Mode 1, 8-bit uart, enable receiver
	TR1 = 1; // Start Timer 1
	
}	

void uart_txchar(char Data)
{
	SBUF = Data;
	while(TI == 0);
	TI = 0;
}	

void uart_sendstring(char *str)
{
	int i;
	for(i=0;str[i]!=0;i++){
		uart_txchar(str[i]);
	}
}	

void main()
{
	uart_init();
	while(1){
		uart_sendstring("Hello!\n\r");
	}	
}	