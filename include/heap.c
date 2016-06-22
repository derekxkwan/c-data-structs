#include "heap.h"

Heap * HeapNew(int type, int maxsize){
	Heap * newHeap = malloc(sizeof(Heap));
	newHeap->type = type > 0 ? 1 : 0;
	//let's 1-index and skip the first idx of the array so need 1 extra idx
	//ie a 1 elt heap needs 2 slots so allocate one more than maxsize
	newHeap->maxsize = maxsize < 1 ? 1 : maxsize;
	newHeap->data = malloc(sizeof(float)*(newHeap->maxsize+1));
	newHeap->size = 0;
	return newHeap;
}

int HeapInv(Heap * heap, const int idx1, const int idx2){
	//return 1 if passes invariant, 0 if fails invariant
	//pass child idx as idx1, parent idx as idx2
	int retVal;
	//bounds checking
	int heapsize = heap->size;
	float elt1, elt2;
	if(idx1 > heapsize || idx2 > heapsize){
		return 0; //return with a fail state
	}
	else{
		//else get vals at indices
		elt1 = heap->data[idx1];
		elt2 = heap->data[idx2];
	};
	if(heap->type == 0){
		//minheap, children must be larger so return 1 if larger
		if(elt1 > elt2){
			retVal = 1;
		}
		else{
			retVal = 0;
		};
	}
	else{
		//maxheap, children must be smaller so return 1 if smaller
		if(elt1 < elt2){
			retVal = 1;
		}
		else{
			retVal = 0;
		};
	};
	return retVal;
}


void HeapSwapElt(float * elt1, float * elt2){
	float temp = *elt1;
	*elt1 = *elt2;
	*elt2 = temp;
}

void HeapPush(Heap * heap, float elt){
	//new position
	if(heap->maxsize >= (heap->size + 1)){
		int size = heap->size;
		//do this only if there's room to put new elt
		int pos = ++size; //inc then eq since we are 1-indexing
		heap->size = size;

		heap->data[pos] = elt;
		//keep comparing to parent which is floor(pos/2)
		//(since they're ints, that's done auto
		//if child fails inv with parent, swap
		for(;!HeapInv(heap, pos,(pos/2)) && (pos/2) >= 1; pos /= 2){
			HeapSwapElt(&(heap->data[pos]), &(heap->data[(pos/2)]));
		};
	}
	else{
		printf("error! no room left!");
	};
}

Heap * HeapHeapify(float * arr, int arrsize, int type, int maxsize){

	//bounds checking 
	if(arrsize  > maxsize){
		maxsize = arrsize;
	};
	Heap * newHeap = HeapNew(type, maxsize);
	
	int i;
	for(i=0; i<arrsize; i++){
		HeapPush(newHeap, *(arr+i));
	};
	return newHeap;
}

float HeapPeek(Heap * heap){
	if(heap->size > 0){
		return heap->data[1];
	}
	else{
		//maybe there's a better thing to return?
		return 0.0;
	};
}

float HeapPop(Heap * heap){
	float retVal = HeapPeek(heap);

	int size = heap->size;
	if(size > 1){
		//more than 1 elt, make last elt first elt and percolate down
		heap->data[1] = heap->data[heap->size];

		heap->size = --size; //decrement;
		//percolate down
		
		int pos = 1; //current position of percolator down
		while((pos*2)<=heap->size){
			//if there's at least a left child 
			int posrep = pos*2; //position to replace
			if((posrep+1)<=heap->size){
				/*if there's a right child
				need to find child that gives best chance at satisfying inv
				if child1 satisfies inv with child2, child1 could be child of child2 so
				then swap with child2 instead of child1*/
				if(HeapInv(heap, posrep, posrep+1)){
					posrep++;
				};
			};
			//if current pos satisfies inv with child, then it should percolate down, else no use in looking so break
			if(HeapInv(heap, pos, posrep)){
				HeapSwapElt(&(heap->data[pos]),&(heap->data[posrep]));
				pos = posrep; //update current position
			}
			else{
				break;
			};
		};
	}
	else if(size == 1){
		//if size == 1, only one elt, just 0 out and decrement size
		heap->data[1] = 0;
		heap->size = --size;
	};
	//else there's nothing inside, so nothing to do
	return retVal;
}

void HeapMerge(Heap * heap1, Heap * heap2){
	//bounds checking
	if(heap1->maxsize < (heap1->size + heap2->size)){
		printf("error! heap1 too small to merge into!");
		return;
	}
	else{
		int i;
		for(i=1; i<=heap2->size; i++){
			HeapPush(heap1, heap2->data[i]);
		};
	};

};



void HeapDelete(Heap * heap){
	free(heap->data);
	free(heap);
}
