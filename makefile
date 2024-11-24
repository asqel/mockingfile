
all:
	gcc src/*.c ../profanOS/tools/entry_elf.c -o mock -Iinclude

profan:
	./profan_build.sh