;Title: tug-o-war
;Name: River Schenck	
;Date: 1/29/2018
;Description: build a program to play tugowar.


$ include (c8051F020.inc) 

;INPUTS
			BTN1 BIT P2.0
			BTN2 BIT P2.1

;OUTPUTS
			LED1_8 EQU P1
			LED9 BIT P2.2
			LED10 BIT P2.3

DSEG at 30h

btn_state: ds 1

CSEG


MOV wdtcn,#0DEh ; disable watchdog
MOV wdtcn,#0ADh
MOV xbr2,#40h ; enable port output




					MOV LED1_8, #0CFH ; Initialize LEDs (1 thru 8). 0CFH => "11001111"
loop1: 		LCALL delay 
					LCALL check_btns
					JB acc.0, Check_R    ;if btn 1 is pressed, check btn 2
					JB acc.1, MR ;if btn 2 is pressed, move right 
					SJMP Loop1
Check_R:  JB acc.1, loop1 ;verify that both bottons are not pushed at the same time
					LCALL move_left
					JNB LED10, Done_Left ;Left wins, move to done loop
					LCALL loop1 
MR: 			LCALL move_right
					JNB P1.0, Done_Right ;Right wins, move to done loop
					SJMP loop1 


delay: ;20ms delay
				MOV R3, #50
lp2: 		MOV R2, #250
lp1: 		DJNZ R2, lp1
				DJNZ R3, lp2
				RET

check_btns: ;verify status of both buttons
			MOV A, P2
			CPL A
			XCH A, btn_state
			XRL A, btn_state
			ANL A, btn_state
			RET

move_Right: 
			MOV A, P1
			MOV C, P2.2
			RRC A 
			MOV P1, A
			SETB P2.2
			RET

move_left: 
			MOV A, LED1_8
			MOV C, P1.7
			JB P2.2, MLA
			CLR LED10
MLA: 	RL A
			SETB Acc.0
			MOV LED1_8, A
			MOV LED9, C
			RET



Done_Left: 	MOV P2, #03h ;both buttons zero  
DLL: 				CLR LED9 ; LED pin low which turns LED on
						CLR LED10 ; LED pin low which turns LED on
						SJMP DLL
						RET

Done_Right:	MOV P2, #03h ;both buttons zero    
DRL: 				MOV LED1_8, #0F3h ;LED pin low which turns LED (1/2) on
						SJMP DRL
						RET

END



