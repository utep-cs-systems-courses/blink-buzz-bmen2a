	.arch msp430g2553

	.p2align 1,0
	.text



def:

	.global toggle_green
	.extern green_on
	.extern red_on



toggle_green:
	.word changed
	.mov #0, &changed
	.mov &changed, r12
	.cmp #0, red_on 	; if(red_on)
	je off
	xor  #1, &green_on	;green_on ^=1
	mov.b #1, r12		; changed=1
	pop r0
off:	

	ret		;return changed
