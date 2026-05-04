#include <stdio.h>

void print_row(int spaces, int bricks);

int main(void)
{
    int n;
    int i;  

    do
    {
        printf("Height: ");
        scanf("%d", &n);
    }
    while (n < 1);

	
    for (i = 0; i < n; i++)
    {
        print_row(n - i - 1, i + 1);
    }

    return 0;
}

void print_row(int spaces, int bricks)
{
    int i;  


    for (i = 0; i < spaces; i++)
    {
        printf(" ");
    }

    
    for (i = 0; i < bricks; i++)
    {
        printf("#");
    }

    
    printf("\n");
}
