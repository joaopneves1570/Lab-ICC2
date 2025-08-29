#include <stdio.h>

int potencia(int n, int k){
    // int r;
    if (k == 1)
        return n;
    if ((k > 1) && (k%2 == 0)){
        int r = potencia(n, k/2);
        return (r * r)%1000;
    }
    else{
        int r = potencia(n,k/2);
        return (r*r*n)%1000;
    }
}

int main(){
    int n, k;

    scanf("%d %d", &n, &k);

    int resultado = potencia(n,k);
    printf("%d\n", resultado);
}

