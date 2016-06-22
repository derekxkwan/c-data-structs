#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

int main(){
	float arr[10] = {3.4, 345.0, 29.5, 1.0, 23.4, 23.6, 8234.9, 2.5, 9.3, 22.5};
	Heap * heap = HeapHeapify(arr, 10, 1, 95);
	printf("heapifying [3.4, 345.0, 29.5, 1.0, 23.4, 23.6, 8234.9, 2.5, 9.3, 22.5]\n");
	float max = HeapPeek(heap);
	printf("max: %f\n", max);
	HeapPush(heap, 39999.9);
	max = HeapPop(heap);
	printf("Popped max with 39999.9 pushed: %f\n", max);
	max = HeapPop(heap);
	printf("Popped max: %f\n", max);
	printf("current size: %d\n", heap->size);

	float arr2[5] = {99999.0, 34.3, 59234.0, -23.4, -5.0};
	printf("heapifying [99999.0, 34.3, 59234.0, -23.4, -5.0] into new heap\n");
	Heap * heap2 = HeapHeapify(arr2, 5, 0, 100);
	float min = HeapPeek(heap2);
	printf("min of new heap: %f\n", min);
	HeapMerge(heap, heap2);
	max = HeapPeek(heap);
	printf("max of new heaped merged with old heap: %f\n", max);
	HeapDelete(heap);
	HeapDelete(heap2);
	printf("deleting heaps\n");

	return 0;
}
