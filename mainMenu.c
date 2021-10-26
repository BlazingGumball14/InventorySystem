#include <stdio.h>



int main()
{
	char menuSelection;
	do
	{
		printf("MAIN MENU\n[A] Add Inventory Item\n[B] Update Inventory Item\n[C] View Inventory Item\n[D] Search Inventory Item\n[E] Delete Inventory Item\n[X] Exit Program\n\nPlease input choice: ");
		scanf("%c", &menuSelection);
	
		switch(menuSelection)
		{
			case 'a': case 'A':
			{
				printf("Success!a");	
				break;
			}
			case 'b': case 'B':
			{
				printf("Success!b");	
				break;
			}
			case 'c': case 'C':
			{
				printf("Success!c");	
				break;
			}
			case 'd': case 'D':
			{
				printf("Success!d");	
				break;
			}
			case 'e': case 'E':
			{
				printf("Success!e");	
				break;
			}
			case 'x': case 'X':
			{
				printf("Success!x");
				menuSelection =	'X';
				break;
			}
			default:
				printf("Invalid Input!\n\n");
		}
		scanf("%c", &menuSelection);
		
	}while(menuSelection != 'X' && menuSelection != 'x');
}

/*

if(menuSelection == 'a' || menuSelection == 'A')
		{
			
			printf("\nSelected A\n\n");
		}
		else
		{
			printf("\nInvalid Input!\n\n");
		}


*/
