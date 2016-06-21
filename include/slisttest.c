#include<stdio.h>
#include<stdlib.h>
#include "slist.h"

int main(){
	
	Slist * myslist = SLnew();
	SLaddFirst(myslist, 3);
	SLaddLast(myslist, 5);
	SLaddAfterIdx(myslist, 10, 0);
	SLdumpList(myslist);
	SLdeleteIdx(myslist, 1);
	SLdumpList(myslist);
	SLprintIdx(myslist, 1);
	SLdeleteList(myslist);
	return 0;
}
