#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void DeleteItem() {
	
	int prodID;
	int lineToDelete = 1;
	char confirmation;
	char charReader;
	char lineReader[100];
	char likeThis[5];
	char productID[5];
	FILE * inventory = fopen("Inventory.csv", "r");
	
	printf("Enter the product ID of the item you want to delete: \n");
	
	if(scanf("%d", &prodID))
	{
		if(prodID <= 99999 && prodID >= 1)
		{
		
			sprintf(productID, "%d", prodID); // cast the prodID into a string and give the value to productID		
			
			while(!feof(inventory)){
			
				fgets(lineReader, 100, inventory); // read each line in the inventory
			
				strncpy(likeThis, lineReader+1,5); // Copy the 5 digit Product ID of the current line
				
			
				if(strcmp (productID, likeThis) == 0){
					
					printf("I found the line to delete! It's line number %d", lineToDelete);
					break;
				} else {
					lineToDelete++;
				}

			}
			
		} else {
			printf("You entered an invalid input!");
			fclose(inventory);
		}
	
	} else{
		
		printf("You entered an invalid input!");
		fclose(inventory);
	}
	
	
	fclose(inventory);

}
