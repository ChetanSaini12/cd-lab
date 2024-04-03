#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_STOP_WORDS 100

int is_stop_word(char *word, char **stop_words, int num_stop_words) {
    for (int i = 0; i < num_stop_words; i++) {
        if (strcmp(word, stop_words[i]) == 0) {
            return 1; // Found stop word
        }
    }
    return 0; // Not a stop word
}

int main() {
    FILE *story_file, *stop_file, *story_without_stopwords_file;
    char word[MAX_WORD_LENGTH];
    char *stop_words[MAX_STOP_WORDS];
    int num_stop_words = 0;

    // Open stop words file
    stop_file = fopen("stop.txt", "r");
    if (stop_file == NULL) {
        printf("Error opening stop.txt file\n");
        return 1;
    }

    // Read stop words into array
    while (fscanf(stop_file, "%s", word) != EOF && num_stop_words < MAX_STOP_WORDS) {
        stop_words[num_stop_words] = strdup(word);
        num_stop_words++;
    }

    // Close stop words file
    fclose(stop_file);

    // Open story file
    story_file = fopen("story.txt", "r");
    if (story_file == NULL) {
        printf("Error opening story.txt file\n");
        return 1;
    }

    // Create new file for story without stop words
    story_without_stopwords_file = fopen("story_without_stopwords.txt", "w");
    if (story_without_stopwords_file == NULL) {
        printf("Error creating story_without_stopwords.txt file\n");
        return 1;
    }

    // Read story file, remove stop words, and write to new file
    while (fscanf(story_file, "%s", word) != EOF) {
        // Convert word to lowercase for case-insensitive comparison
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }

        if (!is_stop_word(word, stop_words, num_stop_words)) {
            fprintf(story_without_stopwords_file, "%s ", word);
        }
    }

    // Close files
    fclose(story_file);
    fclose(story_without_stopwords_file);

    // Free allocated memory for stop words
    for (int i = 0; i < num_stop_words; i++) {
        free(stop_words[i]);
    }

    printf("Stop words removed successfully.\n");

    return 0;
}
