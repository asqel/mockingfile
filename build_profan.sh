CC=gcc
LD=ld

profan_path=../profanOS

CFLAGS="-ffreestanding -fno-exceptions -m32 -I$profan_path/include/zlibs -O1 -nostdinc -Iinclude"
LDFLAGS="-m elf_i386 -nostdlib -L $profan_path/out/zlibs -T $profan_path/tools/link_elf.ld -lc"

rm -rf bin
mkdir -p bin
rm -rf mock

srcs=

count=0
for i in src/*.c $profan_path/tools/entry_elf.c main.c; do
	echo compiling $i
	$CC $CFLAGS -o bin/$count.o -c $i
	if [[ $? != 0 ]]; then
		exit 1;
	fi
    count=$((count + 1))
done

$LD $LDFLAGS bin/*.o -o mock