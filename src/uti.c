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

char *str_dup_to_line(char *str) {
	int len = 0;

	while (str[len] != '\0' && str[len] != '\n')
		len++;

	char *res = malloc(sizeof(char) * (len + 1));
	memcpy(res, str, len);
	res[len] = '\0';
	return res;
}

char **split_line(char *lines) {
	char **res = NULL;
	int line_count = 0;
	int line_start = 0;
	int p = 0;
	while (lines[p] != '\0') {
		res = realloc(res, sizeof(char *) * (line_count + 1));
		res[line_count] = str_dup_to_line(&(lines[line_start]));
		line_count++;
		while (lines[p] != '\0' && lines[p] != '\n')
			p++;
		line_start = p + 1;
	}
	res = realloc(res, sizeof(char *) * (line_count + 1));
	res[line_count] = NULL;
	return res;
}

char *trim_str(char *str) {
	int len = 0;

	while (str[len] != '\0' && str[len] != '\n')
		len++;

	char *res = malloc(sizeof(char) * (len + 1));
	memcpy(res, str, len);
	res[len] = '\0';
	free(str);
	return res;
}

char *trim_lines(char *text) {
	char **lines = split_line(text);
	int p = 0;
	while (lines[p] != NULL) {
		lines[p] = trim_str(lines[p]);
		p++;
	}
	int new_len = 0;

	p = 0;
	while (lines[p] != NULL) {
		new_len += strlen(lines[p]) + 1;
		p++;
	}

	char *res = malloc(sizeof(char) * (new_len + 1));
	res[0] = '\0';
	p = 0;
	while (lines[p] != NULL) {
		strcat(res, lines[p]);
		strcat(res, "\n");
		p++;
	}
	p = 0;
	while (lines[p] != NULL) {
		free(lines[p]);
		p++;
	}
	free(lines);
	free(text);
	return res;
}