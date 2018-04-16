;Title: Ping Pong
;Name: River Schenck and Chad
;Date: 2/11/2018
;Description: this project should be able to do the following:  
			;Hit the ball back a forth.
			;Have 2 different speeds
			;Have 3 hit windows on each side
			;Switch serves every game

;Revisons
	;2/11/18 - initial start, implementing flowchart
	;2/12/18 - adding checkBTN and getting it worked out
	;2/16/18 - implementing the keep moving left and keep moving right routines
	;2/18/18 - adding 2 delays that change from SW1
	;2/20/18 - cleaning up code getting it to be more smooth
	;2/21/18 - added 'main' to the code which acts like a driver
	;2/22/18 - game now switches serve and eleminated 'main' from code because it wasnt needed
	;2/23/18 - cleaned up code FINISHED



;==================================================================
;				 OFF							ON
;SW1  -	Delay1					Delay2
;SW2  -									Right Window (3)
;SW3  -									Right Window (2)
;SW4  - 								Right Window (1)
;SW5  - 								Left  Window (3)
;SW6  - 								Left  Window (2)
;SW7  - 								Left  Window (1)	
;BTN1	(04h)		lLED9(14H) LED10(24H)
;BTN2 (08h)
;==================================================================


;INPUTS: 
       SW1 bit P3.0
			 SW2 bit P3.1
			 SW3 bit P3.2
			 SW4 bit P3.3
			 SW5 bit P3.4
			 SW6 bit P3.5
			 SW7 bit P3.6
			 SW8 bit P3.7
       BTN1 BIT P2.3
       BTN2 BIT P2.2
;OUTPUTS:
       LED1_8 EQU P1
       LED9 bit P2.4
			 LED10 bit P2.5


DSEG AT 30H
	CURRENT:  DS 1
	POSITION: DS 1
	WINDOW3L: DS 1
	WINDOW2L: DS 1
	WINDOW1L: DS 1
	WINDOW3R: DS 1
	WINDOW2R: DS 1
	WINDOW1R: DS 1
	PREV_BTNS:DS 1
	STARTBALL:DS 1

CSEG



			$ include (c8051F020.inc)

mov wdtcn,#0DEh  ; disable watchdog
mov wdtcn, #0ADh  ; disable watchdog
mov xbr2, #40h   ; enable port output


;============================================================================
;Initilize
;Purpose: initilizes the serving off the ball. Goes every other game.
;INPUTS: 
;OUTPUTS:
;Destroys: 
;============================================================================	
		CLR A ; clear A
		MOV A, STARTBALL
		CJNE A, #08H, START_R	; starts ball on right side
		SJMP START_L ; starts ball on left side


;============================================================================
;BUTTON 
;Purpose: checks to see if a button is pressed or if it is being held.
;INPUTS: P2
;OUTPUTS:
;Destroys: A
;============================================================================			
	CHECK_BTN:	
			clr a
			mov a, p2       
			cpl a								 ; complement a
			xch a, PREV_BTNS  	 ; exchange a with old_buttons
			xrl a, PREV_BTNS  	 ; exclusive or a 
			anl a, PREV_BTNS  	 ; and a with old button

			RET


;============================================================================
;START
;Purpose: starts the ball on the side it should be served from
;INPUTS: 
;OUTPUTS:
;Destroys: 
;============================================================================	
	START_R: 
				MOV POSITION, #11;	;move POSITION to 11 so the LED starts on right

	GO_RIGHT:
		SJMP MOVE_RIGHT ; jump to the moving right routine
		
		START_L:
					MOV POSITION ,#0 ;STARTS BALL AT LED#1

	GO_LEFT:
		SJMP MOVE_LEFT	 ;WILL START THE BALL LEFT


;===========================================================================
;MOVE RIGHT
;Purpose: moves the ball right and continues to move it in that direction
; if no button is pressed. This is essentially the driver for the right side.
;INPUTS: 
;OUTPUTS:
;Destroys: A
;===========================================================================

MOVE_RIGHT:
		MOV A, POSITION
		DEC A											;TAKES BALL POSITION ON LEDS AND DECREASES IT
		MOV POSITION, A						;AND WILL LATER SHOW NEW POSITION 
		CJNE A, #00H, HERE				;checks if the game is over
		jmp ENDGAME								;if game is over jump to the end routine
HERE:
		CALL DISPLAY							; display the led
		CALL DELAY								; call delay				
KEEP_RIGHT:	
		CALL CHECK_BTN						;check if the right btn is pressed
		
		CJNE A, #04H, CHECK				;My button changes values at led#2 for some reason
															;so this takes that into consideration
	
		
COMPLETE:			
		CALL RIGHT_WINDOW		;;CHECKS WINDOW
		CJNE  A, #14h, MOVE_RIGHT
		JMP MOVE_LEFT


CHECK:
		CJNE A, #14H, CHECK2
		JMP COMPLETE

CHECK2:
		CJNE A, #24H, MOVE_RIGHT
		JMP COMPLETE
		
;==================================================
;MOVE LEFT
;Purpose: moves the ball left and continues to move it in that direction
;if no button is pressed. This is essentially the driver for the left side.
;INPUTS: 
;OUTPUTS:
;Destroys: A
;==================================================
MOVE_LEFT:
		MOV A, POSITION
		INC A			
		MOV POSITION, A						;TAKES BALL POSITION ON LEDS AND INCREASES IT
		CJNE A, #0BH, THIS				;checks if the game is over
		jmp ENDGAME								; if so jump to the end routine
THIS:						
		CALL DISPLAY							;STARTS THE BALL AND SHOWS ITS POSITION ON THE BAR
		CALL DELAY
KEEP_LEFT	:
		CALL CHECK_BTN						;checks if the left buttton has been pressed
		CJNE  A, #08h, MOVE_LEFT
		CALL LEFT_WINDOW		;;CHECKS WINDOW	
		CJNE  A, #08h, MOVE_LEFT
		JMP MOVE_RIGHT	

;============================================================================
;Window
;Purpose: sees if the BTN press is within the window and sets A to 0 if not
;INPUTS: 
;OUTPUTS:
;Destroys: A
;============================================================================
LEFT_WINDOW:
					JNB SW2, LWINDOW3		;checks if SW2 is on and JUMPS if it is
					JNB SW3, LWINDOW2   ;checks if SW3 is on and JUMPS if it is
					JNB SW4, LWINDOW1		;checks if SW4 is on and JUMPS if it is
					RET

				LWINDOW3:
							MOV A, WINDOW3L	;MOVES value of window to A
							RET
				LWINDOW2:
							MOV A, WINDOW2L ;MOVES value of window to A
							RET
				LWINDOW1:
							MOV A, WINDOW1L ;MOVES value of window to A
							RET
;============================
RIGHT_WINDOW:
					JNB SW5, RWINDOW3		;checks if SW5 is on and JUMPS if it is
					JNB SW6, RWINDOW2		;checks if SW6 is on and JUMPS if it is
					JNB SW7, RWINDOW1		;checks if SW7 is on and JUMPS if it is
					MOV A, #14H
					RET

				RWINDOW3:
							MOV A, WINDOW3R ;MOVES value of window to A
							RET
				RWINDOW2:
							MOV A, WINDOW2R ;MOVES value of window to A
							RET
				RWINDOW1:
							MOV A, WINDOW1R ;MOVES value of window to A
							RET
				

;============================================================================
;DELAYS
;Purpose: delays so the players have time to respond to the LEDs and hit 
;the 'ball' back. This has delay1(slow) and delay2(fast)
;INPUTS: 
;OUTPUTS:
;Destroys: R2, R3, R4
;============================================================================
			
DELAY:  
				JB SW1, DELAY2 			; checks if the button is on, if so jump to delay2
DELAY1:	MOV R4, #7					;DELAY1
LOOP5:	MOV R3, #255
LOOP2:	MOV R2, #255
LOOP1:  DJNZ R2, LOOP1
				DJNZ R3, LOOP2
				DJNZ R4, LOOP5
				RET
				

DELAY2:											;DELAY2
				MOV R3, #200
LOOP4:	MOV R2, #150
LOOP3:	DJNZ R2, LOOP3
				DJNZ R3, LOOP4	
				RET	


;============================================================================
;DISPLAY
;Purpose: this displays the LED of POSITION on the LED bar. It also sets the
;LUT table values to the windows.
;INPUTS: P1, P2
;OUTPUTS: P1, P2
;Destroys: A
;============================================================================	

	DISPLAY:
		mov		A, position				;COPY BALL POSITION TO ACCUMULATOR
		mov 	dptr,#TABLE1    	;POINT TO TABLE P1 INDEX 0
		movc 	a,@a+dptr         ;SET THE INDEX FOR THE P1 TABLE AND GRAB DATA
		mov 	P1, a							;SEND RETURNED VALUE OUT TO PORT
		mov 	a, position  			;COPY BALL POSITION TO ACCUMULATOR
		mov 	dptr,#TABLE2    	;POINT TO TABLE P2 INDEX 0
		movc 	a,@a+dptr         ;SET THE INDEX FOR THE P2 TABLE AND GRAB DATA
		mov 	p2, a	
		mov 	a, position				;SEND RETURNED VALUE OUT TO PORT
		mov   dptr, #TWINDOW3L	;MOVE dptr to TWINDOW3L
		movc  a,@a+dptr
		mov   WINDOW3L, a				;send BTN value to WINDOW3L
		mov 	a, position
		mov   dptr, #TWINDOW2L  ;MOVE dptr to TWINDOW2L
		movc  a,@a+dptr
		mov   WINDOW2L, a       ;send BTN value to WINDOW2L
		mov 	a, position
		mov   dptr, #TWINDOW1L  ;MOVE dptr to TWINDOW1L
		movc  a,@a+dptr
		mov   WINDOW1L, a       ;send BTN value to WINDOW1L
		mov 	a, position
		mov   dptr, #TWINDOW3R  ;MOVE dptr to TWINDOW3R
		movc  a,@a+dptr
		mov   WINDOW3R, a       ;send BTN value to WINDOW3R
		mov 	a, position
		mov   dptr, #TWINDOW2R  ;MOVE dptr to TWINDOW2R
		movc  a,@a+dptr
		mov   WINDOW2R, a       ;send BTN value to WINDOW2R
		mov 	a, position
		mov   dptr, #TWINDOW1R  ;MOVE dptr to TWINDOW1R
		movc  a,@a+dptr
		mov   WINDOW1R, a       ;send BTN value to WINDOW1R
		ret	

			
;============================================================================
;LUT
;Purpose: look up table for LED1-8(TABLE1) and LED9 and LED 10(TABLE2) 
;also tables for the windows
;INPUTS: 
;OUTPUTS:
;Destroys: 
;============================================================================												

ORG 200h

TABLE1:		   db	 1, 11111111B, 11111111B, 01111111B, 10111111B, 11011111B, 11101111B, 11110111B, 11111011B, 11111101B, 11111110B, 11111111B , 1
TABLE2:	  	 db  1, 11011111B, 11101111B, 11111111B, 11111111B, 11111111B, 11111111B, 11111111B, 11111111B, 11111111B, 11111111B, 11111111B , 1

TWINDOW3L:   db  1, 			 00h,				02h,			 03h,				04h,			 05h,				06h,			 07h,				08h,			 08h,				08h,			08h  , 1
TWINDOW2L:   db  1, 			 00h,				00h,			 00h,				00h,			 00h,				00h,			 00h,				00h,			 08h,				08h,			08h  , 1
TWINDOW1L:   db  1, 			 00h,				00h,			 00h,				00h,			 00h,				00h,			 00h,				00h,			 00h,				08h,			08h  , 1
TWINDOW3R:   db  1, 			 14h,				14h,			 14h,				00h,			 00h,				00h,			 00h,				00h,			 00h,				00h,			00h  , 1
TWINDOW2R:   db  1, 			 14h,				14h,			 00h,				00h,			 00h,				00h,			 00h,				00h,			 00h,				00h,			00h  , 1
TWINDOW1R:   db  14h, 			 14h,				00h,			 00h,				00h,			 00h,				00h,			 00h,				00h,			 00h,				00h,			00h  , 1



;============================================================================
;END GAME
;Purpose: ends the game and does a cool little arcade like display. 
;Also, complements STARTBALL so the serve switches next game
;INPUTS: 
;OUTPUTS:
;Destroys: A
;============================================================================	
ENDGAME:
			MOV R5, #03
JMPHERE:											;This just does a cool arcade looking display
			MOV P1, #00000001b
			MOV P2, #00100000b
			CALL DELAY2
			MOV P1, #00000010b
			MOV P2, #00010000b	
			CALL DELAY2
			MOV P2, #00000000b
			MOV P1, #10000100b
			CALL DELAY2
			MOV P1, #01001000b
			CALL DELAY2
			MOV P1, #00110000b
			CALL DELAY2
			MOV P1, #01001000b
			CALL DELAY2
			MOV P2, #00000000b
			MOV P1, #10000100b
			CALL DELAY2
			MOV P1, #00000010b
			MOV P2, #00010000b
			CALL DELAY2
			MOV P1, #00000001b
			MOV P2, #00100000b
			CALL DELAY2
			MOV p1, #0ffh
			MOV p2, #0FFh




			DJNZ R5, JMPHERE			;does the arcade display 3 times

			MOV A, STARTBALL
			CPL A									;complementing STARTBALL to serve on otherside
			MOV STARTBALL, A
			jmp over


over:
			jmp over





			END
