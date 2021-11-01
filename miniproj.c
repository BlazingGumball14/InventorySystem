#include <stdio.h>
#include <stdlib.h>

#include "addFunction.c"
#include "updateItemfinal.c"
#include "viewInventory.c"
#include "DeleteFunction.c"
 
void load_menu(void);
void addItem(void);
 
int main(int argc, char** argv)
{
    load_menu();
    return 0;
}
 
void load_menu(void)
{
    char choice;
 	int ch;
 	
    do
    {
    	system("cls"); //this is for clearing cmd screen //still has a minor minor bug when input is blank
        printf("MAIN MENU\n\nAdd Inventory Item\n");
        printf("[A] Add Inventory Item\n");
        printf("[B] Update Inventory Item\n");
        printf("[C] View Inventory Item\n");
        printf("[D] Search Inventory Item\n");
        printf("[E] Delete Inventory Item\n");
        printf("[X] Exit Program\n");
        printf("\nPlease input choice: ");
        scanf("%c", &choice);
 
        switch(choice)
        {
            case 'A': case 'a': addItem();
                break;
            case 'B': case 'b': updateItem();
                break;
            case 'C': case 'c': viewItem();
            	break;
            case 'D': case 'd':
            	
    			while ( (ch = getchar()) != '\n' && ch != EOF) ;
    
				printf("\n\nSearch Function currently unavailable.\nPress ENTER to continue.\n");
    			while ( (ch = getchar()) != '\n' && ch != EOF)
            	break;
            case 'E': case 'e': DeleteItem();
            	break;
            
            case 'X': case 'x': printf("Quitting program!\n");
            	choice != 'X'; //part of the failsafe while at the end
                exit(0); //program should exit here
                break;
            default: printf("Invalid choice!\n\n"); 
            	
            	/* Flushes input buffer from the newline from scanf() */
    			while ( (ch = getchar()) != '\n' && ch != EOF) ;
    			
   				printf("Press ENTER to continue.\n");
    			while ( (ch = getchar()) != '\n' && ch != EOF)
                break;
        }
 			
    } while (choice != 'X'); //the program should close on exit(0) on the exit case 'X/x'. this here is a failsafe
 
}
