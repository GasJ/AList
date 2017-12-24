#include <stdio.h>
#include "list.h"


  NODE *addOne;
/*
 ListCreate()
 makes a new, empty list, and returns its reference on success.
 Returns a NULL pointer on failure.
 */
struct List *ListCreate(){
  /*declare a list*/
  struct List *newList = NULL;
  List *doubleList;
  int i;
  /*determine whether the list pool and node pool are set*/
  if(allLists == NULL){
    /* if not, set them
     first, malloc memories for them
     we use memories here for expand or shrink space for later use. 
     we need MIN_LISTS lists at first,
     and MIN_NODES+1 nodes in all nodes.
     the more 1 is for nodeFree/linkFree(in the 0 index), which is for link the all available nodes pool */
    allLists = malloc(sizeof(List) * (MIN_LISTS));
    
    /*link the link pool*/
    allLists[0].next_list = &allLists[1];
    for (i = 1; i < MIN_LISTS-1; i++) {
      allLists[i].next_list = &allLists[i + 1];
    }

    currentList=0;  /*global variable for recording how may lists are create*/
    totalList = MIN_LISTS;/*index 0 always be free*/
    
    
    
      allNodes =  malloc(sizeof(NODE) * (MIN_NODES));
  /* nodeFree, is the linker node for the whole node pool, therefore it links to  allNodes[0] */
      nodeFree = &allNodes[0];
  /*link the nodeFree to the first available node
  (all nodes recently malloc are available because they are not used yet)*/
      nodeFree->next_node = &allNodes[1];
  /*link all nodes in the pool*/
      for (i = 1; i < MIN_NODES - 1; i++) {
          allNodes[i].next_node = &allNodes[i + 1];
      }
      currentNode_Available = MIN_NODES-1;
      totalNode = MIN_NODES;
      
      
  }
  
  if (currentList >= totalList-1){
    /*int i;*/
    /* create a list pool, whose size = curren list pool, and then link them
     (this is double the size)*/
    totalList *= 2;
    doubleList = allLists;
    allLists = realloc(doubleList, sizeof(List) * (totalList+1));
    
    /* link all new null list positions */
    allLists[0].next_list = &allLists[currentList+1];
    for (i = currentList+1; i < totalList; i++) {
      doubleList[i].next_list = &doubleList[i+1];
    }
   
  }

   /*pop a list from the list pool*/
   newList = allLists[0].next_list;
   allLists[0].next_list = newList->next_list;
   newList->next_list = NULL;


  currentList++;/* state we used one more list now */
  newList->count = 0;
  newList->used = 1;
  return newList;
}


/*
 ListAdd(list, item)
 adds the new item to list directly after the current item, and makes item
 the current item. If the current pointer is at the end of the list, the
 item is added at the end. Returns 0 on success, -1 on failure.
 */
int ListAdd(struct List *list, void *item){
  /*determine whether the argument is invalid*/
  if(list == NULL || list->current == NULL || item == NULL
    || list->next_list != NULL /*the list is still in the pool*/ ){
    return -1;
  }
  
  /*if current == last, then the situation = listAppend*/
  if(list->current == list->node_last){
    return ListAppend(list, item);
  }
  
  nodeFree = &allNodes[0];
  /*if there is no node available anymore*/
  if(currentNode_Available == 0){
    increasingNPRea();
  }
  
  
  /* GET A NODE FROM NODEFREE */

  addOne  = nodeFree->next_node;
  /*NODE *addOne = (NODE *)&allNodes[0].next_node;*/
  
  /* pop the node from nodeFree */
  allNodes[0].next_node = addOne -> next_node;
  currentNode_Available --;
  addOne->used = 1;

  /* add addOne */
  addOne->item = item;
  addOne->next_node = list->current->next_node;
  addOne->back_node = list->current;
  
  if(addOne->next_node != NULL) addOne->next_node->back_node = addOne;
  if(addOne->back_node != NULL) addOne->back_node->next_node = addOne;
  
  list->current = addOne;
  list->count ++;
  
  return 0;
}

/*
 ListInsert(list, item)
 adds item to list directly before the current item, and makes the new
 items
 the current one. If the current pointer is at the start of the list, the
 item is added at the start.  Returns 0 on success, -1 on failure.
 */
int ListInsert(struct List *list, void *item){
  /*determine whether the argument is invalid*/
  if(list == NULL || item == NULL || list->current == NULL
    || list->next_list != NULL /*the list is still in the pool*/ ){
    return -1;
  }
  
  /*if current == first, then the situation = listAppend*/
  if(list->current == list->node_first){
    return ListPrepend(list,item);
  }
  
  nodeFree = &allNodes[0];
  
  /*if there is no node available anymore*/
  if(currentNode_Available == 0){
    increasingNPRea();
  }
  
  
  /* GET A NODE FROM NODEFREE */
  /*NODE *addOne = (NODE *)&allNodes[0].next_node;*/
  addOne = nodeFree->next_node;
  
  /* pop the node from nodeFree */
  allNodes[0].next_node = addOne -> next_node;
  currentNode_Available --;
  addOne->used = 1;
  
  /* add addOne */
  addOne->item = item;
  addOne->back_node = list->current->back_node;
  addOne->next_node = list->current;
  
  if(addOne->next_node != NULL) addOne->next_node->back_node = addOne;
  if(addOne->back_node != NULL) addOne->back_node->next_node = addOne;
  
  list->current = addOne;
  list->count ++;
  
  
  
  return 0;
}

/*
 ListAppend(list, item)
 adds item to the end of list, and makes the new item the current one.
 Returns 0 on success, -1 on failure.
 */
int ListAppend(struct List *list, void *item){
  /*determine whether the argument is invalid*/
  if(list == NULL || item == NULL ){
    return -1;
  }
  
  /* GET A NODE FROM NODEFREE */
  nodeFree = &allNodes[0];
  
  /*if there is no node available anymore*/
  if(currentNode_Available == 0){
    increasingNPRea();
  }
  
  /*NODE *addOne = (NODE *)&allNodes[0].next_node;*/
  addOne = allNodes[0].next_node;

  /*
  if(allNodes[0].next_node == NULL){
    printf("cnm x 2\n");
  }
  if(addOne == NULL){
    printf("cnm\n");
  }*/
  
  /* pop the node from nodeFree */
  allNodes[0].next_node = addOne -> next_node;
  currentNode_Available --;
  addOne->used = 1;
  
  
  /* add addOne */
  addOne->item = item;
  addOne->next_node = NULL;
  addOne->back_node = list->node_last;
  
  
  if(list->count == 0){
    list->node_first = addOne;
  }else{
    list->node_last->next_node = addOne;
  }
  
  
  list->node_last = addOne;
  list->current = addOne;
  list->count ++;
  
  return 0;
  
}


/*
 ListPrepend(list, item)
 adds item to the front of list, and makes the new item the current one.
 Returns 0 on success, -1 on failure.
 */
int ListPrepend(struct List *list, void *item){
  NODE *addOne;
  /*determine whether the argument is invalid*/
  if(list == NULL || item == NULL
    || list->next_list != NULL /*the list is still in the pool*/){
    return -1;
  }


  nodeFree = &allNodes[0];
  /*if there is no node available anymore*/
  if(currentNode_Available == 0){
    increasingNPRea();
  }
  
  
  /* GET A NODE FROM NODEFREE */
  addOne = nodeFree->next_node;
  /*NODE *addOne = (NODE *)&allNodes[0].next_node;*/
  
  /* pop the node from nodeFree */
  allNodes[0].next_node = addOne -> next_node;
  currentNode_Available --;
  addOne->used = 1;
  
  
  
  /* add addOne */
  addOne->item = item;
  addOne->next_node = list->node_first;
  addOne->back_node = NULL;
  
  
  
  if(list->count == 0){
    list->node_last = addOne;
  }else{
    list->node_first->back_node = addOne;
  }
  
  
  list->node_first = addOne;
  list->current = addOne;
  list->count ++;
  return 0;
  
}


/*
 ListConcat(list1, list2)
 adds list2 to the end of list1.
 The current pointer is set to the current pointer of list1. List2 no
 longer exists after the operation.
 */
void ListConcat(struct List *list1,struct List *list2){
  /*determine whether the argument is invalid
   if list1 is null, we won't do anything for it
   if list2 is null, we don't need to do anything.
   therefore,
   for these two situations, we directly return. */
  if(list1 == NULL || list2 == NULL 
    || list1->next_list != NULL || list2->next_list != NULL /*the list is still in the pool*/){
    return;
  }
  /* link list1 and list2 */
  if (list2->count != 0) {
    if(list1->count != 0){
      list1->node_last->next_node = list2->node_first;
      list2->node_first->back_node = list1->node_last;
    }else{
      list1->node_first = list2->node_first;
    }
    
    /*set list1's last = list2's last*/
    list1->node_last = list2->node_last;
    list1->count += list2->count;
  }
  
  /*set list2 unused and push it to the list pool*/
  list2->count = 0;
  list2->node_first = NULL;
  list2->node_last = NULL;
  list2->current = NULL;
  list2->next_list = allLists[0].next_list;
  allLists[0].next_list = list2;
  currentList --;
  
  return;
  
}


