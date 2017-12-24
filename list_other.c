#include <stdio.h>
#include "list.h"

NODE  *ndFree;
int currentList = 0;  /* record how many lists in the lists[] */
int currentNode_Available = MIN_NODES; /* recor how many nodes in the nodes pool */
int totalNode = MIN_NODES; /* record total nodes */
int totalList = MIN_LISTS; /* record total lists */

/* A function to help print. */
void printList(List *list){
    int i;
    NODE *current = list->node_first;
    printf("The list constent is: ");
    for(i=0; i < list->count ; i++){
      printf("%d ", * (int *)current->item);
      current = current->next_node;
    }
    printf("\n");

    return;
}

void increasingNPAdd(){
    int w;
    NODE *expandNodesPool;
    nodeFree = &allNodes[0];
/* malloc a node pool, whose size = old pool's size */
    currentNode_Available = totalNode;
    expandNodesPool = malloc(sizeof(NODE) * (totalNode));
    /* double the total size count*/            
    totalNode *= 2;
    /* link the nodes pool */            
    nodeFree->next_node = &expandNodesPool[0];
                 
    for (w=0; w < currentNode_Available; w++) {
        expandNodesPool[w].next_node = &expandNodesPool[w + 1];    
    }
}

void createNP(){
    int i;
    allNodes =  malloc(sizeof(NODE) * (MIN_NODES));
/* nodeFree, is the linker node for the whole node pool, therefore it links to  allNodes[0] */
    nodeFree = &allNodes[0];
/*link the nodeFree to the first available node
(all nodes recently malloc are available because they are not used yet)*/
    nodeFree->next_node = &allNodes[1];
/*link all nodes in the pool*/
    for ( i = 1; i < MIN_NODES - 1; i++) {
        allNodes[i].next_node = &allNodes[i + 1];
    }
       
    currentNode_Available = MIN_NODES-1;
    totalNode = MIN_NODES;
    /*printf("out.\n");*/
    
    return;
         
}

int increasingNPRea(){
    int w;
    NODE *expandNodesPool;
    currentNode_Available = totalNode;
    totalNode *= 2;
    expandNodesPool = allNodes;
    allNodes = realloc(expandNodesPool, sizeof(NODE) * (totalNode));


    ndFree = &allNodes[0];

    /*relink the nodepool*/
   allNodes[0].next_node = &allNodes[currentNode_Available];
    for (w=currentNode_Available; w < totalNode; w++) {
        allNodes[w].next_node = &allNodes[w+1];
    }

    
    if(allNodes == NULL) return -1;
    return 0;
}

void decreaseingLPRea(){
    int i;
    List* shrinkNP;
    int frees[100000];
    int counter = 0;
    for(i=1; i < totalList/2; i++){
        if(allLists[i].used == 1){
            frees[counter] = i;
        }
    }


    if(counter != 0){
        while(i < totalList){
            if(allLists[i].used != 0){
                allLists[frees[counter]] = allLists[i];
                counter--;
            }
            i++;
        }
    }


    shrinkNP = allLists;
    totalList /= 2;
    allLists = realloc(shrinkNP, sizeof(List)*(totalList));
    

    return;


}

void decreaseingNPRea(){
    int i;
    NODE* shrinkNP;
    int frees[100000];
    int counter = 0;;
    for(i=1; i < totalNode/2; i++){
        if(allNodes[i].item == NULL){
            /*if(countFree == NULL){
                countFree->next_node = &allNodes[i];
            }
            else{
                allNodes[i].next_node = countFree->next_node;
                printf("here1.\n");
                countFree->next_node = &allNodes[i];
            }*/

            frees[counter] = i;
        }
    }
    /*
    if(countFree != NULL){
        while(i < totalNode){
            if(allNodes[i].item != NULL){
                tmp = countFree;
                countFree = countFree->next_node;

                copy it to a free index
                *tmp = allNodes[i];
            }
            i++;
        }
    }*/

    if(counter != 0){
        while(i < totalNode){
            if(allNodes[i].item != NULL){
                allNodes[frees[counter]] = allNodes[i];
                counter--;
            }
            i++;
        }
    }


    /*printf("here.\n");*/

    shrinkNP = allNodes;
    allNodes = realloc(shrinkNP, sizeof(NODE)*(totalNode/2));
    currentNode_Available = 0;
    totalNode/=2;

    return;
}

NODE* getNode(){
    NODE* getOne;
    nodeFree = &allNodes[0];
  
    
  
    getOne = nodeFree->next_node;
    allNodes[0].next_node = getOne -> next_node;
    currentNode_Available --;
  
    return getOne;
  }



void clear(){
  NODE* clearNode;
/*clear everything(list pool + node pool)*/
/*    if(allLists != NULL)
    allLists = NULL;
    if(allNodes != NULL)
    allNodes = NULL;*/

    /*List* clearList = allLists;
    free(clearList);*/
    allLists = NULL;
    clearNode = allNodes;
    free(clearNode);
}

int AllList(){
    /* return how many lists are created */
    return totalList;
} 

int AllNode(){
  /* return how many lists are created */
  return totalNode;
}

int UsedNode(){
  /* return how many nodes in the node pool */
  return totalNode - 1 - currentNode_Available;
}
  
int UsedList(){
  /* return how many lists used */
  return currentList;
}
