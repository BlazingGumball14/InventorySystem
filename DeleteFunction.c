#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void DeleteItem() {
	
	int prodID;
	int lineToDelete, lines, found, i, j, charNumbers;
	lineToDelete = 1;
	lines = 0;
	found = 0;
	char confirmation;
	char lineReader[1000];
	char nameReader[25];
	char nameReader2[25];
	char nameReader3[25];
	char likeThis[5];
	char productID[5];
	FILE * inventory, * tempFile;
	inventory = fopen("Inventory.csv", "r");
	tempFile = fopen("temp.csv", "w");
	
	printf("Enter the product ID of the item you want to delete: \n");
	
	if(scanf("%d", &prodID)){ // Check if input is valid
	
		if(prodID <= 99999 && prodID >= 1){ // Check if input is 5 digits or less
		
			sprintf(productID, "%d", prodID); // cast the prodID into a string and give the value to productID		
			
			fflush(stdin); // Reset the input buffer
			
			while(!feof(inventory)){
				
				
				fgets(lineReader, 1000, inventory); // read each line in the inventory
			
				if(lineToDelete == 1){
					
					strncpy(likeThis, lineReader+1,5); // Copy the 5 digit Product ID of the current line
				
				} else{
					strncpy(likeThis, lineReader+1,5);
				}
				
			
				if(strcmp (productID, likeThis) == 0){  // This will check each line if the inputted product ID matches the current line's product ID
					
					found++;
					
					// DISPLAY THE ITEM's ATTRIBUTES
					
					for(i = 9; lineReader[i] != '\"' || i < 33; i++){
						
						nameReader[i-9] = lineReader[i];
						
					}
					// Display attribute headers
					printf("ID       ");
					
					if(strlen(nameReader) < 11){
						printf("DESCRIPTION    ");
					} else{
						printf("DESCRIPTION");
						for(j = 1; j <= strlen(nameReader) - 11; j++){
							printf(" ");
						}
						printf("     ");
					}
					
					
					charNumbers = (int)(12 + strlen(nameReader));
					
					printf("QUANTITY    EXPIRY DATE    PRICE\n");
					
					// Display attribute values
						// ID and Description
						
					printf("%.5s     %s    ", lineReader+1, nameReader);
					
						// Quantity
						
					for(i = charNumbers; lineReader[i] != '\"'; i++){
						
						printf("%c", lineReader[i]);
						nameReader2[i-charNumbers] = lineReader[i];
						
					}
					
					if(strlen(nameReader2) < 8){
						
						for(j = 1; j <= 8 - strlen(nameReader2); j++){
							printf(" ");
						}
						printf("     ");
							
					} else{
						printf("     ");
					}
					
					charNumbers += (int)(3 + strlen(nameReader2));
					
						// Expiry Date
						
					for(i = charNumbers; lineReader[i] != '\"'; i++){
						
						printf("%c", lineReader[i]);
						nameReader3[i-charNumbers] = lineReader[i];
						
					}
					
					if(strlen(nameReader3) < 11){
						
						for(j = 1; j <= 8 - strlen(nameReader3); j++){
							printf(" ");
						}
						printf("      ");
							
					} else{
						printf("      ");
					}
					
					charNumbers += (int)(3 + strlen(nameReader3));
					
						// Price
					
					for(i = charNumbers; lineReader[i] != '\"'; i++){
						
						printf("%c", lineReader[i]);
						
					}
					
					// END OF DISPLAY
					
					printf("\n\nAre you sure you want to delete this item? (Y/N)\n");
					
					do{
					
						if(scanf("%c", &confirmation)){ // Final confirmation from user if they really want to delete the item
						
							if(confirmation == 'Y' || confirmation == 'y'){
							
								rewind(inventory);
							
								while(fgets(lineReader, 1000, inventory) != NULL){
									
									
									lines++;
									
									if(lines != lineToDelete){
										
										fprintf(tempFile, "%s", lineReader);
										
									}
									
								}
								
								fclose(inventory);
								fclose(tempFile);
								remove("Inventory.csv");
								rename("temp.csv", "Inventory.csv");
								printf("Item %s successfully deleted!", productID);
							
								
							} else if (confirmation =='N' || confirmation == 'n'){
							
								printf("Item %s was not deleted", productID);
								fclose(inventory);
								fclose(tempFile);
								break;
								
							} else{
								printf("You entered an invalid input!");
							}
						
						} else {
							printf("You entered an invalid input!");

						}
						
						fflush(stdin); // Reset the input buffer
						
					} while(confirmation != 'Y' && confirmation != 'y' && confirmation !='N' && confirmation != 'n');
					
					break;
				} else {
					
					lineToDelete++;
				}

			}
			
			if(found == 0){
				printf("Item %d does not exist!", prodID);
			}
			
		} else {
			printf("You entered an invalid input!");
			fclose(inventory);
			fclose(tempFile);
		}
	
	} else{
		
		printf("You entered an invalid input!");
		fclose(inventory);
		fclose(tempFile);
	}

}
