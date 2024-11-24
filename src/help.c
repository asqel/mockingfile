
#include <string.h>
#include <stdio.h>

#include "version.h"

void print_help() {

}

void print_version() {
	printf("%s", "\
\e[31mMockingfile\n\
	a (not) better Makefile\e[36m\n\
\n\
       %&&&%                     \n\
      %|||||%                    \n\
      %||||%                     \n\
       %|||%          /***\\      \n\
       %||||%      /*###O##>\e[0m--\e[36m   \n\
       #%|||%********####/       \n\
    &---------********##/        \n\
     &----------******#/         \n\
      &-----**--****#/           \n\
          *********\e[0m              \n\
           \\     \\               \n\
            \\     \\       /      \n\
-----------/|\\-\\-/|\\-----{--     \n\
                \\         \\      \n\
                /\\         ^     \n"
	);
	printf("Version %s\n", VERSION);
}

int check_arg_is_help(int argc, char **argv) {
	if (argc == 1) {
		print_help();
		return 1;
	}

	for (int i = 1; i < argc; i++) {
		if (!strcmp(argv[i], "-v") || !strcmp(argv[i], "--version")) {
			print_version();
			return 1;
		}
	}
	return 0;
}