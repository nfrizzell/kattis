#include <stdio.h>
#include <string.h>

int main() 
{
	int c[101];
	int i, j, len, idx;
loop:	memset(c, '\0', sizeof(int)*100);
	int n;
	for (len = 0; len < 101; len++) { n = getchar(); if (n == ' ') break; if (n == EOF) return 0; c[len] = n; }
	for (j = 0; j < len; j++) { c[(101 - len) + j] = c[j]; c[j] = '\0'; }
	scanf("%d", &i); getchar();
	while (i > 0) {
		int base, off, idx = 100;
carry:		if (!c[idx]) { c[idx] = off; if (base == 10) c[idx]++; len++; }
		else if (c[idx] >= '0' && c[idx] <= '9') { base = 10; off = '0'; c[idx]++; }
		else if (c[idx] >= 'a' && c[idx] <= 'z') { base = 26; off = 'a'; c[idx]++; }
		else if (c[idx] >= 'A' && c[idx] <= 'Z') { base = 26; off = 'A'; c[idx]++; }
		if (idx == 100) i--;
		if ((c[idx] - off) >= base) { c[idx] = off; idx--; goto carry; }
	}

	for (j = 101 - len; j < 101; j++) printf("%c", c[j]);
	printf("\n");
	goto loop;
}
