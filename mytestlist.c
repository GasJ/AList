#include <stdio.h>
#include <assert.h>
#include "list.h"


void parameterTest();
void adderTest();
void moverTest();
void removerTest();
void BonusTest();
void otherBonusFunc();

int cmp(int* a, int* b);/*campare function*/
void freeItem(void* item);/*for list free*/

int main(int argc, char *argv[]){

/*we have six parts of test for partC.*/
/*
WE TEST THE ABILITY OF THE LIST FUNCTIONS TO DETERMINE INVALID PARAMETER.
*/
parameterTest();
clear();
/*parameterTest passed.*/

/*
WE TEST ALL ADDERS FUNCTION HERE BUT *WITHOUT* MEMORY BONUS PART, WHICH WILL BE TESTED INDIVIDUALLY LATER.
*/
adderTest();
clear();
/*adderTest passed*/

/*WE TEST ALL MOVERS FUNCTION HERE.*/
moverTest();
clear();
printf("start next one\n");
/*moverTest passed*/

/*
WE TEST ALL REMOVERS FUNCTION HERE BUT *WITHOUT* MEMORY BONUS PART, 
WHICH WILL BE TESTED INDIVIDUALLY LATER.*/
removerTest();
clear();
/*removerTest passed*/

/*
WE TEST MEMORY BONUS PART HERE, FOR MEMORY INCREASE, SHRINK.
at this step, we believe that basic functions can be used now.
ONLY TEST THE ABILITY TO INCREASE AND SHRINK MEMORY
*/
BonusTest();
clear();
/*BonusTest passed*/

/*
WE TEST OTHER FUNCTIONS WE THINK WE COULD ADDIN HERE.
ACTURALLY, WE MAY USE THESE FUNCTIONS, SO WE TESTED BEFORE.
*/
otherBonusFunc();
/*otherFunc passed.*/


printf("all tests finish.\n");
  return 0;
}



/*WE TEST THE ABALITY OF THE LIST FUNCTIONS TO DETEMINE INVALIDE PARAMETER*/
void parameterTest(){
  List* testNull = NULL;
  /*for ListSearch()*/
  void *com = NULL;
  void *comArg = NULL;
 /*THIS PART IS FOR LIST_ADDERS*/
  void *NullItem = NULL;
  
  printf("parameterTest\nWE WILL TEST THE ABILITY OF THE LIST FUNCTIONS TO DETERMINE INVALID PARAMETER.\n"
"we will use assert and if nothing's up, the test past.\n");
  /*THIS PART IS FOR LIST_MOVERS*/
  printf("only test those functions need argument(s)\n");
  
  printf("testing ListCount argument determine\n");
  assert(ListCount(testNull) == -1);
  printf("testing ListCount argument determine pasted\n");
  
  
  
  printf("testing ListFirst argument determine\n");
  assert(ListFirst(testNull) == NULL);
  printf("testing ListFirst argument determine pasted\n");
  
  
  
  printf("testing ListLast argument determine\n");
  assert(ListLast(testNull) == NULL);
  printf("testing ListLast argument determine pasted\n");
  
  printf("testing ListNext argument determine\n");
  assert(ListNext(testNull) == NULL);
  printf("testing ListNext argument determine pasted\n");
  
  printf("testing ListPrev argument determine\n");
  assert(ListPrev(testNull) == NULL);
  printf("testing ListPrev argument determine pasted\n");
  
  printf("testing ListCurr argument determine\n");
  assert(ListCurr(testNull) == NULL);
   printf("testing ListCurr argument determine pasted\n");
  
  printf("testing ListSearch argument determine\n");
  assert(ListSearch(testNull, com, comArg) == NULL);
  printf("testing ListSearch argument determine pasted\n");
  
 /*THIS PART IS FOR LIST_ADDERS*/ 
  printf("testing ListAdd argument determine\n");
  assert(ListAdd(testNull, NullItem) == -1);
  printf("testing ListAdd argument determine pasted\n");
  

  printf("testing ListInsert argument determine\n");
  assert(ListInsert(testNull, NullItem) == -1);
  printf("testing ListInsert argument determine pasted\n");
  
  printf("testing ListAppend argument determine\n");
  assert(ListAppend(testNull, NullItem) == -1);
  printf("testing ListAppend argument determine pasted\n");
  
  

  printf("testing ListPrepend argument determine\n");
  assert(ListPrepend(testNull, NullItem) == -1);
  printf("testing ListPrepend argument determine pasted\n");

  
 
  /*THIS PART IS FOR LIST_REMOVERS*/
  printf("testing ListRemove argument determine\n");
  assert(ListRemove(testNull) == NULL);
  printf("testing ListRemove argument determine pasted\n");

  printf("testing ListConcat argument determine\n");
  ListConcat(testNull,testNull);
  printf("testing ListConcat return nothing, it will run anyway, pased\n");
  
  printf("testing ListFree argument determine\n");
  ListFree(testNull, NullItem);
  printf("testing ListFree return nothing, it will run anyway, pased \n");
  
  printf("testing ListTrim argument determine\n");
  assert(ListTrim(testNull) == NULL);
  printf("testing ListTrim argument determine pasted\n");

  printf("parameterTest passed\n");

}


/* A function to test adders
WE TEST ALL ADDERS FUNCTION HERE BUT *WITHOUT* MEMORY BONUS PART
, WHICH WILL BE TESTED INDIVIDUALLY LATER. */
void adderTest(){
  /*A. test ListCreate()
create testList, and testList2.
- they should not be null.
- they should not be same.
- their fields should be null or 0.
test passed.*/
  printf("ListCreate() test\n");
  List* testList = ListCreate();
  List* testList2 = ListCreate();
  void *NullItem = NULL;
  void *item;
  int rialable = 0;
  void *ri = &rialable;
  int loopCounter;


  /*for list1*/
  int a = 1;
  int b = 2;
  int c = 3;
  int d = 4;
  int e = 5;
  int f = 6;
  int g = 7;
  /*for list2*/
  int x = 20;
  int y = 30;
  int z = 50;
  int i = 88;

  assert(testList != NULL);
  assert(testList2 != NULL);
  assert(ListLast(testList) == NULL);
  assert(ListCurr(testList) == NULL);
  assert(ListFirst(testList) == NULL);
  assert(ListNext(testList) == NULL);
  assert(ListCount(testList) == 0);
  assert(ListLast(testList2) == NULL);
  assert(ListCurr(testList2) == NULL);
  assert(ListFirst(testList2) == NULL);
  assert(ListNext(testList2) == NULL);
  assert(ListCount(testList2) == 0);
  printf("ListCreate() test passed\n");

  printf("ListCreate() test\n");

/*B. test ListAdd()  ListInsert()  ListAppend() ListPrepend()
ListConcat()
Add, concat, and Insert cannot use when the current is null.
we first test whether they can have right feedback(-1).
*/
printf("due to the last test cannot test the situation, list != null && item == null, "
"also, when current == null && item != null && list != null.\n"
"we will test it here.\n"
"test start: (we will use assert and if nothing's up, the test passes.) \n");
assert(ListAdd(testList, NullItem) == -1);
assert(ListAdd(testList, NullItem) == -1);
assert(ListAdd(testList, NullItem) == -1);
assert(ListAdd(testList, NullItem) == -1);
assert(ListAdd(testList, ri) == -1);
assert(ListInsert(testList, ri) == -1);
printf("test passed.\n");

/*and then use different int and different function to correctly adding nodes into the testList. we said, n nodes.
- count should be right(n)
- the order should be right(by print the list)*/
printf("we are testing add, append, insert, prepend randomly.\nafter each adding, the list will be printed: \n");
printf("there are still some assert test to ensure the count field correct");
item = &a;
ListAppend(testList, item);
printf("after append, the list1 should be 1: \n");
printList(testList);
assert(ListCount(testList) == 1);



item = &b;
ListAdd(testList, item);
printf("after adding, the list1 should be 1 2: \n");
printList(testList);
assert(ListCount(testList)== 2);

item = &c;
ListInsert(testList, item);
printf("after inserting, the list1 should be 1 3 2: \n");
printList(testList);
assert(ListCount(testList) == 3);

item = &d;
ListPrepend(testList, item);
printf("after preppend, the list1 should be 4 1 3 2: \n");
printList(testList);
assert(ListCount(testList) == 4);

item = &e;
ListAdd(testList, item);
printf("after adding, the list1 should be 4 5 1 3 2: \n");
printList(testList);
assert(ListCount(testList) == 5);

item = &f;
ListAdd(testList, item);
printf("after adding, the list1 should be 4 5 6 1 3 2: \n");
printList(testList);
assert(ListCount(testList) == 6);

item = &g;
ListAdd(testList, item);
printf("after adding, the list1 should be 4 5 6 7 1 3 2: \n");
printList(testList);
assert(ListCount(testList) == 7);

/*
add repeat items by a loop to another list with (MIN_NODE-n) nodes.
- should not crash
- the order should be right(by print the list)
*/


item = &x;
ListAppend(testList2, item);

item = &y;
ListAdd(testList2, item);

item = &z;
ListAdd(testList2, item);

printf("\nafter adding, the list2 should be 20 30 50: \n");
printList(testList2);

item = &i;
for(loopCounter=0; loopCounter < 20; loopCounter++){
  ListAppend(testList2, item);
}
printf("\nafter adding with a loop,\n"
    "the list2 should be 20 30 50 88 88 88 88 88 88 88 88 88 88 88 88 88 88 88 88 88 88 88 88: \n");
printList(testList2);

/*
concat them
- count should be right
- should not crash
- the order should be right(by print the list)
*/
printf("tesing concat");
printf("there are still some assert test to ensure the count field correct");
ListConcat(testList,testList2);
printf("\nafter concat," 
"the list1 should be 4 5 6 7 1 3 2 20 30 50 88 88 88 88 88 88 88 88 88 88 88 88 88 88 88 88 88 88 88 88: \n");
printList(testList);
assert(ListCount(testList) == 30);
printf("if we can print it correctly, it proved that the part of fields after adding does not have problems.");
printf("adders tests all passed");
}

/* A function to test movers.
WE TEST ALL MOVERS FUNCTION HERE. */
void moverTest(){
  /*
at this step, we proved adders can be used correctly.
we just create a list, test a empty list.
  */
  List* testList = ListCreate();
  int (* compare) ();
  int a = 1;
  int b = 2;
  int c = 3;
  int d = 4;
  int e = 5;
  int f = 6;
  int g = 7;

  int x = 20;
  int y = 30;
  int z = 50;
  int i = 88;
  int* reliable;
  void* item;
  void* result;

  printf("due to the first test cannot test the situation, list != null && comarg == null || com == null, "
  "we will test it here.\n"
  "test start: (we will use assert and if nothing's up, the test passes.) \n");

  assert(ListFirst(testList) == NULL);
  assert(ListNext(testList) == NULL);
  assert(ListCurr(testList) == NULL);
  assert(ListCount(testList) == 0);
  assert(ListSearch(testList, *compare, reliable) == NULL);
  assert(ListPrev(testList) == NULL);

  /*
  then add some pointer.
determine whether it can return right value.
  */

  item = &a;
  ListAppend(testList, item);
  
  item = &b;
  ListAppend(testList, item);
  
  item = &c;
  ListAppend(testList, item);
  
  item = &d;
  ListAppend(testList, item);
  
  item = &e;
  ListAppend(testList, item);
  
  item = &f;
  ListAppend(testList, item);
  
  item = &g;
  ListAppend(testList, item);

  printList(testList);
  printf("current item should be %d\n"
  "first item should be %d\nlast item should be %d\npre item should be %d\n", g, a, g, f);
  printf("current item is: %d\n",  * (int *)testList->current->item);
  printf(
  "first item is: %d\n"
  "last item is: %d\n"
  "pre item is: %d\n", 
  * (int *) ListFirst(testList),
  * (int *) ListLast(testList),
  * (int *) ListPrev(testList) );

  /*
  for search function we will search
- list is empty #DONE
- a null item #DONE
- a non-null item in the list
- an item not in the list
- first item
- last item
- current item
  */

  printf("now, we are going to test search function in mover.\n"
"we will choose a non-special item in the list to test now.\n"
"we say 5\n");

result = ListSearch(testList, cmp, &e);
if(result == NULL){
  printf("########failed.###########\nreturn value is null, but should be 5\n");
}else{
  printf("return value is %d.\n", *(int *) result);
}
assert(*(int *) result == 5);
printf("passes ");

  /*
  for search function we will search
- list is empty #DONE
- a null item #DONE
- a non-null item in the list #DONE
- an item not in the list
- first item
- last item
- current item
  */

printf("an item not in the list test\n");
result = ListSearch(testList, cmp, &x);
if(result == NULL){
  printf("return null, pass.\n");
}else{
  printf("########failed.###########\nreturn value is %d, but should be null\n", *(int *) result);
}


  /*
  for search function we will search
- list is empty #DONE
- a null item #DONE
- a non-null item in the list #DONE
- an item not in the list #DNOE
- first item
- last item
- current item
  */
  printf("we will choose a special item in the list to test now.\n"
  "we say 1, as the first item\n");
  item = &a;
  result = ListSearch(testList, cmp, item);
  if(result == NULL){
    printf("########failed.###########\nreturn value is null, but should be 1\n");
  }else{
    printf("return value is %d.\n", *(int *) result);
  }
  assert(*(int *) result == 1);
  printf("passes\n");


  /*
  for search function we will search
- list is empty #DONE
- a null item #DONE
- a non-null item in the list #DONE
- an item not in the list #DNOE
- first item #DONE
- last item 
- current item
  */
  printf("we will choose a special item in the list to test now.\n"
  "we say 7, as the last item\n");
  item = &g;
  result = ListSearch(testList, cmp, item);
  if(result == NULL){
    printf("########failed.###########\nreturn value is null, but should be 7\n");
  }else{
    printf("return value is %d.\n", *(int *) result);
  }
  assert(*(int *) result == 7);
  printf("passes\n");

    /*
  for search function we will search
- list is empty #DONE
- a null item #DONE
- a non-null item in the list #DONE
- an item not in the list #DNOE
- first item #DONE
- last item #DONE
- current item
  */
  ListPrev(testList);
  printf("we will choose a special item in the list to test now.\n"
  "we say %d, as the current item\n", *(int *)ListCurr(testList));
  item = ListCurr(testList);
  result = ListSearch(testList, cmp, item);
  if(result == NULL){
    printf("########failed.###########\nreturn value is null, but should be %d\n", *(int *) ListCurr(testList));
  }else{
    printf("return value is %d.\n", *(int *) result);
  }
  assert(result == ListCurr(testList));
  printf("passes\n");

      /*
  for search function we will search
- list is empty #DONE
- a null item #DONE
- a non-null item in the list #DONE
- an item not in the list #DNOE
- first item #DONE
- last item #DONE
- current item #DONE
  */

  printf("mover tests passed.\n");

}


/* A function to test removers.
WE TEST ALL REMOVERS FUNCTION HERE BUT *WITHOUT* MEMORY BONUS PART, 
WHICH WILL BE TESTED INDIVIDUALLY LATER. */
void removerTest(){
  /*
we just create a list,
then add some pointer.
delete them all.
add some pointer.
delete some of them.
  */
  List* testList = ListCreate();
  int a = 1;
  int b = 2;
  int c = 3;
  int d = 4;
  int e = 5;
  int f = 6;
  int g = 7;
  void* item;
  void* remove;
  /*
  then add some pointer.
determine whether it can return right value.
  */

  item = &a;
  ListAppend(testList, item);

  printList(testList);
  printf("now we are testing coner of situation, where list's count == 1\n");
  remove = ListRemove(testList);
  printf("removed item shoud be %d\n"
"and it is: %d\n", a, *(int *)remove);

  
  item = &b;
  ListAppend(testList, item);
  
  item = &c;
  ListAppend(testList, item);
  
  item = &d;
  ListAppend(testList, item);

  printf("now we are testing the situation, where list has several nodes in it\n");
  remove = ListRemove(testList);
  printf("removed item shoud be %d\n"
  "and it is: %d\n", d, *(int *)remove);
  remove = ListTrim(testList);
  printf("removed item shoud be %d\n"
  "and it is: %d\n", c, *(int *)remove); 


  item = &e;
  ListAppend(testList, item);
  
  item = &f;
  ListAppend(testList, item);
  
  item = &g;
  ListAppend(testList, item);

  printf("now the list should be: 2 5 6 7\n");
  printList(testList);

  printf("calling listFree, the list constent should be nothing\n");
  ListFree(testList, freeItem);
  printf("remover tests passes.\n");


}


/* A function to test bonus part (increasing and decreasing memory. 
  WE TEST MEMORY BONUS PART HERE, FOR MEMORY INCREASE, SHRINK. */
void BonusTest(){
  /*
  at this step, we believe that basic functions can be used now.
  ONLY TEST THE ABILITY TO INCREASE AND SHRINK MEMORY
  */
  List* testlist;
  List* testlist2;
  List* testlist3;
  List* testlist4;
  List* testlist5;
  List* testlist6;
  List* testlist7;
  List* testlist8;
  List* testlist9;
  List* testlist10;
  List* testlist11;
  List* testlist12;

  int a = 1;
  int b = 2;
  int c = 3;
  int d = 4;
  int e = 53;
  int f = 69;
  int g = 73;
  int k = 88;

  int x = 88;
  int y = 99;
  int z = 57;

  int counter;
  /*
- INCREASING
NODE POOL PART
###
one list
add an integer (to prove the memory does not lost later)
add a lot of integer with a loop (still smaller than min_node)
add another unique integer
print*/
 testlist = ListCreate();
 ListAppend(testlist, &x);
 
 for(counter=0; counter < 80; counter++){
   ListAppend(testlist, &a);
 }
 printf("now we start to detect the ability of memory increasing for node pool.\n");

 ListAppend(testlist, &y);
 printf("now the list should be: 88 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 99 \n");
 printList(testlist);

 for(counter=0; counter < 80; counter++){
  ListAppend(testlist, &b);
 } 

 
 printf("now the list should be: 88 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 99 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2\n");
 printList(testlist);


/*
add a little more nodes to make node pool double first time
print
add twice double
print
  */

 ListAppend(testlist, &z);
  for(counter=0; counter < 400; counter++){
   ListAppend(testlist, &c);
  } 
  printf("now the list should be: 88 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 99 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 57 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3\n");
  printList(testlist);

  assert(ListCount(testlist) == 563);
  printf("node pool memory increasing test with 1 list passed.\n");

  ListFree(testlist, freeItem);

/*
###
two list
list1 - add 20 nodes with several unique items
list2 - add 20 nodes with several unique items
print both, they should both be right
*/
testlist = ListCreate();
testlist2 = ListCreate();
ListAppend(testlist, &x);
ListAppend(testlist2, &y);

for(counter=0; counter < 19; counter++){
  ListAppend(testlist, &a);
}
for(counter=0; counter < 19; counter++){
  ListAppend(testlist2, &b);
}
printf("the testlist should be: 88 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1\n");
printList(testlist);
printf("the testlist2 should be: 99 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2\n");
printList(testlist2);

/*
list1 - add (min_node) nodes 
print both, they should both be right
list2 - add (2 * total_nodes) nodes 
print both, they should both be right
*/
ListAppend(testlist, &g);
for(counter=0; counter < 100; counter++){
  ListAppend(testlist, &a);
}

printf("the testlist should be: 88 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 73 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 \n");
printList(testlist);
printf("the testlist2 should be: 99 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2\n");
printList(testlist2);

for(counter=0; counter < 200; counter++){
  ListAppend(testlist2, &b);
}
printf("the testlist should be: 88 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 73 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 \n");
printList(testlist);
printf("the testlist2 should be: 99 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 \n");
printList(testlist2);

printf("node pool memory increasing test with 2 lists passed.\n"
"node pool memory increasing test passed.\n");

/*
### LIST POOL PART
create other 10 lists
add several nodes in them
print
print both, they should both be right
*/
printf("list pool memory increasing test starts.\n");

testlist3  = ListCreate();
testlist4  = ListCreate();
testlist5  = ListCreate();
testlist6  = ListCreate();
testlist7  = ListCreate();
testlist8  = ListCreate();
testlist9  = ListCreate();
testlist10  = ListCreate();
testlist11  = ListCreate();
testlist12  = ListCreate();

for(counter=0; counter < 10; counter++){
  ListAppend(testlist3, &c);
}
for(counter=0; counter < 10; counter++){
  ListAppend(testlist4, &d);
}
for(counter=0; counter < 10; counter++){
  ListAppend(testlist5, &e);
}
for(counter=0; counter < 10; counter++){
  ListAppend(testlist6, &f);
}
for(counter=0; counter < 10; counter++){
  ListAppend(testlist7, &g);
}

for(counter=0; counter < 10; counter++){
  ListAppend(testlist8, &a);
}
for(counter=0; counter < 10; counter++){
  int res =ListAppend(testlist9, &k);
}
for(counter=0; counter < 10; counter++){
  ListAppend(testlist10, &y);
}
for(counter=0; counter < 10; counter++){
  ListAppend(testlist11, &z);
}
for(counter=0; counter < 10; counter++){
  ListAppend(testlist12, &a);
}

printf("the testlist should be: 88 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 73 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 \n");
printList(testlist);
printf("the testlist2 should be: 99 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 \n");
printList(testlist2);
printf("the testlist3 should be: 3 3 3 3 3 3 3 3 3 3 \n");
printList(testlist3);
printf("the testlist4 should be: 4 4 4 4 4 4 4 4 4 4\n");
printList(testlist4);
printf("the testlist5 should be: 53 53 53 53 53 53 53 53 53 53\n");
printList(testlist5);
printf("the testlist6 should be: 69 69 69 69 69 69 69 69 69 69\n");
printList(testlist6);
printf("the testlist7 should be: 73 73 73 73 73 73 73 73 73 73\n");
printList(testlist7);
printf("the testlist8 should be: 1 1 1 1 1 1 1 1 1 1 \n");
printList(testlist8);
printf("the testlist9 should be: 88 88 88 88 88 88 88 88 88 88 \n");
printList(testlist9);
printf("the testlist10 should be: 99 99 99 99 99 99 99 99 99 99 \n");
printList(testlist10);
printf("the testlist11 should be: 57 57 57 57 57 57 57 57 57 57 \n");
printList(testlist11);
printf("the testlist12 should be: 1 1 1 1 1 1 1 1 1 1\n");
printList(testlist12);

printf("list pool memory increasing test passes.\n");

/*
- DECREASING$$$$$$$$
*/

/*
### NODE POOL PART
free several lists (will release nodes to node pool)
then the node pool should shrink
test available nodes
test total nodes
print all remain lists
- the print result should be same as the result before deletion.
test passed.
*/
printf("node pool memory decreasing test starts.\n");
printf("total nodes before deleting are: %d\n", totalNode);

ListFree(testlist2, freeItem);
printf("the testlist2 should be: empty \n");
printList(testlist2);
ListFree(testlist, freeItem);
printf("the testlist should be: empty \n");
printList(testlist);

printf("total nodes after deleting should be 100\n");
printf("total nodes after deleting are: %d\n", totalNode);

printf("the testlist3 should be: 3 3 3 3 3 3 3 3 3 3 \n");
printList(testlist3);
printf("the testlist4 should be: 4 4 4 4 4 4 4 4 4 4\n");
printList(testlist4);
printf("the testlist5 should be: 53 53 53 53 53 53 53 53 53 53\n");
printList(testlist5);
printf("the testlist6 should be: 69 69 69 69 69 69 69 69 69 69\n");
printList(testlist6);
printf("the testlist7 should be: 73 73 73 73 73 73 73 73 73 73\n");
printList(testlist7);
printf("the testlist8 should be: 1 1 1 1 1 1 1 1 1 1 \n");
printList(testlist8);
printf("the testlist9 should be: 88 88 88 88 88 88 88 88 88 88 \n");
printList(testlist9);
printf("the testlist10 should be: 99 99 99 99 99 99 99 99 99 99 \n");
printList(testlist10);
printf("the testlist11 should be: 57 57 57 57 57 57 57 57 57 57 \n");
printList(testlist11);
printf("the testlist12 should be: 1 1 1 1 1 1 1 1 1 1\n");
printList(testlist12);

printf("node pool memory decreasing test passes.\n");

/*
### LIST POOL PART
free 3 of the lists.
total_list should be OLD_total_list/2 (10)
print all others 
- the print result should be same as the result before deletion.
*/

ListFree(testlist12,freeItem);
printf("total_list is: %d\n" 
"usedlist is: %d\n",AllList(), UsedList() );
ListFree(testlist11,freeItem);
printf("total_list is: %d\n" 
"usedlist is: %d\n",AllList(), UsedList() );
ListFree(testlist10,freeItem);
printf("total_list is: %d\n" 
"usedlist is: %d\n",AllList(), UsedList() );

printf("total_list should be 10.\n"
"total_list is: %d\n", AllList());

printf("the testlist2 should be: empty \n");
printList(testlist2);
printf("the testlist should be: empty \n");
printList(testlist);

printf("the testlist3 should be: 3 3 3 3 3 3 3 3 3 3 \n");
printList(testlist3);
printf("the testlist4 should be: 4 4 4 4 4 4 4 4 4 4\n");
printList(testlist4);
printf("the testlist5 should be: 53 53 53 53 53 53 53 53 53 53\n");
printList(testlist5);
printf("the testlist6 should be: 69 69 69 69 69 69 69 69 69 69\n");
printList(testlist6);
printf("the testlist7 should be: 73 73 73 73 73 73 73 73 73 73\n");
printList(testlist7);
printf("the testlist8 should be: 1 1 1 1 1 1 1 1 1 1 \n");
printList(testlist8);
printf("the testlist9 should be: 88 88 88 88 88 88 88 88 88 88 \n");
printList(testlist9);

return;


}


/* A function to test other functions part(also bonus).
WE TEST OTHER FUNCTIONS WE THINK WE COULD ADDIN HERE. */
void otherBonusFunc(){

  printf("all other function proved right duing before part.\n"
"other functions part past.\n");

}


int cmp(int* a, int* b){
  return (a == b);
}

void freeItem(void* item){
  item = NULL; 
}
