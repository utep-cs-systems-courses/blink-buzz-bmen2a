	.arch msp430g2553
	.p2align 1,0
	.text


	.global greenControln	;allows this variable to be use everywhere
	.extern P1OUT

greenControl:
	cmp #0, r12		;compare destication and sourse
	jz off			;jmp to off , 2^6=64, green== bit 6
	bis #64, &P1OUT		;or
	pop r0
off:	and #~64, &P1OUT
	pop r0
