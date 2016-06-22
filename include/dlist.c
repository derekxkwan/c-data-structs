#include "dlist.h"

Dnode * DLnewNode(int ins);

Dnode * DLnewNode(int ins){
	Dnode * newNode = malloc(sizeof(Dnode));
	newNode->data = ins;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

Dlist * DLnew(){
	Dlist * dlist = malloc(sizeof(Dlist));
	dlist->head = NULL;
	dlist->tail = NULL;
	return dlist;
}

void DLaddFirst(Dlist * dlist, int ins){
	Dnode * curHead = dlist->head;
	if(curHead == NULL){
		dlist->head =dlist->tail = DLnewNode(ins);
	}
	else{
		dlist->head = DLnewNode(ins);
		curHead->prev = dlist->head;
		dlist->head->next = curHead;
	};
}

void DLaddLast(Dlist * dlist, int ins){
	Dnode * curTail = dlist->tail;
	if(curTail == NULL){
		dlist->head = dlist->tail = DLnewNode(ins);	
	}
	else{
		dlist->tail = DLnewNode(ins);
		curTail->next = dlist->tail;
		dlist->tail->prev = curTail;
	};
}

void DLaddAfterIdx(Dlist * dlist, int ins, int idx){
	Dnode * curNode = dlist->head;
	//if idx < 0, add at beginning
	if(idx < 0){
		DLaddFirst(dlist, ins);
	}
	else if(curNode == NULL){
		//if list is empty, just stick it at the head (and tail)
		dlist->head = dlist->tail = DLnewNode(ins);
	}
	else{
		//if not, traverse until we hit the correct idx
		//if idx does not exist (too big), add at end
		int counter = 0;
		while(counter < idx && curNode->next != NULL){
			curNode = curNode->next;
			counter++;
		};
		Dnode * curNext = curNode->next;
		curNode->next = DLnewNode(ins);
		curNode->next->next = curNext;
		curNode->next->prev = curNode;
		//edge case, if curNext is null
		if(curNext == NULL){
			dlist->tail = curNode->next;
		}
		else{
			curNext->prev = curNode->next;
		};
	};

}


void DLaddBeforeIdx(Dlist * dlist, int ins, int idx){
	Dnode * curNode = dlist->head;
	//if idx < 0, add at beginning
	if(idx < 0){
		DLaddFirst(dlist, ins);
	}
	else if(curNode == NULL){
		//if list is empty, just stick it at the head (and tail)
		dlist->head = dlist->tail = DLnewNode(ins);
	}
	else{
		//if not, traverse until we hit the correct idx
		//if idx does not exist (too big), add at end
		int counter = 0;
		Dnode * prevNode = NULL;
		while(counter < idx && curNode->next != NULL){
			prevNode = curNode;
			curNode = curNode->next;
			counter++;
		};
		if(counter != idx){
			//reached the end without hitting idx
			//so add at the end
			DLaddLast(dlist, ins);
		}
		else if(prevNode == NULL){
			//we're at the head, just add to the head
			DLaddFirst(dlist, ins);
		}
		else{
			//else normal operating procedures
			prevNode->next = DLnewNode(ins);
			prevNode->next->next = curNode;
			prevNode->next->prev = prevNode;
			curNode->prev = prevNode->next;
		};
	};

}

void DLdeleteIdx(Dlist * dlist, int idx){
	Dnode * curNode = dlist->head;
	if(curNode != NULL && idx >= 0){
		Dnode * prevNode = NULL;
		int counter = 0;
		while(counter < idx && curNode->next != NULL){
			prevNode = curNode;
			curNode = curNode->next;
			counter++;
		};
		if(counter==idx){
			//if we actually hit idx, else ignore
			Dnode * nextNode = curNode->next;
			if(prevNode != NULL){
				prevNode->next = nextNode;
			};
			if(nextNode != NULL){
				nextNode->prev = prevNode;
			};
			//edge cases
			if(dlist->head == curNode){
				dlist->head = nextNode;
			};
			if(dlist->tail == curNode){
				dlist->tail = prevNode;
			};
			free(curNode);
		};
	};
}

void DLprintIdx(Dlist * dlist, int idx){
	Dnode * curNode = dlist->head;
	if(curNode != NULL){
		int counter = 0;
		while(curNode->next != NULL && counter < idx){
			curNode = curNode->next;
			counter++;
		};
		if(counter==idx){
			printf("%d\n", curNode->data);
		};
	};
}

void DLdumpList(Dlist * dlist){
	Dnode * curNode = dlist->head;
	while(curNode != NULL){
		printf("%d ", curNode->data);
		curNode = curNode->next;
	};
	printf("\n");
}

void DLreverse(Dlist * dlist){
	Dnode * curNode = dlist->head;
	if(curNode != NULL){
		Dnode * prevNode = curNode->prev;
		Dnode * nextNode;
		while(curNode != NULL){
			nextNode = curNode->next;
			//swapping
			curNode->next = prevNode;
			curNode->prev = nextNode;
			//incrementing
			prevNode = curNode;
			curNode = nextNode;	
		};
		//swapping head and tail
		dlist->tail = dlist->head;
		dlist->head = prevNode;
	};
}

void DLemptyList(Dlist * dlist){
	Dnode * curNode = dlist->head;
	while(curNode != NULL){
		Dnode * nextNode = curNode->next;
		free(curNode);
		curNode = nextNode;
	};
	dlist->head = NULL;
	dlist->tail = NULL;
}

void DLdeleteList(Dlist * dlist){
	DLemptyList(dlist);
	free(dlist);
}
