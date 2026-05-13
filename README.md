Exercício 1 — Calcula o n-ésimo termo da sequência de Fibonacci de forma recursiva simples. O caso base é quando n é 0 ou 1, retornando o próprio valor. Para os demais casos, a função chama a si mesma para n-1 e n-2 e soma os resultados.
O problema dessa abordagem é que os mesmos subproblemas são recalculados várias vezes, tornando o algoritmo muito ineficiente para valores grandes de n. O programa exibe a quantidade total de chamadas recursivas para evidenciar isso.

Exercício 2 — Resolve o mesmo problema do exercício anterior, mas armazena os resultados já calculados em um vetor alocado dinamicamente. Antes de fazer uma chamada recursiva, a função verifica se o resultado daquele índice já existe no cache. Se sim, retorna direto sem recursão. Se não, calcula, salva no cache e retorna.
O caso base e a lógica recursiva são idênticos à versão ingênua. A diferença está apenas no reaproveitamento dos resultados, o que reduz drasticamente a quantidade de chamadas. O programa executa as duas versões e exibe o comparativo.

Exercício 3 — Move n discos do pino A para o pino C usando o pino B como auxiliar. O caso base é quando há apenas um disco, que é movido diretamente para o destino. Para mais discos, a função move os n-1 discos menores para o pino auxiliar, move o disco maior para o destino e depois move os n-1 discos do auxiliar para o destino.
O programa lista cada movimento realizado e exibe o total ao final. O número mínimo de movimentos para n discos é sempre 2ⁿ - 1.
