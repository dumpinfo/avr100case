	.module httpserv.c
	.area text(rom, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
_html_mt:
	.blkw 1
	.area idata
	.word L2
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
	.dbsym s html_mt _html_mt pc
	.area text(rom, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
	.dbfunc s ASPCallback _ASPCallback fI
	.dbstruct 0 0 __iobuf
	.dbend
;         stream -> R10,R11
;   pASPFunction -> R12,R13
	.even
_ASPCallback:
	xcall push_xgset003C
	movw R10,R18
	movw R12,R16
	.dbline -1
	.dbline 263
; /*
;  * Copyright (C) 2001-2004 by egnite Software GmbH. All rights reserved.
;  *
;  * Redistribution and use in source and binary forms, with or without
;  * modification, are permitted provided that the following conditions
;  * are met:
;  *
;  * 1. Redistributions of source code must retain the above copyright
;  *    notice, this list of conditions and the following disclaimer.
;  * 2. Redistributions in binary form must reproduce the above copyright
;  *    notice, this list of conditions and the following disclaimer in the
;  *    documentation and/or other materials provided with the distribution.
;  * 3. Neither the name of the copyright holders nor the names of
;  *    contributors may be used to endorse or promote products derived
;  *    from this software without specific prior written permission.
;  *
;  * THIS SOFTWARE IS PROVIDED BY EGNITE SOFTWARE GMBH AND CONTRIBUTORS
;  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
;  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
;  * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL EGNITE
;  * SOFTWARE GMBH OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
;  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
;  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
;  * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
;  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
;  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
;  * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
;  * SUCH DAMAGE.
;  *
;  * For additional information see http://www.ethernut.de/
;  *
;  */
; 
; /*!
;  * $Log$
;  * Revision 1.21  2009/02/18 12:18:58  olereinhardt
;  * 2009-02-18  Ole Reinhardt <ole.reinhardt@thermotemp.de>
;  *
;  *           Fixed compilier warnings. Especialy signedness of char buffers
;  *           as well as unused code on arm platform and main functions without
;  *           return value
;  *
;  * Revision 1.20  2009/02/06 15:37:40  haraldkipp
;  * Added stack space multiplier and addend. Adjusted stack space.
;  *
;  * Revision 1.19  2008/07/25 10:20:12  olereinhardt
;  * Fixed compiler bug for AVR-ICC and added missing PSTR macro around
;  * prog_char strings
;  *
;  * Revision 1.18  2008/07/17 11:56:20  olereinhardt
;  * Updated the webserver demo to show new webserver functions (different cgi
;  * pathes with seperate authentication, $QUERY_STRING parameter for ssi
;  * included CGIs)
;  *
;  * Revision 1.17  2008/05/13 19:31:34  thiagocorrea
;  * NutHttpSendHeaderBot is marked as deprecated, use NutHttpSendHeaderBottom instead.
;  *
;  * Revision 1.16  2007/07/17 18:29:30  haraldkipp
;  * Server thread names not unique on SAM7X. Fixed by Marti Raudsepp.
;  *
;  * Revision 1.15  2006/09/07 09:01:36  haraldkipp
;  * Discovery registration added.
;  * Re-arranged network interface setup to exclude DHCP code from ICCAVR
;  * builds and make it work with the demo compiler. Unfinished.
;  * Added PHAT file system support. Untested.
;  *
;  * Revision 1.14  2006/03/02 19:44:03  haraldkipp
;  * MMC and PHAT enabled.
;  *
;  * Revision 1.13  2006/01/11 08:32:57  hwmaier
;  * Added explicit type casts to silence a few avr-gcc 3.4.3 warning messages
;  *
;  * Revision 1.12  2005/11/22 09:14:13  haraldkipp
;  * Replaced specific device names by generalized macros.
;  *
;  * Revision 1.11  2005/10/16 23:22:20  hwmaier
;  * Removed unreferenced nutconfig.h include statement
;  *
;  * Revision 1.10  2005/08/05 11:32:50  olereinhardt
;  * Added SSI and ASP sample
;  *
;  * Revision 1.9  2005/04/05 18:04:17  haraldkipp
;  * Support for ARM7 Wolf Board added.
;  *
;  * Revision 1.8  2005/02/23 04:39:26  hwmaier
;  * no message
;  *
;  * Revision 1.7  2005/02/22 02:44:34  hwmaier
;  * Changes to compile as well for AT90CAN128 device.
;  *
;  * Revision 1.6  2004/12/16 10:17:18  haraldkipp
;  * Added Mikael Adolfsson's excellent parameter parsing routines.
;  *
;  * Revision 1.5  2004/03/16 16:48:26  haraldkipp
;  * Added Jan Dubiec's H8/300 port.
;  *
;  * Revision 1.4  2003/11/04 17:46:52  haraldkipp
;  * Adapted to Ethernut 2
;  *
;  * Revision 1.3  2003/09/29 16:33:12  haraldkipp
;  * Using portable strtok and strtok_r
;  *
;  * Revision 1.2  2003/08/07 08:27:58  haraldkipp
;  * Bugfix, remote not displayed in socket list
;  *
;  * Revision 1.1  2003/07/20 15:56:14  haraldkipp
;  * *** empty log message ***
;  *
;  */
; 
; /*!
;  * \example httpd/httpserv.c
;  *
;  * Simple multithreaded HTTP daemon.
;  */
; 
; /* 
;  * Unique MAC address of the Ethernut Board. 
;  *
;  * Ignored if EEPROM contains a valid configuration.
;  */
; #define MY_MAC  "\x00\x06\x98\x30\x00\x35"
; 
; /* 
;  * Unique IP address of the Ethernut Board. 
;  *
;  * Ignored if DHCP is used. 
;  */
; #define MY_IPADDR "192.168.192.35"
; 
; /* 
;  * IP network mask of the Ethernut Board.
;  *
;  * Ignored if DHCP is used. 
;  */
; #define MY_IPMASK "255.255.255.0"
; 
; /* 
;  * Gateway IP address for the Ethernut Board.
;  *
;  * Ignored if DHCP is used. 
;  */
; #define MY_IPGATE "192.168.192.1"
; 
; /* ICCAVR Demo is limited. Try to use the bare minimum. */
; #if !defined(__IMAGECRAFT__)
; 
; /* Wether we should use DHCP. */
; #define USE_DHCP
; /* Wether we should run a discovery responder. */
; #define USE_DISCOVERY
; /* Wether to use PHAT file system. */
; //#define USE_PHAT
; 
; #endif /* __IMAGECRAFT__ */
; 
; 
; #ifdef USE_PHAT
; 
; #if defined(ETHERNUT3)
; 
; /* Ethernut 3 file system. */
; #define MY_FSDEV       devPhat0
; #define MY_FSDEV_NAME  "PHAT0" 
; 
; /* Ethernut 3 block device interface. */
; #define MY_BLKDEV      devNplMmc0
; #define MY_BLKDEV_NAME "MMC0"
; 
; #elif defined(AT91SAM7X_EK)
; 
; /* SAM7X-EK file system. */
; #define MY_FSDEV       devPhat0
; #define MY_FSDEV_NAME  "PHAT0" 
; 
; /* SAM7X-EK block device interface. */
; #define MY_BLKDEV      devAt91SpiMmc0
; #define MY_BLKDEV_NAME "MMC0"
; 
; #elif defined(AT91SAM9260_EK)
; 
; /* SAM9260-EK file system. */
; #define MY_FSDEV       devPhat0
; #define MY_FSDEV_NAME  "PHAT0" 
; 
; /* SAM9260-EK block device interface. */
; #define MY_BLKDEV      devAt91Mci0
; #define MY_BLKDEV_NAME "MCI0"
; 
; #endif
; #endif /* USE_PHAT */
; 
; #ifndef MY_FSDEV
; #define MY_FSDEV        devUrom
; #endif
; 
; #ifdef MY_FSDEV_NAME
; #define MY_HTTPROOT     MY_FSDEV_NAME ":/" 
; #endif
; 
; 
; #include <cfg/os.h>
; 
; #include <string.h>
; #include <io.h>
; #include <fcntl.h>
; #include <time.h>
; 
; #include <dev/board.h>
; #include <dev/urom.h>
; #include <dev/nplmmc.h>
; #include <dev/sbimmc.h>
; #include <fs/phatfs.h>
; 
; #include <sys/version.h>
; #include <sys/thread.h>
; #include <sys/timer.h>
; #include <sys/heap.h>
; #include <sys/confnet.h>
; #include <sys/socket.h>
; 
; #include <arpa/inet.h>
; #include <net/route.h>
; 
; #include <pro/httpd.h>
; #include <pro/dhcp.h>
; #include <pro/ssi.h>
; #include <pro/asp.h>
; #include <pro/discover.h>
; 
; #ifdef NUTDEBUG
; #include <sys/osdebug.h>
; #include <net/netdebug.h>
; #endif
; 
; /* Server thread stack size. */
; #ifndef HTTPD_SERVICE_STACK
; #if defined(__AVR__)
; #define HTTPD_SERVICE_STACK ((580 * NUT_THREAD_STACK_MULT) + NUT_THREAD_STACK_ADD)
; #elif defined(__arm__)
; #define HTTPD_SERVICE_STACK ((1024 * NUT_THREAD_STACK_MULT) + NUT_THREAD_STACK_ADD)
; #else
; #define HTTPD_SERVICE_STACK  ((2048 * NUT_THREAD_STACK_MULT) + NUT_THREAD_STACK_ADD)
; #endif
; #endif
; 
; static char *html_mt = "text/html";
; 
; 
; /**************************************************************/
; /*  ASPCallback                                               */
; /*                                                            */
; /* This routine must have been registered by                  */
; /* NutRegisterAspCallback() and is automatically called by    */
; /* NutHttpProcessFileRequest() when the server process a page */
; /* with an asp function.                                      */
; /*                                                            */
; /* Return 0 on success, -1 otherwise.                         */
; /**************************************************************/
; 
; 
; static int ASPCallback (char *pASPFunction, FILE *stream)
; {
	.dbline 264
;     if (strcmp(pASPFunction, "usr_date") == 0) {
	ldi R18,<L6
	ldi R19,>L6
	movw R16,R12
	xcall _strcmp
	cpi R16,0
	cpc R16,R17
	brne L4
X0:
	.dbline 264
	.dbline 265
;         fprintf(stream, "Dummy example: 01.01.2005");
	ldi R18,<L7
	ldi R19,>L7
	movw R16,R10
	xcall _fprintf
	.dbline 266
;         return(0);
	clr R16
	clr R17
	xjmp L3
L4:
	.dbline 269
;     }
; 
;     if (strcmp(pASPFunction, "usr_time") == 0) {
	ldi R18,<L10
	ldi R19,>L10
	movw R16,R12
	xcall _strcmp
	cpi R16,0
	cpc R16,R17
	brne L8
X1:
	.dbline 269
	.dbline 270
;         fprintf(stream, "Dummy example: 12:15:02");
	ldi R18,<L11
	ldi R19,>L11
	movw R16,R10
	xcall _fprintf
	.dbline 271
;         return(0);
	clr R16
	clr R17
	xjmp L3
L8:
	.dbline 274
;     }
; 
;     return (-1);
	ldi R16,-1
	ldi R17,-1
	.dbline -2
L3:
	.dbline 0 ; func end
	xjmp pop_xgset003C
	.dbsym r stream 10 pS[__iobuf]
	.dbsym r pASPFunction 12 pc
	.dbend
	.area lit(rom, con, rel)
L13:
	.byte 60,'H,'T,'M,'L,62,60,'H,'E,'A,'D,62,60,'T,'I,'T
	.byte 'L,'E,62,'P,'a,'r,'a,'m,'e,'t,'e,'r,'s,60,47,'T
	.byte 'I,'T,'L,'E,62,60,47,'H,'E,'A,'D,62,60,'B,'O,'D
	.byte 'Y,62,60,'H,49,62,'P,'a,'r,'a,'m,'e,'t,'e,'r,'s
	.byte 60,47,'H,49,62,0
L14:
	.byte 60,47,'B,'O,'D,'Y,62,60,47,'H,'T,'M,'L,62,0
L15:
	.byte 'M,'e,'t,'h,'o,'d,58,32,37,'s,60,'B,'R,62,13,10
	.byte 'V,'e,'r,'s,'i,'o,'n,58,32,'H,'T,'T,'P,47,37,'d
	.byte 46,37,'d,60,'B,'R,62,13,10,'C,'o,'n,'t,'e,'n,'t
	.byte 32,'l,'e,'n,'g,'t,'h,58,32,37,'l,'d,60,'B,'R,62
	.byte 13,10,0
L16:
	.byte 'U,'R,'L,58,32,37,'s,60,'B,'R,62,13,10,0
L17:
	.byte 'A,'r,'g,'u,'m,'e,'n,'t,58,32,37,'s,60,'B,'R,62
	.byte 13,10,0
L18:
	.byte 'C,'o,'n,'t,'e,'n,'t,32,'t,'y,'p,'e,58,32,37,'s
	.byte 60,'B,'R,62,13,10,0
L19:
	.byte 'C,'o,'o,'k,'i,'e,58,32,37,'s,60,'B,'R,62,13,10
	.byte 0
L20:
	.byte 'A,'u,'t,'h,32,'i,'n,'f,'o,58,32,37,'s,60,'B,'R
	.byte 62,13,10,0
L21:
	.byte 'U,'s,'e,'r,32,'a,'g,'e,'n,'t,58,32,37,'s,60,'B
	.byte 'R,62,13,10,0
	.area text(rom, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
	.dbfunc s ShowQuery _ShowQuery fI
	.dbstruct 0 34 _REQUEST
	.dbfield 0 req_method I
	.dbfield 2 req_version I
	.dbfield 4 req_length L
	.dbfield 8 req_url pc
	.dbfield 10 req_query pc
	.dbfield 12 req_type pc
	.dbfield 14 req_cookie pc
	.dbfield 16 req_auth pc
	.dbfield 18 req_agent pc
	.dbfield 20 req_qptrs ppc
	.dbfield 22 req_numqptrs I
	.dbfield 24 req_ims L
	.dbfield 28 req_referer pc
	.dbfield 30 req_host pc
	.dbfield 32 req_connection I
	.dbend
	.dbsym s agent_fmt L21 A[21:21]kc
	.dbsym s auth_fmt L20 A[20:20]kc
	.dbsym s cookie_fmt L19 A[17:17]kc
	.dbsym s type_fmt L18 A[23:23]kc
	.dbsym s query_fmt L17 A[19:19]kc
	.dbsym s url_fmt L16 A[14:14]kc
	.dbsym s req_fmt L15 A[67:67]kc
	.dbsym s foot L14 A[15:15]kc
	.dbsym s head L13 A[70:70]kc
;             cp -> R22,R23
;            req -> R20,R21
;         stream -> R10,R11
	.even
_ShowQuery:
	xcall push_xgsetF00C
	movw R20,R18
	movw R10,R16
	sbiw R28,10
	.dbline -1
	.dbline 287
; }
; 
; /*
;  * CGI Sample: Show request parameters.
;  *
;  * See httpd.h for REQUEST structure.
;  *
;  * This routine must have been registered by NutRegisterCgi() and is
;  * automatically called by NutHttpProcessRequest() when the client
;  * request the URL 'cgi-bin/test.cgi'.
;  */
; static int ShowQuery(FILE * stream, REQUEST * req)
; {
	.dbline 306
;     char *cp;
;     /*
;      * This may look a little bit weird if you are not used to C programming
;      * for flash microcontrollers. The special type 'prog_char' forces the
;      * string literals to be placed in flash ROM. This saves us a lot of
;      * precious RAM.
;      */
;     static prog_char head[] = "<HTML><HEAD><TITLE>Parameters</TITLE></HEAD><BODY><H1>Parameters</H1>";
;     static prog_char foot[] = "</BODY></HTML>";
;     static prog_char req_fmt[] = "Method: %s<BR>\r\nVersion: HTTP/%d.%d<BR>\r\nContent length: %ld<BR>\r\n";
;     static prog_char url_fmt[] = "URL: %s<BR>\r\n";
;     static prog_char query_fmt[] = "Argument: %s<BR>\r\n";
;     static prog_char type_fmt[] = "Content type: %s<BR>\r\n";
;     static prog_char cookie_fmt[] = "Cookie: %s<BR>\r\n";
;     static prog_char auth_fmt[] = "Auth info: %s<BR>\r\n";
;     static prog_char agent_fmt[] = "User agent: %s<BR>\r\n";
; 
;     /* These useful API calls create a HTTP response for us. */
;     NutHttpSendHeaderTop(stream, req, 200, "Ok");
	ldi R24,<L22
	ldi R25,>L22
	std y+3,R25
	std y+2,R24
	ldi R24,200
	ldi R25,0
	std y+1,R25
	std y+0,R24
	movw R18,R20
	movw R16,R10
	xcall _NutHttpSendHeaderTop
	.dbline 307
;     NutHttpSendHeaderBottom(stream, req, html_mt, -1);
	ldi R24,255
	ldi R25,255
	ldi R26,255
	ldi R27,255
	std y+2,R24
	std y+3,R25
	std y+4,R26
	std y+5,R27
	lds R2,_html_mt
	lds R3,_html_mt+1
	std y+1,R3
	std y+0,R2
	movw R18,R20
	movw R16,R10
	xcall _NutHttpSendHeaderBottom
	.dbline 310
; 
;     /* Send HTML header. */
;     fputs_P(head, stream);
	movw R18,R10
	ldi R16,<L13
	ldi R17,>L13
	xcall _fputs_P
	.dbline 315
; 
;     /*
;      * Send request parameters.
;      */
;     switch (req->req_method) {
	movw R30,R20
	ldd R22,z+0
	ldd R23,z+1
	cpi R22,1
	ldi R30,0
	cpc R23,R30
	breq L26
X2:
	cpi R22,2
	ldi R30,0
	cpc R23,R30
	breq L28
X3:
	cpi R22,3
	ldi R30,0
	cpc R23,R30
	breq L30
X4:
	xjmp L23
L26:
	.dbline 317
;     case METHOD_GET:
;         cp = "GET";
	ldi R22,<L27
	ldi R23,>L27
	.dbline 318
;         break;
	xjmp L24
L28:
	.dbline 320
;     case METHOD_POST:
;         cp = "POST";
	ldi R22,<L29
	ldi R23,>L29
	.dbline 321
;         break;
	xjmp L24
L30:
	.dbline 323
;     case METHOD_HEAD:
;         cp = "HEAD";
	ldi R22,<L31
	ldi R23,>L31
	.dbline 324
;         break;
	xjmp L24
L23:
	.dbline 326
;     default:
;         cp = "UNKNOWN";
	ldi R22,<L32
	ldi R23,>L32
	.dbline 327
;         break;
L24:
	.dbline 329
;     }
;     fprintf_P(stream, req_fmt, cp, req->req_version / 10, req->req_version % 10, req->req_length);
	movw R30,R20
	ldd R2,z+4
	ldd R3,z+5
	ldd R4,z+6
	ldd R5,z+7
	std y+6,R2
	std y+7,R3
	std y+8,R4
	std y+9,R5
	ldd R2,z+2
	ldd R3,z+3
	ldi R18,10
	ldi R19,0
	movw R16,R2
	xcall mod16s
	std y+5,R17
	std y+4,R16
	ldi R18,10
	ldi R19,0
	movw R16,R2
	xcall div16s
	std y+3,R17
	std y+2,R16
	std y+1,R23
	std y+0,R22
	ldi R18,<L15
	ldi R19,>L15
	movw R16,R10
	xcall _fprintf_P
	.dbline 330
;     if (req->req_url)
	movw R30,R20
	ldd R2,z+8
	ldd R3,z+9
	tst R2
	brne X5
	tst R3
	breq L33
X5:
	.dbline 331
;         fprintf_P(stream, url_fmt, req->req_url);
	std y+1,R3
	std y+0,R2
	ldi R18,<L16
	ldi R19,>L16
	movw R16,R10
	xcall _fprintf_P
L33:
	.dbline 332
;     if (req->req_query)
	movw R30,R20
	ldd R2,z+10
	ldd R3,z+11
	tst R2
	brne X6
	tst R3
	breq L35
X6:
	.dbline 333
;         fprintf_P(stream, query_fmt, req->req_query);
	std y+1,R3
	std y+0,R2
	ldi R18,<L17
	ldi R19,>L17
	movw R16,R10
	xcall _fprintf_P
L35:
	.dbline 334
;     if (req->req_type)
	movw R30,R20
	ldd R2,z+12
	ldd R3,z+13
	tst R2
	brne X7
	tst R3
	breq L37
X7:
	.dbline 335
;         fprintf_P(stream, type_fmt, req->req_type);
	std y+1,R3
	std y+0,R2
	ldi R18,<L18
	ldi R19,>L18
	movw R16,R10
	xcall _fprintf_P
L37:
	.dbline 336
;     if (req->req_cookie)
	movw R30,R20
	ldd R2,z+14
	ldd R3,z+15
	tst R2
	brne X8
	tst R3
	breq L39
X8:
	.dbline 337
;         fprintf_P(stream, cookie_fmt, req->req_cookie);
	std y+1,R3
	std y+0,R2
	ldi R18,<L19
	ldi R19,>L19
	movw R16,R10
	xcall _fprintf_P
L39:
	.dbline 338
;     if (req->req_auth)
	movw R30,R20
	ldd R2,z+16
	ldd R3,z+17
	tst R2
	brne X9
	tst R3
	breq L41
X9:
	.dbline 339
;         fprintf_P(stream, auth_fmt, req->req_auth);
	std y+1,R3
	std y+0,R2
	ldi R18,<L20
	ldi R19,>L20
	movw R16,R10
	xcall _fprintf_P
L41:
	.dbline 340
;     if (req->req_agent)
	movw R30,R20
	ldd R2,z+18
	ldd R3,z+19
	tst R2
	brne X10
	tst R3
	breq L43
X10:
	.dbline 341
;         fprintf_P(stream, agent_fmt, req->req_agent);
	std y+1,R3
	std y+0,R2
	ldi R18,<L21
	ldi R19,>L21
	movw R16,R10
	xcall _fprintf_P
L43:
	.dbline 344
; 
;     /* Send HTML footer and flush output buffer. */
;     fputs_P(foot, stream);
	movw R18,R10
	ldi R16,<L14
	ldi R17,>L14
	xcall _fputs_P
	.dbline 345
;     fflush(stream);
	movw R16,R10
	xcall _fflush
	.dbline 347
; 
;     return 0;
	clr R16
	clr R17
	.dbline -2
L12:
	.dbline 0 ; func end
	adiw R28,10
	xjmp pop_xgsetF00C
	.dbsym r cp 22 pc
	.dbsym r req 20 pS[_REQUEST]
	.dbsym r stream 10 pS[__iobuf]
	.dbend
	.area lit(rom, con, rel)
L46:
	.byte 60,'H,'T,'M,'L,62,60,'H,'E,'A,'D,62,60,'T,'I,'T
	.byte 'L,'E,62,'T,'h,'r,'e,'a,'d,'s,60,47,'T,'I,'T,'L
	.byte 'E,62,60,47,'H,'E,'A,'D,62,60,'B,'O,'D,'Y,62,60
	.byte 'H,49,62,'T,'h,'r,'e,'a,'d,'s,60,47,'H,49,62,13
	.byte 10,60,'T,'A,'B,'L,'E,32,'B,'O,'R,'D,'E,'R,62,60
	.byte 'T,'R,62,60,'T,'H,62,'H,'a,'n,'d,'l,'e,60,47,'T
	.byte 'H,62,60,'T,'H,62,'N,'a,'m,'e,60,47,'T,'H,62,60
	.byte 'T,'H,62,'P,'r,'i,'o,'r,'i,'t,'y,60,47,'T,'H,62
	.byte 60,'T,'H,62,'S,'t,'a,'t,'u,'s,60,47,'T,'H,62,60
	.byte 'T,'H,62,'E,'v,'e,'n,'t,60,'B,'R,62,'Q,'u,'e,'u
	.byte 'e,60,47,'T,'H,62,60,'T,'H,62,'T,'i,'m,'e,'r,60
	.byte 47,'T,'H,62,60,'T,'H,62,'S,'t,'a,'c,'k,45,60,'B
	.byte 'R,62,'p,'o,'i,'n,'t,'e,'r,60,47,'T,'H,62,60,'T
	.byte 'H,62,'F,'r,'e,'e,60,'B,'R,62,'S,'t,'a,'c,'k,60
	.byte 47,'T,'H,62,60,47,'T,'R,62,13,10,0
L47:
	.byte 60,'T,'R,62,60,'T,'D,62,37,48,52,'X,60,47,'T,'D
	.byte 62,60,'T,'D,62,37,'s,60,47,'T,'D,62,60,'T,'D,62
	.byte 37,'u,60,47,'T,'D,62,60,'T,'D,62,37,'s,60,47,'T
	.byte 'D,62,60,'T,'D,62,37,48,52,'X,60,47,'T,'D,62,60
	.byte 'T,'D,62,37,48,52,'X,60,47,'T,'D,62,60,'T,'D,62
	.byte 37,48,52,'X,60,47,'T,'D,62,60,'T,'D,62,37,'u,60
	.byte 47,'T,'D,62,60,'T,'D,62,37,'s,60,47,'T,'D,62,60
	.byte 47,'T,'R,62,13,10,0
L48:
	.byte 60,47,'T,'A,'B,'L,'E,62,60,47,'B,'O,'D,'Y,62,60
	.byte 47,'H,'T,'M,'L,62,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L49:
	.blkw 1
	.area idata
	.word L50
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
	.blkw 1
	.area idata
	.word L51
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
	.blkw 1
	.area idata
	.word L52
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
	.blkw 1
	.area idata
	.word L53
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
	.area text(rom, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
	.dbfunc s ShowThreads _ShowThreads fI
	.dbstruct 0 25 _NUTTHREADINFO
	.dbfield 0 td_next pS[_NUTTHREADINFO]
	.dbfield 2 td_qnxt pS[_NUTTHREADINFO]
	.dbfield 4 td_qpec i
	.dbfield 6 td_name A[9:9]c
	.dbfield 15 td_state c
	.dbfield 16 td_sp i
	.dbfield 18 td_priority c
	.dbfield 19 td_memory pc
	.dbfield 21 td_timer pV
	.dbfield 23 td_queue pV
	.dbend
	.dbsym s thread_states L49 A[8:4]pc
	.dbsym s foot L48 A[23:23]kc
	.dbsym s tfmt L47 A[119:119]kc
	.dbsym s head L46 A[236:236]kc
;            tdp -> R20,R21
;            req -> R12,R13
;         stream -> R10,R11
	.even
_ShowThreads:
	xcall push_xgsetF03C
	movw R12,R18
	movw R10,R16
	sbiw R28,18
	.dbline -1
	.dbline 358
; }
; 
; /*
;  * CGI Sample: Show list of threads.
;  *
;  * This routine must have been registered by NutRegisterCgi() and is
;  * automatically called by NutHttpProcessRequest() when the client
;  * request the URL 'cgi-bin/threads.cgi'.
;  */
; static int ShowThreads(FILE * stream, REQUEST * req)
; {
	.dbline 370
;     static prog_char head[] = "<HTML><HEAD><TITLE>Threads</TITLE></HEAD><BODY><H1>Threads</H1>\r\n"
;         "<TABLE BORDER><TR><TH>Handle</TH><TH>Name</TH><TH>Priority</TH><TH>Status</TH><TH>Event<BR>Queue</TH><TH>Timer</TH><TH>Stack-<BR>pointer</TH><TH>Free<BR>Stack</TH></TR>\r\n";
; #if defined(__AVR__)
;     static prog_char tfmt[] =
;         "<TR><TD>%04X</TD><TD>%s</TD><TD>%u</TD><TD>%s</TD><TD>%04X</TD><TD>%04X</TD><TD>%04X</TD><TD>%u</TD><TD>%s</TD></TR>\r\n";
; #else
;     static prog_char tfmt[] =
;         "<TR><TD>%08lX</TD><TD>%s</TD><TD>%u</TD><TD>%s</TD><TD>%08lX</TD><TD>%08lX</TD><TD>%08lX</TD><TD>%lu</TD><TD>%s</TD></TR>\r\n";
; #endif
;     static prog_char foot[] = "</TABLE></BODY></HTML>";
;     static char *thread_states[] = { "TRM", "<FONT COLOR=#CC0000>RUN</FONT>", "<FONT COLOR=#339966>RDY</FONT>", "SLP" };
;     NUTTHREADINFO *tdp = nutThreadList;
	.dbline 373
; 
;     /* Send HTTP response. */
;     NutHttpSendHeaderTop(stream, req, 200, "Ok");
	ldi R24,<L22
	ldi R25,>L22
	std y+3,R25
	std y+2,R24
	ldi R24,200
	ldi R25,0
	std y+1,R25
	std y+0,R24
	movw R18,R12
	movw R16,R10
	xcall _NutHttpSendHeaderTop
	.dbline 374
;     NutHttpSendHeaderBottom(stream, req, html_mt, -1);
	ldi R24,255
	ldi R25,255
	ldi R26,255
	ldi R27,255
	std y+2,R24
	std y+3,R25
	std y+4,R26
	std y+5,R27
	lds R2,_html_mt
	lds R3,_html_mt+1
	std y+1,R3
	std y+0,R2
	movw R18,R12
	movw R16,R10
	xcall _NutHttpSendHeaderBottom
	.dbline 377
; 
;     /* Send HTML header. */
;     fputs_P(head, stream);
	movw R18,R10
	ldi R16,<L46
	ldi R17,>L46
	xcall _fputs_P
	.dbline 378
;     for (tdp = nutThreadList; tdp; tdp = tdp->td_next) {
	lds R20,_nutThreadList
	lds R21,_nutThreadList+1
	xjmp L57
L54:
	.dbline 378
	.dbline 379
;         fprintf_P(stream, tfmt, (uptr_t) tdp, tdp->td_name, tdp->td_priority,
	ldi R24,239
	ldi R25,190
	ldi R26,173
	ldi R27,222
	movw R30,R20
	adiw R30,19
	push R26
	push R27
	ldd R26,z+0
	ldd R27,z+1
	movw R30,R26
	pop R27
	pop R26
	ldd R2,z+0
	ldd R3,z+1
	ldd R4,z+2
	ldd R5,z+3
	cp R2,R24
	cpc R3,R25
	cpc R4,R26
	cpc R5,R27
	breq L60
X11:
	ldi R22,<L58
	ldi R23,>L58
	xjmp L61
L60:
	ldi R22,<L59
	ldi R23,>L59
L61:
	std y+17,R23
	std y+16,R22
	movw R30,R20
	ldd R6,z+16
	ldd R7,z+17
	ldd R2,z+19
	ldd R3,z+20
	movw R4,R6
	sub R4,R2
	sbc R5,R3
	std y+15,R5
	std y+14,R4
	std y+13,R7
	std y+12,R6
	ldd R2,z+21
	ldd R3,z+22
	std y+11,R3
	std y+10,R2
	ldd R2,z+23
	ldd R3,z+24
	std y+9,R3
	std y+8,R2
	ldi R24,<L49
	ldi R25,>L49
	ldd R30,z+15
	clr R31
	lsl R30
	rol R31
	add R30,R24
	adc R31,R25
	ldd R2,z+0
	ldd R3,z+1
	std y+7,R3
	std y+6,R2
	movw R30,R20
	ldd R2,z+18
	clr R3
	std y+5,R3
	std y+4,R2
	movw R24,R30
	adiw R24,6
	std y+3,R25
	std y+2,R24
	std y+1,R21
	std y+0,R20
	ldi R18,<L47
	ldi R19,>L47
	movw R16,R10
	xcall _fprintf_P
	.dbline 383
;                   thread_states[tdp->td_state], (uptr_t) tdp->td_queue, (uptr_t) tdp->td_timer,
;                   (uptr_t) tdp->td_sp, (uptr_t) tdp->td_sp - (uptr_t) tdp->td_memory,
;                   *((u_long *) tdp->td_memory) != DEADBEEF ? "Corr" : "OK");
;     }
L55:
	.dbline 378
	movw R30,R20
	ldd R20,z+0
	ldd R21,z+1
L57:
	.dbline 378
	cpi R20,0
	cpc R20,R21
	breq X13
	xjmp L54
X13:
X12:
	.dbline 384
;     fputs_P(foot, stream);
	movw R18,R10
	ldi R16,<L48
	ldi R17,>L48
	xcall _fputs_P
	.dbline 385
;     fflush(stream);
	movw R16,R10
	xcall _fflush
	.dbline 387
; 
;     return 0;
	clr R16
	clr R17
	.dbline -2
L45:
	.dbline 0 ; func end
	adiw R28,18
	xjmp pop_xgsetF03C
	.dbsym r tdp 20 pS[_NUTTHREADINFO]
	.dbsym r req 12 pS[_REQUEST]
	.dbsym r stream 10 pS[__iobuf]
	.dbend
	.area lit(rom, con, rel)
L63:
	.byte 60,'H,'T,'M,'L,62,60,'H,'E,'A,'D,62,60,'T,'I,'T
	.byte 'L,'E,62,'T,'i,'m,'e,'r,'s,60,47,'T,'I,'T,'L,'E
	.byte 62,60,47,'H,'E,'A,'D,62,60,'B,'O,'D,'Y,62,60,'H
	.byte 49,62,'T,'i,'m,'e,'r,'s,60,47,'H,49,62,13,10,0
L64:
	.byte 60,'T,'A,'B,'L,'E,32,'B,'O,'R,'D,'E,'R,62,60,'T
	.byte 'R,62,60,'T,'H,62,'H,'a,'n,'d,'l,'e,60,47,'T,'H
	.byte 62,60,'T,'H,62,'C,'o,'u,'n,'t,'d,'o,'w,'n,60,47
	.byte 'T,'H,62,60,'T,'H,62,'T,'i,'c,'k,32,'R,'e,'l,'o
	.byte 'a,'d,60,47,'T,'H,62,60,'T,'H,62,'C,'a,'l,'l,'b
	.byte 'a,'c,'k,60,'B,'R,62,'A,'d,'d,'r,'e,'s,'s,60,47
	.byte 'T,'H,62,60,'T,'H,62,'C,'a,'l,'l,'b,'a,'c,'k,60
	.byte 'B,'R,62,'A,'r,'g,'u,'m,'e,'n,'t,60,47,'T,'H,62
	.byte 60,47,'T,'R,62,13,10,0
L65:
	.byte 60,'T,'R,62,60,'T,'D,62,37,48,52,'X,60,47,'T,'D
	.byte 62,60,'T,'D,62,37,'l,'u,60,47,'T,'D,62,60,'T,'D
	.byte 62,37,'l,'u,60,47,'T,'D,62,60,'T,'D,62,37,48,52
	.byte 'X,60,47,'T,'D,62,60,'T,'D,62,37,48,52,'X,60,47
	.byte 'T,'D,62,60,47,'T,'R,62,13,10,0
L66:
	.byte 60,47,'T,'A,'B,'L,'E,62,60,47,'B,'O,'D,'Y,62,60
	.byte 47,'H,'T,'M,'L,62,0
	.area text(rom, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
	.dbfunc s ShowTimers _ShowTimers fI
	.dbstruct 0 16 _NUTTIMERINFO
	.dbfield 0 tn_next pS[_NUTTIMERINFO]
	.dbfield 2 tn_prev pS[_NUTTIMERINFO]
	.dbfield 4 tn_ticks l
	.dbfield 8 tn_ticks_left l
	.dbfield 12 tn_callback pfV
	.dbfield 14 tn_arg pV
	.dbend
	.dbsym s foot L66 A[23:23]kc
	.dbsym s tfmt L65 A[75:75]kc
	.dbsym s thead L64 A[136:136]kc
	.dbsym s head L63 A[64:64]kc
;     ticks_left -> y+14
;            tnp -> R12,R13
;            req -> R12,R13
;         stream -> R10,R11
	.even
_ShowTimers:
	xcall push_xgsetF03C
	movw R12,R18
	movw R10,R16
	sbiw R28,18
	.dbline -1
	.dbline 398
; }
; 
; /*
;  * CGI Sample: Show list of timers.
;  *
;  * This routine must have been registered by NutRegisterCgi() and is
;  * automatically called by NutHttpProcessRequest() when the client
;  * request the URL 'cgi-bin/timers.cgi'.
;  */
; static int ShowTimers(FILE * stream, REQUEST * req)
; {
	.dbline 411
;     static prog_char head[] = "<HTML><HEAD><TITLE>Timers</TITLE></HEAD><BODY><H1>Timers</H1>\r\n";
;     static prog_char thead[] =
;         "<TABLE BORDER><TR><TH>Handle</TH><TH>Countdown</TH><TH>Tick Reload</TH><TH>Callback<BR>Address</TH><TH>Callback<BR>Argument</TH></TR>\r\n";
; #if defined(__AVR__)
;     static prog_char tfmt[] = "<TR><TD>%04X</TD><TD>%lu</TD><TD>%lu</TD><TD>%04X</TD><TD>%04X</TD></TR>\r\n";
; #else
;     static prog_char tfmt[] = "<TR><TD>%08lX</TD><TD>%lu</TD><TD>%lu</TD><TD>%08lX</TD><TD>%08lX</TD></TR>\r\n";
; #endif
;     static prog_char foot[] = "</TABLE></BODY></HTML>";
;     NUTTIMERINFO *tnp;
;     u_long ticks_left;
; 
;     NutHttpSendHeaderTop(stream, req, 200, "Ok");
	ldi R24,<L22
	ldi R25,>L22
	std y+3,R25
	std y+2,R24
	ldi R24,200
	ldi R25,0
	std y+1,R25
	std y+0,R24
	movw R18,R12
	movw R16,R10
	xcall _NutHttpSendHeaderTop
	.dbline 412
;     NutHttpSendHeaderBottom(stream, req, html_mt, -1);
	ldi R20,255
	ldi R21,255
	ldi R22,255
	ldi R23,255
	std y+2,R20
	std y+3,R21
	std y+4,R22
	std y+5,R23
	lds R2,_html_mt
	lds R3,_html_mt+1
	std y+1,R3
	std y+0,R2
	movw R18,R12
	movw R16,R10
	xcall _NutHttpSendHeaderBottom
	.dbline 415
; 
;     /* Send HTML header. */
;     fputs_P(head, stream);
	movw R18,R10
	ldi R16,<L63
	ldi R17,>L63
	xcall _fputs_P
	.dbline 416
;     if ((tnp = nutTimerList) != 0) {
	lds R2,_nutTimerList
	lds R3,_nutTimerList+1
	movw R12,R2
	tst R12
	brne X14
	tst R13
	brne X16
	xjmp L67
X16:
X14:
	.dbline 416
	.dbline 417
;         fputs_P(thead, stream);
	movw R18,R10
	ldi R16,<L64
	ldi R17,>L64
	xcall _fputs_P
	.dbline 418
;         ticks_left = 0;
	ldi R20,0
	ldi R21,0
	ldi R22,0
	ldi R23,0
	std y+14,R20
	std y+15,R21
	std y+16,R22
	std y+17,R23
	xjmp L70
L69:
	.dbline 419
;         while (tnp) {
	.dbline 420
;             ticks_left += tnp->tn_ticks_left;
	movw R30,R12
	adiw R30,8
	ldd R2,z+0
	ldd R3,z+1
	ldd R4,z+2
	ldd R5,z+3
	ldd R6,y+14
	ldd R7,y+15
	ldd R8,y+16
	ldd R9,y+17
	add R6,R2
	adc R7,R3
	adc R8,R4
	adc R9,R5
	std y+14,R6
	std y+15,R7
	std y+16,R8
	std y+17,R9
	.dbline 421
;             fprintf_P(stream, tfmt, (uptr_t) tnp, ticks_left, tnp->tn_ticks, (uptr_t) tnp->tn_callback, (uptr_t) tnp->tn_arg);
	movw R30,R12
	ldd R2,z+14
	ldd R3,z+15
	std y+13,R3
	std y+12,R2
	ldd R2,z+12
	ldd R3,z+13
	std y+11,R3
	std y+10,R2
	adiw R30,4
	ldd R2,z+0
	ldd R3,z+1
	ldd R4,z+2
	ldd R5,z+3
	std y+6,R2
	std y+7,R3
	std y+8,R4
	std y+9,R5
	ldd R2,y+14
	ldd R3,y+15
	ldd R4,y+16
	ldd R5,y+17
	std y+2,R2
	std y+3,R3
	std y+4,R4
	std y+5,R5
	std y+1,R13
	std y+0,R12
	ldi R18,<L65
	ldi R19,>L65
	movw R16,R10
	xcall _fprintf_P
	.dbline 422
;             tnp = tnp->tn_next;
	movw R30,R12
	ldd R12,z+0
	ldd R13,z+1
	.dbline 423
;         }
L70:
	.dbline 419
	tst R12
	breq X17
	xjmp L69
X17:
	tst R13
	breq X18
	xjmp L69
X18:
X15:
	.dbline 424
;     }
L67:
	.dbline 426
; 
;     fputs_P(foot, stream);
	movw R18,R10
	ldi R16,<L66
	ldi R17,>L66
	xcall _fputs_P
	.dbline 427
;     fflush(stream);
	movw R16,R10
	xcall _fflush
	.dbline 429
; 
;     return 0;
	clr R16
	clr R17
	.dbline -2
L62:
	.dbline 0 ; func end
	adiw R28,18
	xjmp pop_xgsetF03C
	.dbsym l ticks_left 14 l
	.dbsym r tnp 12 pS[_NUTTIMERINFO]
	.dbsym r req 12 pS[_REQUEST]
	.dbsym r stream 10 pS[__iobuf]
	.dbend
	.area lit(rom, con, rel)
L73:
	.byte 60,'H,'T,'M,'L,62,60,'H,'E,'A,'D,62,60,'T,'I,'T
	.byte 'L,'E,62,'S,'o,'c,'k,'e,'t,'s,60,47,'T,'I,'T,'L
	.byte 'E,62,60,47,'H,'E,'A,'D,62,60,'B,'O,'D,'Y,62,60
	.byte 'H,49,62,'S,'o,'c,'k,'e,'t,'s,60,47,'H,49,62,13
	.byte 10,60,'T,'A,'B,'L,'E,32,'B,'O,'R,'D,'E,'R,62,60
	.byte 'T,'R,62,60,'T,'H,62,'H,'a,'n,'d,'l,'e,60,47,'T
	.byte 'H,62,60,'T,'H,62,'T,'y,'p,'e,60,47,'T,'H,62,60
	.byte 'T,'H,62,'L,'o,'c,'a,'l,60,47,'T,'H,62,60,'T,'H
	.byte 62,'R,'e,'m,'o,'t,'e,60,47,'T,'H,62,60,'T,'H,62
	.byte 'S,'t,'a,'t,'u,'s,60,47,'T,'H,62,60,47,'T,'R,62
	.byte 13,10,0
L74:
	.byte 60,'T,'R,62,60,'T,'D,62,37,48,52,'X,60,47,'T,'D
	.byte 62,60,'T,'D,62,'T,'C,'P,60,47,'T,'D,62,60,'T,'D
	.byte 62,37,'s,58,37,'u,60,47,'T,'D,62,0
L75:
	.byte 60,'T,'D,62,37,'s,58,37,'u,60,47,'T,'D,62,60,'T
	.byte 'D,62,0
L76:
	.byte 60,47,'T,'A,'B,'L,'E,62,60,47,'B,'O,'D,'Y,62,60
	.byte 47,'H,'T,'M,'L,62,0
L77:
	.byte 'L,'I,'S,'T,'E,'N,0
L78:
	.byte 'S,'Y,'N,'S,'E,'N,'T,0
L79:
	.byte 'S,'Y,'N,'R,'C,'V,'D,0
L80:
	.byte 60,'F,'O,'N,'T,32,'C,'O,'L,'O,'R,61,35,'C,'C,48
	.byte 48,48,48,62,'E,'S,'T,'A,'B,'L,60,47,'F,'O,'N,'T
	.byte 62,0
L81:
	.byte 'F,'I,'N,'W,'A,'I,'T,49,0
L82:
	.byte 'F,'I,'N,'W,'A,'I,'T,50,0
L83:
	.byte 'C,'L,'O,'S,'E,'W,'A,'I,'T,0
L84:
	.byte 'C,'L,'O,'S,'I,'N,'G,0
L85:
	.byte 'L,'A,'S,'T,'A,'C,'K,0
L86:
	.byte 'T,'I,'M,'E,'W,'A,'I,'T,0
L87:
	.byte 'C,'L,'O,'S,'E,'D,0
L88:
	.byte 'U,'N,'K,'N,'O,'W,'N,0
	.area text(rom, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
	.dbfunc s ShowSockets _ShowSockets fI
	.dbstruct 0 4 _NBDATA
	.dbfield 0 vp pV
	.dbfield 2 sz I
	.dbend
	.dbstruct 0 19 _NETBUF
	.dbfield 0 nb_next pS[_NETBUF]
	.dbfield 2 nb_flags c
	.dbfield 3 nb_dl S[_NBDATA]
	.dbfield 7 nb_nw S[_NBDATA]
	.dbfield 11 nb_tp S[_NBDATA]
	.dbfield 15 nb_ap S[_NBDATA]
	.dbend
	.dbstruct 0 115 tcp_socket
	.dbfield 0 so_next pS[tcp_socket]
	.dbfield 2 so_device pV
	.dbfield 4 so_devtype c
	.dbfield 5 so_devread pfI
	.dbfield 7 so_devwrite pfI
	.dbfield 9 so_devwrite_P pfI
	.dbfield 11 so_devioctl pfI
	.dbfield 13 so_devocnt i
	.dbfield 15 so_devobuf pc
	.dbfield 17 so_devobsz i
	.dbfield 19 so_state c
	.dbfield 20 so_local_addr l
	.dbfield 24 so_local_port i
	.dbfield 26 so_remote_addr l
	.dbfield 30 so_remote_port i
	.dbfield 32 so_tx_flags c
	.dbfield 33 so_tx_isn l
	.dbfield 37 so_tx_una l
	.dbfield 41 so_tx_nxt l
	.dbfield 45 so_tx_wl1 l
	.dbfield 49 so_tx_wl2 l
	.dbfield 53 so_tx_win i
	.dbfield 55 so_tx_dup c
	.dbfield 56 so_tx_nbq pS[_NETBUF]
	.dbfield 58 so_tx_tq pV
	.dbfield 60 so_rx_isn l
	.dbfield 64 so_rx_nxt l
	.dbfield 68 so_rx_win i
	.dbfield 70 so_rx_cnt I
	.dbfield 72 so_rx_bsz I
	.dbfield 74 so_rd_cnt I
	.dbfield 76 so_rx_apc C
	.dbfield 77 so_rx_buf pS[_NETBUF]
	.dbfield 79 so_rx_tq pV
	.dbfield 81 so_rx_nbq pS[_NETBUF]
	.dbfield 83 so_mss i
	.dbfield 85 so_rtt_seq l
	.dbfield 89 so_rtto i
	.dbfield 91 so_retransmits i
	.dbfield 93 so_time_wait i
	.dbfield 95 so_retran_time i
	.dbfield 97 so_last_error i
	.dbfield 99 so_pc_tq pV
	.dbfield 101 so_ac_tq pV
	.dbfield 103 so_read_to l
	.dbfield 107 so_write_to l
	.dbfield 111 so_oos_drop l
	.dbend
	.dbsym s st_unknown L88 A[8:8]kc
	.dbsym s st_closed L87 A[7:7]kc
	.dbsym s st_timewait L86 A[9:9]kc
	.dbsym s st_lastack L85 A[8:8]kc
	.dbsym s st_closing L84 A[8:8]kc
	.dbsym s st_closewait L83 A[10:10]kc
	.dbsym s st_finwait2 L82 A[9:9]kc
	.dbsym s st_finwait1 L81 A[9:9]kc
	.dbsym s st_estab L80 A[34:34]kc
	.dbsym s st_synrcvd L79 A[8:8]kc
	.dbsym s st_synsent L78 A[8:8]kc
	.dbsym s st_listen L77 A[7:7]kc
	.dbsym s foot L76 A[23:23]kc
	.dbsym s tfmt2 L75 A[19:19]kc
	.dbsym s tfmt1 L74 A[44:44]kc
	.dbsym s head L73 A[163:163]kc
;           st_P -> R22,R23
;             ts -> R20,R21
;            req -> R12,R13
;         stream -> R10,R11
	.even
_ShowSockets:
	xcall push_xgsetF0FC
	movw R12,R18
	movw R10,R16
	sbiw R28,6
	.dbline -1
	.dbline 440
; }
; 
; /*
;  * CGI Sample: Show list of sockets.
;  *
;  * This routine must have been registered by NutRegisterCgi() and is
;  * automatically called by NutHttpProcessRequest() when the client
;  * request the URL 'cgi-bin/sockets.cgi'.
;  */
; static int ShowSockets(FILE * stream, REQUEST * req)
; {
	.dbline 468
;     /* String literals are kept in flash ROM. */
;     static prog_char head[] = "<HTML><HEAD><TITLE>Sockets</TITLE></HEAD>"
;         "<BODY><H1>Sockets</H1>\r\n"
;         "<TABLE BORDER><TR><TH>Handle</TH><TH>Type</TH><TH>Local</TH><TH>Remote</TH><TH>Status</TH></TR>\r\n";
; #if defined(__AVR__)
;     static prog_char tfmt1[] = "<TR><TD>%04X</TD><TD>TCP</TD><TD>%s:%u</TD>";
; #else
;     static prog_char tfmt1[] = "<TR><TD>%08lX</TD><TD>TCP</TD><TD>%s:%u</TD>";
; #endif
;     static prog_char tfmt2[] = "<TD>%s:%u</TD><TD>";
;     static prog_char foot[] = "</TABLE></BODY></HTML>";
;     static prog_char st_listen[] = "LISTEN";
;     static prog_char st_synsent[] = "SYNSENT";
;     static prog_char st_synrcvd[] = "SYNRCVD";
;     static prog_char st_estab[] = "<FONT COLOR=#CC0000>ESTABL</FONT>";
;     static prog_char st_finwait1[] = "FINWAIT1";
;     static prog_char st_finwait2[] = "FINWAIT2";
;     static prog_char st_closewait[] = "CLOSEWAIT";
;     static prog_char st_closing[] = "CLOSING";
;     static prog_char st_lastack[] = "LASTACK";
;     static prog_char st_timewait[] = "TIMEWAIT";
;     static prog_char st_closed[] = "CLOSED";
;     static prog_char st_unknown[] = "UNKNOWN";
;     prog_char *st_P;
;     extern TCPSOCKET *tcpSocketList;
;     TCPSOCKET *ts;
; 
;     NutHttpSendHeaderTop(stream, req, 200, "Ok");
	ldi R24,<L22
	ldi R25,>L22
	std y+3,R25
	std y+2,R24
	ldi R24,200
	ldi R25,0
	std y+1,R25
	std y+0,R24
	movw R18,R12
	movw R16,R10
	xcall _NutHttpSendHeaderTop
	.dbline 469
;     NutHttpSendHeaderBottom(stream, req, html_mt, -1);
	ldi R24,255
	ldi R25,255
	ldi R26,255
	ldi R27,255
	std y+2,R24
	std y+3,R25
	std y+4,R26
	std y+5,R27
	lds R2,_html_mt
	lds R3,_html_mt+1
	std y+1,R3
	std y+0,R2
	movw R18,R12
	movw R16,R10
	xcall _NutHttpSendHeaderBottom
	.dbline 472
; 
;     /* Send HTML header. */
;     fputs_P(head, stream);
	movw R18,R10
	ldi R16,<L73
	ldi R17,>L73
	xcall _fputs_P
	.dbline 473
;     for (ts = tcpSocketList; ts; ts = ts->so_next) {
	lds R20,_tcpSocketList
	lds R21,_tcpSocketList+1
	xjmp L92
L89:
	.dbline 473
	.dbline 474
;         switch (ts->so_state) {
	movw R30,R20
	ldd R22,z+19
	clr R23
	cpi R22,0
	cpc R22,R23
	brne X31
	xjmp L106
X31:
X19:
	cpi R22,1
	ldi R30,0
	cpc R23,R30
	breq L96
X20:
	cpi R22,2
	ldi R30,0
	cpc R23,R30
	breq L97
X21:
	cpi R22,3
	ldi R30,0
	cpc R23,R30
	breq L98
X22:
	cpi R22,4
	ldi R30,0
	cpc R23,R30
	breq L99
X23:
	cpi R22,5
	ldi R30,0
	cpc R23,R30
	breq L102
X24:
	cpi R22,6
	ldi R30,0
	cpc R23,R30
	breq L100
X25:
	cpi R22,7
	ldi R30,0
	cpc R23,R30
	breq L103
X26:
	cpi R22,8
	ldi R30,0
	cpc R23,R30
	breq L104
X27:
	cpi R22,9
	ldi R30,0
	cpc R23,R30
	breq L101
X28:
	cpi R22,10
	ldi R30,0
	cpc R23,R30
	breq L105
X29:
	xjmp L93
L96:
	.dbline 476
;         case TCPS_LISTEN:
;             st_P = (prog_char *) st_listen;
	ldi R22,<L77
	ldi R23,>L77
	.dbline 477
;             break;
	xjmp L94
L97:
	.dbline 479
;         case TCPS_SYN_SENT:
;             st_P = (prog_char *) st_synsent;
	ldi R22,<L78
	ldi R23,>L78
	.dbline 480
;             break;
	xjmp L94
L98:
	.dbline 482
;         case TCPS_SYN_RECEIVED:
;             st_P = (prog_char *) st_synrcvd;
	ldi R22,<L79
	ldi R23,>L79
	.dbline 483
;             break;
	xjmp L94
L99:
	.dbline 485
;         case TCPS_ESTABLISHED:
;             st_P = (prog_char *) st_estab;
	ldi R22,<L80
	ldi R23,>L80
	.dbline 486
;             break;
	xjmp L94
L100:
	.dbline 488
;         case TCPS_FIN_WAIT_1:
;             st_P = (prog_char *) st_finwait1;
	ldi R22,<L81
	ldi R23,>L81
	.dbline 489
;             break;
	xjmp L94
L101:
	.dbline 491
;         case TCPS_FIN_WAIT_2:
;             st_P = (prog_char *) st_finwait2;
	ldi R22,<L82
	ldi R23,>L82
	.dbline 492
;             break;
	xjmp L94
L102:
	.dbline 494
;         case TCPS_CLOSE_WAIT:
;             st_P = (prog_char *) st_closewait;
	ldi R22,<L83
	ldi R23,>L83
	.dbline 495
;             break;
	xjmp L94
L103:
	.dbline 497
;         case TCPS_CLOSING:
;             st_P = (prog_char *) st_closing;
	ldi R22,<L84
	ldi R23,>L84
	.dbline 498
;             break;
	xjmp L94
L104:
	.dbline 500
;         case TCPS_LAST_ACK:
;             st_P = (prog_char *) st_lastack;
	ldi R22,<L85
	ldi R23,>L85
	.dbline 501
;             break;
	xjmp L94
L105:
	.dbline 503
;         case TCPS_TIME_WAIT:
;             st_P = (prog_char *) st_timewait;
	ldi R22,<L86
	ldi R23,>L86
	.dbline 504
;             break;
	xjmp L94
L106:
	.dbline 506
;         case TCPS_CLOSED:
;             st_P = (prog_char *) st_closed;
	ldi R22,<L87
	ldi R23,>L87
	.dbline 507
;             break;
	xjmp L94
L93:
	.dbline 509
;         default:
;             st_P = (prog_char *) st_unknown;
	ldi R22,<L88
	ldi R23,>L88
	.dbline 510
;             break;
L94:
	.dbline 515
;         }
;         /*
;          * Fixed a bug reported by Zhao Weigang.
;          */
;         fprintf_P(stream, tfmt1, (uptr_t) ts, inet_ntoa(ts->so_local_addr), ntohs(ts->so_local_port));
	movw R30,R20
	ldd R16,z+20
	ldd R17,z+21
	ldd R18,z+22
	ldd R19,z+23
	xcall _inet_ntoa
	movw R30,R20
	ldd R4,z+24
	ldd R5,z+25
	movw R24,R4
	andi R24,0
	movw R2,R24
	mov R2,R3
	clr R3
	movw R24,R4
	andi R25,0
	mov R25,R24
	clr R24
	or R24,R2
	or R25,R3
	std y+5,R25
	std y+4,R24
	std y+3,R17
	std y+2,R16
	std y+1,R21
	std y+0,R20
	ldi R18,<L74
	ldi R19,>L74
	movw R16,R10
	xcall _fprintf_P
	.dbline 516
;         fprintf_P(stream, tfmt2, inet_ntoa(ts->so_remote_addr), ntohs(ts->so_remote_port));
	movw R30,R20
	ldd R16,z+26
	ldd R17,z+27
	ldd R18,z+28
	ldd R19,z+29
	xcall _inet_ntoa
	movw R12,R16
	movw R30,R20
	ldd R14,z+30
	ldd R15,z+31
	movw R24,R14
	andi R24,0
	movw R2,R24
	mov R2,R3
	clr R3
	movw R24,R14
	andi R25,0
	mov R25,R24
	clr R24
	or R24,R2
	or R25,R3
	std y+3,R25
	std y+2,R24
	std y+1,R13
	std y+0,R12
	ldi R18,<L75
	ldi R19,>L75
	movw R16,R10
	xcall _fprintf_P
	.dbline 517
;         fputs_P(st_P, stream);
	movw R18,R10
	movw R16,R22
	xcall _fputs_P
	.dbline 518
;         fputs("</TD></TR>\r\n", stream);
	movw R18,R10
	ldi R16,<L107
	ldi R17,>L107
	xcall _fputs
	.dbline 519
;         fflush(stream);
	movw R16,R10
	xcall _fflush
	.dbline 520
;     }
L90:
	.dbline 473
	movw R30,R20
	ldd R20,z+0
	ldd R21,z+1
L92:
	.dbline 473
	cpi R20,0
	cpc R20,R21
	breq X32
	xjmp L89
X32:
X30:
	.dbline 522
; 
;     fputs_P(foot, stream);
	movw R18,R10
	ldi R16,<L76
	ldi R17,>L76
	xcall _fputs_P
	.dbline 523
;     fflush(stream);
	movw R16,R10
	xcall _fflush
	.dbline 525
; 
;     return 0;
	clr R16
	clr R17
	.dbline -2
L72:
	.dbline 0 ; func end
	adiw R28,6
	xjmp pop_xgsetF0FC
	.dbsym r st_P 22 pkc
	.dbsym r ts 20 pS[tcp_socket]
	.dbsym r req 12 pS[_REQUEST]
	.dbsym r stream 10 pS[__iobuf]
	.dbend
	.area lit(rom, con, rel)
L109:
	.byte 60,'H,'T,'M,'L,62,60,'B,'O,'D,'Y,62,60,'B,'R,62
	.byte 60,'H,49,62,'F,'o,'r,'m,32,'R,'e,'s,'u,'l,'t,60
	.byte 47,'H,49,62,60,'B,'R,62,60,'B,'R,62,0
L110:
	.byte 60,'B,'R,62,60,'B,'R,62,60,'p,62,60,'a,32,'h,'r
	.byte 'e,'f,61,34,46,46,47,'i,'n,'d,'e,'x,46,'h,'t,'m
	.byte 'l,34,62,'r,'e,'t,'u,'r,'n,32,'t,'o,32,'m,'a,'i
	.byte 'n,60,47,'a,62,60,47,'B,'O,'D,'Y,62,60,47,'H,'T
	.byte 'M,'L,62,60,47,'p,62,0
	.area text(rom, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
	.dbfunc e ShowForm _ShowForm fI
	.dbsym s html_body L110 A[72:72]kc
	.dbsym s html_head L109 A[45:45]kc
;          count -> R12,R13
;          value -> R10,R11
;           name -> R14,R15
;              i -> R22,R23
;            req -> R20,R21
;         stream -> y+16
	.even
_ShowForm::
	xcall push_arg4
	xcall push_xgsetF0FC
	movw R20,R18
	sbiw R28,6
	.dbline -1
	.dbline 538
; }
; 
; /*
;  * CGI Sample: Proccessing a form.
;  *
;  * This routine must have been registered by NutRegisterCgi() and is
;  * automatically called by NutHttpProcessRequest() when the client
;  * request the URL 'cgi-bin/form.cgi'.
;  *
;  * Thanks to Tom Boettger, who provided this sample for ICCAVR.
;  */
; int ShowForm(FILE * stream, REQUEST * req)
; {
	.dbline 542
;     static prog_char html_head[] = "<HTML><BODY><BR><H1>Form Result</H1><BR><BR>";
;     static prog_char html_body[] = "<BR><BR><p><a href=\"../index.html\">return to main</a></BODY></HTML></p>";
; 
;     NutHttpSendHeaderTop(stream, req, 200, "Ok");
	ldi R24,<L22
	ldi R25,>L22
	std y+3,R25
	std y+2,R24
	ldi R24,200
	ldi R25,0
	std y+1,R25
	std y+0,R24
	movw R18,R20
	ldd R16,y+16
	ldd R17,y+17
	xcall _NutHttpSendHeaderTop
	.dbline 543
;     NutHttpSendHeaderBottom(stream, req, html_mt, -1);
	ldi R24,255
	ldi R25,255
	ldi R26,255
	ldi R27,255
	std y+2,R24
	std y+3,R25
	std y+4,R26
	std y+5,R27
	lds R2,_html_mt
	lds R3,_html_mt+1
	std y+1,R3
	std y+0,R2
	movw R18,R20
	ldd R16,y+16
	ldd R17,y+17
	xcall _NutHttpSendHeaderBottom
	.dbline 546
; 
;     /* Send HTML header. */
;     fputs_P(html_head, stream);
	ldd R18,y+16
	ldd R19,y+17
	ldi R16,<L109
	ldi R17,>L109
	xcall _fputs_P
	.dbline 548
; 
;     if (req->req_query) {
	movw R30,R20
	ldd R2,z+10
	ldd R3,z+11
	tst R2
	brne X33
	tst R3
	breq L111
X33:
	.dbline 548
	.dbline 554
;         char *name;
;         char *value;
;         int i;
;         int count;
; 
;         count = NutHttpGetParameterCount(req);
	movw R16,R30
	xcall _NutHttpGetParameterCount
	movw R12,R16
	.dbline 556
;         /* Extract count parameters. */
;         for (i = 0; i < count; i++) {
	clr R22
	clr R23
	xjmp L116
L113:
	.dbline 556
	.dbline 557
;             name = NutHttpGetParameterName(req, i);
	movw R18,R22
	movw R16,R20
	xcall _NutHttpGetParameterName
	movw R14,R16
	.dbline 558
;             value = NutHttpGetParameterValue(req, i);
	movw R18,R22
	movw R16,R20
	xcall _NutHttpGetParameterValue
	movw R10,R16
	.dbline 563
; 
;             /* Send the parameters back to the client. */
; 
; #ifdef __IMAGECRAFT__
;             fprintf(stream, "%s: %s<BR>\r\n", name, value);
	std y+3,R11
	std y+2,R10
	std y+1,R15
	std y+0,R14
	ldi R18,<L117
	ldi R19,>L117
	ldd R16,y+16
	ldd R17,y+17
	xcall _fprintf
	.dbline 567
; #else
;             fprintf_P(stream, PSTR("%s: %s<BR>\r\n"), name, value);
; #endif
;         }
L114:
	.dbline 556
	subi R22,255  ; offset = 1
	sbci R23,255
L116:
	.dbline 556
	cp R22,R12
	cpc R23,R13
	brlt L113
X34:
	.dbline 568
;     }
L111:
	.dbline 570
; 
;     fputs_P(html_body, stream);
	ldd R18,y+16
	ldd R19,y+17
	ldi R16,<L110
	ldi R17,>L110
	xcall _fputs_P
	.dbline 571
;     fflush(stream);
	ldd R16,y+16
	ldd R17,y+17
	xcall _fflush
	.dbline 573
; 
;     return 0;
	clr R16
	clr R17
	.dbline -2
L108:
	.dbline 0 ; func end
	adiw R28,6
	xcall pop_xgsetF0FC
	adiw R28,4
	ret
	.dbsym r count 12 I
	.dbsym r value 10 pc
	.dbsym r name 14 pc
	.dbsym r i 22 I
	.dbsym r req 20 pS[_REQUEST]
	.dbsym l stream 16 pS[__iobuf]
	.dbend
	.dbfunc e SSIDemoCGI _SSIDemoCGI fI
	.dbstruct 0 18 _tm
	.dbfield 0 tm_sec I
	.dbfield 2 tm_min I
	.dbfield 4 tm_hour I
	.dbfield 6 tm_mday I
	.dbfield 8 tm_mon I
	.dbfield 10 tm_year I
	.dbfield 12 tm_wday I
	.dbfield 14 tm_yday I
	.dbfield 16 tm_isdst I
	.dbend
;            now -> y+30
;       loc_time -> y+12
;          count -> R12,R13
;          value -> R10,R11
;           name -> R14,R15
;              i -> R20,R21
;            req -> R22,R23
;         stream -> y+44
	.even
_SSIDemoCGI::
	xcall push_arg4
	xcall push_xgsetF0FC
	movw R22,R18
	sbiw R28,34
	.dbline -1
	.dbline 586
; }
; 
; /*
;  * CGI Sample: Dynamic output cgi included by ssi.shtml file
;  *
;  * This routine must have been registered by NutRegisterCgi() and is
;  * automatically called by NutHttpProcessRequest() when the client
;  * request the URL 'cgi-bin/form.cgi'.
;  *
;  * Thanks to Tom Boettger, who provided this sample for ICCAVR.
;  */
; int SSIDemoCGI(FILE * stream, REQUEST * req)
; {
	.dbline 587
;     if (req->req_query) {
	movw R30,R22
	ldd R2,z+10
	ldd R3,z+11
	tst R2
	brne X35
	tst R3
	breq L119
X35:
	.dbline 587
	.dbline 593
;         char *name;
;         char *value;
;         int i;
;         int count;
; 
;         count = NutHttpGetParameterCount(req);
	movw R16,R30
	xcall _NutHttpGetParameterCount
	movw R12,R16
	.dbline 597
;         
;         /* Extract count parameters. */
; #ifdef __IMAGECRAFT__        
;         fprintf(stream, "CGI ssi-demo.cgi called with parameters: These are the parameters\r\n<p>");
	ldi R18,<L121
	ldi R19,>L121
	ldd R16,y+44
	ldd R17,y+45
	xcall _fprintf
	.dbline 601
; #else
;         fprintf_P(stream, PSTR("CGI ssi-demo.cgi called with parameters: These are the parameters\r\n<p>"));
; #endif
;         for (i = 0; i < count; i++) {
	clr R20
	clr R21
	xjmp L125
L122:
	.dbline 601
	.dbline 602
;             name = NutHttpGetParameterName(req, i);
	movw R18,R20
	movw R16,R22
	xcall _NutHttpGetParameterName
	movw R14,R16
	.dbline 603
;             value = NutHttpGetParameterValue(req, i);
	movw R18,R20
	movw R16,R22
	xcall _NutHttpGetParameterValue
	movw R10,R16
	.dbline 608
; 
;             /* Send the parameters back to the client. */
; 
; #ifdef __IMAGECRAFT__
;             fprintf(stream, "%s: %s<BR>\r\n", name, value);
	std y+3,R11
	std y+2,R10
	std y+1,R15
	std y+0,R14
	ldi R18,<L117
	ldi R19,>L117
	ldd R16,y+44
	ldd R17,y+45
	xcall _fprintf
	.dbline 612
; #else
;             fprintf_P(stream, PSTR("%s: %s<BR>\r\n"), name, value);
; #endif
;         }
L123:
	.dbline 601
	subi R20,255  ; offset = 1
	sbci R21,255
L125:
	.dbline 601
	cp R20,R12
	cpc R21,R13
	brlt L122
X36:
	.dbline 613
;     } else {
	xjmp L120
L119:
	.dbline 613
	.dbline 618
;         time_t now;
;         tm     loc_time;
;         
;         /* Called without any parameter, show the current time */
;         now = time(NULL);
	clr R16
	clr R17
	xcall _time
	std y+30,R16
	std y+31,R17
	std y+32,R18
	std y+33,R19
	.dbline 619
;         localtime_r(&now, &loc_time);
	movw R18,R28
	subi R18,244  ; offset = 12
	sbci R19,255
	movw R16,R28
	subi R16,226  ; offset = 30
	sbci R17,255
	xcall _localtime_r
	.dbline 621
; #ifdef __IMAGECRAFT__        
;         fprintf(stream, "CGI ssi-demo.cgi called without any parameter.<br><br>Current time is: %02d.%02d.%04d -- %02d:%02d:%02d<br>\r\n",
	ldd R2,y+12
	ldd R3,y+13
	std y+11,R3
	std y+10,R2
	ldd R2,y+14
	ldd R3,y+15
	std y+9,R3
	std y+8,R2
	ldd R2,y+16
	ldd R3,y+17
	std y+7,R3
	std y+6,R2
	ldd R24,y+22
	ldd R25,y+23
	subi R24,148  ; offset = 1900
	sbci R25,248
	std y+5,R25
	std y+4,R24
	ldd R24,y+20
	ldd R25,y+21
	adiw R24,1
	std y+3,R25
	std y+2,R24
	ldd R2,y+18
	ldd R3,y+19
	std y+1,R3
	std y+0,R2
	ldi R18,<L126
	ldi R19,>L126
	ldd R16,y+44
	ldd R17,y+45
	xcall _fprintf
	.dbline 627
;                   loc_time.tm_mday, loc_time.tm_mon+1, loc_time.tm_year+1900, loc_time.tm_hour, loc_time.tm_min, loc_time.tm_sec);
; #else 
;         fprintf_P(stream, PSTR("CGI ssi-demo.cgi called without any parameter.<br><br>Current time is: %02d.%02d.%04d -- %02d:%02d:%02d<br>\r\n"),
;                   loc_time.tm_mday, loc_time.tm_mon+1, loc_time.tm_year+1900, loc_time.tm_hour, loc_time.tm_min, loc_time.tm_sec);
; #endif
;     }
L120:
	.dbline 629
; 
;     fflush(stream);
	ldd R16,y+44
	ldd R17,y+45
	xcall _fflush
	.dbline 631
; 
;     return 0;
	clr R16
	clr R17
	.dbline -2
L118:
	.dbline 0 ; func end
	adiw R28,34
	xcall pop_xgsetF0FC
	adiw R28,4
	ret
	.dbsym l now 30 L
	.dbsym l loc_time 12 S[_tm]
	.dbsym r count 12 I
	.dbsym r value 10 pc
	.dbsym r name 14 pc
	.dbsym r i 20 I
	.dbsym r req 22 pS[_REQUEST]
	.dbsym l stream 44 pS[__iobuf]
	.dbend
	.dbfunc e Service _Service fV
;         stream -> R14,R15
;           sock -> R12,R13
;             id -> R10
;            arg -> R10,R11
	.even
_Service::
	xcall push_xgset30FC
	movw R10,R16
	sbiw R28,2
	.dbline -1
	.dbline 647
; }
; 
; /*! \fn Service(void *arg)
;  * \brief HTTP service thread.
;  *
;  * The endless loop in this thread waits for a client connect,
;  * processes the HTTP request and disconnects. Nut/Net doesn't
;  * support a server backlog. If one client has established a
;  * connection, further connect attempts will be rejected.
;  * Typically browsers open more than one connection in order
;  * to load images concurrently. So we run this routine by
;  * several threads.
;  *
;  */
; THREAD(Service, arg)
; {
	.dbline 650
;     TCPSOCKET *sock;
;     FILE *stream;
;     u_char id = (u_char) ((uptr_t) arg);
	.dbline 655
; 
;     /*
;      * Now loop endless for connections.
;      */
;     for (;;) {
L133:
	.dbline 655
	.dbline 660
; 
;         /*
;          * Create a socket.
;          */
;         if ((sock = NutTcpCreateSocket()) == 0) {
	xcall _NutTcpCreateSocket
	movw R12,R16
	tst R12
	brne L137
	tst R13
	brne L137
X37:
	.dbline 660
	.dbline 661
;             printf("[%u] Creating socket failed\n", id);
	mov R18,R10
	clr R19
	ldi R16,<L139
	ldi R17,>L139
	xcall _printf_M
	.dbline 662
;             NutSleep(5000);
	ldi R16,136
	ldi R17,19
	ldi R18,0
	ldi R19,0
	xcall _NutSleep
	.dbline 663
;             continue;
	xjmp L133
L137:
	.dbline 670
;         }
; 
;         /*
;          * Listen on port 80. This call will block until we get a connection
;          * from a client.
;          */
;         NutTcpAccept(sock, 80);
	ldi R18,80
	ldi R19,0
	movw R16,R12
	xcall _NutTcpAccept
	.dbline 672
; #if defined(__AVR__)
;         printf("[%u] Connected, %u bytes free\n", id, NutHeapAvailable());
	ldi R16,<_heapFreeList
	ldi R17,>_heapFreeList
	xcall _NutHeapRootAvailable
	std y+1,R17
	std y+0,R16
	mov R18,R10
	clr R19
	ldi R16,<L140
	ldi R17,>L140
	xcall _printf_M
	xjmp L142
L141:
	.dbline 682
; #else
;         printf("[%u] Connected, %lu bytes free\n", id, NutHeapAvailable());
; #endif
; 
;         /*
;          * Wait until at least 8 kByte of free RAM is available. This will
;          * keep the client connected in low memory situations.
;          */
; #if defined(__AVR__)
;         while (NutHeapAvailable() < 8192) {
	.dbline 686
; #else
;         while (NutHeapAvailable() < 4096) {
; #endif
;             printf("[%u] Low mem\n", id);
	mov R18,R10
	clr R19
	ldi R16,<L144
	ldi R17,>L144
	xcall _printf_M
	.dbline 687
;             NutSleep(1000);
	ldi R16,232
	ldi R17,3
	ldi R18,0
	ldi R19,0
	xcall _NutSleep
	.dbline 688
;         }
L142:
	.dbline 682
	ldi R16,<_heapFreeList
	ldi R17,>_heapFreeList
	xcall _NutHeapRootAvailable
	movw R20,R16
	cpi R16,0
	ldi R30,32
	cpc R17,R30
	brlo L141
X38:
	.dbline 693
; 
;         /*
;          * Associate a stream with the socket so we can use standard I/O calls.
;          */
;         if ((stream = _fdopen((int) ((uptr_t) sock), "r+b")) == 0) {
	ldi R18,<L147
	ldi R19,>L147
	movw R16,R12
	xcall __fdopen
	movw R20,R16
	movw R14,R20
	cpi R16,0
	cpc R16,R17
	brne L145
X39:
	.dbline 693
	.dbline 694
;             printf("[%u] Creating stream device failed\n", id);
	mov R18,R10
	clr R19
	ldi R16,<L148
	ldi R17,>L148
	xcall _printf_M
	.dbline 695
;         } else {
	xjmp L146
L145:
	.dbline 695
	.dbline 702
;             /*
;              * This API call saves us a lot of work. It will parse the
;              * client's HTTP request, send any requested file from the
;              * registered file system or handle CGI requests by calling
;              * our registered CGI routine.
;              */
;             NutHttpProcessRequest(stream);
	movw R16,R14
	xcall _NutHttpProcessRequest
	.dbline 707
; 
;             /*
;              * Destroy the virtual stream device.
;              */
;             fclose(stream);
	movw R16,R14
	xcall _fclose
	.dbline 708
;         }
L146:
	.dbline 713
; 
;         /*
;          * Close our socket.
;          */
;         NutTcpCloseSocket(sock);
	movw R16,R12
	xcall _NutTcpCloseSocket
	.dbline 714
;         printf("[%u] Disconnected\n", id);
	mov R18,R10
	clr R19
	ldi R16,<L149
	ldi R17,>L149
	xcall _printf_M
	.dbline 715
;     }
	.dbline 655
	.dbline 655
	xjmp L133
X40:
	.dbline -2
L132:
	.dbline 0 ; func end
	adiw R28,2
	xjmp pop_xgset30FC
	.dbsym r stream 14 pS[__iobuf]
	.dbsym r sock 12 pS[tcp_socket]
	.dbsym r id 10 c
	.dbsym r arg 10 pV
	.dbend
	.area lit(rom, con, rel)
L163:
	.byte 0,6,152,48,0,53,0
L195:
	.byte 'h,'t,'t,'p,'d,48,0
	.area text(rom, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
	.dbfunc e main _main fI
;         thname -> y+14
;        ip_gate -> y+29
;        ip_mask -> y+25
;        ip_addr -> y+21
;            mac -> y+14
;           baud -> y+10
;              i -> R20
	.even
_main::
	sbiw R28,33
	.dbline -1
	.dbline 724
; }
; 
; /*!
;  * \brief Main application routine.
;  *
;  * Nut/OS automatically calls this entry after initialization.
;  */
; int main(void)
; {
	.dbline 725
;     u_long baud = 115200;
	ldi R24,0
	ldi R25,194
	ldi R26,1
	ldi R27,0
	std y+10,R24
	std y+11,R25
	std y+12,R26
	std y+13,R27
	.dbline 731
;     u_char i;
; 
;     /*
;      * Initialize the uart device.
;      */
;     NutRegisterDevice(&DEV_DEBUG, 0, 0);
	clr R2
	std y+0,R2
	clr R18
	clr R19
	ldi R16,<_devDebug0
	ldi R17,>_devDebug0
	xcall _NutRegisterDevice
	.dbline 732
;     freopen(DEV_DEBUG_NAME, "w", stdout);
	lds R2,___iob+2
	lds R3,___iob+2+1
	std y+1,R3
	std y+0,R2
	ldi R18,<L152
	ldi R19,>L152
	ldi R16,<L151
	ldi R17,>L151
	xcall _freopen
	.dbline 733
;     _ioctl(_fileno(stdout), UART_SETSPEED, &baud);
	lds R16,___iob+2
	lds R17,___iob+2+1
	xcall __fileno
	movw R24,R28
	adiw R24,10
	std y+1,R25
	std y+0,R24
	ldi R18,257
	ldi R19,1
	xcall __ioctl
	.dbline 734
;     NutSleep(200);
	ldi R16,200
	ldi R17,0
	ldi R18,0
	ldi R19,0
	xcall _NutSleep
	.dbline 735
;     printf("\n\nNut/OS %s HTTP Daemon...", NutVersionString());
	xcall _NutVersionString
	movw R18,R16
	ldi R16,<L155
	ldi R17,>L155
	xcall _printf_M
	.dbline 747
; 
; #ifdef NUTDEBUG
;     NutTraceTcp(stdout, 0);
;     NutTraceOs(stdout, 0);
;     NutTraceHeap(stdout, 0);
;     NutTracePPP(stdout, 0);
; #endif
; 
;     /*
;      * Register Ethernet controller.
;      */
;     if (NutRegisterDevice(&DEV_ETHER, 0, 0)) {
	clr R2
	std y+0,R2
	clr R18
	clr R19
	ldi R16,<_devEth0
	ldi R17,>_devEth0
	xcall _NutRegisterDevice
	movw R10,R16
	cpi R16,0
	cpc R16,R17
	breq L156
X41:
	.dbline 747
	.dbline 748
;         puts("Registering device failed");
	ldi R16,<L158
	ldi R17,>L158
	xcall _puts_M
	.dbline 749
;     }
L156:
	.dbline 751
; 
;     printf("Configure %s...", DEV_ETHER_NAME);
	ldi R18,<L160
	ldi R19,>L160
	ldi R16,<L159
	ldi R17,>L159
	xcall _printf_M
	.dbline 752
;     if (NutNetLoadConfig(DEV_ETHER_NAME)) {
	ldi R16,<L160
	ldi R17,>L160
	xcall _NutNetLoadConfig
	movw R10,R16
	cpi R16,0
	cpc R16,R17
	brne X48
	xjmp L161
X48:
X42:
	.dbline 752
	.dbline 753
;         u_char mac[] = MY_MAC;
	ldi R24,<L163
	ldi R25,>L163
	movw R30,R28
	adiw R30,14
	ldi R16,7
	ldi R17,0
	st -y,R31
	st -y,R30
	st -y,R25
	st -y,R24
	xcall asgncblkx
	.dbline 755
; 
;         printf("initial boot...");
	ldi R16,<L164
	ldi R17,>L164
	xcall _printf_M
	.dbline 759
; #ifdef USE_DHCP
;         if (NutDhcpIfConfig(DEV_ETHER_NAME, mac, 60000)) 
; #endif
;         {
	.dbline 760
;             u_long ip_addr = inet_addr(MY_IPADDR);
	ldi R16,<L165
	ldi R17,>L165
	xcall _inet_addr
	std y+21,R16
	std y+22,R17
	std y+23,R18
	std y+24,R19
	.dbline 761
;             u_long ip_mask = inet_addr(MY_IPMASK);
	ldi R16,<L166
	ldi R17,>L166
	xcall _inet_addr
	std y+25,R16
	std y+26,R17
	std y+27,R18
	std y+28,R19
	.dbline 762
;             u_long ip_gate = inet_addr(MY_IPGATE);
	ldi R16,<L167
	ldi R17,>L167
	xcall _inet_addr
	std y+29,R16
	std y+30,R17
	std y+31,R18
	std y+32,R19
	.dbline 764
; 
;             printf("No DHCP...");
	ldi R16,<L168
	ldi R17,>L168
	xcall _printf_M
	.dbline 765
;             if (NutNetIfConfig(DEV_ETHER_NAME, mac, ip_addr, ip_mask) == 0) {
	ldd R2,y+25
	ldd R3,y+26
	ldd R4,y+27
	ldd R5,y+28
	std y+4,R2
	std y+5,R3
	std y+6,R4
	std y+7,R5
	ldd R2,y+21
	ldd R3,y+22
	ldd R4,y+23
	ldd R5,y+24
	std y+0,R2
	std y+1,R3
	std y+2,R4
	std y+3,R5
	movw R18,R28
	subi R18,242  ; offset = 14
	sbci R19,255
	ldi R16,<L160
	ldi R17,>L160
	xcall _NutNetIfConfig
	movw R10,R16
	cpi R16,0
	cpc R16,R17
	brne L169
X43:
	.dbline 765
	.dbline 767
;                 /* Without DHCP we had to set the default gateway manually.*/
;                 if(ip_gate) {
	ldd R2,y+29
	ldd R3,y+30
	ldd R4,y+31
	ldd R5,y+32
	clc
	tst R2
	cpc R3,R2
	cpc R4,R2
	cpc R5,R2
	breq L171
X44:
	.dbline 767
	.dbline 768
;                     printf("hard coded gate...");
	ldi R16,<L173
	ldi R17,>L173
	xcall _printf_M
	.dbline 769
;                     NutIpRouteAdd(0, 0, ip_gate, &DEV_ETHER);
	ldi R24,<_devEth0
	ldi R25,>_devEth0
	std y+9,R25
	std y+8,R24
	ldd R2,y+29
	ldd R3,y+30
	ldd R4,y+31
	ldd R5,y+32
	std y+4,R2
	std y+5,R3
	std y+6,R4
	std y+7,R5
	ldi R24,0
	ldi R25,0
	ldi R26,0
	ldi R27,0
	std y+0,R24
	std y+1,R25
	std y+2,R26
	std y+3,R27
	ldi R16,0
	ldi R17,0
	ldi R18,0
	ldi R19,0
	xcall _NutIpRouteAdd
	.dbline 770
;                 }
L171:
	.dbline 771
;                 puts("OK");
	ldi R16,<L59
	ldi R17,>L59
	xcall _puts_M
	.dbline 772
;             }
	xjmp L162
L169:
	.dbline 773
;             else {
	.dbline 774
;                 puts("failed");
	ldi R16,<L174
	ldi R17,>L174
	xcall _puts_M
	.dbline 775
;             }
	.dbline 776
;         }
	.dbline 777
;     }
	xjmp L162
L161:
	.dbline 778
;     else {
	.dbline 787
; #ifdef USE_DHCP
;         if (NutDhcpIfConfig(DEV_ETHER_NAME, 0, 60000)) {
;             puts("failed");
;         }
;         else {
;             puts("OK");
;         }
; #else
;         if (NutNetIfConfig(DEV_ETHER_NAME, 0, 0, confnet.cdn_ip_mask)) {
	lds R4,_confnet+20+2
	lds R5,_confnet+20+2+1
	lds R2,_confnet+20
	lds R3,_confnet+20+1
	std y+4,R2
	std y+5,R3
	std y+6,R4
	std y+7,R5
	ldi R24,0
	ldi R25,0
	ldi R26,0
	ldi R27,0
	std y+0,R24
	std y+1,R25
	std y+2,R26
	std y+3,R27
	clr R18
	clr R19
	ldi R16,<L160
	ldi R17,>L160
	xcall _NutNetIfConfig
	movw R10,R16
	cpi R16,0
	cpc R16,R17
	breq L175
X45:
	.dbline 787
	.dbline 788
;             puts("failed");
	ldi R16,<L174
	ldi R17,>L174
	xcall _puts_M
	.dbline 789
;         }
	xjmp L176
L175:
	.dbline 790
;         else {
	.dbline 791
;             puts("OK");
	ldi R16,<L59
	ldi R17,>L59
	xcall _puts_M
	.dbline 792
;         }
L176:
	.dbline 794
; #endif
;     }
L162:
	.dbline 795
;     printf("%s ready\n", inet_ntoa(confnet.cdn_ip_addr));
	lds R18,_confnet+16+2
	lds R19,_confnet+16+2+1
	lds R16,_confnet+16
	lds R17,_confnet+16+1
	xcall _inet_ntoa
	movw R10,R16
	movw R18,R10
	ldi R16,<L178
	ldi R17,>L178
	xcall _printf_M
	.dbline 804
; 
; #ifdef USE_DISCOVERY
;     NutRegisterDiscovery((u_long)-1, 0, DISF_INITAL_ANN);
; #endif
; 
;     /*
;      * Register our device for the file system.
;      */
;     NutRegisterDevice(&MY_FSDEV, 0, 0);
	clr R2
	std y+0,R2
	clr R18
	clr R19
	ldi R16,<_devUrom
	ldi R17,>_devUrom
	xcall _NutRegisterDevice
	.dbline 834
; 
; #ifdef MY_BLKDEV
;     /* Register block device. */
;     printf("Registering block device '" MY_BLKDEV_NAME "'...");
;     if (NutRegisterDevice(&MY_BLKDEV, 0, 0)) {
;         puts("failed");
;         for (;;);
;     }
;     puts("OK");
; 
;     /* Mount partition. */
;     printf("Mounting block device '" MY_BLKDEV_NAME ":1/" MY_FSDEV_NAME "'...");
;     if (_open(MY_BLKDEV_NAME ":1/" MY_FSDEV_NAME, _O_RDWR | _O_BINARY) == -1) {
;         puts("failed");
;         for (;;);
;     }
;     puts("OK");
; #endif
; 
; #ifdef MY_HTTPROOT
;     /* Register root path. */
;     printf("Registering HTTP root '" MY_HTTPROOT "'...");
;     if (NutRegisterHttpRoot(MY_HTTPROOT)) {
;         puts("failed");
;         for (;;);
;     }
;     puts("OK");
; #endif
; 
;     NutRegisterCgiBinPath("cgi-bin/;user/cgi-bin/;admin/cgi-bin/");
	ldi R16,<L180
	ldi R17,>L180
	xcall _NutRegisterCgiBinPath
	.dbline 841
; 
; 
;     /*
;      * Register our CGI sample. This will be called
;      * by http://host/cgi-bin/test.cgi?anyparams
;      */
;     NutRegisterCgi("test.cgi", ShowQuery);
	ldi R18,<PL_ShowQuery
	ldi R19,>PL_ShowQuery
	ldi R16,<L181
	ldi R17,>L181
	xcall _NutRegisterCgi
	.dbline 849
; 
;     /* 
;      * Register a cgi included by the ssi demo. This will show how dynamic 
;      * content is included in a ssi page and how the request parameters for 
;      * a site are passed down to the included cgi.
;      */
;     
;     NutRegisterCgi("ssi-demo.cgi", SSIDemoCGI);
	ldi R18,<PL_SSIDemoCGI
	ldi R19,>PL_SSIDemoCGI
	ldi R16,<L182
	ldi R17,>L182
	xcall _NutRegisterCgi
	.dbline 855
;     
;     /*
;      * Register some CGI samples, which display interesting
;      * system informations.
;      */
;     NutRegisterCgi("threads.cgi", ShowThreads);
	ldi R18,<PL_ShowThreads
	ldi R19,>PL_ShowThreads
	ldi R16,<L183
	ldi R17,>L183
	xcall _NutRegisterCgi
	.dbline 856
;     NutRegisterCgi("timers.cgi", ShowTimers);
	ldi R18,<PL_ShowTimers
	ldi R19,>PL_ShowTimers
	ldi R16,<L184
	ldi R17,>L184
	xcall _NutRegisterCgi
	.dbline 857
;     NutRegisterCgi("sockets.cgi", ShowSockets);
	ldi R18,<PL_ShowSockets
	ldi R19,>PL_ShowSockets
	ldi R16,<L185
	ldi R17,>L185
	xcall _NutRegisterCgi
	.dbline 862
; 
;     /*
;      * Finally a CGI example to process a form.
;      */
;     NutRegisterCgi("form.cgi", ShowForm);
	ldi R18,<PL_ShowForm
	ldi R19,>PL_ShowForm
	ldi R16,<L186
	ldi R17,>L186
	xcall _NutRegisterCgi
	.dbline 868
; 
;     /*
;      * Protect the cgi-bin directory with
;      * user and password.
;      */
;     NutRegisterAuth("admin", "root:root");
	ldi R18,<L188
	ldi R19,>L188
	ldi R16,<L187
	ldi R17,>L187
	xcall _NutRegisterAuth
	.dbline 869
;     NutRegisterAuth("user", "user:user");
	ldi R18,<L190
	ldi R19,>L190
	ldi R16,<L189
	ldi R17,>L189
	xcall _NutRegisterAuth
	.dbline 874
; 
;     /*
;      * Register SSI and ASP handler
;      */
;     NutRegisterSsi();
	xcall _NutRegisterSsi
	.dbline 875
;     NutRegisterAsp();
	xcall _NutRegisterAsp
	.dbline 876
;     NutRegisterAspCallback(ASPCallback);
	ldi R16,<PL_ASPCallback
	ldi R17,>PL_ASPCallback
	xcall _NutRegisterAspCallback
	.dbline 880
;     /*
;      * Start four server threads.
;      */
;     for (i = 1; i <= 4; i++) {
	ldi R20,1
	xjmp L194
L191:
	.dbline 880
	.dbline 881
;         char thname[] = "httpd0";
	ldi R24,<L195
	ldi R25,>L195
	movw R30,R28
	adiw R30,14
	ldi R16,7
	ldi R17,0
	st -y,R31
	st -y,R30
	st -y,R25
	st -y,R24
	xcall asgncblkx
	.dbline 883
; 
;         thname[5] = '0' + i;
	mov R24,R20
	subi R24,208    ; addi 48
	std y+19,R24
	.dbline 884
;         NutThreadCreate(thname, Service, (void *) (uptr_t) i, 
	ldi R24,580
	ldi R25,2
	std y+3,R25
	std y+2,R24
	mov R2,R20
	clr R3
	std y+1,R3
	std y+0,R2
	ldi R18,<PL_Service
	ldi R19,>PL_Service
	movw R16,R28
	subi R16,242  ; offset = 14
	sbci R17,255
	xcall _NutThreadCreate
	.dbline 886
;             (HTTPD_SERVICE_STACK * NUT_THREAD_STACK_MULT) + NUT_THREAD_STACK_ADD);
;     }
L192:
	.dbline 880
	inc R20
L194:
	.dbline 880
	ldi R24,4
	cp R24,R20
	brsh L191
X46:
	.dbline 891
; 
;     /*
;      * We could do something useful here, like serving a watchdog.
;      */
;     NutThreadSetPriority(254);
	ldi R16,254
	xcall _NutThreadSetPriority
	.dbline 892
;     for (;;) {
L197:
	.dbline 892
	.dbline 893
;         NutSleep(60000);
	ldi R16,96
	ldi R17,234
	ldi R18,0
	ldi R19,0
	xcall _NutSleep
	.dbline 894
;     }
	.dbline 892
	.dbline 892
	xjmp L197
X47:
	.dbline -2
L150:
	.dbline 0 ; func end
	adiw R28,33
	ret
	.dbsym l thname 14 A[7:7]c
	.dbsym l ip_gate 29 l
	.dbsym l ip_mask 25 l
	.dbsym l ip_addr 21 l
	.dbsym l mac 14 A[7:7]c
	.dbsym l baud 10 l
	.dbsym r i 20 c
	.dbend
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L190:
	.blkb 10
	.area idata
	.byte 'u,'s,'e,'r,58,'u,'s,'e,'r,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L189:
	.blkb 5
	.area idata
	.byte 'u,'s,'e,'r,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L188:
	.blkb 10
	.area idata
	.byte 'r,'o,'o,'t,58,'r,'o,'o,'t,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L187:
	.blkb 6
	.area idata
	.byte 'a,'d,'m,'i,'n,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L186:
	.blkb 9
	.area idata
	.byte 'f,'o,'r,'m,46,'c,'g,'i,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L185:
	.blkb 12
	.area idata
	.byte 's,'o,'c,'k,'e,'t,'s,46,'c,'g,'i,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L184:
	.blkb 11
	.area idata
	.byte 't,'i,'m,'e,'r,'s,46,'c,'g,'i,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L183:
	.blkb 12
	.area idata
	.byte 't,'h,'r,'e,'a,'d,'s,46,'c,'g,'i,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L182:
	.blkb 13
	.area idata
	.byte 's,'s,'i,45,'d,'e,'m,'o,46,'c,'g,'i,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L181:
	.blkb 9
	.area idata
	.byte 't,'e,'s,'t,46,'c,'g,'i,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L180:
	.blkb 38
	.area idata
	.byte 'c,'g,'i,45,'b,'i,'n,47,59,'u,'s,'e,'r,47,'c,'g
	.byte 'i,45,'b,'i,'n,47,59,'a,'d,'m,'i,'n,47,'c,'g,'i
	.byte 45,'b,'i,'n,47,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L178:
	.blkb 10
	.area idata
	.byte 37,'s,32,'r,'e,'a,'d,'y,10,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L174:
	.blkb 7
	.area idata
	.byte 'f,'a,'i,'l,'e,'d,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L173:
	.blkb 19
	.area idata
	.byte 'h,'a,'r,'d,32,'c,'o,'d,'e,'d,32,'g,'a,'t,'e,46
	.byte 46,46,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L168:
	.blkb 11
	.area idata
	.byte 'N,'o,32,'D,'H,'C,'P,46,46,46,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L167:
	.blkb 14
	.area idata
	.byte 49,57,50,46,49,54,56,46,49,57,50,46,49,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L166:
	.blkb 14
	.area idata
	.byte 50,53,53,46,50,53,53,46,50,53,53,46,48,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L165:
	.blkb 15
	.area idata
	.byte 49,57,50,46,49,54,56,46,49,57,50,46,51,53,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L164:
	.blkb 16
	.area idata
	.byte 'i,'n,'i,'t,'i,'a,'l,32,'b,'o,'o,'t,46,46,46,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L160:
	.blkb 5
	.area idata
	.byte 'e,'t,'h,48,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L159:
	.blkb 16
	.area idata
	.byte 'C,'o,'n,'f,'i,'g,'u,'r,'e,32,37,'s,46,46,46,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L158:
	.blkb 26
	.area idata
	.byte 'R,'e,'g,'i,'s,'t,'e,'r,'i,'n,'g,32,'d,'e,'v,'i
	.byte 'c,'e,32,'f,'a,'i,'l,'e,'d,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L155:
	.blkb 27
	.area idata
	.byte 10,10,'N,'u,'t,47,'O,'S,32,37,'s,32,'H,'T,'T,'P
	.byte 32,'D,'a,'e,'m,'o,'n,46,46,46,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L152:
	.blkb 2
	.area idata
	.byte 'w,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L151:
	.blkb 6
	.area idata
	.byte 'u,'a,'r,'t,48,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L149:
	.blkb 19
	.area idata
	.byte 91,37,'u,93,32,'D,'i,'s,'c,'o,'n,'n,'e,'c,'t,'e
	.byte 'd,10,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L148:
	.blkb 36
	.area idata
	.byte 91,37,'u,93,32,'C,'r,'e,'a,'t,'i,'n,'g,32,'s,'t
	.byte 'r,'e,'a,'m,32,'d,'e,'v,'i,'c,'e,32,'f,'a,'i,'l
	.byte 'e,'d,10,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L147:
	.blkb 4
	.area idata
	.byte 'r,43,'b,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L144:
	.blkb 14
	.area idata
	.byte 91,37,'u,93,32,'L,'o,'w,32,'m,'e,'m,10,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L140:
	.blkb 31
	.area idata
	.byte 91,37,'u,93,32,'C,'o,'n,'n,'e,'c,'t,'e,'d,44,32
	.byte 37,'u,32,'b,'y,'t,'e,'s,32,'f,'r,'e,'e,10,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L139:
	.blkb 29
	.area idata
	.byte 91,37,'u,93,32,'C,'r,'e,'a,'t,'i,'n,'g,32,'s,'o
	.byte 'c,'k,'e,'t,32,'f,'a,'i,'l,'e,'d,10,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L126:
	.blkb 110
	.area idata
	.byte 'C,'G,'I,32,'s,'s,'i,45,'d,'e,'m,'o,46,'c,'g,'i
	.byte 32,'c,'a,'l,'l,'e,'d,32,'w,'i,'t,'h,'o,'u,'t,32
	.byte 'a,'n,'y,32,'p,'a,'r,'a,'m,'e,'t,'e,'r,46,60,'b
	.byte 'r,62,60,'b,'r,62,'C,'u,'r,'r,'e,'n,'t,32,'t,'i
	.byte 'm,'e,32,'i,'s,58,32,37,48,50,'d,46,37,48,50,'d
	.byte 46,37,48,52,'d,32,45,45,32,37,48,50,'d,58,37,48
	.byte 50,'d,58,37,48,50,'d,60,'b,'r,62,13,10,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L121:
	.blkb 71
	.area idata
	.byte 'C,'G,'I,32,'s,'s,'i,45,'d,'e,'m,'o,46,'c,'g,'i
	.byte 32,'c,'a,'l,'l,'e,'d,32,'w,'i,'t,'h,32,'p,'a,'r
	.byte 'a,'m,'e,'t,'e,'r,'s,58,32,'T,'h,'e,'s,'e,32,'a
	.byte 'r,'e,32,'t,'h,'e,32,'p,'a,'r,'a,'m,'e,'t,'e,'r
	.byte 's,13,10,60,'p,62,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L117:
	.blkb 13
	.area idata
	.byte 37,'s,58,32,37,'s,60,'B,'R,62,13,10,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L107:
	.blkb 13
	.area idata
	.byte 60,47,'T,'D,62,60,47,'T,'R,62,13,10,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L59:
	.blkb 3
	.area idata
	.byte 'O,'K,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L58:
	.blkb 5
	.area idata
	.byte 'C,'o,'r,'r,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L53:
	.blkb 4
	.area idata
	.byte 'S,'L,'P,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L52:
	.blkb 31
	.area idata
	.byte 60,'F,'O,'N,'T,32,'C,'O,'L,'O,'R,61,35,51,51,57
	.byte 57,54,54,62,'R,'D,'Y,60,47,'F,'O,'N,'T,62,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L51:
	.blkb 31
	.area idata
	.byte 60,'F,'O,'N,'T,32,'C,'O,'L,'O,'R,61,35,'C,'C,48
	.byte 48,48,48,62,'R,'U,'N,60,47,'F,'O,'N,'T,62,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L50:
	.blkb 4
	.area idata
	.byte 'T,'R,'M,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L32:
	.blkb 8
	.area idata
	.byte 'U,'N,'K,'N,'O,'W,'N,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L31:
	.blkb 5
	.area idata
	.byte 'H,'E,'A,'D,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L29:
	.blkb 5
	.area idata
	.byte 'P,'O,'S,'T,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L27:
	.blkb 4
	.area idata
	.byte 'G,'E,'T,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L22:
	.blkb 3
	.area idata
	.byte 'O,'k,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L11:
	.blkb 24
	.area idata
	.byte 'D,'u,'m,'m,'y,32,'e,'x,'a,'m,'p,'l,'e,58,32,49
	.byte 50,58,49,53,58,48,50,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L10:
	.blkb 9
	.area idata
	.byte 'u,'s,'r,95,'t,'i,'m,'e,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L7:
	.blkb 26
	.area idata
	.byte 'D,'u,'m,'m,'y,32,'e,'x,'a,'m,'p,'l,'e,58,32,48
	.byte 49,46,48,49,46,50,48,48,53,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L6:
	.blkb 9
	.area idata
	.byte 'u,'s,'r,95,'d,'a,'t,'e,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
L2:
	.blkb 10
	.area idata
	.byte 't,'e,'x,'t,47,'h,'t,'m,'l,0
	.area data(ram, con, rel)
	.dbfile C:\ethernut-4.9.7\nutapp_13h\httpd\httpserv.c
;     return 0;
; }
	.area  func_lit
PL_Service:	.word `_Service
PL_ASPCallback:	.word `_ASPCallback
PL_ShowForm:	.word `_ShowForm
PL_ShowSockets:	.word `_ShowSockets
PL_ShowTimers:	.word `_ShowTimers
PL_ShowThreads:	.word `_ShowThreads
PL_SSIDemoCGI:	.word `_SSIDemoCGI
PL_ShowQuery:	.word `_ShowQuery
