/*
Braden Ackles & Alex Wilson
Assignment 3: Part 3
4/26/2015
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <float.h>
#include "cirListDeque.h"

/* Double Link Struture */
struct DLink {
	TYPE value;/* value of the link */
	struct DLink * next;/* pointer to the next link */
	struct DLink * prev;/* pointer to the previous link */
};

# define TYPE_SENTINEL_VALUE DBL_MAX 


/* ************************************************************************
 Deque ADT based on Circularly-Doubly-Linked List WITH Sentinel
 ************************************************************************ */

struct cirListDeque {
	int size;/* number of links in the deque */
	struct DLink *Sentinel;	/* pointer to the sentinel */
};

/* internal functions prototypes */
struct DLink* _createLink (TYPE val);
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v);
void _removeLink(struct cirListDeque *q, struct DLink *lnk);

/* ************************************************************************
	Deque Functions
************************************************************************ */

/*	Initialize deque.
	param: 	q		pointer to the deque
	pre:	q is not null
	post:	q->Sentinel is allocated and q->size equals zero*/
void _initCirListDeque (struct cirListDeque *q) {
  	/* FIXME: you must write this */
	assert(q != NULL);
	struct DLink *Sentinel = malloc(sizeof(struct DLink));
	q->size = 0;
	q -> Sentinel = Sentinel;	//possibly not needed
	q -> Sentinel -> next = q -> Sentinel;
	q -> Sentinel -> prev = q -> Sentinel;
}

/*create a new circular list deque*/
struct cirListDeque *createCirListDeque(){
	struct cirListDeque *newCL = malloc(sizeof(struct cirListDeque));
	_initCirListDeque(newCL);
	return(newCL);
}

/*	Create a link for a value.
	param: 	val		the value to create a link for
	pre:	none
	post:	a link to store the value*/
struct DLink * _createLink (TYPE val){
	/* FIXME: you must write this */
	struct DLink *newL = malloc(sizeof(struct DLink));
	newL -> value = val;
	return newL;
}

/*	Adds a link after another link
	param: 	q		pointer to the deque
	param: 	lnk		pointer to the existing link in the deque
	param: 	v		value of the new link to be added after the existing link
	pre:	q is not null
	pre: 	lnk is not null
	pre:	lnk is in the deque 
	post:	the new link is added into the deque after the existing link*/
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v){
	/* FIXME: you must write this */	 
	assert(lnk != NULL);
	assert(q != NULL);
	struct DLink *newL = _createLink(v);
	newL -> next = lnk -> next;
	newL -> prev = lnk;
	lnk -> next -> prev = newL;
	lnk->next = newL;
	q -> size = (q->size) + 1;
}

/*	Adds a link to the back of the deque
	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the back of the deque*/
void addBackCirListDeque (struct cirListDeque *q, TYPE val) {
	/* FIXME: you must write this */	 
	assert(q != NULL);
	struct DLink *newL = _createLink(val);
	q -> Sentinel -> prev -> next = newL;	//set the last link in the list to point to the new link
	newL -> prev = q -> Sentinel -> prev;	//set the newlink last to the old last
	newL -> next = q -> Sentinel;			//set the new link next to the sentinel
	q->Sentinel -> prev = newL;				//set the sentinel prev to the new Link
	q->size = (q->size) + 1;				//Increase the size
}

/*	Adds a link to the front of the deque
	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the front of the deque*/
void addFrontCirListDeque(struct cirListDeque *q, TYPE val){
	/* FIXME: you must write this */	 
	assert(q != NULL);
	struct DLink *newL = _createLink(val);
	q -> Sentinel -> next -> prev = newL;	//set the last link in the list to point to the new link
	newL -> prev = q -> Sentinel;			//set the newlink last to the old last
	newL -> next = q -> Sentinel -> next;	//set the new link next to the sentinel
	q -> Sentinel -> next = newL;			//set the sentinel prev to the new Link
	q -> size = (q->size) + 1;				//Increase the size
}

/*	Get the value of the front of the deque
	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the front of the deque*/
TYPE frontCirListDeque(struct cirListDeque *q){
	/* FIXME: you must write this */	 
	assert(q -> size != 0);
	assert(q != NULL);
	return q -> Sentinel -> next -> value;
}

/*	 Get the value of the back of the deque
	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the back of the deque*/
TYPE backCirListDeque(struct cirListDeque *q){
	/* FIXME: you must write this */	 
	assert(q->size != 0);
	assert(q != NULL);
	return q->Sentinel->prev->value;
}

/*	Remove a link from the deque
	param: 	q		pointer to the deque
	param: 	lnk		pointer to the link to be removed
	pre:	q is not null and q is not empty
	post:	the link is removed from the deque*/
void _removeLink(struct cirListDeque *q, struct DLink *lnk){
	/* FIXME: you must write this */	 
	assert(q -> size != 0);
	assert(q != NULL);
	assert(lnk != q->Sentinel);
	lnk -> prev -> next = lnk -> next;
	struct DLink *temp = lnk;
	temp -> next -> prev = temp -> prev;
	free(temp);
	q -> size = (q -> size) - 1;
}

/*	Remove the front of the deque
	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the front is removed from the deque*/
void removeFrontCirListDeque (struct cirListDeque *q) {
	/* FIXME: you must write this */	 
	assert(q -> size != 0);
	assert(q != NULL);
	_removeLink(q, q -> Sentinel -> next);
}


/*	Remove the back of the deque
	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the back is removed from the deque*/
void removeBackCirListDeque(struct cirListDeque *q){
  	/* FIXME: you must write this */
	assert(q->size != 0);
	assert(q != NULL);
	_removeLink(q, q->Sentinel->prev);
}

/*	 De-allocate all links of the deque
	param: 	q		pointer to the deque
	pre:	none
	post:	All links (including Sentinel) are de-allocated*/
void freeCirListDeque(struct cirListDeque *q){
	/* FIXME: you must write this */	 
	do{
		removeFrontCirListDeque(q);
	} while (isEmptyCirListDeque(q));
	free(q -> Sentinel);
}

/* 	Deallocate all the links and the deque itself. 
	param: 	v		pointer to the dynamic array
	pre:	v is not null
	post:	the memory used by v->data is freed*/
void deleteCirListDeque(struct cirListDeque *q) {
	assert(q != 0);
	freeCirListDeque(q);
	free(q);
}

/*	Check whether the deque is empty
	param: 	q		pointer to the deque
	pre:	q is not null
	ret: 	1 if the deque is empty. Otherwise, 0.*/
int isEmptyCirListDeque(struct cirListDeque *q) {
  	/* FIXME: you must write this */
	assert(q != NULL);
	if (q->size == 0){
		return 1;
	}
	else{
		return 0;
	}
}

/*	 Print the links in the deque from front to back
	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the links in the deque are printed from front to back*/
void printCirListDeque(struct cirListDeque *q){
	/* FIXME: you must write this */	 
	assert(q -> size != 0);
	assert(q != NULL);
	struct DLink *temp = q -> Sentinel -> next;
	printf("Below is the List(printed \"front\" to \"back)\n");
	do{
		printf("%f, ", temp -> value);
		temp = temp->next;
	} while (temp != q -> Sentinel);
}

/*	Reverse the deque
	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the deque is reversed*/
void reverseCirListDeque(struct cirListDeque *q){
	/* FIXME: you must write this */	 
	assert(q->size != 0);
	assert(q != NULL);
	struct DLink *tmp = q -> Sentinel;
	struct DLink *temp = q -> Sentinel -> prev;
	do{
		tmp -> prev = tmp -> next;
		tmp -> next = temp;
		tmp = tmp -> prev;
		temp = temp -> next;
	} while (tmp != q->Sentinel);
}