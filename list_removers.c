//Gas

#include <stdio.h>
#include "list.h"


int b = -1;/*only for test*/

/*
 ListRemove(list)
 Return current item and take it out of list. Make the next item the
 current one.
*/
void *ListRemove(struct List *list){
  NODE *nodeRemove;
  void *itemRemove;
  int usedNode;
  if(list == NULL || list->count == 0 || list->current == NULL){
    return NULL;
  }
  
  nodeRemove = list->current;
  /* if only one item in the list */
  if(list->count == 1){
    list->node_first = NULL;
    list->node_last = NULL;
  }else{/* if count > 1 */
    if(list->current == list->node_last){ /* delete last of list */
      list->node_last = nodeRemove->back_node;
      list->node_last->next_node = NULL;
    }else if(list->current == list->node_first){ /* delete first of list */
      list->node_first = nodeRemove->next_node;
      list->node_first->back_node = NULL;
    }else{ /* delete between first and last of list */
      nodeRemove->back_node->next_node = nodeRemove->next_node;
      nodeRemove->next_node->back_node = nodeRemove->back_node;
    }
  }

  list->current = nodeRemove->next_node;
  list->count --;
  
  
  itemRemove = nodeRemove->item;
  
  /* add one available node to the node pool */
  /*nodeRemove->item = NULL;*/
  nodeRemove->next_node = allNodes[0].next_node;
  allNodes[0].next_node = nodeRemove;
  nodeRemove->back_node = NULL;
  
  currentNode_Available ++;
  nodeRemove->used = 0;
  

  /* determine the memory of the node, we say it is n,
    if used# =  x: x < 2/n && n > MIN_NODES, realloc the node pool */
  usedNode = (totalNode -1) - currentNode_Available;
  if(usedNode == totalNode/2 && totalNode > MIN_NODES){
    decreaseingNPRea();
  }

  /*printf("remove item is: %d. \n", *(int *)itemRemove);*/
  return itemRemove;
}



/*
 ListFree(list, itemFree)
 delete list.
 itemFree is a pointer to a routine that frees an item.
 It should be invoked (within ListFree) as:
 (*itemFree)(itemToBeFreed);
*/
void ListFree(struct List *list, void (*itemFree)()){
  if(list == NULL || list->next_list != NULL /*the list is still in the pool*/ ){
    /*if list is null, do nothing*/
    return;
  }
  
  while(list->count != 0 ) {
    (*itemFree)(list->node_last);
    ListTrim(list);
  }

  if (list->count != 0 || list->current != NULL) {
    printf("error in ListFree, list_removers.c\n");
  }
  
  list->next_list = allLists[0].next_list;
  allLists[0].next_list = list;
  currentList --;

  
  /*
   shrink the list pool.
   */
  if(currentList <= ((totalList/2) - 1) && totalList > MIN_LISTS){
    decreaseingLPRea();
  }
  
  
  return;
}


/*
 ListTrim(list);
 Return last item and take it out of list.
 The current pointer shall be the new last item in the list.
*/
void *ListTrim(struct List *list){
  NODE* removeNode;
  void* itemRemove;
  int usedNode;
  
  if(list == NULL || list->count == 0 
    || list->next_list != NULL /*the list is still in the pool*/){
    return NULL;
  }


  removeNode =  list->node_last;
  removeNode =  list->node_last;
  if(list->count == 1){
    list->node_last = NULL;
    list->node_first = NULL;
  }else{
    list->node_last = removeNode->back_node;
    list->node_last->next_node = NULL;
  }
  list->current = list->node_last;
  list->count --;
  
  itemRemove = removeNode->item;
  
  /*add it into node pool*/
  removeNode->next_node = allNodes[0].next_node;
  allNodes[0].next_node = removeNode;
  removeNode->back_node = NULL;


  removeNode->used = 0;
  currentNode_Available ++;



  /*
   shrink the node pool.
   */
  usedNode = (totalNode -1) - currentNode_Available;
  if(usedNode == totalNode/2 && totalNode > MIN_NODES){
    decreaseingNPRea();
  }

  
  
  return itemRemove;
  
}

