#include <stdio.h>

long long fibonacci(int n, long long *calls)
{
    (*calls)++;

    if (n <= 1)
        return n;
    
    return fibonacci(n - 1, calls) + fibonacci(n - 2, calls);
}

int main(void)
{
    int n;

    printf("Digite o valor de n: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Valor inválido. Informe um inteiro nao negativo.\n");
        return 1;
    }

    long long calls = 0;
    long long resultado = fibonacci(n, &calls);

    printf("\nFibonacci(%d) = %lld\n", n, resultado);
    printf("Total de chamadas recursivas: %lld\n", calls);

    return 0;
}
