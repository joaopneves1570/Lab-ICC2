#include <stdio.h>

int main() {
    int n, k;
    int resultado = 1;

    scanf("%d %d", &n, &k);

    n = n % 1000; // já reduz a base para evitar overflow

    // Exponenciação rápida iterativa
    while (k > 0) {
        if (k % 2 == 1) { // se k é ímpar
            resultado = (resultado * n) % 1000;
        }
        n = (n * n) % 1000; // quadrado da base
        k /= 2;
    }

    // Saída sem zeros à esquerda
    printf("%d\n", resultado);

    return 0;
}
