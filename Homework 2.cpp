//Write the destroy function recursively

struct node *destroy_recursive(struct node *head) {
    // 1. Temel Durum (Base Case): Eðer liste boþsa veya sona gelindiyse
    if (head == NULL) {
        return NULL;
    }

    // 2. Özyineleme (Recursive Step): Önce listenin geri kalanýný yok et
    // Bu, listenin en sonuna kadar gitmemizi saðlar.
    destroy_recursive(head->next);

    // 3. Ýþlem: Geri dönerken düðümü serbest býrak (free)
    free(head);

    // Baþlangýç pointer'ýný NULL yapmak için NULL döndür
    return NULL;
}
