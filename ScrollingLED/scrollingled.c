 #include<reg51.h>
 #define LED P2
 void delay(void);
 void left(void);
 void right(void);
 unsigned int j;
 void right()
 {
 for (j=0x80; j>=0x01; j>>=1)
 {
 LED = j;
 delay();
 }
 }
 void left()
 {
 for (j=0x01; j<=0x80; j<<=1)
 {
 LED = j;
 delay();
 }
 }
 void delay(void)
 {
 }
 void main()
 {
 left();
 right();
 }