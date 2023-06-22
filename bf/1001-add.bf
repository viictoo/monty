,                           ;read and store char in c1
------------------------------------------------ ;ascii to decimal
>                           ;move ptr to p2
,                           ;read and store char in c2
------------------------------------------------ ;ascii to decimal
[                	            ; begin loop
	-                           ; dec c2
		<                           ; go to c1
			+                           ; inc c1
				>                           ; move to c2
]	                            ; cell empty so exit the loop
<       	                    ;c1
++++++++++++++++++++++++++++++++++++++++++++++++     ;return ascii equivalent
.                           ;print output in c1
