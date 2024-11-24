#ifndef UTI_H
#define UTI_H

#undef u8
#undef u16
#undef u32

#undef i8
#undef i16
#undef i32


typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned int u32;

typedef signed char i8;
typedef short int i16;
typedef int i32;

char *read_file(char *path);



#endif