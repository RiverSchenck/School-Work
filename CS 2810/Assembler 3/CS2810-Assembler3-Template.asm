TITLE CS2810 Assembler Template

; Student Name: River Schenck
; Assignment Due Date: July 29 2018

INCLUDE Irvine32.inc
.data
	vsemester byte "CS2810 Summer Semester 2018",0
	vassignment byte "Assembler Assignment #3",0
	vname byte "River Schenck",0
	vPrompt byte "ENTER MP3 FRAME HEADER IN HEX FORMAT: ",0
	vMpeg25 byte "MPEG Version 2.5",0
	vMpeg20 byte "MPEG Version 2.0",0
	vMpeg10 byte "MPEG Version 1.0",0
	vMpegRE byte "MPEG Reserved",0
	vLayerR byte "Layer Reserved",0
	vLayer3 byte "LayerIII",0
	vLayer2 byte "LayerII",0
	vLayer1 byte "LayerI",0
	vSample1V1 byte "Sampling Rate: 44100 Hz",0
	vSample1V2 byte "Sampling Rate: 22050 Hz",0
	vSample1V3 byte "Sampling Rate: 11025 Hz",0
	vSample2V1 byte "Sampling Rate: 48000 Hz",0
	vSample2V2 byte "Sampling Rate: 24000 Hz",0
	vSample2V3 byte "Sampling Rate: 12000 Hz",0
	vSample3V1 byte "Sampling Rate: 32000 Hz",0
	vSample3V2 byte "Sampling Rate: 16000 Hz",0
	vSample3V3 byte "Sampling Rate: 8000 Hz",0
	vSample4 byte "Sampling Rate: Reserved",0
	

.code
main PROC

;Try 0FFFB9264h
	;Version 1
	;LayerIII
	;44,100Hz

;Try 0FFF240C0h
	;Version 2
	;LayerIII
	;22,050 Hz

;Try 0FFFBA040h
	;Version 1
	;LayerIII
	;44,100Hz

;#1 Clear the display	
	CALL clrscr 
	mov ebx, 0

;#2 Display Semester
;#3 Display Assignment
;#4 Display Name
	CALL DisplaySemester
	CALL DisplayAssignment
	CALL DisplayName

;#5 Prompt
	CALL Prompt

;#6 MP3
	CALL DisplayVersion
	CALL Layer
	CALL Sampling





DisplaySemester: 
	mov dh, 10 ; dh=2
	mov dl, 12 ; dl=12
	call gotoxy
	mov edx, offset vsemester
	call WriteString
	ret;

DisplayAssignment:
	mov dh, 11
	mov dl, 12
	call gotoxy
	mov edx, offset vassignment
	call WriteString
	ret;

DisplayName:
	mov dh, 12
	mov dl, 12
	call gotoxy
	mov edx, offset vname
	call WriteString
	ret;

Prompt:
	mov dh, 13
	mov dl, 12
	call gotoxy
	mov edx, offset vPrompt
	call WriteString
	;get input
	mov dh, 14
	mov dl, 12
	call gotoxy
	call ReadHex
	mov ecx, eax ; move for future use
	ret;





DisplayVersion:
			;AAAAAAAAAAABBCCDEEEEFFGHIIJJKLMM
	and eax, 00000000000110000000000000000000b ;mask bits
	shr eax, 19 ;rotate to number
		mov dh, 15 
		mov dl, 12
		call gotoxy

	cmp eax, 00b
	jz dMpeg25

	cmp eax, 01b
	jz dMpegRE
	
	cmp eax, 10b
	jz dMpeg20

	mov edx, offset vMpeg10
	mov ebx, 01b
	jmp DisplayStringVersion

dMpeg25:
	mov ebx, 11b;
	mov edx, offset vMpeg25
	jmp DisplayStringVersion

dMpegRE:
	mov edx, offset vMpegRe
	jmp DisplayStringVersion

dMpeg20:
	mov ebx, 10b;
	mov edx, offset vMPeg20
	jmp DisplayStringVersion

DisplayStringVersion:
	call WriteString
	ret ;return DisplayVersion





Layer:
			;AAAAAAAAAAABBCCDEEEEFFGHIIJJKLMM
	mov eax, ecx ;reset
	and eax, 00000000000001100000000000000000b ;mask bits
	shr eax, 17 ;rotate to number
		mov dh, 16 
		mov dl, 12
		call gotoxy

	cmp eax, 00b
	jz LayerR

	cmp eax, 01b
	jz Layer3
	
	cmp eax, 10b
	jz Layer2

	mov edx, offset vLayer1
	jmp DisplayStringLayer

LayerR:
	mov edx, offset vLayerR
	jmp DisplayStringLayer

Layer3:
	mov edx, offset vLayer3
	jmp DisplayStringLayer

Layer2:
	mov edx, offset vLayer2
	jmp DisplayStringLayer

DisplayStringLayer:
	call WriteString
	ret ;return DisplayVersion


Sampling:

	mov eax, ecx; reset
			;AAAAAAAAAAABBCCDEEEEFFGHIIJJKLMM
	and eax, 00000000000000000000110000000000b ;mask bits
	shr eax, 10 ;rotate to number
		mov dh, 17 
		mov dl, 12
		call gotoxy

	cmp eax, 00b
	jz Sample1

	cmp eax, 01b
	jz Sample2
	
	cmp eax, 10b
	jz Sample3

	mov edx, offset vSample4
	jmp DisplayStringSample

Sample1:
	cmp ebx, 01b
	jz Sample1V1

	cmp ebx, 10b
	jz Sample1V2
	
	mov edx, offset vSample1V3
	jmp DisplayStringSample

Sample2:
	cmp ebx, 01b
	jz Sample2V1

	cmp ebx, 10b
	jz Sample2V2
	
	mov edx, offset vSample2V3
	jmp DisplayStringSample

Sample3:
	cmp ebx, 01b
	jz Sample3V1

	cmp ebx, 10b
	jz Sample3V2
	
	mov edx, offset vSample3V3
	jmp DisplayStringSample

	Sample1V1:
		mov edx, offset vSample1V1
		jmp DisplayStringSample

	Sample1V2:
		mov edx, offset vSample1V2
		jmp DisplayStringSample

	Sample2V1:
		mov edx, offset vSample2V1
		jmp DisplayStringSample

	Sample2V2:
		mov edx, offset vSample2V3
		jmp DisplayStringSample

	Sample3V1:
		mov edx, offset vSample3V1
		jmp DisplayStringSample

	Sample3V2:
		mov edx, offset vSample3V3
		jmp DisplayStringSample


DisplayStringSample:
	call WriteString
	ret ;return DisplaySample








	xor ecx, ecx
	call ReadChar

	exit
main ENDP

END main










