#include "list.h"

int a = -1;

/*
  ListCount(list)
  returns the number of items in list.
*/
int ListCount(struct List *list){
  if (list == NULL){
    return a;
  }
  return list->count;
}

/*
  ListFirst(list)
  returns a pointer to the first item in list and makes the first
  item the current item.
*/
void *ListFirst(struct List *list){
  if(list == NULL || list->count == 0 || list->node_first == NULL){
    return NULL;
  }
  list->current = list->node_first;
  return ListCurr(list);
}

/*
  ListLast(list)
  returns a pointer to the last item in list and makes the last
  item the current one.
*/
void *ListLast(struct List *list){
  if(list == NULL || list->count == 0 || list->node_last == NULL){
    return NULL;
  }
  list->current = list->node_last;
  return ListCurr(list);
}

/*
  ListNext(list)
  advances list's current item by one, and returns a pointer to the
  new current item. If this operation attempts to advances the
  current item beyond the end of the list, a NULL pointer is
  returned.
*/
void *ListNext(struct List *list){
  if(list == NULL || list->count == 0 || list->current == NULL ){
    return NULL;
  }
  
  list->current = list->current->next_node;
  return ListCurr(list);
}

/*
  ListPrev(list)
  backs up list's current item by one,
  and returns a pointer to the new current item.
  If this operation attempts to back up the current item
  beyond the start of the list, a NULL pointer is returned.
*/
void *ListPrev(struct List *list){
  if(list == NULL || list->count == 0 || list->current == NULL 
    || list->next_list != NULL /*the list is still in the pool*/){
    return NULL;
  }
  list->current = list->current->back_node;
  return ListCurr(list);
}

/*
  ListCurr(list)
  returns a pointer to the current item in list.
*/
void *ListCurr(struct List *list){
  if(list == NULL || list->count == 0 || list->current == NULL
    || list->next_list != NULL /*the list is still in the pool*/){
    return NULL;
  }
  return list->current->item;
}


/*
  ListSearch(list, comparator, comparisonArg)
  searches list starting at the current item
  until the end is reached or a match is found.
  In this context, a match is determined by the comparator parameter.
  This parameter is a pointer to a routine that
  takes as its first argument an item pointer,
  and as its second argument comparisonArg.
  Comparator returns 0 if the item and comparisonArg don't match
  (i.e. didn't find it),
  or 1 if they do (i.e. found it).
  Exactly what constitutes a match is up to the implementor of comparator.
  If a match is found, the current pointer is left at the matched item and
  the pointer to that item is returned. If no match is found, the current
  pointer is left at the end of the list and a NULL pointer is returned.
*/
void *ListSearch(struct List *list, int (*comparator)(), void *comparisonArg){
  void *Item = NULL;
  void* travel;
  int result;
  if(list == NULL || comparator == NULL || comparisonArg == NULL || list->count == 0
    || list->next_list != NULL /*the list is still in the pool*/){
    return Item;
  }
  travel = ListFirst(list);
  while(travel != NULL){
    result =  (*comparator)(comparisonArg, travel);
    if(result == 1){
      break;
    }
    travel = ListNext(list);
  }
  if(travel == NULL){
    list->current = list->node_last;
  }
  
  return travel;
}





