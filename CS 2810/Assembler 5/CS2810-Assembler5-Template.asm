TITLE CS2810 Assembler Template

; Student Name: River Schenck
; Assignment Due Date: July 29 2018

INCLUDE Irvine32.inc
.data
	vsemester byte "CS2810 Summer Semester 2018",0
	vassignment byte "Assembler Assignment #5",0
	vname byte "River Schenck",0
	vPrompt byte "Guess a number between 0 and 100: ",0
	vtoohigh byte " is too high",0
	vtoolow byte " is too low",0
	vplayagain byte "Would you like to play again? (1 for yes, 0 for no)",0
	vCarriageReturn byte 13,10,0
	vGuessagain byte "Guess Again: ",0
	vCorrect byte " is correct!"



.code
main PROC
Start:

;#1 Clear the display	
	CALL clrscr 
	mov ebx, 0

;#2 Display Semester
;#3 Display Assignment
;#4 Display Name
	CALL DisplaySemester
	CALL DisplayAssignment
	CALL DisplayName

;#6 Random Number
;#7 Prompt
	CALL RandomNumber
	CALL Prompt
	;CALL Input

;#8 Higher or Lower


Loopit:
	call ReadDec
	call WriteDec
	cmp eax, ecx
	JG Toohigh; Guess is greater than
	JL TooLow; Guess is less than
	jmp Gotit

Gotit:
	mov edx, offset vCorrect
	call WriteString
	mov edx, offset vCarriageReturn
	call WriteString
	mov edx, offset vplayagain
	call WriteString
	mov edx, offset vCarriageReturn
	call WriteString
	mov eax, 0
	call ReadDec
	cmp eax, 0
	JZ Over
	jmp start

Over:
	exit
	
	
	
TooHigh:
	mov edx, offset vTooHigh
	call WriteString
	jmp GuessAgain	
	
TooLow:
	mov edx, offset vTooLow
	call WriteString
	jmp GuessAgain
	

GuessAgain:
	mov edx, offset vCarriageReturn
	call WriteString
	mov edx, offset vGuessagain
	call WriteString
	jmp Loopit;
	
DisplaySemester: 
	mov dh, 4 ; dh=2
	mov dl, 0 ; dl=12
	call gotoxy
	mov edx, offset vsemester
	call WriteString
	ret;

DisplayAssignment:
	mov dh, 5
	mov dl, 0
	call gotoxy
	mov edx, offset vassignment
	call WriteString
	ret;

DisplayName:
	mov dh, 6
	mov dl, 0
	call gotoxy
	mov edx, offset vname
	call WriteString
	ret;

Prompt:
	mov dh, 8
	mov dl, 0
	call gotoxy
	mov edx, offset vPrompt
	call WriteString
	ret;

RandomNumber:
	Call Randomize
	mov eax, 101
	Call RandomRange
	;Call WriteDec
	mov ecx, eax ;holds random number
	ret;

Input:
	mov edx, offset vCarriageReturn
	call WriteString
	call ReadDec
	call writeDec
	ret;


	exit
main ENDP

END main










