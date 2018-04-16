#include <C8051F020.h>
#include <lcd1.h>

long set_point_sum;
int  set_point;
unsigned char  set_point_count;
int  stemp_avg;
char set_temp;
int room_temp;
int rtemp;           //
long rtemp_sum;
unsigned char rtemp_count;
int  rtemp_avg;

unsigned char put_char (unsigned char row, unsigned char col, char ch);
//void display_temps(void);
//void timer2_of(void);

void main()
{


	WDTCN = 0xde;  // disable watchdog
    WDTCN = 0xad;
    XBR2 = 0x40;   // enable port output
    XBR0 = 4;      // enable uart 0
	REF0CN = 7;
	OSCXCN = 0x67; // turn on external crystal
	TMOD = 0x20;   // wait 1ms using T1 mode 2
	TH1 = -167;    // 2MHz clock, 167 counts - 1ms
	TR1 = 1;
	while ( TF1 == 0 ) { }          // wait 1ms
	while ( !(OSCXCN & 0x80) ) { }  // wait till oscillator stable
	OSCICN = 8;    // switch over to 22.1184MHz


	T2CON  =  0x08; //Set the timer auto-reload   
	RCAP2H = -1800 >> 8; //22.1184E6/12/1024 = 1800
	RCAP2L = -1800;
	TR2    =  1;
	IE     =  0x80; //0x80; //do not enable timer 2 interrupt
	EIE2   =  0x02; //enable ADC interrupt
	ADC0CF =  0x40; //set conversion clock [(22.184Hz/2.5MHz) - 1] = 8
	ADC0CN =  0x8C; //enable ADC, starts conversion when T2 overfows
	REF0CN =  0x07; //set reference voltage
	//AMX0SL =  0x01; 
	P2   = 	  0xFF; // LEDs off
	P1   = 	  0xFF;

	init_lcd(); //Blank Screen

	put_char(0,0, 'T');
	put_char(0,6, 'E');
	put_char(0,12,'M');
	put_char(0,18,'P');
	put_char(0,24,'E');
	put_char(0,30,'R');
	put_char(0,36,'A');
	put_char(0,42,'T');
	put_char(0,48,'U');
	put_char(0,54,'R');
	put_char(0,60,'E');	
	put_char(0,66,' ');

	put_char(2,0, 'S');
	put_char(2,6, 'E');
	put_char(2,12,'T');
	put_char(2,18,' ');
	put_char(2,24,'T');
	put_char(2,30,'E');
	put_char(2,36,'M');
	put_char(2,42,'P');
	put_char(2,48,' ');

	while(1)
	{ 
		put_char(2,54,set_temp / 10 +'0');
		put_char(2,60,set_temp % 10 +'0');
		put_char(0,72, room_temp /10 + '0');
		put_char(0,78, room_temp %10 + '0');

		refresh_screen();
	
		if (room_temp < set_temp)
		{
			P2   = 0x00; //LEDs on
			P1   = 0x00;

				put_char(6,0, 'C');
				put_char(6,6, 'H');
				put_char(6,12,'E');
				put_char(6,18,'C');
				put_char(6,24,'K');
				put_char(6,30,' ');
				put_char(6,36,'T');
				put_char(6,42,'E');
				put_char(6,48,'M');
				put_char(6,54,'P');
				put_char(6,60,'!');	
				put_char(6,66,'!');


		}
		else
		{
			P2   = 0xFF;//LEDs off
			P1   = 0xFF;
				put_char(6,0, ' ');
				put_char(6,6, ' ');
				put_char(6,12,' ');
				put_char(6,18,' ');
				put_char(6,24,' ');
				put_char(6,30,' ');
				put_char(6,36,' ');
				put_char(6,42,' ');
				put_char(6,48,' ');
				put_char(6,54,' ');
				put_char(6,60,' ');	
				put_char(6,66,' ');
		}

	}
	//display_temps();
	
}

void ADC_int(void) interrupt 15 
{
	AD0INT = 0;
	TF2 = 0;

	if(AMX0SL == 0x00) //AIN0.0
	{
		//ADC0CF = 0x041; //set gain 2
		AMX0SL = 8;
		set_point = ((ADC0H << 8)| ADC0L); //reading from pot.
		set_point_sum += set_point;
		set_point_count++;
	
		if (set_point_count == 255)
		{
			stemp_avg = set_point_sum/255;
			set_point_sum = 0;
			set_point_count = 0;
			set_temp = ((stemp_avg * 31L) >> 12) + 55;

		}
		//AMX0SL == 8;
		ADC0CF |= 1; //set gain to 1
	
	}	
	else //if(AMX0SL == 0x08)
	{
		AMX0SL = 0x00;
		rtemp= (ADC0H << 8)| ADC0L;// data from temp sensor
		rtemp_sum += rtemp;
		rtemp_count ++;
		if (rtemp_count == 255)
		{	
			rtemp_avg = rtemp_sum/255;
			rtemp_sum = 0;
			rtemp_count = 0;
			room_temp = (12084L*(rtemp_avg - 2475L))/(65336L);

		}
		ADC0CF |= 1;		
	}		
	
}	

unsigned char put_char (unsigned char row, unsigned char col, char ch)
{
	int loc = row * 128 + col;
	int font = (ch - ' ') * 5;
	char i;
	for (i=0; i<5; i++)
	{
		screen[loc +i] = font5x8[font+i];
	}

	return (col+6);
}