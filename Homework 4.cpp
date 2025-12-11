/*Write the elements in a doubly linked list recursively and non-recursively.*/

//RECURSIVE
#include <stdio.h>
#include <stdlib.h>

// Düðüm tanýmý
typedef struct Node {
    int veri;
    struct Node* onceki;
    struct Node* sonraki;
} Node;

// Yeni düðüm oluþturma
Node* yeniDugum(int veri) {
    Node* yeni = (Node*)malloc(sizeof(Node));
    yeni->veri = veri;
    yeni->onceki = NULL;
    yeni->sonraki = NULL;
    return yeni;
}

// Listenin sonuna eleman ekleme
void sonaEkle(Node** bas, int veri) {
    Node* yeni = yeniDugum(veri);
    if (*bas == NULL) {
        *bas = yeni;
        return;
    }
    Node* tmp = *bas;
    while (tmp->sonraki != NULL) {
        tmp = tmp->sonraki;
    }
    tmp->sonraki = yeni;
    yeni->onceki = tmp;
}

// Rekürsif yazdýrma
void yaz(Node* bas) {
    if (bas == NULL) {
        return;
    }
    printf("%d ", bas->veri);
    yaz(bas->sonraki);
}

int main() {
    Node* bas = NULL;

    sonaEkle(&bas, 10);
    sonaEkle(&bas, 20);
    sonaEkle(&bas, 30);
    sonaEkle(&bas, 40);

    printf("Liste: ");
    yaz(bas);  // Rekürsif olarak yazdýr
    printf("\n");

    return 0;
}

//NON-RECURSIVE
#include <stdio.h>
#include <stdlib.h>

// Düðüm tanýmý
typedef struct Node {
    int veri;
    struct Node* onceki;
    struct Node* sonraki;
} Node;

// Yeni düðüm oluþturma
Node* yeniDugum(int veri) {
    Node* yeni = (Node*)malloc(sizeof(Node));
    yeni->veri = veri;
    yeni->onceki = NULL;
    yeni->sonraki = NULL;
    return yeni;
}

// Listenin sonuna düðüm ekleme
void sonaEkle(Node** bas, int veri) {
    Node* yeni = yeniDugum(veri);
    if (*bas == NULL) {
        *bas = yeni;
        return;
    }

    Node* temp = *bas;
    while (temp->sonraki != NULL) {
        temp = temp->sonraki;
    }

    temp->sonraki = yeni;
    yeni->onceki = temp;
}

// Ýteratif olarak yazdýrma
void yaz(Node* bas) {
    Node* temp = bas;
    while (temp != NULL) {
        printf("%d ", temp->veri);
        temp = temp->sonraki;
    }
}

int main() {
    Node* bas = NULL;

    sonaEkle(&bas, 5);
    sonaEkle(&bas, 15);
    sonaEkle(&bas, 25);
    sonaEkle(&bas, 35);

    printf("Liste: ");
    yaz(bas);  // Rekürsif olmayan þekilde yazdýr
    printf("\n");

    return 0;
}
