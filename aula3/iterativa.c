#include <stdio.h>

int main(){
    int n, k, rfinal = 1;
    scanf("%d %d", &n, &k);
    if (n == 0){
        printf("0");
        return 0;
    }
    if (k == 0){
        printf("%d", rfinal);
        return 0;
    }

    for (int i = 0; i < k; i++){
        rfinal = (rfinal * n)%1000;
    }
    rfinal = (rfinal * rfinal) %1000;
    
    printf("%d", rfinal);

    return 0;
}