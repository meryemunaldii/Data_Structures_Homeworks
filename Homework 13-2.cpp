/*
Min Heap de tam ikili aðaç yapýsýndadýr.
Her düðümün deðeri, çocuk düðümlerinin deðerlerinden küçük veya eþittir.
Bu yüzden en küçük eleman her zaman kökte yer alýr.
Zamanlama, iþlem sýralama, Dijkstra algoritmasý gibi yerlerde sýkça kullanýlýr.
Ekleme ve silme iþlemleri O(log n) karmaþýklýðýndadýr./*
*/
#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

// Eleman ekleme
void insertMin(int value) {
    int i = size;
    heap[size++] = value;

    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// Heapify down
void minHeapify(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        minHeapify(smallest);
    }
}

// En küçük elemaný sil
int deleteMin() {
    if (size <= 0) return -1;

    int root = heap[0];
    heap[0] = heap[--size];
    minHeapify(0);
    return root;
}

// Heap yazdýr
void printHeap() {
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    insertMin(10);
    insertMin(40);
    insertMin(30);
    insertMin(5);
    insertMin(12);

    printHeap();

    printf("Silinen min: %d\n", deleteMin());
    printHeap();

    return 0;
}

