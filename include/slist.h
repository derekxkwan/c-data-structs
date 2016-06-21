#include <stdio.h>
#include <stdlib.h>

#ifndef SLIST_HEADER
#define SLIST_HEADER

typedef struct snodedef{
	int data;
	struct snodedef * next;
} Snode;

typedef struct slistdef{
	Snode * head;
} Slist;

Slist * SLnew();
void SLemptyList();
void SLdeleteList();
void SLaddFirst(Slist * slist, int ins);
void SLaddLast(Slist * slist, int ins);
void SLaddAfterIdx(Slist * slist, int ins, int idx);
void SLaddBeforeIdx(Slist * slist, int ins, int idx);
void SLdeleteIdx(Slist * slist, int idx);
void SLprintIdx(Slist * slist, int idx);
void SLdumpList(Slist * slist);
void SLreverse(Slist * slist);

#endif
