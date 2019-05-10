#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//Node Functions
node* newNode(char name[], char b[], char p[]){
	node* n = (node*)malloc(sizeof(node)); //malloc returns void pointer, we cast it to node pointer
	
	for(int i = 0; i < 20; i++){ //Copy given char array to n's char array, since there cannot be an assigment to a character array.
		n -> name[i] = name[i];
	}

	for(int i = 0; i < 8; i++){
		n -> bday[i] = b[i];
	}

	for(int i = 0; i < 10; i++){
		n -> phone[i] = p[i];
	}
	
	return n; 
}

void  setName(node* n, char name[])
{
	for(int i = 0; i < 20; i++){
		n -> name[i] = name[i];
	}
}

void  setBday(node* n, char b[])
{
    for(int i = 0; i < 8 ; i++){
		n -> bday[i] = b[i];
	}
}

void  setPhone(node* n, char p[])
{
    for(int i = 0; i < 10 ; i++){
		n -> phone[i] = p[i];
	}
}

void  setNext(node* n, node* nx)
{
	n->next = (struct node*)nx;
}

char*  getName(node* n) //MIGHT NEED TO CHANGE RETURN TYPE OF GETTERS
{
	return n->name;
}

char*   getBday(node* n)
{
	return n-> bday;
}

char*   getPhone(node* n)
{
	return n-> phone;
}

node* getNext(node* n)
{
	return (node*) n-> next;
}

//List Functions
void setHead(list* l, node* n)
{
	l->head = n;
}

void setTail(list* l, node* n)

{
	l->tail = n;
}

void setCursor(list* l, node* n)
{
	l->cursor = n;
}

void addNode(list* l, node* n){ //Push
	if(getEntries(l) == 0){
		setHead(l,n);
		setTail(l,n);
		// setCursor(l,n); //REMOVED TO MATCH LL SOLUTION

		l -> entries++;
		return;
	}

	setNext(getTail(l), n); 
	setTail(l,n);
	l -> entries++;
	
}


void addNodeAt(list* l, node* n, int i) //Insert after i
{
	if(i == 0){ //if desired index is begining of list and list is empty.
		
        setNext(n, getHead(l)); //Make n's next the current head
		setHead(l,n); //point the head to n
		
        //setTail(l,n); //REMOVED TO MATCH LL SOLUTION 
		// setCursor(l,n); //REMOVED TO MATCH LL SOLUTION 

		l -> entries++;
		return;
	}

	setCursor(l, getHead(l)); //Make cursor point to begining of list
	
	for(int e = 0; e < i; e++){ //move cursor until reaching i
		forward(l);
	}

	setNext(n, getNext(getCursor(l))); //make n's next the next element of the current index
	setNext(getCursor(l), n); 
	l -> entries++;

}

node* getHead(list* l)
{
	return l->head;
}

node* getTail(list* l)
{
	return l->tail;
}

node* getCursor(list* l)
{
	return l->cursor;
}

unsigned int getEntries(list* l)
{
	return l->entries;
}

void forward(list* l) //Move cursor to next
{
	if(getNext(getCursor(l)) != NULL){ //If cursor next is not null, move it.
		l -> cursor = getNext(getCursor(l));
	}
}
/*PROJECT METHODS --------------------------------------------------------------*/
void printList(list* l){//Print list.
    setCursor(l,getHead(l)); //Set cursor to head of list.

    for(int i = 0; i < getEntries(l); i++){ 
        
        printf("\n Name: "); 
        for(int i = 0; i < 20; i++){ //Print char array 'name'
            printf("%c", getCursor(l) -> name[i]);
        }

        printf("\n Birthday: ");
        for(int i = 0; i < 8; i++){ //Print char array 'bday'
            printf("%c", getCursor(l) -> bday[i]);
        }

        printf("\n Phone: ");
        for(int i = 0; i < 10; i++){
            printf("%c", getCursor(l) -> phone[i]); //Print char array 'phone'
        }
        
        forward(l); //Move current 
    }
}

void printEntries(list* l){ //Print L's entries.
    if(getEntries(l) < 1){
        printf("There are no entries in the list.\n");
    }
    if (getEntries(l) == 1){
        printf("There is 1 contact in the list.\n");
    }
    else{
        printf("There are %i contacts in the list.\n", l -> entries);
    }
}




//--------------------------------------------------------------------------
// gotoStart(); //go to start of list -set cursor to start of list
// gotoEnd(); //go to end of list - set cursor to end of list
// deleteNode(); //remove last node
// deleteNodeAt(); //delete node at specified index
// getNodeAt(); //retrieve node from specified index

// void deleteNode(list* l){
// 	while(getCursor(l) -> next != NULL ){
// 		forward(l);
// 	}

// }



//Use -> instead of calling other functions