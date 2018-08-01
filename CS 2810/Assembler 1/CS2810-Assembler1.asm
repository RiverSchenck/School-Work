TITLE CS2810 Assembler Template

; Student Name:
; Assignment Due Date:

INCLUDE Irvine32.inc
.data
	vsemester byte "Cs2810 Summer Semester 2018",0
	vassignment byte "Assembler Assignment #1",0
	vname byte "River Schenck",0
	

.code
main PROC

	call clrscr

	mov dh, 2 ; dh=2
	mov dl, 12 ; dl=12
	call gotoxy

	mov edx, offset vsemester
	call WriteString

	mov dh, 4
	mov dl,12
	call gotoxy

	mov edx, offset vname
	call WriteString

	mov dh, 3
	mov dl, 12
	call gotoxy

	mov edx, offset vassignment
	call WriteString

	xor ecx, ecx
	call ReadChar




	exit
main ENDP

END main