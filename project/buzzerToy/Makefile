#makefile configuration

COMMON_OBJECTS =

CPU = msp430g2553

CFLAGS = -mmcu=${CPU} -I../h

LDFLAGS = -L/opt/ti/msp430_gcc/include



#switch compiler

CC = msp430-elf-gcc
AS = msp430-elf-as


all: main.elf



#additional rules for files

main.elf: ${COMMON_OBJECTS} main.c stateMachines.o led.o wdInterruptHandler.o p2_interrupt_handler.o switches.o buzzer.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^
main-s.elf: ${COMMON_OBJECTS} assembly-s.o

	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ ../lib/libTimer.a

load: main.elf
	msp430loader.sh main.elf



clean:

	rm -f *.o *.elf

stateMachines.o:stateMachines.c stateMachines.h toggleGreen.c

led.o:led.c led.h

buzzer.o:buzzer.c buzzer.h

switches.o:switches.c switches.h 

wdInterruptHandler.o: wdInterruptHandler.c

p2_interrupt_handler.o: p2_interrupt_handler.c
