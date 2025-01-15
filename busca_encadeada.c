#include <stdio.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

celula *busca (celula *le, int x) {
   celula *p;
   for (p = le; p != NULL; p = p->prox)
      if (p->dado == x) return p;
   return NULL;
}

celula *busca_rec (celula *le, int x) {
    celula *p = le;
    if (p-> dado == x) return p;
    if (p-> prox == NULL) return NULL;
    return busca_rec(p->prox, x);
}