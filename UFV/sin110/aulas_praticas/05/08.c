#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    char string1[501], string2[501];
    int i;
    bool iguais = true;

    printf("String 01: ");
    fgets(string1, sizeof(string1), stdin);

    printf("String 02: ");
    fgets(string2, sizeof(string2), stdin);

    for (i = 0; string1[i] != '\0' && string1[i] != '\n'; i++);
    string1[i] = '\0';

    for (i = 0; string2[i] != '\0' && string2[i] != '\n'; i++);
    string2[i] = '\0';

    for (i = 0; string1[i] != '\0' || string2[i] != '\0'; i++)
    {
        if (string1[i] != string2[i])
        {
            iguais = false;
            break;
        }
    }

    if (iguais)
        printf("As duas strings são iguais.\n");
    else
        printf("As duas strings não são iguais.\n");

    return 0;
}
