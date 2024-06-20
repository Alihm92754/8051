#include<reg51.h>
#include<stdio.h>

void uart_Init();
void uart_TxChar(char);
char uart_RxChar();
void uart_SendingString(char *str);

sbit Lamp = P0^0;
sbit Fan = P0^0;

void uart_Init()
{
	TMOD = 0x20;
	TH1 = 0xFD;
	SCON = 0x50;
	TR1 = 1;
}

void uart_TxChar(char Data)
{
	SBUF = Data;
	while(TI == 0);
	TI = 0;
}

char uart_RxChar()
{
	char dat;
	while(RI == 0);
	RI = 0;
	dat = SBUF;
	return(dat);
}

void uart_SendString(char *str)
{
	int i;
	for(i=0;str[i]!=0;i++){
		uart_TxChar(str[i]);
	}
}

void main()
{
	char Data_in;
	uart_Init();
	P0 = 0;
  while(1){
		Data_in = uart_RxChar();
		if(Data_in == '1'){
			Lamp = 1;
			uart_SendString("Lamp On");
		}
		else if(Data_in == '2'){
			Lamp = 0;
			uart_SendString("Lamp Off");
		}
		else if(Data_in == '3'){
			Fan = 1;
			uart_SendString("Fan On");
		}
		else if(Data_in == '4'){
			Fan = 0;
			uart_SendString("Fan Off");
		}
		else{
			uart_SendString("choose 1,2,3,4");
		}
	}
}	

