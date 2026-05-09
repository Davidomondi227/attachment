#include <stdio.h>

int main(int argc, char *argv[])
{

    int k;
    int i;
    int j;
    char plaintext[1000];

    /* 1. Validate argument count */
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    /* 2. Validate key and convert to integer */
    k = 0;
    for (i = 0; argv[1][i] != '\0'; i++)
    {
        if (argv[1][i] < '0' || argv[1][i] > '9')
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        k = k * 10 + (argv[1][i] - '0');
    }

    /* 3. Get input from user */
    printf("plaintext:  ");
    if (fgets(plaintext, sizeof(plaintext), stdin) == NULL)
    {
        return 1;
    }

    printf("ciphertext: ");

    /* 4. Encrypt */
    for (j = 0; plaintext[j] != '\0'; j++)
    {
        char p = plaintext[j];

        if (p >= 'A' && p <= 'Z')
        {
            /* Shift uppercase */
            printf("%c", (p - 'A' + k) % 26 + 'A');
        }
        else if (p >= 'a' && p <= 'z')
        {
            /* Shift lowercase */
            printf("%c", (p - 'a' + k) % 26 + 'a');
        }
        else
        {
            /* Print everything else as-is */
            printf("%c", p);
        }
    }

    return 0;
}