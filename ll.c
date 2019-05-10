#include <stdio.h>
#include "list.h"

int main()
{
	list results;
	setCursor(&results, getHead(&results));
	
    printAll(getCursor(&results));
	setName(getCursor(&results),"Newname");
	printAll(getCursor(&results));

	

}