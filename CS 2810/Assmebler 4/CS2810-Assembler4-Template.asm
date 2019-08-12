TITLE CS2810 Assembler Template

; Student Name: River Schenck
; Assignment Due Date: July 29 2018

INCLUDE Irvine32.inc
.data
	vsemester byte "CS2810 Summer Semester 2018",0
	vassignment byte "Assembler Assignment #3",0
	vname byte "River Schenck",0
	vPrompt byte "ENTER FAT16 FILE DATE: ",0
	varray	byte "January",0,"  "
			byte "February",0," "
			byte "March",0,"    "
			byte "April",0,"    "
			byte "May",0,"      "
			byte "June",0,"     "
			byte "July",0,"     "
			byte "August",0,"   "
			byte "September",0
			byte "October",0,"  "
			byte "November",0," "
			byte "December",0," "			
	vSuffixes byte "--stndrdthththththththththththththththththstndrdthththththththst",0
	vDay byte " ----,",0
	vYear byte " ----",13,10,0
	

.code
main PROC  

;#1 Clear the display	
	CALL clrscr 
	mov ebx, 0

;#2 Display Semester
;#3 Display Assignment
;#4 Display Name
	CALL DisplaySemester
	CALL DisplayAssignment
	CALL DisplayName

;#5 FAT16 file date
	CALL PROMPT
	CALL MONTH
	CALL DAY
	CALL YEAR




DisplaySemester: 
	mov dh, 4 ; dh=2
	mov dl, 33 ; dl=12
	call gotoxy
	mov edx, offset vsemester
	call WriteString
	ret;

DisplayAssignment:
	mov dh, 5
	mov dl, 33
	call gotoxy
	mov edx, offset vassignment
	call WriteString
	ret;

DisplayName:
	mov dh, 6
	mov dl, 33
	call gotoxy
	mov edx, offset vname
	call WriteString
	ret;

Prompt:
	mov dh, 8
	mov dl, 33
	call gotoxy
	mov edx, offset vPrompt
	call WriteString
	call ReadHex ;get input
	ROR ax, 8 ; LITTLE ENDIAN
	mov ecx, eax 
	ret

Month:
	mov dh, 10
	mov dl, 33
	call gotoxy
	AND ax, 0000000111100000b ;MASKING MIDDLE 4 BITS
	SHR ax, 5 ;SHIFT TO GET NUMBER
	;-----<Month Code>-----	
	;mov eax, 1
	sub eax, 1
	mov edx, offset [varray]
	mov bl, 10
	mul bl
	add edx, eax
	call WriteString
	ret

Day:
	MOV eax, ecx ;RESTORE NUMBER
	AND ax, 0000000000011111b; MASKING RIGHT 5 BITS
	MOV BH, 10
	DIV BH
	ADD ax, 3030h
	MOV word ptr [vDay+1], ax
	;-----<Suffix code>-----
	mov eax, ecx
	AND ax, 0000000000011111b; MASKING RIGHT 5 BITS
	shl eax, 1  ;shift binary by 1 multiplies by 2
	mov edx, offset [vSuffixes] ;pull in Suffixes
	add edx, eax
	mov bx, word ptr [edx]
	mov word ptr [vDay+3], bx
	mov edx, offset [vDay]
	call WriteString
	ret

Year:
	mov eax, ecx
	AND ax, 1111111000000000b ;MASKING LEFT 7 BITS
	SHR ax, 9 ;SHIFT TO GET NUMBER
	mov dx, 1980
	add ax, dx
	;-----<Year to ascii Code>-----
	xor dx, dx
	mov bx, 1000
	div bx
	add al, 30h
	mov byte ptr [vYear+1], al
	mov ax, dx
	xor dx, dx
	mov bx, 100
	div bx
	add al, 30h
	mov byte ptr [vYear+2], al
	mov ax, dx
	mov bl, 10
	div bl
	add ax, 3030h
	mov word ptr [vYear+3],ax
	mov edx, offset [vYear]
	call WriteString








	xor ecx, ecx
	call ReadChar


	exit
main ENDP

END main