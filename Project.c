#include <stdio.h>
#include <string.h>
#include "list.h"

int main
{
  int x = 1;
  while(x = 1)
  {
    printf("What would you like to do?\n");
    printf("add - insert something in the phonebook?\n");
    printf("delete - delete something from the phonebook?\n");
    printf("print - print out one of the contacts?\n");
    printf("find - return the element selected?\n");
    printf("exit - nothing at all\n");
    scanf("%s", &input);
    
    switch(input){
      case "add": 
            char na[20];
            char b[8];
            char p[10];
          
            printf("enter name\n");
            scanf("%s", na);
          
            printf("enter birthday.\n");
            scanf("%s", b);
            printf("enter phonenumber:\n");
            scanf("%s", p);

        //create node
            node* newnode = node*(na,b,p);
            addnode(newnode)
            break;
        
      case 'delete':
         
        
              printf("\ncontact deleted\n");    
             break;
        
      case 'print':
             printf("\nfull contact list\n");
            
            
             break;
      case 'find':
             printf("\nsearch results\n");

             break;
      case 'load':
        
        
            printf("\nlist succesfully loaded\n");         
             break;
      case 'exit':
            
             printf("\nexit\n");
             exit = 0;
             break;
      case default
             printf("\nPlease enter a valid command\n");
             break;
  

  
   }

 }

void main(){
    node *X = node("LUIS","08082000","0123456789");
}
