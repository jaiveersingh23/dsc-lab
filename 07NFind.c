#include <stdio.h>
#include <string.h>

int nfind(char *string, char *pat) {
    int i, j, start = 0;
    int lasts = strlen(string) - 1;
    int lastp = strlen(pat) - 1;
    int endmatch = lastp;

    for (i = 0; endmatch <= lasts; endmatch++, start++) {
        if (string[endmatch] == pat[lastp]) {
            for (j = 0, i = start; j < lastp && string[i] == pat[j]; i++, j++)
                ;

            if (j == lastp) {
                return start; 
            }
        }
    }

    return -1;
}

int main() {
    char text[] = "AUTOMOBILE";
    char pattern[] = "MOBILE";

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);

    int result = nfind(text, pattern);

    if (result != -1) {
        printf("Pattern found at index %d\n", result);
    } else {
        printf("Pattern not found\n");
    }

    return 0;
}
