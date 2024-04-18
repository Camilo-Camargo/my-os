CROSS_COMPILE=x86_64-elf-
CC=$(CROSS_COMPILE)gcc
LD=$(CROSS_COMPILE)ld
FILES=$(wildcard *.c **/*.c **/**/*.c **/**/**/*.c)    
OBJS=$(FILES:.c=.o) 

all: objs os

objs: 
	$(foreach source, ${FILES}, gcc -c $(source) -o $(patsubst %.c,%.o,$(source)) -ffreestanding -m32 -fno-stack-protector ;) 
	echo ${OBJS}

os: ${OBJS}
	nasm -f elf boot.asm -o boot.o 
	${CC} -m32 -nostdlib -nodefaultlibs -lgcc boot.o ${OBJS} -T linker.ld  -o myos   
	cp myos iso/boot/
	grub-mkrescue iso --output=myos.iso  
	qemu-system-x86_64 myos.iso -m 500M

clean:
	rm -rf $(OBJS)

