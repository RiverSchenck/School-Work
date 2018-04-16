;Title:  ECE 3710 Lab 5
;Author: River Schenck
;Description: 


;==================================================================						
;BTN1	(04h)(left)		
;BTN2 (08h)(right)
;==================================================================

$include (c8051f020.inc)

dseg at 30h
random: ds 1
PREV_BTNS: ds 1
tenths: ds 1
seconds: ds 1
t_ten: ds 1
t_sec: ds 1



cseg at 00h
 ljmp main
		
				
				org 0023h 		; serial interupt
				ljmp serial


				org 002bh			;timer 2
				clr t2con.7		;clear flag
				ljmp sample_buttons


ORG 40h
main:

mov wdtcn,#0DEh  ; disable watchdog
mov wdtcn, #0ADh  ; disable watchdog
mov xbr0, #04h
mov xbr2, #40h   ; enable port output


;=========================================================================
;INPUTS 
;=========================================================================
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
;========================================================================
;OUTPUTS
;========================================================================
       LED1_8 EQU P1
       LED9 bit P2.4
			 LED10 bit P2.5
			 timer_value		equ 65535-1667		;10 ms delay with 2 mhz processing speed





								mov	xbr0,#04h	; enable uart 0
								mov	oscxcn,#67H	; turn on external crystal
								mov	tmod,#20H	; wait 1ms using T1 mode 2
								mov t2con, #04h
								mov	th1,#256-167	; 2MHz clock, 167 counts = 1ms
								setb	tr1
	wait1:
								jnb	tf1,wait1
								clr	tr1		; 1ms has elapsed, stop timer
								clr	tf1
	wait2:
								mov	a,oscxcn	; now wait for crystal to stabilize
								jnb	acc.7,wait2
								mov	oscicn,#8	; engage! Now using 22.1184MHz

								mov r5, #10
								mov tenths, #0
								mov seconds, #0
								clr psw.1

								mov	scon0,#50H	; 8-bit, variable baud, receive enable
								mov	th1,#-6		; 9600 baud
								mov IE, #0B3h
								mov IP, #30h
								setb	tr1		; start baud clock

								setb	tr2
								mov rcap2h, #high(-18432)
								mov rcap2l, #low(-18432)


;===============================================================================
;Main
;===============================================================================
program:	

sjmp program


;===============================================================================
;button sampling
;===============================================================================
sample_buttons: push Acc
								mov a, p2
								cpl a								 ; complement a
								xch a, PREV_BTNS  	 ; exchange a with old_buttons
								xrl a, PREV_BTNS  	 ; exclusive or a 
								anl a, PREV_BTNS  	 ; and a with old button
								jb	acc.2, reset
								jb	acc.3, toggle
								sjmp	start_stop



;===============================================================================
;button one start/stop unless at 10
;===============================================================================
toggle:					mov A, p1
								cjne A, #5fh, good_to_go
								clr psw.1
								jmp finish
good_to_go:			cpl psw.1
								sjmp start_stop


;===============================================================================
;resets
;===============================================================================
reset:					clr psw.1
								mov tenths, #0
								mov seconds, #0
								mov r5, #10
								mov P1, #0ffh
								sjmp finish


;===============================================================================
;turn off
;===============================================================================
start_stop:			jnb psw.1, finish
								djnz r5, finish
								mov r5, #10
								inc tenths


display:				mov P1, #0ffh
								mov A, tenths
								mov dptr, #tenths_table
								movc a, @a+dptr
								anl P1, A
								mov A, tenths
								cjne A, #0Ah, step_2
								mov tenths, #0
								inc seconds

step_2:					mov A, seconds
								mov dptr, #seconds_table
								movc A, @a+dptr
								anl P1, a

								mov A, P1
								cjne A, #05Fh, finish								
								cpl psw.1

finish:					POP Acc
								RETI

;===============================================================================
;LUT
;===============================================================================
tenths_table:  db 0FFH, 0FEH, 0FDH, 0FCH, 0FBH, 0FAH, 0F9H, 0F8H, 0F7H, 0F6H, 0FFH
seconds_table: db 0FFH, 0EFH, 0DFH, 0CFH, 0BFH, 0AFH, 09FH, 08FH, 07FH, 06FH, 05FH



;===============================================================================
;serial interupt
;===============================================================================
serial:					jb ti, trans
								mov A, sbuf0
								cjne A, #72h, check_s
								mov A, P1
								cjne A, #5fh, good_to_gos
								clr psw.1
								jmp over
good_to_gos:		setb psw.1
								jmp over
check_s:				cjne A, #73h, check_c
								clr psw.1
								jmp over							
check_c:				cjne A, #63h, check_t
								clr psw.1
								mov tenths, #0
								mov seconds, #0
								mov r5, #10
								mov P1, #0ffh
								jmp over
check_t:				cjne A, #74h, over
								mov t_sec, seconds
								mov t_ten, tenths
								mov r6, #4
								mov dptr, #mess_sec
								mov A, t_sec
								movc A, @a+dptr
								mov sbuf0, A
								clr ti
								clr ri
								reti


over:						clr ri
								reti

trans:					mov A, t_sec
								cjne A, #10, not_ten
								inc A
								movc A, @a+dptr
								mov sbuf0, A
								inc t_sec
								clr ti
								reti

not_ten:				mov A, r6
								cjne A, #4, send_tenths
								jz send_10
								mov A, #"."
								mov sbuf0, A
								dec r6
								clr ti
								reti

send_tenths: 		cjne A, #3, send_13
								mov dptr, #mess_ten
								mov A, t_ten
								movc A, @a+dptr
								mov sbuf0, A
								dec r6
								clr ti
								reti

send_13:				cjne A, #2, send_10
								mov A, #13
								mov sbuf0, A
								dec r6
								clr ti
								reti

send_10:				cjne A, #1, done
								mov a, #10
								mov sbuf0, A
								dec r6
								clr ti

done:						clr ti
								reti


;===============================================================================
;strings
;===============================================================================
mess_sec:		db			"012345678910",0
mess_ten:   db			"0123456789",0


end
