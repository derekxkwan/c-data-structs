#include<stdio.h>
#include<stdlib.h>
#include "slist.h"

int main(){
	
	Slist * myslist = SLnew();
	SLaddFirst(myslist, 3);
	SLaddLast(myslist, 5);
	SLaddAfterIdx(myslist, 10, 0);
	printf("adding 3 to head, 5 to tail, 10 after 3: ");
	SLdumpList(myslist);
	SLreverse(myslist);
	printf("reversing list: ");
	SLdumpList(myslist);
	printf("deleting idx 1: ");
	SLdeleteIdx(myslist, 1);
	SLdumpList(myslist);
	printf("printing idx 1: ");
	SLprintIdx(myslist, 1);
	printf("printing head: %d\n", myslist->head->data);
	SLdeleteList(myslist);
	printf("freeing list\n");
	return 0;
}
