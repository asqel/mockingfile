/*-------------------------------\
                                 |
    supposed to be a moking bird |
         a (not) better makefile |
                                 |
       %&&&%                     |
      %|||||%                    |
      %||||%                     |
       %|||%          /***\      |
       %||||%      /*###O##>--   |
       #%|||%********####/       |
    &---------********##/        |
     &----------******#/         |
      &-----**--****#/           |
          *********              |
           \     \               |
            \     \       /      |
-----------/|\-\-/|\-----{--     |
                \         \      |
                /\         ^     |
--------------------------------*/
#include <stdlib.h>

#include "help.h"
#include "uti.h"
#include "exec.h"

char *mockfile_names[] = {
	"Mockfile",
	"mockfile",
	"MockFile",
	"MOCKFILE",
	"MOCKfile",
	"mockFILE",
	"MockFILE",
	NULL
};

int main(int argc, char **argv) {
	int i = 0;
	char *text = NULL;

	if (check_arg_is_help(argc, argv))
		return 0;

	while (text == NULL && mockfile_names[i] != NULL) {
		text = read_file(mockfile_names[i]);
		i++;
	}
	text = trim_lines(text);
	i = 1;
	while (i < argc) {
		do_mockfile(text, argv[i]);
		i++;
	}

	free(text);
	return 0;
}