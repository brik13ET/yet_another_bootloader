CC=i686-elf-gcc
AS=nasm
LD=i686-elf-ld
PP=cpp

CCFLAGS=-Iinclude -c -ffreestanding -Wall -Werror -Wextra 
ASFLAGS=
LDFLAGS=-T bin/link.ld -nostdlib -L../cross/lib/gcc/i686-elf/12.0.0 -lgcc

CCFILES=$(notdir $(wildcard src/*.c) )
ASFILES=$(notdir $(wildcard src/*.s) )

.DEFAULT_GOAL = build
.PHONY := all clean image build

$(addprefix bin/, %.c.o) : $(addprefix src/, %.c) bin
	$(CC) $(CCFLAGS) $? -o $@

$(addprefix bin/, %.s.o) : $(addprefix src/, %.s) bin
	$(AS) $(ASFLAGS) $? -o $@

bin:
	mkdir bin

clean:
	rm -r bin
	rm image.bin

link.ld: link.ldpp
	cpp link.ldpp -o bin/link.ld

build: $(addprefix bin/, $(addsuffix .o, $(CCFILES) $(ASFILES)) ) link.ld
	$(LD) $(LDFLAGS) $(wildcard bin/*.c.o bin/*.s.o) -o bin/build

image: build
	objcopy -O binary bin/build image.bin
