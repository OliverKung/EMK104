/***/
/*This is a code that for hotmap scan function test,run at 2400bps@12.000Mbps
and we try to make it possible for hotmap function*/
/***/
#include <reg52.h>
#include <intrins.h>
//#include <Scan.c>

/***/
#define uint unsigned int
#define uchar unsigned char
/***/
#define KeyPort1 P0
#define KeyPort2 P1
#define KeyPort3 P2
sbit row5 = P0^0;
sbit row6 = P0^1;
sbit row7 = P0^2;
sbit row8 = P0^3;
sbit row9 = P0^4;
sbit row10 = P0^5;
sbit row11 = P0^6;
sbit row12 = P0^7;
sbit row13 = P2^7;
sbit row14 = P2^6;

sbit col15 = P1^6;
sbit col16 = P1^5;
sbit col17 = P1^4;
sbit col18 = P1^3;
sbit col19 = P1^2;
sbit col20 = P1^1;
sbit col21 = P1^0;
sbit col22 = P2^0;
sbit col23 = P2^1;
sbit col24 = P2^2;
sbit col25 = P2^3;
sbit col26 = P2^4;
sbit col27 = P2^5;

/***/
#define Fn 233
#define WinL 234
#define CtrlL 235
#define CtrlR 236
#define AltL 237
#define AltR 238
#define ShiftL 239
#define ShiftR 240
#define Macro1 241
#define Macro2 242
#define Macro3 243
#define Macro4 244
#define Macro5 245 
#define Menu 118
uchar hotMap[51]={0},hotMapX[51]={0};
uchar code keyMap[101]=
{
	0,86,79,92,87,81,88,4,90,//PgDn,Num.,Num7,Num+,Num0,NumEnt,A,Num5
	83,85,97,86,96,49,98,64,9,93,//Home,PgUp,Num*,Num-,Num/,\,Num1,F7,F,Num8
	20,35,22,18,40,25,42,67,47,63,//Q,6,S,O,Enter,V,BS,F10,[,F6
	5,43,76,37,7,28,54,23,57,32,//B,Tab,Del,8,D,Y,<,T,Caps,3
	27,16,11,15,56,59,58,21,65,//X,M,H,L,/,F2,F1,R,F8
	68,38,13,39,48,73,8,30,55,61,//F11,9,J,0,],Insert,E,1,>,F4
	34,41,14,45,52,69,26,31,51,46,//5,ESC,K,-,",F12,W,2,:,+
	53,Macro3,33,Macro4,24,Macro5,17,80,36,66,//~,Up,4,Down,U,Left,N,Right,7,F9
	84,82,99,91,94,Fn,12,95,//End,Num2,Num3.Num6,Num9,Fn,I,NumLock
	WinL,29,10,//Win_L,Z,G
	CtrlL,Macro2,60,6,//CtrlL,CtrlR,F3,C
	AltL,Menu,19,62,//AltL,AltR,P,F5
	ShiftL,ShiftR,89,44//ShiftL,ShiftR,Num4,Space
	};
uchar code keyMapOriginal[101]=
{
	0,78,99,95,87,98,88,4,93,//PgDn,Num.,Num7,Num+,Num0,NumEnt,A,Num5
	74,75,85,86,84,49,89,64,9,96,//Home,PgUp,Num*,Num-,Num/,\,Num1,F7,F,Num8
	20,35,22,18,40,25,42,67,47,63,//Q,6,S,O,Enter,V,BS,F10,[,F6
	5,43,76,37,7,28,54,23,57,32,//B,Tab,Del,8,D,Y,<,T,Caps,3
	27,16,11,15,56,59,58,21,65,//X,M,H,L,/,F2,F1,R,F8
	68,38,13,39,48,73,8,30,55,61,//F11,9,J,0,],Insert,E,1,>,F4
	34,41,14,45,52,69,26,31,51,46,//5,ESC,K,-,",F12,W,2,:,+
	53,82,33,81,24,80,17,79,36,66,//~,Up,4,Down,U,Left,N,Right,7,F9
	77,90,91,94,97,Fn,12,83,//End,Num2,Num3.Num6,Num9,Fn,I,NumLock
	WinL,29,10,//Win_L,Z,G
	CtrlL,CtrlR,60,6,//CtrlL,CtrlR,F3,C
	AltL,AltR,19,62,//AltL,AltR,P,F5
	ShiftL,ShiftR,92,44//ShiftL,ShiftR,Num4,Space
	};
uchar code shiftkeyMap[101]=
{
	0,78,99,95,87,98,88,4,93,//PgDn,Num.,Num7,Num+,Num0,NumEnt,A,Num5
	74,75,85,86,84,49,89,64,9,96,//Home,PgUp,Num*,Num-,Num/,\,Num1,F7,F,Num8
	20,35,22,18,40,25,42,67,47,63,//Q,6,S,O,Enter,V,BS,F10,[,F6
	5,43,76,37,7,28,54,23,57,32,//B,Tab,Del,8,D,Y,<,T,Caps,3
	27,16,11,15,56,59,58,21,65,//X,M,H,L,/,F2,F1,R,F8
	68,38,13,39,48,73,8,30,55,61,//F11,9,J,0,],Insert,E,1,>,F4
	34,41,14,45,52,69,26,31,51,46,//5,ESC,K,-,",F12,W,2,:,+
	53,82,33,81,24,80,17,79,36,66,//~,Up,4,Down,U,Left,N,Right,7,F9
	77,90,91,94,97,Fn,12,83,//End,Num2,Num3.Num6,Num9,Fn,I,NumLock
	WinL,29,10,//Win_L,Z,G
	CtrlL,CtrlR,60,6,//CtrlL,CtrlR,F3,C
	AltL,AltR,19,62,//AltL,AltR,P,F5
	ShiftL,ShiftR,92,44//ShiftL,ShiftR,Num4,Space
};
/***/

/***/
uchar Buffer[8]={0};
/***/
void delay10ms(void)//actually delay2ms
{
    unsigned char a,b;
    for(b=4;b>0;b--)
        for(a=248;a>0;a--);
    _nop_();  //if Keil,require use intrins.h
}
/***/

/***/
void delay1ms(uchar timeX)   //误差 -0.651041666667us
{
    unsigned char a,b;
	for(timeX;timeX>0;timeX--)
		for(b=102;b>0;b--)
			for(a=3;a>0;a--);
}
/***/

/***/
void delay10_Sendms(void)   //误差 -0.000000000002us
{
    unsigned char a,b;
    for(b=249;b>0;b--)
        for(a=17;a>0;a--);
}
/***/
void delay1s(void)   //delta=-0.000000000227us
{
    unsigned char a,b,c;
    for(c=13;c>0;c--)
        for(b=247;b>0;b--)
            for(a=142;a>0;a--);
    _nop_();  //if Keil,require use intrins.h
}
/***/
void KeyScan()
{
	P0 = 0xFF;
	P1 = 0xFF;
	P2 = 0xFF;
	col27 = 0;
	if(P0!=0xFF||row13!=1||row14!=1)
	{
		P0 = 0xFF;
		P1 = 0xFF;
		P2 = 0xFF;
		col27 = 0;
		delay10ms();
		if(P0!=0xFF||row13!=1||row14!=1)
		{
			if(row5==0);
			if(row6==0)hotMap[1]=1;
			if(row7==0)hotMap[2]=1;
			if(row8==0)hotMap[3]=1;
			if(row9==0)hotMap[4]=1;
			if(row10==0);
			if(row11==0)hotMap[5]=1;
			if(row12==0)hotMap[6]=1;
			if(row13==0)hotMap[7]=1;
			if(row14==0)hotMap[8]=1;
		}
	}
	P0 = 0xFF;
	P1 = 0xFF;
	P2 = 0xFF;
	col26 = 0;
	if(P0!=0xFF||row13!=1||row14!=1)
	{
		P0 = 0xFF;
		P1 = 0xFF;
		P2 = 0xFF;
		col26 = 0;
		delay10ms();
		if(P0!=0xFF||row13!=1||row14!=1)
		{
			if(row5==0)hotMap[9]=1;
			if(row6==0)hotMap[10]=1;
			if(row7==0)hotMap[11]=1;
			if(row8==0)hotMap[12]=1;
			if(row9==0)hotMap[13]=1;
			if(row10==0)hotMap[14]=1;
			if(row11==0)hotMap[15]=1;
			if(row12==0)hotMap[16]=1;
			if(row13==0)hotMap[17]=1;
			if(row14==0)hotMap[18]=1;
		}
	}
	P0 = 0xFF;
	P1 = 0xFF;
	P2 = 0xFF;
	col25 = 0;
	if(P0!=0xFF||row13!=1||row14!=1)
	{
		P0 = 0xFF;
		P1 = 0xFF;
		P2 = 0xFF;
		col25 = 0;
		delay10ms();
		if(P0!=0xFF||row13!=1||row14!=1)
		{
			if(row5==0)hotMap[19]=1;
			if(row6==0)hotMap[20]=1;
			if(row7==0)hotMap[21]=1;
			if(row8==0)hotMap[22]=1;
			if(row9==0)hotMap[23]=1;
			if(row10==0)hotMap[24]=1;
			if(row11==0)hotMap[25]=1;
			if(row12==0)hotMap[26]=1;
			if(row13==0)hotMap[27]=1;
			if(row14==0)hotMap[28]=1;
		}
	}
	P0 = 0xFF;
	P1 = 0xFF;
	P2 = 0xFF;
	col24 = 0;
	if(P0!=0xFF||row13!=1||row14!=1)
	{
		P0 = 0xFF;
		P1 = 0xFF;
		P2 = 0xFF;
		col24 = 0;
		delay10ms();
		if(P0!=0xFF||row13!=1||row14!=1)
		{
			if(row5==0)hotMap[29]=1;
			if(row6==0)hotMap[30]=1;
			if(row7==0)hotMap[31]=1;
			if(row8==0)hotMap[32]=1;
			if(row9==0)hotMap[33]=1;
			if(row10==0)hotMap[34]=1;
			if(row11==0)hotMap[35]=1;
			if(row12==0)hotMap[36]=1;
			if(row13==0)hotMap[37]=1;
			if(row14==0)hotMap[38]=1;
		}
	}
	P0 = 0xFF;
	P1 = 0xFF;
	P2 = 0xFF;
	col23 = 0;
	if(P0!=0xFF||row13!=1||row14!=1)
	{
		P0 = 0xFF;
		P1 = 0xFF;
		P2 = 0xFF;
		col23 = 0;
		delay10ms();
		if(P0!=0xFF||row13!=1||row14!=1)
		{
			if(row5==0)hotMap[39]=1;
			if(row6==0)hotMap[40]=1;
			if(row7==0)hotMap[41]=1;
			if(row8==0);
			if(row9==0)hotMap[42]=1;
			if(row10==0)hotMap[43]=1;
			if(row11==0)hotMap[44]=1;
			if(row12==0)hotMap[45]=1;
			if(row13==0)hotMap[46]=1;
			if(row14==0)hotMap[47]=1;
		}
	}
	P0 = 0xFF;
	P1 = 0xFF;
	P2 = 0xFF;
	col22 = 0;
	if(P0!=0xFF||row13!=1||row14!=1)
	{
		P0 = 0xFF;
		P1 = 0xFF;
		P2 = 0xFF;
		col22 = 0;
		delay10ms();
		if(P0!=0xFF||row13!=1||row14!=1)
		{
			if(row5==0)hotMap[48]=1;
			if(row6==0)hotMap[49]=1;
			if(row7==0)hotMap[50]=1;
			if(row8==0)hotMapX[1]=1;
			if(row9==0)hotMapX[2]=1;
			if(row10==0)hotMapX[3]=1;
			if(row11==0)hotMapX[4]=1;
			if(row12==0)hotMapX[5]=1;
			if(row13==0)hotMapX[6]=1;
			if(row14==0)hotMapX[7]=1;
		}
	}
	P0 = 0xFF;
	P1 = 0xFF;
	P2 = 0xFF;
	col21 = 0;
	if(P0!=0xFF||row13!=1||row14!=1)
	{
		P0 = 0xFF;
		P1 = 0xFF;
		P2 = 0xFF;
		col21 = 0;
		delay10ms();
		if(P0!=0xFF||row13!=1||row14!=1)
		{
			if(row5==0)hotMapX[8]=1;
			if(row6==0)hotMapX[9]=1;
			if(row7==0)hotMapX[10]=1;
			if(row8==0)hotMapX[11]=1;
			if(row9==0)hotMapX[12]=1;
			if(row10==0)hotMapX[13]=1;
			if(row11==0)hotMapX[14]=1;
			if(row12==0)hotMapX[15]=1;
			if(row13==0)hotMapX[16]=1;
			if(row14==0)hotMapX[17]=1;
		}
	}
	P0 = 0xFF;
	P1 = 0xFF;
	P2 = 0xFF;
	col20 = 0;
	if(P0!=0xFF||row13!=1||row14!=1)
	{
		P0 = 0xFF;
		P1 = 0xFF;
		P2 = 0xFF;
		col20 = 0;
		delay10ms();
		if(P0!=0xFF||row13!=1||row14!=1)
		{
			if(row5==0)hotMapX[18]=1;
			if(row6==0)hotMapX[19]=1;
			if(row7==0)hotMapX[20]=1;
			if(row8==0)hotMapX[21]=1;
			if(row9==0)hotMapX[22]=1;
			if(row10==0)hotMapX[23]=1;
			if(row11==0)hotMapX[24]=1;
			if(row12==0)hotMapX[25]=1;
			if(row13==0)hotMapX[26]=1;
			if(row14==0)hotMapX[27]=1;
		}
	}
	P0 = 0xFF;
	P1 = 0xFF;
	P2 = 0xFF;
	col19 = 0;
	if(P0!=0xFF||row13!=1||row14!=1)
	{
		P0 = 0xFF;
		P1 = 0xFF;
		P2 = 0xFF;
		col19 = 0;
		delay10ms();
		if(P0!=0xFF||row13!=1||row14!=1)
		{
			if(row5==0)hotMapX[28]=1;
			if(row6==0)hotMapX[29]=1;
			if(row7==0)hotMapX[30]=1;
			if(row8==0)hotMapX[31]=1;
			if(row9==0)hotMapX[32]=1;
			if(row10==0);
			if(row11==0);
			if(row12==0)hotMapX[33]=1;
			if(row13==0)hotMapX[34]=1;
			if(row14==0)hotMapX[35]=1;
		}
	}
		P0 = 0xFF;
	P1 = 0xFF;
	P2 = 0xFF;
	col18 = 0;
	if(P0!=0xFF||row13!=1||row14!=1)
	{
		P0 = 0xFF;
		P1 = 0xFF;
		P2 = 0xFF;
		col18 = 0;
		delay10ms();
		if(P0!=0xFF||row13!=1||row14!=1)
		{
			if(row5==0);
			if(row6==0);
			if(row7==0);
			if(row8==0);
			if(row9==0);
			if(row10==0);
			if(row11==0)hotMapX[36]=1;
			if(row12==0);
			if(row13==0)hotMapX[37]=1;
			if(row14==0)hotMapX[38]=1;
		}
	}
	P0 = 0xFF;
	P1 = 0xFF;
	P2 = 0xFF;
	col17 = 0;
	if(P0!=0xFF||row13!=1||row14!=1)
	{
		P0 = 0xFF;
		P1 = 0xFF;
		P2 = 0xFF;
		col17 = 0;
		delay10ms();
		if(P0!=0xFF||row13!=1||row14!=1)
		{
			if(row5==0);
			if(row6==0);
			if(row7==0);
			if(row8==0);
			if(row9==0)hotMapX[39]=1;
			if(row10==0)hotMap[40]=1;
			if(row11==0);
			if(row12==0);
			if(row13==0)hotMapX[41]=1;
			if(row14==0)hotMapX[42]=1;
		}
	}
	P0 = 0xFF;
	P1 = 0xFF;
	P2 = 0xFF;
	col16 = 0;
	if(P0!=0xFF||row13!=1||row14!=1)
	{
		P0 = 0xFF;
		P1 = 0xFF;
		P2 = 0xFF;
		col16 = 0;
		delay10ms();
		if(P0!=0xFF||row13!=1||row14!=1)
		{
			if(row5==0);
			if(row6==0);
			if(row7==0)hotMapX[43]=1;
			if(row8==0)hotMapX[44]=1;
			if(row9==0);
			if(row10==0);
			if(row11==0);
			if(row12==0);
			if(row13==0)hotMapX[45]=1;
			if(row14==0)hotMapX[46]=1;
		}
	}
	P0 = 0xFF;
	P1 = 0xFF;
	P2 = 0xFF;
	col15 = 0;
	if(P0!=0xFF||row13!=1||row14!=1)
	{
		P0 = 0xFF;
		P1 = 0xFF;
		P2 = 0xFF;
		col15 = 0;
		delay10ms();
		if(P0!=0xFF||row13!=1||row14!=1)
		{
			if(row5==0)hotMapX[47]=1;
			if(row6==0)hotMapX[48]=1;
			if(row7==0);
			if(row8==0);
			if(row9==0);
			if(row10==0);
			if(row11==0);
			if(row12==0);
			if(row13==0)hotMapX[49]=1;
			if(row14==0)hotMapX[50]=1;
		}
	}
}
/***/
void hotMapClear()
{
	uchar i=0;
	for(i=0;i<51;i++)
		{
            hotMap[i]=0;
            hotMapX[i]=0;
        }
	for(i=0;i<8;i++)Buffer[i]=0;
}
/***/
void InitUART(void)//Init UART 9600bps@11.0592MHz
{
    TMOD = 0x20;
    SCON = 0x40;
    TH1 = 0xFD;
    TL1 = TH1;
    PCON = 0x00;
    TR1 = 1;
}
/***/

/***/
void SendOneByte(unsigned char c)//Send one byte at UART Serial
{
    SBUF = c;
    while(!TI);
    TI = 0;
}
/***/

/***/
void SendOneArray(uchar *sendBuffer)
{
	uchar i=0;
	for(i=0;i<8;i++)
	{
		SendOneByte(sendBuffer[i]);
	}
	delay10ms();
}
/***/

/***/
uchar findFnKey()
{
	uchar i=0;
	for(i=0;i<=100;i++)
	{
		if(keyMap[i]==Fn)return i;
	}
	return 0;
}
/***/

void Macro1_Act()
{
	
}
void Macro2_Act()
{
	
}
void Macro3_Act()
{
	
}
void Macro4_Act()
{
	
}
void Macro5_Act()
{
	
}
void main()
{
    uchar i=0,j=0,FnPosition=0;
	delay1s();
    InitUART();
	hotMapClear();
	FnPosition=findFnKey();
    while(1)
    {
        hotMapClear();
		KeyScan();
        //delay10ms();
		if(hotMap[FnPosition]==0)
        {
			for(i=0;i<51;i++)
			{
				if(hotMap[i]!=0)
				{	
					switch(keyMap[i])
					{
						case WinL: Buffer[0]=Buffer[0]|0x08; break;
						case CtrlL: Buffer[0]=Buffer[0]|0x01; break;
						case CtrlR: Buffer[0]=Buffer[0]|0x10; break;
						case AltL: Buffer[0]=Buffer[0]|0x04; break;
						case AltR: Buffer[0]=Buffer[0]|0x40; break;
						case ShiftL: Buffer[0]=Buffer[0]|0x02; break;
						case ShiftR: Buffer[0]=Buffer[0]|0x20; break;
						case Macro1: Macro1_Act(); goto end; break;
						case Macro2: Macro2_Act(); goto end; break;
						case Macro3: Macro3_Act(); goto end; break;
						case Macro4: Macro4_Act(); goto end; break;
						case Macro5: Macro5_Act(); goto end; break;
						default:
							if(Buffer[7]!=0)goto Send;
							for(j=2;j<8;j++)
							{
								if(Buffer[j]==0)
								{
									Buffer[j]=keyMap[i];
									break;
								}
							}
						break;	
					}
				}
				//delay10ms();
				if(hotMapX[i]!=0)
				{
					switch(keyMap[i+50])
					{
						case WinL: Buffer[0]=Buffer[0]|0x08; break;
						case CtrlL: Buffer[0]=Buffer[0]|0x01; break;
						case CtrlR: Buffer[0]=Buffer[0]|0x10; break;
						case AltL: Buffer[0]=Buffer[0]|0x04; break;
						case AltR: Buffer[0]=Buffer[0]|0x40; break;
						case ShiftL: Buffer[0]=Buffer[0]|0x02; break;
						case ShiftR: Buffer[0]=Buffer[0]|0x20; break;
						case Macro1: Macro1_Act(); goto end; break;
						case Macro2: Macro2_Act(); goto end; break;
						case Macro3: Macro3_Act(); goto end; break;
						case Macro4: Macro4_Act(); goto end; break;
						case Macro5: Macro5_Act(); goto end; break;
						default:
							if(Buffer[7]!=0)goto Send;
							for(j=2;j<8;j++)
							{
								if(Buffer[j]==0)
								{
									Buffer[j]=keyMap[i+50];
									break;
								}
							}
						break;	
					}
				}
			}
		}
		else
		{
			for(i=0;i<51;i++)
			{
				if(hotMap[i]!=0)
				{	
					switch(keyMap[i])
					{
						case WinL: Buffer[0]=Buffer[0]|0x08; break;
						case CtrlL: Buffer[0]=Buffer[0]|0x01; break;
						case CtrlR: Buffer[0]=Buffer[0]|0x10; break;
						case AltL: Buffer[0]=Buffer[0]|0x04; break;
						case AltR: Buffer[0]=Buffer[0]|0x40; break;
						case ShiftL: Buffer[0]=Buffer[0]|0x02; break;
						case ShiftR: Buffer[0]=Buffer[0]|0x20; break;
						case Macro1: Macro1_Act(); goto end; break;
						case Macro2: Macro2_Act(); goto end; break;
						case Macro3: Macro3_Act(); goto end; break;
						case Macro4: Macro4_Act(); goto end; break;
						case Macro5: Macro5_Act(); goto end; break;
						default:
							if(Buffer[7]!=0)goto Send;
							for(j=2;j<8;j++)
							{
								if(Buffer[j]==0)
								{
									Buffer[j]=shiftkeyMap[i];
									break;
								}
							}
						break;	
					}
				}
				//delay10ms();
				if(hotMapX[i]!=0)
				{
					switch(keyMap[i+50])
					{
						case WinL: Buffer[0]=Buffer[0]|0x08; break;
						case CtrlL: Buffer[0]=Buffer[0]|0x01; break;
						case CtrlR: Buffer[0]=Buffer[0]|0x10; break;
						case AltL: Buffer[0]=Buffer[0]|0x04; break;
						case AltR: Buffer[0]=Buffer[0]|0x40; break;
						case ShiftL: Buffer[0]=Buffer[0]|0x02; break;
						case ShiftR: Buffer[0]=Buffer[0]|0x20; break;
						case Macro1: Macro1_Act(); goto end; break;
						case Macro2: Macro2_Act(); goto end; break;
						case Macro3: Macro3_Act(); goto end; break;
						case Macro4: Macro4_Act(); goto end; break;
						case Macro5: Macro5_Act(); goto end; break;
						default:
							if(Buffer[7]!=0)goto Send;
							for(j=2;j<8;j++)
							{
								if(Buffer[j]==0)
								{
									Buffer[j]=shiftkeyMap[i+50];
									break;
								}
							}
						break;	
					}
				}
			}
		}
		end:
        Send:
		//Buffer[0]=0x10;
		SendOneArray(Buffer);
        hotMapClear();
    }
}