   1                     ; C Compiler for STM8 (COSMIC Software)
   2                     ; Generator V4.2.8 - 03 Dec 2008
2807                     ; 11 void GPIO_Init(void)
2807                     ; 12 {
2809                     	switch	.text
2810  0000               _GPIO_Init:
2814                     ; 13   PG_DDR |=0x02;//0B0000 0010 即PG1为输出模式
2816  0000 72125020      	bset	_PG_DDR,#1
2817                     ; 14 	PG_CR1 |=0x02;//即PG_CR1 = PG_CR1 | 0x02  推挽输出
2819  0004 72125021      	bset	_PG_CR1,#1
2820                     ; 15 	PG_CR2 &=0xfd;//0B1111 1101 
2822  0008 72135022      	bres	_PG_CR2,#1
2823                     ; 17 	PB_DDR &=0xfc;//0B1111 1001
2825  000c c65007        	ld	a,_PB_DDR
2826  000f a4fc          	and	a,#252
2827  0011 c75007        	ld	_PB_DDR,a
2828                     ; 18 	PB_CR1 |=0x03;//0B0000 0110
2830  0014 c65008        	ld	a,_PB_CR1
2831  0017 aa03          	or	a,#3
2832  0019 c75008        	ld	_PB_CR1,a
2833                     ; 19 }
2836  001c 81            	ret
2888                     ; 20 void delay(unsigned int x)
2888                     ; 21 {
2889                     	switch	.text
2890  001d               _delay:
2892  001d 5204          	subw	sp,#4
2893       00000004      OFST:	set	4
2896                     ; 23 	 for(i=x;i>0;i--)
2898  001f 1f01          	ldw	(OFST-3,sp),x
2900  0021 2017          	jra	L7202
2901  0023               L3202:
2902                     ; 24 	    for(j=300;j>0;j--);
2904  0023 ae012c        	ldw	x,#300
2905  0026 1f03          	ldw	(OFST-1,sp),x
2906  0028               L3302:
2910  0028 1e03          	ldw	x,(OFST-1,sp)
2911  002a 1d0001        	subw	x,#1
2912  002d 1f03          	ldw	(OFST-1,sp),x
2915  002f 1e03          	ldw	x,(OFST-1,sp)
2916  0031 26f5          	jrne	L3302
2917                     ; 23 	 for(i=x;i>0;i--)
2919  0033 1e01          	ldw	x,(OFST-3,sp)
2920  0035 1d0001        	subw	x,#1
2921  0038 1f01          	ldw	(OFST-3,sp),x
2922  003a               L7202:
2925  003a 1e01          	ldw	x,(OFST-3,sp)
2926  003c 26e5          	jrne	L3202
2927                     ; 25 }
2930  003e 5b04          	addw	sp,#4
2931  0040 81            	ret
2959                     ; 26 main()
2959                     ; 27 { 
2960                     	switch	.text
2961  0041               _main:
2963  0041 89            	pushw	x
2964       00000002      OFST:	set	2
2967                     ; 28   GPIO_Init();
2969  0042 adbc          	call	_GPIO_Init
2971  0044               L1502:
2972                     ; 31     if((IN0==0)&(IN1==0))
2974                     	btst	_IN1
2975  0049 2505          	jrult	L21
2976  004b ae0001        	ldw	x,#1
2977  004e 2001          	jra	L41
2978  0050               L21:
2979  0050 5f            	clrw	x
2980  0051               L41:
2981  0051 1f01          	ldw	(OFST-1,sp),x
2982                     	btst	_IN0
2983  0058 2505          	jrult	L61
2984  005a ae0001        	ldw	x,#1
2985  005d 2001          	jra	L02
2986  005f               L61:
2987  005f 5f            	clrw	x
2988  0060               L02:
2989  0060 01            	rrwa	x,a
2990  0061 1402          	and	a,(OFST+0,sp)
2991  0063 01            	rrwa	x,a
2992  0064 1401          	and	a,(OFST-1,sp)
2993  0066 01            	rrwa	x,a
2994  0067 a30000        	cpw	x,#0
2995  006a 2706          	jreq	L5502
2996                     ; 33 		  LED=0;
2998  006c 7213501e      	bres	_LED
3000  0070 20d2          	jra	L1502
3001  0072               L5502:
3002                     ; 35 	  else if(IN0==0)
3004                     	btst	_IN0
3005  0077 2514          	jrult	L1602
3006                     ; 37 			LED=1;
3008  0079 7212501e      	bset	_LED
3009                     ; 38 			delay(100);
3011  007d ae0064        	ldw	x,#100
3012  0080 ad9b          	call	_delay
3014                     ; 39 			LED=0;
3016  0082 7213501e      	bres	_LED
3017                     ; 40 			delay(100);
3019  0086 ae0064        	ldw	x,#100
3020  0089 ad92          	call	_delay
3023  008b 20b7          	jra	L1502
3024  008d               L1602:
3025                     ; 42 		 else if(IN1==0)
3027                     	btst	_IN1
3028  0092 2515          	jrult	L5602
3029                     ; 44 			LED=1;
3031  0094 7212501e      	bset	_LED
3032                     ; 45 			delay(25);
3034  0098 ae0019        	ldw	x,#25
3035  009b ad80          	call	_delay
3037                     ; 46 			LED=0;
3039  009d 7213501e      	bres	_LED
3040                     ; 47 			delay(25);
3042  00a1 ae0019        	ldw	x,#25
3043  00a4 cd001d        	call	_delay
3046  00a7 209b          	jra	L1502
3047  00a9               L5602:
3048                     ; 53 	    LED=1;
3050  00a9 7212501e      	bset	_LED
3051  00ad 2095          	jra	L1502
3096                     	xdef	_main
3097                     	xdef	_delay
3098                     	xdef	_GPIO_Init
3117                     	end
