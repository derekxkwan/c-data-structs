#include <stdio.h>
#include <stdlib.h>

#ifndef HEAP_HEADER
#define HEAP_HEADER

typedef struct heapdef{
	int type; //0 = min, 1 = max
	int maxsize; //size of array to store heap (has one extra index for 1-indexing)
	int size; //current size of heap
	float * data; //place to store data
} Heap;

Heap * HeapNew(int type, int maxsize);
Heap * HeapHeapify(float * arr, int arrsize, int type, int maxsize); //take an array of floats and make a new heap
float HeapPeek(Heap * heap); //find max/min
float HeapPop(Heap * heap); //find max/min and remove
void HeapPush(Heap * heap, float elt); //insert a new element
void HeapDelete(Heap * heap); //delete the whole thing
void HeapMerge(Heap * heap1, Heap * heap2); //merge heap2 into heap1, adopting the type of heap1

//UTILITY FUNCTIONS
void HeapSwapElt(float * elt1, float * elt2); //elt swapping utility func
int HeapInv(Heap * heap, const int idx1, const int idx2); //heap comparator based on heap type

#endif
