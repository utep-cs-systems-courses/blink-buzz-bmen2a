	.arch msp430g2553

	.p2align 1,0
	.text



def:

	.global toggle_green
	.extern green_on
	.extern red_on



toggle_green:
	.word changed
	.movb #0, &changed
	.cmp #0, red_on 	; if(red_on)
	jmp off
	xor  #1, &green_on	;green_on ^=1
	movb #1, &changed	; changed=1
	pop r0
off:	

	return changed		;return changed
