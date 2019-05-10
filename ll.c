#include <stdio.h>
#include "list.h"

int main()
{
	list results;

	addNode(&results, newNode("12345678901234567890", "12345678","0123456789"));
	// addNode(&results, newNode('B', 89));
	// addNode(&results, newNode('D', 65));
	// addNode(&results, newNode('F', 50));
	
	// addNodeAt(&results, newNode('C', 77), 1);
	
	setCursor(&results, getHead(&results));
	

}