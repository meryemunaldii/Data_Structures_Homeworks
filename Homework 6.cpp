/*Arrayla kuyruk yap ,peak yap, enqueue, dequeue yap.*/

#include <stdio.h>
#include <stdlib.h>

#define BOYUT 5 // Kuyruðun maksimum kapasitesi

int items[BOYUT];
int front = -1; // Kuyruðun baþý
int rear = -1;  // Kuyruðun sonu

// Kuyruk Dolu mu Kontrolü
int isFull() {
    if ((front == 0 && rear == BOYUT - 1) || (front == rear + 1)) {
        return 1;
    }
    return 0;
}

// Kuyruk Boþ mu Kontrolü
int isEmpty() {
    if (front == -1) {
        return 1;
    }
    return 0;
}

// ENQUEUE: Kuyruða Eleman Ekleme
void enqueue(int element) {
    if (isFull()) {
        printf("\nKuyruk Dolu! (Overflow) -> %d eklenemedi.\n", element);
    } else {
        if (front == -1) { 
            front = 0; // Ýlk eleman ekleniyorsa front'u 0 yap
        }
        
        // Rear'ý bir artýr (modülo ile döngüsellik saðlanýr)
        rear = (rear + 1) % BOYUT;
        items[rear] = element;
        printf("%d eklendi.\n", element);
    }
}

// DEQUEUE: Kuyruktan Eleman Çýkarma
int dequeue() {
    int element;
    if (isEmpty()) {
        printf("\nKuyruk Bos! (Underflow)\n");
        return -1;
    } else {
        element = items[front];
        
        // Eðer içeride tek eleman kaldýysa ve onu siliyorsak, indeksleri sýfýrla
        if (front == rear) {
            front = -1;
            rear = -1;
        } 
        // Deðilse front'u bir ilerlet (modülo ile döngüsellik saðlanýr)
        else {
            front = (front + 1) % BOYUT;
        }
        printf("%d cikarildi.\n", element);
        return element;
    }
}

// Kuyruðu Ekrana Yazdýrma (Görselleþtirme için)
void display() {
    int i;
    if (isEmpty()) {
        printf("\nKuyruk Bos\n");
    } else {
        printf("\nKuyruk icerigi -> ");
        for (i = front; i != rear; i = (i + 1) % BOYUT) {
            printf("%d ", items[i]);
        }
        printf("%d \n", items[i]);
    }
}

int main() {
    // Test Ýþlemleri
    dequeue(); // Boþken çýkarma denemesi
    
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50); // Kuyruk doldu
    
    enqueue(60); // Taþma (Overflow) testi
    
    display();
    
    dequeue(); // 10 çýkar
    dequeue(); // 20 çýkar
    
    display();
    
    enqueue(60); // Döngüsel olduðu için 10 ve 20'nin yerine ekleyebilmeli
    
    display();

    return 0;
}

