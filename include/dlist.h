#include <stdio.h>
#include <stdlib.h>

#ifndef DLIST_HEADER
#define DLIST_HEADER

typedef struct dnodedef{
	int data;
	struct dnodedef * next;
	struct dnodedef * prev;
} Dnode;

typedef struct dlistdef{
	Dnode * head;
	Dnode * tail;
} Dlist;

Dlist * DLnew();
void DLemptyList();
void DLdeleteList();
void DLaddFirst(Dlist * dlist, int ins);
void DLaddLast(Dlist * dlist, int ins);
void DLaddAfterIdx(Dlist * dlist, int ins, int idx);
void DLaddBeforeIdx(Dlist * dlist, int ins, int idx);
void DLdeleteIdx(Dlist * dlist, int idx);
void DLprintIdx(Dlist * dlist, int idx);
void DLdumpList(Dlist * dlist);
void DLreverse(Dlist * dlist);

#endif
