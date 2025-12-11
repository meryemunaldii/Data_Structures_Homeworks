/*What is the Towers of Hanoi?

Towers of Hanoi is a classic mental exercise and recursive execution problem, covering fundamental rules in computer science and mathematics.

This problem is often solved using recursion. The simple logic is:
To move n disks:
1.)Move n-1 disks from A to B (with C as a slave).
2.)Move the largest disk (the nth disk) from A to C.
3.)Move n-1 disks from B to C (with A as a slave).*/

#include <stdio.h>

// Hanoi Fonksiyonu
// n: Disk sayýsý
// kaynak: Kaynak çubuk (A)
// yardimci: Yardýmcý çubuk (B)
// hedef: Hedef çubuk (C)
void hanoi(int n, char kaynak, char yardimci, char hedef) {
    
    // Temel Durum (Base Case): Sadece 1 disk kaldýysa direkt hedefe taþý
    if (n == 1) {
        printf("Disk 1 tasindi: %c -> %c\n", kaynak, hedef);
        return;
    }
    
    // ADIM 1: n-1 diski, kaynak'tan yardimci'ya taþý (hedef'i geçici kullan)
    hanoi(n - 1, kaynak, hedef, yardimci);
    
    // ADIM 2: En büyük diski (n. disk), kaynak'tan hedef'e taþý
    printf("Disk %d tasindi: %c -> %c\n", n, kaynak, hedef);
    
    // ADIM 3: n-1 diski, yardimci'dan hedef'e taþý (kaynak'ý geçici kullan)
    hanoi(n - 1, yardimci, kaynak, hedef);
}

int main() {
    int n;
    
    printf("Disk sayisini giriniz: ");
    scanf("%d", &n);
    
    printf("\n--- Adimlar ---\n");
    // A: Kaynak, B: Yardýmcý, C: Hedef
    hanoi(n, 'A', 'B', 'C'); 
    
    return 0;
}
