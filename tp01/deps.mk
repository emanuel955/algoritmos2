CC	:=	gcc
CFLAGS	:=	-g -std=c99 -Wall -Wtype-limits -pedantic -Wconversion -Wno-sign-conversion 

strutil	:	strutil.o
fixcol	:	fixcol.o
bf	:	bf.o