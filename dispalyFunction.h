
/*  displayFunction.h
 *
 *	This header file use to keep all about function to use in this programs
 *  that are located in displayFunction.c 
 *

 */

typedef struct 
	{
	char productID[10];			/*digit code of an item*/
	char productDes[40];			/*category of an item*/
	char quantity[10];		/*subcategory of an item*/
	char expirationDate[11];				/*operating system of an item*/
	char price[128];				/*date the item purchase*/
	}INV_T;

/* 	This function display the current contents of the 
 *  database (all objects) on the screen. */
void displayAll();
