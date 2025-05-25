#include <stdio.h>


// verifica se o numero é primo
// se o numero < 2, logo nao é primo, logo retorna 0 (false)
// para i = 2 e 2 * 2 menor ou igual ao numero, adicione 1 ao i, logo:
            // para i = 3 e 3 *3 menor ou igual ao numero, adicione 1 ao 1
            // e assim vai.
    // se o resto da divisao entre o valor do numero e o valor de i for igual 0,
    // retorna 0 ( false), pois nao é primo
     // caso for diferente de 0, retorne 1
int confirma_primo(int num)
{
    if (num < 2)
        return 0;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int main(void)
{
    // variavel da quantidade (ainda nao definida)
    // variavel do contador, definida inicialmente como 0, pois ainda nao teve contagem
    // variavel de teste_primo --> teste = 2 pois 2 é o 1° numero primo
   int qtd, cont = 0, teste = 2;

    // bloqueia o usuario de inserir uma quantidade menor ou igual a 0
   do
   {
    printf("Quantos números devem aparecer? ");
    scanf("%d", &qtd);
   }
   while (qtd <= 0);

   // exibe os n(qtd) numeros primos
   printf("Os primeiros %d primos são: \n", qtd);

   // enquanto o contador (0 inicialmente) for menor que a quantidade (inserida pelo usuario)
        // se a confirmaçao de numero primo estiver no teste atual
            // mostre o numero e some 1 ao contador (agora tendo o valor de 1)
        // adiciona 1 ao teste (no caso inicialmente 2 (que é o 1° numero primo)), indo para o proximo numero primo (no caso inicial -> 3)
   while (cont < qtd)
   {
    if (confirma_primo(teste))
    {
        printf("%d ", teste);
        cont++;
    }
    teste++;
   }

   printf("\n");
    return 0;
}
