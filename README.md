#this is a List Library based on C language.

Lists are composed of elements called nodes (NODE data type). Each node is able to hold one item. An item is any C data type that can be pointed to - so the node structure should have a (void *) field in it to reference the item held by that node. For the purposes of this assignment, though, your code should allow a user to create several lists WHERE EACH LIST HAS A HOMOGENOUS DATA TYPE.

The implementation of the library shall have dynamic memory allocation on a per-list or per-node basis for the size of the list pool and the node pool can be change automatically. These are separate data types and test code knows only about LISTs and items. It knows nothing about NODEs. Also note that there is no ListInit() function, it will have to find some way to know when the first execution happens. Define a maximum number of LISTs and a maximum number of NODEs and implement the library such that any LIST may have between 0 and the maximum number of nodes at different points in time, but no more than the maximum number of nodes may be in use at any one point in time. Think of the array of NODEs as a pool that may be shared between the lists. Over time, there can also be a different number of LISTs actively being used.
Trying to avoid traversing or searching the list whenever possible. It is possible to avoid traversing/searching in every function, except of course, ListSearch() (and ListFree()).
Memory Allocation Principles. In this version of List library, I'm trying to  implement the list memory structure so that there are a variable number of list nodes and list headers. This does not mean that I will allocate them on-demand. I have compile-time constants MIN_LISTS and MIN_NODES, which specify the minimum amount of memory (array size) to allocate for each of these data structures in ONE malloc for each data structure. If obtaining a new node or a new list fails, double the amount of memory allocated for whichever resource has filled up (see the man page for realloc()). If it determines that less than half the allocated memory is being used for lists or nodes, it just divides the amount of memory by 2 and copy the used nodes or lists into the new space. Of course, it never goes below MIN_LISTS or MIN_NODES. This is the way Java implements arrays and vectors, and the way current versions of the LINUX kernel handle the task_struct array - but trying to implement it in C.

