#include<reg51.h>
#define lcd_data_port P3
sbit rs = P2^0;
sbit rw = P2^1;
sbit en = P2^2;
void delay(unsigned int count)
{
	int i, j;
	for(i = 0;i<count;i++)
	for(j=0;j<112;j++);
}
void LCD_Command(unsigned char cmd)
{
	lcd_data_port = cmd;
	rs = 0;
	rw=0;
	en=1;
	delay(1);
	en = 0;
	delay(5);
}
void LCD_Char(unsigned char char_data)
{
	lcd_data_port = char_data;
	rs = 1;
	rw=0;
	en=1;
	delay(1);
	en = 0;
	delay(5);
}
void LCD_String(unsigned char *str)
{
	int i;
	for(i=0;str[i]!=0;i++)
	{
		LCD_Char(str[i]);
	}
}
void LCD_Init(void)
{
	delay(20);
	LCD_Command(0x38);
	LCD_Command(0x0F);
	LCD_Command(0x06);
	LCD_Command(0x01);
	LCD_Command(0x80);
}
void main()
{
	LCD_Init();
	LCD_String("JIIT");
	while(1);
}
