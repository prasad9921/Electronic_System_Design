#include<reg51.h>
sbit sen1=p2^0;
sbit sen2=p2^1;
sbit rs=p3^6;
sbit en=p3^7;
void lcdcmd(unsigned char);
void lcddat(unsigned char);
void delay();
void lcddis(unsigned char *s,unsigned char r);
void lcdconv(unsigned char);
void main()
{
unsigned char x;
p0=0xff;
p1=0xff;
p2=0xff;
p3=0xff;
lcdcmd(0x38);
delay();
lcdcmd(0x10);
delay();
lcdcmd(0x10);
delay();
lcdcmd(0x0c);
delay();
lcdcmd(0x80);
delay();
lcddis("WELCOME",7);
delay();
delay();
delay();
delay();
delay();
lcdcmd(0xc0);
lcddis("Visitor counter",15);
delay();
delay();
delay();
delay();
lcdcmd(0x01);
delay();
lcdcmd(0x80);
delay();
lcddis("Entry: 00",9);
lcdcmd(0x89);
while(1)
{
if(sen1==0)
{
lcdmcd(0x80);
delay();
lcddis("Entry: 8);
lcdmcd(0x87);
x=x+1;
lcdconv(x);
}
if(sen2==0&&x>0)
{
lcdmcd(0x80);
lcddis("Entry: ,8);
lcdmcd(0x87);
x=x-1;
lcdconv(x);
delay();
}
}
}
void lcdmcd(unsignedchar val)
{
p1=val;
rs=0;
en=1;
delay();
en=0;
}
void lcddat(unsigned char dat)
{
p1=dat;
rs=1;
en=1;
delay();
en=0;
}
void lcddis(unsigned char *s,unsigned char r)
{
unsigned char w;
for(w=0;w<r;w++)
{
lcddat(s[w]);
delay();
}
}
void lcdconv(unsigned char num)
{
unsigned char p,n;
p=num/10;
n=num%10;
p=p+0x30;
n=n+0x30;
lcddat(p);
lcddat(n);
}
void delay()
{
unsigned int k,l;
for(k=0;k<10;k++)
for(l=0;l<1000;l++)
}