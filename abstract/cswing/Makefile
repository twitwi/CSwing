
CC = gcc
CFLAGS = -Wall
JDK = /usr/lib/jvm/java-7-openjdk-amd64
ON = linux
CFLAGSVM=-I${JDK}/include/ -I${JDK}/include/${ON}/

a___libcswing.a: cswing.o javahelper.o
	ar -rsc $@ $+

a___libcswing32.a: cswing32.o javahelper32.o
	ar -rsc $@ $+

../cswing.zip: a___libcswing.a a___libcswing32.a
	cd .. && zip -r cswing.zip cswing/*.a cswing/cswing.h cswing/cswing.c cswing/javahelper.h cswing/javahelper.c cswing/conf cswing/*.jar

%.o:%.c
	$(CC) $(CFLAGSVM) -c $< -o $@

%32.o:%.c
	$(CC) -m32 $(CFLAGSVM) -c $< -o $@
#sudo aptitude install libc6-dev-i386

,,test: test-cswing-events.c a___libcswing.a 
	$(CC) $+ -ldl -I ./ -o $@
