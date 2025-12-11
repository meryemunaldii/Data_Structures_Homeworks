/*Genelde Binary Tree (ikili aðaç) için kullanýlýr ve dizide indekslere göre yerleþim kurallarý vardýr.
 1. Root (kök) her zaman index 0'dadýr.
 2. Bir elemanýn çocuklarýný bulma
Dizideki bir elemanýn index'i = i ise:
"	Left child (sol çocuk): 2*i + 1
"	Right child (sað çocuk): 2*i + 2
3. Bir elemanýn parent'ýný bulma
Parent index = (i - 1) / 2 (tam sayý bölme)
*/


#include <stdio.h>

int tree[100]; // array tabanlý tree

void setRoot(int value){
    tree[0] = value;
}

void setLeft(int parentIndex, int value){
    tree[2*parentIndex + 1] = value;
}

void setRight(int parentIndex, int value){
    tree[2*parentIndex + 2] = value;
}

int main(){
    setRoot(10);
    setLeft(0, 20);
    setRight(0, 30);
    setLeft(1, 40);
    setRight(1, 50);

    for(int i = 0; i < 10; i++){
        if(tree[i] != 0)
            printf("Index %d -> %d\n", i, tree[i]);
    }

    return 0;
}

