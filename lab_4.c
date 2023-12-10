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

    // Open the input file
    if ((inputFile = fopen("input.txt", "r")) == NULL) {
        printf("%s", "Error opening input file.\n");
        return 1;
    }

    // Open the output file
    if ((outputFile = fopen("output.txt", "w")) == NULL) {
        printf("%s", "Error opening output file.\n");
        fclose(inputFile);
        return 1;
    }

    // Read each line from the input file
    while (fgets(line, sizeof(line), inputFile) != NULL) {
        // Remove the newline character at the end
        line[strcspn(line, "\n")] = '\0';

        // Process the line and replace vowels with '@'
        processLine(line);

        // Display lines with an even number of characters
        if (strlen(line) % 2 == 0) {
            printf("Modified Line: %s\n", line);
        }

        // Write the processed line to the output file
        fprintf(outputFile, "%s\n", line);
    }

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    printf("Processing complete. \n");

    return 0;
}
