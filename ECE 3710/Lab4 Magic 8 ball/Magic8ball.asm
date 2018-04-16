;Title: Lab4 - Magic 8 Ball
;Name: River Schenck
;Date: 2/11/2018
;Description: this lab should be able  


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
;BTN1	(04h)(left)		
;BTN2 (08h)(right)
;==================================================================





dseg at 30h

RANDOM:    DS 1
PREV_BTNS: DS 1



			$ include (c8051F020.inc)
cseg

mov wdtcn,#0DEh  ; disable watchdog
mov wdtcn, #0ADh  ; disable watchdog
mov xbr2, #40h   ; enable port output





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



			  mov	xbr0,#04h			; enable uart 0
				mov	oscxcn,#67H		; turn on external crystal
				mov	tmod,#20H			; wait 1ms using T1 mode 2
				mov	th1,#256-167	; 2MHz clock, 167 counts = 1ms
				setb	tr1


wait1:
				jnb	tf1,wait1
				clr	tr1						; 1ms has elapsed, stop timer
				clr	tf1
wait2:
				mov	a,oscxcn			; now wait for crystal to stabilize
				jnb	acc.7,wait2
				mov	oscicn,#8			; engage! Now using 22.1184MHz

				mov	scon0,#50H		; 8-bit, variable baud, receive enable
				mov	th1,#-6				; 9600 baud
				setb	tr1					; start baud clock

				MOV random, #10   ;start with lights off
				call Lights_out

;============================================================================
;Random Number
;============================================================================

randomize:		jnb tf1, start
							clr tf1
							djnz random, start
							mov random, #10				;random in range of 1-10
							jmp start



;============================================================================
;Receive
;============================================================================

	recieve:
					MOV R0, #00H
					JB 	RI, r_ready
					JMP no_char
	r_ready:MOV	R0, SBUF0
					CLR RI
	no_char:ret
;============================================================================
;Check Button
;============================================================================			
	line:													// goes to the next line in PUTTY
								mov A, #13
								call transfer
								mov A, #10
								call transfer

 start:					call delay
 								mov A, P2
								cpl a								 ; complement a
								xch a, PREV_BTNS  	 ; exchange a with old_buttons
								xrl a, PREV_BTNS  	 ; exclusive or a 
								anl a, PREV_BTNS  	 ; and a with old button
								jb acc.3, magic
								jb acc.2, magic

								call recieve
								CJNE R0, #00H, magic

								sjmp randomize
								sjmp start


;============================================================================
;light led
;============================================================================	

magic:
					mov A, random
					call delay 
					jmp one



;============================================================================
;Delay
;============================================================================	

delay:		mov r7, #200
loop1:		mov r6, #100
loop2:		djnz r6, loop2
					djnz r7, loop1
					ret



;============================================================================
;Turns off leds
;============================================================================	

Lights_out: mov P2, #0ffh
						mov p1, #0ffh
						ret


;============================================================================
;transfer characters
;============================================================================	

transfer:			mov SBUF0, A
send:					jnb TI, send
							clr TI
							ret

;============================================================================
;First - "It is certain"
;============================================================================	

one:			dec A
					jnz two
					call Lights_out
					clr P1.0
					mov A, #"I"
					call transfer
					mov A, #"t"
					call transfer
					mov A, #" "
					call transfer
					mov A, #"i"
					call transfer
					mov A, #"s"
					call transfer
					mov A, #" "
					call transfer
					mov A, #"C"
					call transfer
					mov A, #"e"
					call transfer
					mov A, #"r"
					call transfer
					mov A, #"t"
					call transfer
					mov A, #"a"
					call transfer
					mov A, #"i"
					call transfer
					mov A, #"n"
					call transfer
					jmp line



;============================================================================
;Second - "You may rely on it"
;============================================================================	

two:			dec A
					jnz three
					call Lights_out
					clr P1.1
					mov A, #"Y"
					call transfer
					mov A, #"o"
					call transfer
					mov A, #"u"
					call transfer
					mov A, #" "
					call transfer
					mov A, #"m"
					call transfer
					mov A, #"a"
					call transfer
					mov A, #"y"
					call transfer
					mov A, #" "
					call transfer
					mov A, #"r"
					call transfer
					mov A, #"e"
					call transfer
					mov A, #"l"
					call transfer
					mov A, #"y"
					call transfer
					mov A, #" "
					call transfer
					mov A, #"o"
					call transfer
					mov A, #"n"
					call transfer
					mov A, #" "
					call transfer
					mov A, #"i"
					call transfer
					mov A, #"t"
					call transfer
					jmp line



;============================================================================
;Thirs - "Without a doubt"
;============================================================================	

three:			dec A
					jnz four
					call Lights_out
					clr P1.2
					mov A, #"W"
					call transfer
					mov A, #"i"
					call transfer
					mov A, #"t"
					call transfer
					mov A, #"h"
					call transfer
					mov A, #"o"
					call transfer
					mov A, #"u"
					call transfer
					mov A, #"t"
					call transfer
					mov A, #" "
					call transfer
					mov A, #"a"
					call transfer
					mov A, #" "
					call transfer
					mov A, #"d"
					call transfer
					mov A, #"o"
					call transfer
					mov A, #"u"
					call transfer
					mov A, #"b"
					call transfer
					mov A, #"t"
					call transfer
					jmp line



;============================================================================
;Fourth - "Yes"
;============================================================================	

four:			dec A
					jnz five
					call Lights_out
					clr P1.3
					mov A, #"Y"
					call transfer
					mov A, #"e"
					call transfer
					mov A, #"s"
					call transfer
					jmp line



;============================================================================
;Fifth - "Most Likely"
;============================================================================	

five:			dec A
					jnz six
					call Lights_out
					clr P1.4
					mov A, #"M"
					call transfer
					mov A, #"o"
					call transfer
					mov A, #"s"
					call transfer
					mov A, #"t"
					call transfer
					mov A, #" "
					call transfer
					mov A, #"l"
					call transfer
					mov A, #"i"
					call transfer
					mov A, #"k"
					call transfer
					mov A, #"e"
					call transfer
					mov A, #"l"
					call transfer
					mov A, #"y"
					call transfer
					jmp line


;============================================================================
;Sixth - "Reply hazy, try again"
;============================================================================	

six:			dec A
					jnz seven
					call Lights_out
					clr P1.5
					mov A, #"R"
					call transfer
					mov A, #"e"
					call transfer
					mov A, #"p"
					call transfer
					mov A, #"l"
					call transfer
					mov A, #"y"
					call transfer
					mov A, #" "
					call transfer
					mov A, #"h"
					call transfer
					mov A, #"a"
					call transfer
					mov A, #"z"
					call transfer
					mov A, #"y"
					call transfer
					mov A, #","
					call transfer
					mov A, #" "
					call transfer
					mov A, #"t"
					call transfer
					mov A, #"r"
					call transfer
					mov A, #"y"
					call transfer
					mov A, #" "
					call transfer
					mov A, #"a"
					call transfer
					mov A, #"g"
					call transfer
					mov A, #"a"
					call transfer
					mov A, #"i"
					call transfer
					mov A, #"n"
					call transfer
					jmp line


;============================================================================
;Seventh - "Concentrate and ask again"
;============================================================================	

seven:			dec A
					jnz eight
					call Lights_out
					clr P1.6
					mov A, #"C"
					call transfer
					mov A, #"o"
					call transfer
					mov A, #"n"
					call transfer
					mov A, #"c"
					call transfer
					mov A, #"e"
					call transfer
					mov A, #"n"
					call transfer
					mov A, #"t"
					call transfer
					mov A, #"r"
					call transfer
					mov A, #"a"
					call transfer
					mov A, #"t"
					call transfer
					mov A, #"e"
					call transfer
					mov A, #" "
					call transfer
					mov A, #"a"
					call transfer
					mov A, #"n"
					call transfer
					mov A, #"d"
					call transfer
					mov A, #" "
					call transfer
					mov A, #"a"
					call transfer
					mov A, #"s"
					call transfer
					mov A, #"k"
					call transfer
					mov A, #" "
					call transfer
					mov A, #"a"
					call transfer
					mov A, #"g"
					call transfer
					mov A, #"a"
					call transfer
					mov A, #"i"
					call transfer
					mov A, #"n"
					call transfer
					jmp line



;============================================================================
;Eighth - "Don't count on it"
;============================================================================	

eight:			dec A
					jnz nine
					call Lights_out
					clr P1.7
					mov A, #"D"
					call transfer
					mov A, #"o"
					call transfer
					mov A, #"n"
					call transfer
					mov A, #"'"
					call transfer
					mov A, #"t"
					call transfer
					mov A, #" "
					call transfer
					mov A, #"c"
					call transfer
					mov A, #"o"
					call transfer
					mov A, #"u"
					call transfer
					mov A, #"n"
					call transfer
					mov A, #"t"
					call transfer
					mov A, #" "
					call transfer
					mov A, #"o"
					call transfer
					mov A, #"n"
					call transfer
					mov A, #" "
					call transfer
					mov A, #"i"
					call transfer
					mov A, #"t"
					call transfer
					jmp line



;============================================================================
;Ninth - "Very doubtful"
;============================================================================	

nine:			dec A
					jnz ten
					call Lights_out
					clr P2.4
					mov A, #"V"
					call transfer
					mov A, #"e"
					call transfer
					mov A, #"r"
					call transfer
					mov A, #"y"
					call transfer
					mov A, #" "
					call transfer
					mov A, #"d"
					call transfer
					mov A, #"o"
					call transfer
					mov A, #"u"
					call transfer
					mov A, #"b"
					call transfer
					mov A, #"t"
					call transfer
					mov A, #"f"
					call transfer
					mov A, #"u"
					call transfer
					mov A, #"l"
					call transfer
					jmp line


;============================================================================
;Tenth - "My reply is no"
;============================================================================	

ten:			
					call Lights_out
					clr P2.5
					mov A, #"M"
					call transfer
					mov A, #"y"
					call transfer
					mov A, #" "
					call transfer
					mov A, #"r"
					call transfer
					mov A, #"e"
					call transfer
					mov A, #"p"
					call transfer
					mov A, #"l"
					call transfer
					mov A, #"y"
					call transfer
					mov A, #" "
					call transfer
					mov A, #"i"
					call transfer
					mov A, #"s"
					call transfer
					mov A, #" "
					call transfer
					mov A, #"n"
					call transfer
					mov A, #"o"
					jmp line





					END