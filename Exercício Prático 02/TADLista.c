#include <stdlib.h>

typedef struct{
    int chave;
}Item;

typedef struct Cell{
    Item item;
    struct Cell* prox;
}Cell;

typedef struct{
    Cell* first;
    Cell* last;
}List;

//

void initializeList(List* list){
    list->first = (Cell*)malloc(sizeof(Cell));
    list->first->prox = NULL;
    list->last = list->first;
}

void addOnEnd(List* list, Item item){
    list->last->prox = (Cell*)malloc(sizeof(Cell));
    list->last = list->last->prox;
    list->last->prox = NULL;

    list->last->item = item;
}

void addOnPosition(List* list, int position, Item item){
    if(position < 1 || position > sizeOfList(list)){
        return;
    }

    Cell* newCell = (Cell*)malloc(sizeof(Cell));

    Cell* previousCell = list->first;
    Cell* nextCell = previousCell->prox;

    for(int i = 0; i < position; i++){
        previousCell = previousCell->prox;
        nextCell = nextCell->prox;
    }

    //acho que está errado a partir de agora

    newCell = previousCell->prox;
    previousCell->prox = newCell;

    newCell->item = item;
    
}

void destroyList(List* list){
    Cell* thisCell = list->first;
}

int sizeOfList(List* list){
    Cell* thisCell = list->first->prox;
    int size = 0;

    while(thisCell != NULL){
        size++;
        thisCell = thisCell->prox;
    }

    return size;
}