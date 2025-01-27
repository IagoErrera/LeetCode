#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    int n = strlen(s);
	char* out = (char*)malloc(sizeof(char) * (n + 1));
	int i = 0;

	if (numRows == 1) return s;

	for (int row = 0; row < numRows; row++) {
		int j = row;
		while (j < n && i < n) {
			out[i++] = s[j];

			if (row == (numRows - 1)) j += 2 * (numRows - 1);
			else j += 2 * (numRows - (row + 1));
			if (j >= n) break;

			out[i++] = s[j];

			if (row != 0) j += 2 * row;
			else j += 2 * (numRows - 1);
			if (j >= n) break;
		}
	}

	out[n] = '\0';
	
	return out;
}

int main() {
	char* zigzag = convert("AB", 1);

	printf("%s\n\r", zigzag);

	return 0;
}
