#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void updateItem() {
	int i;  
	int prodID;
	int lineToDelete, lines, found;
	lineToDelete = 1;
	lines = 0;
	found = 0;
	char confirmation;
	char lineReader[100];
	char likeThis[5];
	char productID[5];
	char myArray[50];
	char nArray[100];
	int repeat = 1;

	
	FILE * inventory, * tempFile;
	inventory = fopen("inventorysample.csv", "r");
	tempFile = fopen("temp.csv", "w");
	
	printf("Enter the product ID of the item you want to update: \n");
	
	if(scanf("%d", &prodID)){ // Check if input is valid
	
		if(prodID <= 99999 && prodID >= 1){ // Check if input is 5 digits or less
		
			sprintf(productID, "%d", prodID); // cast the prodID into a string and give the value to productID		
			
			fflush(stdin); // Reset the input buffer
			
			while(!feof(inventory)){
			
				fgets(lineReader, 100, inventory); // read each line in the inventory
			
				strncpy(likeThis, lineReader+1,5); // Copy the 5 digit Product ID of the current line
				
			
				if(strcmp (productID, likeThis) == 0){  // This will check each line if the inputted product ID matches the current line's product ID
					
					found++;
					printf("%s\n", lineReader);
					
					printf("Input the data for update: \n");
					
					while (repeat) {
    					printf("Enter Product ID: ");
   						scanf("%s", myArray);
   						fflush(stdin);
    					repeat = 0; 
    					
    					if (strlen(myArray) != 5) {
       						 printf("Invalid Input!");
      						  //repeat = 1;
        						exit(1);
    }
   						 for (i = 0; i < 5; ++i) {
       						 if (!isdigit(myArray[i])) {
           						 printf("Invalid Input!");
            					//repeat = 1;
            					exit(1);		
        }
    }
}					sprintf(nArray, "\%s%s\"", nArray, myArray);

    					printf("Enter Product Name: ");
    						fgets(myArray, sizeof(myArray), stdin);
    						strtok(myArray, "\n");
   							fflush(stdin);
    						repeat = 0; 
    						for (i = 0; i < 50; ++i) {
    	 					if (strlen(myArray) > 30) {
        					printf("Invalid Input!");
							exit(1);
        }
    }

					sprintf(nArray,"%s,\"%s\"", nArray, myArray);
					

    					printf("Enter Product Quantity: ");
    					scanf("%s", myArray);
   						fflush(stdin);
    						//fgets(myArray, sizeof(myArray), stdin);
    					//	strtok(myArray, "\n");
   						//	fflush(stdin);
    						repeat = 0; 
    					for (i = 0; i < 30; ++i) {
    	 					if (strlen(myArray) > 5|| !isdigit(myArray[i])) {
        					printf("Invalid Input!");
							exit(1);			 
        }
        //	for (i = 0; i < 5; ++i) {
       		//			if (!isdigit(myArray[i])) {
           		//		printf("Invalid Input!");
            	//		exit(1);
      //  }
 // }
    }
  				
					sprintf(nArray,"%s,\"%s\"", nArray, myArray);
					
					
				
    					printf("Enter Product Expiry: ");
   						 	fgets(myArray, sizeof(myArray), stdin);
    						strtok(myArray, "\n");
   							fflush(stdin);
    						repeat = 0; 
    						for (i = 0; i < 15; ++i) {
    	 					if (strlen(myArray) > 11) {
        					printf("Invalid Input!");
							exit(1);
        }
    }

   //						 for (i = 0; i < 15; ++i) {
     //  						 if (!isalpha(myArray[i])) {
     //      						 printf("Invalid Input!");
     //       					//repeat = 1;
     //       					exit(1);
     //   }
 //   }
//}
					sprintf(nArray,"%s,\"%s\"", nArray, myArray);
					
					
			
    					printf("Enter Product price: ");
   						fgets(myArray, sizeof(myArray), stdin);
    						strtok(myArray, "\n");
   							fflush(stdin);
    						repeat = 0; 
    						for (i = 0; i < 15; ++i) {
    	 					if (strlen(myArray) > 10) {
        					printf("Invalid Input!");
							exit(1);

}
}

					sprintf(nArray,"%s,\"%s\"\n", nArray, myArray);
					

					
					printf("Are you sure you want to update this product? (Y/N)\n");
					
					do{
					
						if(scanf("%c", &confirmation)){ // Final confirmation from user if they really want to delete the item
						
							if(confirmation == 'Y' || confirmation == 'y'){
							
								rewind(inventory);
							
							
								while(fgets(lineReader, 100, inventory) != NULL){
									
									
									lines++;
									
									if(lines != lineToDelete){
										
										fprintf(tempFile, "%s", lineReader);
										
									}
									else if (lines==lineToDelete){
										fprintf(tempFile, "%s", nArray);
									}
								}
								
								fclose(inventory);
								fclose(tempFile);
								remove("inventorysample.csv");
								rename("temp.csv", "inventorysample.csv");
								printf("Item %s successfully deleted!", productID);
							
								
							} else if (confirmation =='N' || confirmation == 'n'){
							
								printf("Item %s was not updated", productID);
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
				}else {
					
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

int main(){
	updateItem();
	return 0;
}
