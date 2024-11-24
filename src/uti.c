#include "uti.h"

#include <stdio.h>
#include <stdlib.h>

u32 get_file_len(char *path) {
	int start = 0;
	int end = 0;
	FILE *file = fopen(path, "r");
	if (file == NULL)
		return 0;

	fseek(file, 0, SEEK_SET);
	start = ftell(file);

	fseek(file, 0, SEEK_END);
	end = ftell(file);
	
	fclose(file);
	return end - start;
}

char *read_file(char *path) {
	char *text = NULL;
	u32 len = get_file_len(path);
	FILE *file = fopen(path, "r");

	if (file == NULL)
		return NULL;

	text = malloc(sizeof(char) * (len + 1));

	fread(text, sizeof(char), len, file);
	text[len] = '\0';

	fclose(file);
	return text;

}
