
CC = gcc
CFLAGS = -Wall
JDK = /usr/lib/jvm/java-7-openjdk-amd64
ON = linux
CFLAGSVM=-I${JDK}/include/ -I${JDK}/include/${ON}/

a___libcswing.a: cswing.o javahelper.o
	ar -rsc $@ $+

../cswing.zip: a___libcswing.a
	cd .. && zip -r cswing.zip cswing/*.a cswing/cswing.h cswing/conf cswing/*.jar

%.o:%.c
	$(CC) $(CFLAGSVM) -c $< -o $@

,,test: test-cswing.c a___libcswing.a 
	$(CC) $+ -ldl -o $@
