#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isVowel(char ch) {
    ch = tolower(ch);
    return strchr("aeiou", ch) != NULL;
}

void processLine(char *line) {
    for (int i = 0; line[i] != '\0'; ++i) {
        if (isalpha(line[i]) && isVowel(line[i])) {
            line[i] = '@';
        }
    }
}

int main() {
    FILE *inputFile, *outputFile;
    char line[100];

    if ((inputFile = fopen("input.txt", "r")) == NULL) {
        printf("%s", "Error opening input file.\n");
        return 1;
    }

    if ((outputFile = fopen("output.txt", "w")) == NULL) {
        printf("%s", "Error opening output file.\n");
        fclose(inputFile);
        return 1;
    }

    while (fgets(line, sizeof(line), inputFile) != NULL) {
        line[strcspn(line, "\n")] = '\0';

        processLine(line);

        if (strlen(line) % 2 == 0) {
            printf("Modified Line: %s\n", line);
        }

        fprintf(outputFile, "%s\n", line);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Processing complete. \n");

    return 0;
}
