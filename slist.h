#include <stdio.h>
#include <stdlib.h>

typedef struct snodedef{
	int data;
	struct snodedef * next;
} Snode;

typdef struct slistdef{
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
void SLreverse(Slist * slist);
