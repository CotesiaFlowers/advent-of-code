#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int readnum(char **s) {
	char c;

	int n=0, r=0; // nth digit, result

	do { c = (*s)[++n]; } while (isdigit(c));
	
	c = **s;
	for (;n;n--) {
		r += ((int)c-'0') * pow(10, n-1);
		c = *++(*s);
	}
	
	while (!isdigit(c) && c!=EOF) c = *++(*s);

	return r;
}

int main() {
	FILE *f = fopen("input2", "r");
	fseek(f, 0, SEEK_END);
	long size = ftell(f);
	rewind(f);
	char *input = (char*) malloc(size);
	fread(input, size, 1, f);
	int paper=0, ribbon=0;
	input[size]=EOF;

	do {
		int l=0 ,w=0, h=0;
		l=readnum(&input);
		w=readnum(&input);
		h=readnum(&input);
		int a = MIN(MIN(l,w), h); // smallest axis
		int b = MIN(MAX(l,h), MIN(MAX(l,w), MAX(w,h))); // second smallest axis
		paper += a * b + 2*l*w + 2*w*h + 2*h*l;
		ribbon += 2*a + 2*b + l*w*h;

	} while (*input != EOF);

	printf("wrapping paper: %dft\n", paper);
	printf("ribbon: %dft\n", ribbon);
}
