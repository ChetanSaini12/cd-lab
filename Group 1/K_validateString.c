#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_a_star(char *str)
{
    // Check if the string is of the form a*
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != 'a')
        {
            return 0;
        }
    }
    return 1;
}

int is_a_b_plus(char *str)
{
    // Check if the string is of the form a*b+
    int a_count = 0;
    int b_count = 0;
    int i = 0;

    // Count the number of 'a's at the beginning
    while (str[i] == 'a')
    {
        a_count++;
        i++;
    }

    // Count the number of 'b's after 'a's
    while (str[i] == 'b')
    {
        b_count++;
        i++;
    }

    // Check if 'a's are followed by one or more 'b's
    return (a_count > 0 && b_count > 0 && str[i] == '\0');
}

int is_abb(char *str)
{
    // Check if the string is "abb"
    return (strlen(str) == 3 && str[0] == 'a' && str[1] == 'b' && str[2] == 'b');
}

int main()
{
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    if (is_a_star(str))
    {
        printf("String matches pattern a*\n");
    }
    else if (is_a_b_plus(str))
    {
        printf("String matches pattern a*b+\n");
    }
    else if (is_abb(str))
    {
        printf("String matches pattern abb\n");
    }
    else
    {
        printf("String does not match any pattern.\n");
    }

    return 0;
}
