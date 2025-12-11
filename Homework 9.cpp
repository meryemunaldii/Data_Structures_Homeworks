/*
Ýlk örnek: a - b + c * 2 (iþlem önceliklerine göre AST: + kök, sol - alt aðaç, sað * alt aðaç).
Ýkinci örnek: (a + b) * (c - d).

Node yapýsý: operatör, deðiþken veya sayý düðümlerini tutuyor.

new_op, new_num, new_var: aðaç düðümleri yaratýyor.

print_ast: aðaç yapýsýný saða döndürülmüþ þekilde yazdýrýyor (yukarýdaki slaytta gördüðümüz gibi basamaklý görünüm saðlar).

eval: deðiþkenlere verdiðin deðerlerle ifadeyi hesaplýyor.


*/
#include <stdio.h>
#include <stdlib.h>

typedef enum { NODE_OP, NODE_NUM, NODE_VAR } NodeType;

typedef struct Node {
    NodeType type;
    char op;         // for NODE_OP: '+', '-', '*', '/'
    int value;       // for NODE_NUM
    char var;        // for NODE_VAR (like 'a', 'b')
    struct Node *left, *right;
} Node;

/* --- Node oluþturucular --- */
Node* new_op(char op, Node* l, Node* r){
    Node* n = malloc(sizeof(Node));
    n->type = NODE_OP; n->op = op; n->left = l; n->right = r;
    return n;
}
Node* new_num(int v){
    Node* n = malloc(sizeof(Node));
    n->type = NODE_NUM; n->value = v; n->left = n->right = NULL;
    return n;
}
Node* new_var(char name){
    Node* n = malloc(sizeof(Node));
    n->type = NODE_VAR; n->var = name; n->left = n->right = NULL;
    return n;
}

/* --- AST'i "rotated" (saða döndürülmüþ) þekilde yazdýrma --- */
void print_ast(Node* root, int level){
    if(!root) return;
    print_ast(root->right, level + 1);

    for(int i=0;i<level;i++) printf("    "); // 4-space indent per level

    if(root->type == NODE_OP)
        printf("%c\n", root->op);
    else if(root->type == NODE_NUM)
        printf("%d\n", root->value);
    else
        printf("%c\n", root->var);

    print_ast(root->left, level + 1);
}

/* --- Basit deðerlendirme: deðiþkenlere deðer ver --- */
int eval(Node* root, int vars[26]){
    if(root->type == NODE_NUM) return root->value;
    if(root->type == NODE_VAR) return vars[root->var - 'a'];
    int L = eval(root->left, vars);
    int R = eval(root->right, vars);
    switch(root->op){
        case '+': return L + R;
        case '-': return L - R;
        case '*': return L * R;
        case '/': return R != 0 ? L / R : 0;
    }
    return 0;
}

/* --- Belleði temizle --- */
void free_ast(Node* n){
    if(!n) return;
    free_ast(n->left);
    free_ast(n->right);
    free(n);
}

/* --- Örnekler --- */
int main(void){
    /* Örnek 1: a - b + c * 2
       AST (önceliklere göre):        +
                                     / \
                                   -     *
                                  / \   / \
                                 a  b  c   2
    */
    Node* ex1 = new_op('+',
                    new_op('-', new_var('a'), new_var('b')),
                    new_op('*', new_var('c'), new_num(2))
                 );

    printf("Example 1: expression = a - b + c * 2\n");
    print_ast(ex1, 0);

    int vars[26] = {0};
    vars['a' - 'a'] = 10;
    vars['b' - 'a'] = 3;
    vars['c' - 'a'] = 4;
    printf("Evaluated (a=10,b=3,c=4): %d\n\n", eval(ex1, vars));

    /* Örnek 2: (a + b) * (c - d)
       AST:
                  *
                 / \
                +   -
               / \ / \
              a  b c  d
    */
    Node* ex2 = new_op('*',
                    new_op('+', new_var('a'), new_var('b')),
                    new_op('-', new_var('c'), new_var('d'))
                  );

    printf("Example 2: expression = (a + b) * (c - d)\n");
    print_ast(ex2, 0);

    vars['a' - 'a'] = 2;
    vars['b' - 'a'] = 3;
    vars['c' - 'a'] = 10;
    vars['d' - 'a'] = 4;
    printf("Evaluated (a=2,b=3,c=10,d=4): %d\n", eval(ex2, vars));

    free_ast(ex1);
    free_ast(ex2);
    return 0;
}


