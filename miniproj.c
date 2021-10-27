#include <stdio.h>
#include <stdlib.h>

#include "addFunction.c"
 
void load_menu(void);
void addItem(void);
//void rest(void);
 
int main(int argc, char** argv)
{
    load_menu();
    return 0;
}
 
void load_menu(void)
{
    char choice, temp;
 	int ch;
 	
    do
    {
    	system("cls"); //this is for clearing cmd screen //still has a minor minor bug when input is blank
        printf("MAIN MENU\n\nAdd Inventort Item\n");
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
            /* Edit your function
			case 'B': case 'b': //rest(); //that rest function is from the original code, which I used as test function 2
                break;
            case 'C': case 'c': 
            	break;
            case 'D': case 'd': 
            	break;
            case 'E': case 'e': 
            	break;
            */
            case 'X': case 'x': printf("Quitting program!\n");
            	choice != 'X'; //part of the failsafe while at the end
                exit(0); //program should exit here
                break;
            default: printf("Invalid choice!\n\n"); //I still don't know how C handles char so this part is a bit buggy
            	
            	/* Flushes input buffer from the newline from scanf() */
    			while ( (ch = getchar()) != '\n' && ch != EOF) ;
    			
   				printf("Press ENTER to continue.\n");
    			while ( (ch = getchar()) != '\n' && ch != EOF)
                break;
        }
 			
    } while (choice != 'X'); //the program should close on exit(0) on the exit case 'X/x'. this here is a failsafe
 
}
 
      
 
 /* this is from the original code I copied
 	feel free to enable it to experiment a bit if you want
 
void rest(void)
{
    int ch;
    printf("Sleepy sleepy... zZZzZzZz\n");
    printf("You now feel awake again!\n");
 
    // Flushes input buffer 
    while ((ch = getchar()) != '\n' && ch != EOF) ;
 
    printf("\n\nPress ENTER to continue.\n");
    while ((ch = getchar()) != '\n' && ch != EOF)
        ;
 
    return;
}
*/


/*this is a recycle bin

if(choice != 0)
 	scanf("%c", &temp);

-------------------------------------

/*choice = 'z';
            	printf("Press Enter to continue\n");
 				scanf("%c", &temp);					//i'm trying to clear buffer here
 				scanf("%c", &choice);
            	//inv = 1;/
            	
-----------------------------------------
 
 		/*reproducing what Klars did to resolve same bug concept
 		if(inv == 1 )
 		{
 			printf("Press Enter to continue\n");
 			scanf("%c", &temp);
 		}/
 		
-------------------------

    	//inv = 0;
*/
