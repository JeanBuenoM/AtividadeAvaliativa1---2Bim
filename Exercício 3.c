#include <stdio.h>
#include <stdlib.h>

void hanoi(int n, char origem, char destino, char aux, long long *moves)
{
    if (n == 1) {
        printf("  Disco  1 : %c  -->  %c\n", origem, destino);
        (*moves)++;
        return;
    }

    hanoi(n - 1, origem, aux, destino, moves);

    printf("  Disco %2d : %c  -->  %c\n", n, origem, destino);
    (*moves)++;

    hanoi(n - 1, aux, destino, origem, moves);
}

int main(void)
{
    int n;
    printf("Torres de Hanoi\n");
    printf("Digite o numero de discos: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Valor inválido. Informe um inteiro positivo.\n");
        return 1;
    }
  
    long long moves = 0;

    printf("\n--- Sequência de movimentos (A = origem, C = destino, B = auxiliar) ---\n\n");

    if (n <= 20) {
        hanoi(n, 'A', 'C', 'B', &moves);
    } else {
        printf("[Aviso] n > 20: listagem de movimentos omitida por excesso de saída.\n");
   
        if (n <= 30) {
            hanoi(n, 'A', 'C', 'B', &moves);
        } else {
            moves = 1;
            for (int i = 0; i < n; i++) {
                moves *= 2;
            }
            moves -= 1;
        }
    }

    printf("\n--- Resultado ---\n");
    printf("Discos         : %d\n", n);
    printf("Total de movimentos: %lld  (formula: 2^n - 1 = 2^%d - 1)\n",
           moves, n);

    return 0;
}
