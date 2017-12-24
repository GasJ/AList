#include <stdio.h>
#include <stdlib.h>

typedef struct NODE NODE;
typedef struct List List;

struct NODE{
  int *item;
  int used;
  NODE *back_node;
  NODE *next_node;
};

struct List{
  NODE *node_first;
  NODE *node_last;
  int used;
  int count;
  NODE *current;
  List *next_list;
};





#define MIN_NODES 100
#define MIN_LISTS 10
extern int currentList;  /* record how many lists used */
extern int currentNode_Available; /* recor how many nodes in the nodes pool */
extern int totalNode; /* record total nodes */
extern int totalList; /* record total lists */

NODE  *allNodes;
List  *allLists;
NODE  *nodeFree;



/*
  ListCreate()
  makes a new, empty list, and returns its reference on success.
  Returns a NULL pointer on failure.
*/
struct List *ListCreate();

/*
  ListCount(list)
  returns the number of items in list.
*/
int ListCount(struct List *list);


/*
  ListFirst(list)
  returns a pointer to the first item in list and makes the first
  item the current item.
*/
void *ListFirst(struct List *list);

/*
  ListLast(list)
  returns a pointer to the last item in list and makes the last
  item the current one.
*/
void *ListLast(struct List *list);

/*
  ListNext(list)
  advances list's current item by one, and returns a pointer to the
  new current item. If this operation attempts to advances the
  current item beyond the end of the list, a NULL pointer is
  returned.
*/
void *ListNext(struct List *list);

/*
  ListPrev(list)
  backs up list's current item by one,
  and returns a pointer to the new current item.
  If this operation attempts to back up the current item
  beyond the start of the list, a NULL pointer is returned.
*/
void *ListPrev(struct List *list);

/*
  ListCurr(list)
  returns a pointer to the current item in list.
*/
void *ListCurr(struct List *list);

/*
  ListAdd(list, item)
  adds the new item to list directly after the current item, and makes item
  the current item. If the current pointer is at the end of the list, the
  item is added at the end. Returns 0 on success, -1 on failure.
*/
int ListAdd(struct List *list, void *item);

/*
  ListInsert(list, item)
  adds item to list directly before the current item, and makes the new
  item
  the current one. If the current pointer is at the start of the list, the
  item is added at the start.  Returns 0 on success, -1 on failure.
*/
int ListInsert(struct List *list, void *item);

/*
  ListAppend(list, item)
  adds item to the end of list, and makes the new item the current one.
  Returns 0 on success, -1 on failure.
*/
int ListAppend(struct List *list, void * item);

/*
  ListPrepend(list, item)
  adds item to the front of list, and makes the new item the current one.
  Returns 0 on success, -1 on failure.
*/
int ListPrepend(struct List *list,void * item);

/*
  ListRemove(list)
  Return current item and take it out of list. Make the next item the
 current one.
*/
void *ListRemove(struct List *list);

/*
  ListConcat(list1, list2)
  adds list2 to the end of list1.
  The current pointer is set to the current pointer of list1. List2 no
  longer exists after the operation.
*/
void ListConcat(struct List *list1, struct List *list2);

/*
  ListFree(list, itemFree)
  delete list.
  itemFree is a pointer to a routine that frees an item.
  It should be invoked (within ListFree) as:
  (*itemFree)(itemToBeFreed);
*/
void ListFree(struct List *list, void (*itemFree)());


/*
  ListTrim(list);
  Return last item and take it out of list.
  The current pointer shall be the new last item in the list.
*/
void *ListTrim(struct List *list);


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
void *ListSearch(struct List *list, int (*comparator)(), void *comparisonArg);


/*################
other functions for bonus
################*/

/*print the list*/
void printList(List *list);

void clear();/*clear everything(list pool + node pool)*/

int AllList(); /* return how many lists are created */
int AllNode();/* return how many nodes in the node pool */
int UsedNode();/* return how many nodes used */
int UsedList();/* return how many lists used */

int increasingNPRea(); 
void decreaseingNPRea();
void decreaseingLPRea();


NODE* getNode();

void createNP();





