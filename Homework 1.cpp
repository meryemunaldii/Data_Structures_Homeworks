/*Sparse Matrix and its representations
• A matrix is a two-dimensional data object made of m rows and n
columns, therefore having total m x n values. If most of the
elements of the matrix have 0 value, then it is called a sparse
matrix.
Why to use Sparse Matrix instead of simple matrix ?
• Storage: There are lesser non-zero elements than zeros and thus
lesser memory can be used to store only those elements.
• Computing time: Computing time can be saved by logically
designing a data structure traversing only non-zero elements..*/
#include <stdio.h>
#include <stdlib.h>

// Düðüm Yapýsý
struct Node {
    int row;
    int col;
    int value;
    struct Node *next;
};

// Yeni düðüm oluþturma fonksiyonu
void create_new_node(struct Node **head, int r, int c, int val) {
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->row = r;
    newNode->col = c;
    newNode->value = val;
    newNode->next = NULL;

    // Eðer liste boþsa, baþa ekle
    if (*head == NULL) {
        *head = newNode;
    } 
    // Deðilse, listenin sonuna git ve ekle
    else {
        temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Sparse Matrix'i Yazdýrma
void printSparse(struct Node *start) {
    struct Node *temp = start;
    
    printf("\nSparse Matrix (Linked List):\n");
    printf("Satir\tSutun\tDeger\n");
    printf("---------------------\n");
    
    while (temp != NULL) {
        printf("%d\t%d\t%d\n", temp->row, temp->col, temp->value);
        temp = temp->next;
    }
}

int main() {
    // 4x5'lik Örnek Matris
    int matrix[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    struct Node *head = NULL; // Listenin baþý
    int i, j;

    // Matrisi tara ve 0 olmayanlarý listeye ekle
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            if (matrix[i][j] != 0) {
                create_new_node(&head, i, j, matrix[i][j]);
            }
        }
    }

    printSparse(head);

    return 0;
}

