#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

/* Double Link*/
struct DLink {
    TYPE value;
    struct DLink * next;
    struct DLink * prev;
};

/* Double Linked List with Head and Tail Sentinels  */
struct linkedList{
    int size;
    struct DLink *firstLink;
    struct DLink *lastLink;
};

/*
	initList
	param lst the linkedList
	pre: lst is not null
	post: lst size is 0
 */
void _initList (struct linkedList *lst) {
    assert(lst != NULL);
    
    struct DLink *firstSent = (struct DLink *) malloc(sizeof(struct DLink));
    struct DLink *lastSent = (struct DLink *) malloc(sizeof(struct DLink));
    
    lst->firstLink = firstSent;
    lst->lastLink = lastSent;
    
    firstSent->next = lastSent;
    firstSent->prev = NULL;
    lastSent->prev = firstSent;
    lastSent->next = NULL;
    
    lst->size = 0;
}

/*
 createList
 param: none
 pre: none
 post: firstLink and lastLink reference sentinels
 */

struct linkedList *createLinkedList(){
    struct linkedList *newList = malloc(sizeof(struct linkedList));
    _initList(newList);
    return(newList);
}

/*
	_addLinkBeforeBefore
	param: lst the linkedList
	param: l the  link to add before
	param: v the value to add
	pre: lst is not null
	pre: l is not null
	post: lst is not empty
 */

/* Adds Before the provided link, l */

void _addLinkBefore(struct linkedList *lst, struct DLink *l, TYPE v){
    assert(lst != NULL);
    assert(l != NULL);
    struct DLink *newLink = (struct DLink *) malloc(sizeof(struct DLink));
    
    newLink->value = v;
    newLink->next = l;
    newLink->prev = l->prev;
    l->prev->next = newLink;
    l->prev = newLink;
    lst->size++;
}

/*
	_removeLink
	param: lst the linkedList
	param: l the linke to be removed
	pre: lst is not null
	pre: l is not null
	post: lst size is reduced by 1
 */
void _removeLink(struct linkedList *lst, struct DLink *l){
    assert(lst != NULL);
    assert(l != NULL);
    l->prev->next = l->next;
    l->next->prev = l->prev;
    free(l);
    lst->size--;
}

/*
	isEmptyList
	param: lst the linkedList
	pre: lst is not null
	post: none
 */
int isEmptyList(struct linkedList *lst){
    assert(lst != NULL);
    if (lst->size == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

/* De-allocate all links of the list
	param: 	lst		pointer to the linked list
	pre:	none
	post:	All links (including the two sentinels) are de-allocated
 */
void freeLinkedList(struct linkedList *lst){
    while(!isEmptyList(lst)) {
        /* remove the link right after the first sentinel */
        _removeLink(lst, lst->firstLink->next);
    }
    /* remove the first and last sentinels */
    free(lst->firstLink);
    free(lst->lastLink);
}

/* 	Deallocate all the links and the linked list itself.
 
	param: 	v		pointer to the dynamic array
	pre:	v is not null
	post:	the memory used by v->data is freed
 */
void deleteLinkedList(struct linkedList *lst){
    assert (lst != 0);
    freeLinkedList(lst);
    free(lst);
}


/* Function to print list
 Pre: lst is not null
 */
void printList(struct linkedList* lst){
    struct DLink *tempPtr;
    assert(lst != NULL);
    tempPtr = lst->firstLink->next;
    printf("\nContents of the Linked List: \n");
    while (tempPtr->next != NULL) {
        printf(" %d \n", tempPtr->value);
        tempPtr = tempPtr->next;
    }
}

/* ************************************************************************
	Deque Interface Functions
 ************************************************************************ */

/*
	addFrontList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
 */
void addFrontList(struct linkedList *lst, TYPE e){
    assert(lst != NULL);
    _addLinkBefore(lst, lst->firstLink->next, e);
}

/*
	addBackList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
 */
void addBackList(struct linkedList *lst, TYPE e) {
    assert(lst != NULL);
    _addLinkBefore(lst, lst->lastLink, e);
}

/*
	frontList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: none
 */
TYPE frontList (struct linkedList *lst){
    assert(lst != NULL);
    assert(lst->size != 0);
    return lst->firstLink->next->value;
}

/*
	backList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: lst is not empty
 */
TYPE backList(struct linkedList *lst){
    assert(lst != NULL);
    assert(lst->size != 0);
    return lst->lastLink->prev->value;
}
/*
	removeFrontList
	param: lst the linkedList
	pre:lst is not null
	pre: lst is not empty
	post: size is reduced by 1
 */
void removeFrontList(struct linkedList *lst){
   	_removeLink(lst, lst->firstLink->next);
}

/*
	removeBackList
	param: lst the linkedList
	pre: lst is not null
	pre:lst is not empty
	post: size reduced by 1
 */
void removeBackList(struct linkedList *lst){
    _removeLink(lst, lst->lastLink->prev);
}


/* ************************************************************************
	Stack Interface Functions
 ************************************************************************ */

/*
	Add an item to the bag
	param: 	lst		pointer to the bag
	param: 	v		value to be added
	pre:	lst is not null
	post:	a link storing val is added to the bag
 */
void addList(struct linkedList *lst, TYPE v){
    assert(lst != NULL);
    _addLinkBefore(lst, lst->firstLink->next, v);
    //printList(lst);
}

/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0
 
	param:	lst		pointer to the bag
	param:	e		the value to look for in the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	no changes to th
	e bag
 */
int containsList (struct linkedList *lst, TYPE e){
    struct DLink *tempPtr; 
    assert(lst != NULL);
    assert(lst->size != 0);
    tempPtr = lst->firstLink->next;
    while (tempPtr->next != NULL) {
        if (tempPtr->value == e) {
            return 1;
        }
		tempPtr = tempPtr->next;
    }
    return 0;
}

/*	Removes the first occurrence of the specified value from the collection
	if it occurs
 
	param:	lst		pointer to the bag
	param:	e		the value to be removed from the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	e has been removed
	post:	size of the bag is reduced by 1
 */
void removeList (struct linkedList *lst, TYPE e){
    struct DLink *tempPtr;
    assert(lst != NULL);
    assert(lst->size != 0);
    tempPtr = lst->firstLink->next;
    while (tempPtr->next != NULL) {
        if (tempPtr->value == e) {
            _removeLink(lst, tempPtr);
        }
    }
}