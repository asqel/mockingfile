
void do_mockfile(char *text, char *section) {
	int i = 0;
	int done = 0;

	while (text[i] != '\0') {
		if (uti_isapce(text[i])) {
			i++;
			continue;
		}
	
		int start = i;
		int end = start;

		while (text[end] != '\0' && text[end] != '\n')
			end++;
		if ()

	}
	if (!done) {
		printf("nothing to be done for %s\n", section);
	}
}
