#include <stdio.h>

int main(){
    int n, k, rfinal = 1;
    scanf("%d %d", &n, &k);
    if (n == 0){
        printf("0");
        return 0;
    }
    // Caso a potência seja nula (N⁰ = 1)
    if (k == 0){
        printf("%d", rfinal);
        return 0;
    }
    // Só utiliza os 3 último números
    for (int i = 0; i < k; i++){
        rfinal = (rfinal * n)%1000;
    }
    
    
    printf("%d", rfinal);

    return 0;
}