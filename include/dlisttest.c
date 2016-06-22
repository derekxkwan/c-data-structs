#include<stdio.h>
#include<stdlib.h>
#include "dlist.h"

int main(){
	
	Dlist * mydlist = DLnew();
	DLaddFirst(mydlist, 9);
	DLaddLast(mydlist, 2);
	DLaddAfterIdx(mydlist, 10, 0);
	DLaddBeforeIdx(mydlist, 3, 0);
	DLaddAfterIdx(mydlist, 7, 3);
	printf("adding 9 to head, 2 to tail, 10 after 9, 3 before 9, 7 after 2: ");
	DLdumpList(mydlist);
	printf("head: %d, tail: %d\n", mydlist->head->data, mydlist->tail->data);
	DLreverse(mydlist);
	printf("reversing list: ");
	DLdumpList(mydlist);
	printf("deleting idx 1: ");
	DLdeleteIdx(mydlist, 1);
	DLdumpList(mydlist);
	printf("printing idx 1: ");
	DLprintIdx(mydlist, 1);
	printf("head: %d, tail: %d\n", mydlist->head->data, mydlist->tail->data);
	DLdeleteList(mydlist);
	printf("freeing list\n");
	return 0;
}
