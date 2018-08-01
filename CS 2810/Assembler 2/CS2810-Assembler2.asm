TITLE CS2810 Assembler Template

; Student Name: River Schenck
; Assignment Due Date: 7/23/2018

INCLUDE Irvine32.inc
.data
	vsemester byte "CS2810 Summer Semester 2018",0
	vassignment byte "Assembler Assignment #2",0
	vname byte "River Schenck",0
	vTimeField byte "--:--:--",0
	vPrompt byte "ENTER FAT16 TIME IN HEX FORMAT: ",0
	

.code
main PROC

	;Clear the display
	CALL clrscr

;**************************************************************
	;Prompt the user for FAT16 file time in hex format and allow the user to enter it on row 19, column 20.
	mov dh, 19
	mov dl, 20
	CALL gotoxy
	mov edx, offset vPrompt
	call WriteString

	;get input
	CALL ReadHex




;**************************************************************
; FIRST 5 BITS FOR HOUR

	ROR ax, 8 ; LITTLE ENDIAN
	MOV ecx, eax ; SAVING VALUE IN ECX FOR FUTURE USE
	AND ax, 1111100000000000b ; MASKING FIRST 5 BITS FOR HOUR
	SHR ax, 11 ; SHIFT 11 OVER TO GET NUMBER
	MOV BH, 10
	DIV BH
	ADD ax, 3030h ; FOR ACCURATE ASCII
	MOV word ptr [vTimeField+0], ax ; INPUT IN VTIMEFIELD
	;call WriteString

;**************************************************************
; MIDDLE 6 BITS FOR MINUTES

	MOV eax, ecx
	AND ax, 0000011111100000b
	SHR ax, 5
	MOV BH, 10
	DIV BH
	ADD ax, 3030h
	MOV word ptr [vTimeField+3], ax
	;call WriteString

;**************************************************************
; LAST 5 BITS X2 FOR SECONDS

	MOV eax, ecx
	AND ax, 0000000000011111b
	SHL ax, 1
	MOV BH, 10
	DIV BH
	ADD ax, 3030h
	MOV word ptr [vTimeField+6], ax
	;Call WriteString
		
		;Display the converted file time on row 20, column 20.
		MOV dh, 20
		MOV dl, 20
		CALL gotoxy
		mov edx, OFFSET vTimeField
		call WriteString
		




	;**************************************************************
	; DISPLAY STRINGS

		; Display the string "CS 2810 Spring Semester 2018" on row 15 column 20 of the display.
		mov dh, 15 ; 
		mov dl, 20 ; 
		call gotoxy

		mov edx, offset vsemester
		call WriteString

		; Display your name on row 17, column 20 of the display.
		mov dh, 17
		mov dl, 20
		call gotoxy

		mov edx, offset vname
		call WriteString

		; Display the string "Assembler Assignment #2" on row 16, column 20.
		mov dh, 16
		mov dl, 20
		call gotoxy

		mov edx, offset vassignment
		call WriteString

	xor ecx, ecx
	call ReadChar


	exit
main ENDP

END main