#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int num;

    printf("Iniciar a contagem regressiva em: ");
    scanf("%d", &num);

    for (int cont = num; cont <= num; cont--)
    {
        printf("%d ", cont);
        sleep(1);

        // para nao continuar a contar depois de 0
        if (cont == 0)
        {
            break;
        }
    }
    printf("\n");

    return 0;
}
