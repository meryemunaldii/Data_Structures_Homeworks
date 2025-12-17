

/*Max Heap, tam ikili aðaç yapýsýnda bir veri yapýsýdýr.
Her düðümün deðeri, çocuk düðümlerinin deðerlerinden büyük veya eþittir.
Bu nedenle en büyük eleman her zaman kökte bulunur.
Genellikle öncelik kuyruðu (priority queue) ve heap sort uygulamalarýnda kullanýlýr.
Ekleme ve silme iþlemleri O(log n) zaman alýr.


*/

#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

// Eleman ekleme (heapify up)
void insertMax(int value) {
    int i = size;
    heap[size++] = value;

    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// Heapify down
void maxHeapify(int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;

    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        maxHeapify(largest);
    }
}

// En büyük elemaný sil
int deleteMax() {
    if (size <= 0) return -1;

    int root = heap[0];
    heap[0] = heap[--size];
    maxHeapify(0);
    return root;
}

// Heap yazdýr
void printHeap() {
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    insertMax(10);
    insertMax(40);
    insertMax(30);
    insertMax(5);
    insertMax(12);

    printHeap();

    printf("Silinen max: %d\n", deleteMax());
    printHeap();

    return 0;
}

