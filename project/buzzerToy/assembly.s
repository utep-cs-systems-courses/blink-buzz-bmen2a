	.arch msp430g2553

	.p2align 1,0



	.text



def:

	.word




toggle_green:
	.cmp #0, r12 		; if(red_on)
	jz off
	bis #64, &green_on	;green_on ^=1
				; changed=1
	pop r0
off:	

	pop r0 			;return changed
