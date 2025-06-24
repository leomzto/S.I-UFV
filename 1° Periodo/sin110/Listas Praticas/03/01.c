#include <stdio.h>


int main(void)
{
    int n1 = 1, n2 = 1;

   while(n1 <= 10 && n2 <= 10)
   {
    
    printf("%d x %d = %d\n", n1, n2, n1 * n2);
    n2++;

    if (n2 == 11)
        {
            n2 = 1;
            n1++;
            printf("\n");
        }
   }
    return 0;
}
