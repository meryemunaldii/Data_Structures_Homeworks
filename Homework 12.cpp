/*Bir grafý array ile göstermek için en basit yöntem:
Adjacency List (Komþuluk Listesi)
Her düðüm için bir array oluþturdum.
Bu array içinde o düðüme baðlý olan tüm düðümler tuttum.
Örneðin çizdiðin yapýya göre:
C1 ? C2
C2 ? C3
C3 ? C4, C5
C4 ? (bað yok)
C5 ? (bað yok

Bunu þöyle array'lerle tutarsýn:

neighbors[1] = {2}
neighbors[2] = {3}
neighbors[3] = {4, 5}
neighbors[4] = {}
neighbors[5] = {}
*/
#include <stdio.h>
#define MAX 10
int main() {
    // Komþuluk listeleri
    int neighbors[MAX][MAX] = {0};
    int count[MAX] = {0};
    // Baðlantýlar (C1 -> C2)
    neighbors[1][ count[1]++ ] = 2;

    // C2 -> C3
    neighbors[2][ count[2]++ ] = 3;

    // C3 -> C4 ve C5
    neighbors[3][ count[3]++ ] = 4;
    neighbors[3][ count[3]++ ] = 5;

    // Yazdýrma
    for(int i = 1; i <= 5; i++) {
        printf("C%d -> ", i);
        for(int j = 0; j < count[i]; j++) {
            printf("C%d ", neighbors[i][j]);
        }
        printf("\n");
    }

    return 0;
}

