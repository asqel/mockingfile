
#include <stdlib.h>

/*
makefile-like section
ex:
	section:
		...
*/
int line_is_section(char *text) {
	int p = 0;
	int is_inside_brackets = 0;
	int is_inside_parenthesis = 0;
	int is_inside_curly_brackets = 0;

	while (text[p] != '\0' && text[p] != ':') {
		if (text[p] == '(')
			is_inside_parenthesis++;
		if (text[p] == ')')
			is_inside_parenthesis--;
		if (text[p] == '{')
			is_inside_curly_brackets++;
		if (text[p] == '}')
			is_inside_curly_brackets--;
		if (text[p] == '[')
			is_inside_brackets++;
		if (text[p] == ']')
			is_inside_brackets--;
		p++;
	}
	if (is_inside_parenthesis != 0 || is_inside_curly_brackets != 0 || is_inside_brackets != 0)
		return 0;
	return 1;
	
}

typedef struct {
	char *name;
	char *dependencies;
	char **lines;
	int line_count;
} mock_section;

int make_section(char *text, mock_section *sec) {
	
}

void do_mockfile(char *text, char *section) {
	int i = 0;
	int done = 0;
	mock_section *sec = NULL;
	int section_count = 0;

	while (text[i] != '\0') {
		if (line_is_section(&(text[i]))) {
			sec = realloc(sec, sizeof(mock_section) * (section_count + 1));
			i += make_section(&(text[i]), &sec[section_count]);
			section_count++;
		}

	}
	if (!done) {
		printf("nothing to be done for %s\n", section);
	}
}
