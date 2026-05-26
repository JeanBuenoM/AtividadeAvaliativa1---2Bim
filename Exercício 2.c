#include <stdio.h>
#include <stdlib.h>

#define NAO_CALCULADO (-1LL)   /* sentinela: posicao ainda nao visitada */

long long fib_naive(int n, long long *calls)
{
    (*calls)++;
    if (n <= 1) return n;
    return fib_naive(n - 1, calls) + fib_naive(n - 2, calls);
}

long long fib_memo(int n, long long *cache, long long *calls)
{
    (*calls)++;

    if (n <= 1)
        return n;

    if (cache[n] != NAO_CALCULADO)
        return cache[n];

    cache[n] = fib_memo(n - 1, cache, calls)
             + fib_memo(n - 2, cache, calls);

    return cache[n];
}

int main(void)
{
    int n;

    printf("Digite o valor de n: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Entrada inválida. Informe um inteiro não negativo.\n");
        return 1;
    }

    long long calls_naive = 0;
    long long res_naive = 0;

    if (n <= 45) {
        res_naive = fib_naive(n, &calls_naive);
    } else {
        printf("\n[Aviso] n > 45: versão não otimizada omitida.\n");
        calls_naive = -1; 
    }

    long long *cache = (long long *) malloc((n + 1) * sizeof(long long));
    if (cache == NULL) {
        printf("Erro: falha na alocacao de memoria.\n");
        return 1;
    }

    for (int i = 0; i <= n; i++)
        cache[i] = NAO_CALCULADO;

    long long calls_memo = 0;
    long long res_memo = fib_memo(n, cache, &calls_memo);

    printf("\nFibonacci(%d) = %lld\n", n, res_memo);

    printf("\n--- Comparativo de chamadas recursivas ---\n");
    if (calls_naive >= 0)
        printf("  Versao não otimizada : %lld chamadas (resultado: %lld)\n",
               calls_naive, res_naive);
    else
        printf("  Versão não otimizada  : não executada (n muito grande)\n");

    printf("  Versão memorizada: %lld chamadas\n", calls_memo);

    if (calls_naive > 0)
        printf("\n  Redução de chamadas: %.1fx menos com memorização.\n",
               (double) calls_naive / calls_memo);

    free(cache);
    return 0;
}
