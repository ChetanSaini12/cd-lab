#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int is_comment(char *line)
{
    // Check if line is a single-line comment
    if (strstr(line, "//") == line)
    {
        return 1;
    }

    // Check if line is a multi-line comment start
    if (strstr(line, "/*") != NULL)
    {
        return 2;
    }

    // Check if line is a multi-line comment end
    if (strstr(line, "*/") != NULL)
    {
        return 3;
    }

    return 0; // Not a comment
}

int main()
{
    FILE *input_file;
    char line[MAX_LINE_LENGTH];
    int line_number = 0;
    int inside_multi_line_comment = 0;

    // Open input C program file
    input_file = fopen("input.c", "r");
    if (input_file == NULL)
    {
        printf("Error opening input file\n");
        return 1;
    }

    // Read each line from input file and identify comments
    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL)
    {
        line_number++;

        // Check if inside multi-line comment
        if (inside_multi_line_comment)
        {
            printf("Multi-line comment: %s", line);

            // Check if this line contains the end of multi-line comment
            if (strstr(line, "*/") != NULL)
            {
                inside_multi_line_comment = 0;
            }
            continue;
        }

        int comment_type = is_comment(line);

        switch (comment_type)
        {
        case 1:
            printf("Single-line comment at line %d: %s", line_number, line);
            break;
        case 2:
            printf("Multi-line comment starts at line %d: %s", line_number, line);
            inside_multi_line_comment = 1;
            break;
        case 3:
            printf("Multi-line comment ends at line %d: %s", line_number, line);
            break;
        default:
            break;
        }
    }

    // Close input file
    fclose(input_file);

    return 0;
}
