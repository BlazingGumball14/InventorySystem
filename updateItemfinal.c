#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void updateItem(void) {
	int i;  
	int prodID;
	int lineToUpdate, lines, found;
	lineToUpdate = 1;
	lines = 0;
	found = 0;
	char confirmation;
	char lineReader[100];
	char likeThis[5];
	char productID[5];
	char myArray[50];
	char nArray[100];
	int repeat = 1;
  	int j =  0;
  	int wordExist=0;
	int bufferLength = 255;
	char line[bufferLength];
	
	
	FILE* filePointer;
	filePointer = fopen("Inventory.csv", "r");
	FILE * inventory, * tempFile;
	inventory = fopen("Inventory.csv", "r");
	tempFile = fopen("temp.csv", "w");
	
	printf("Enter the product ID of the item you want to update: ");
	
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
					
					printf("Input the data for update: \n\n");
					
					while (repeat) {
    				printf("Enter Product ID: ");
   				    scanf("%s", myArray);
   				    fflush(stdin);
   				    repeat = 0;
						while(fgets(line, bufferLength, filePointer))
							{
								char *ptr = strstr(line, myArray); 
								if (ptr != NULL) 
									{
									wordExist=1;
									break;
										}
									}
									fclose(filePointer); 
							for (i = 0; i < 5; ++i) { //check if input is less than 5
       							if (!isdigit(myArray[i])) {
           							printf("Invalid Input!");
            							system("miniproj.exe");		
       							 }
  							  }
								if (strlen(myArray) != 5) {
       						 		printf("Invalid Input!");
        								system("miniproj.exe");
   								 }
								if (strcmp (productID, myArray) == 0){ //compare original product ID to new product ID
									continue;
								}
								if (wordExist==1) //if new product ID already exists inside the csv file
									{
										printf("Invalid input! %s already exists", myArray);
										system("miniproj.exe");
									}
								else 
									{
									continue;
									}						
								}
					
						sprintf(nArray, "\"%s\"", myArray);

    					printf("Enter Product Name: ");
    						fgets(myArray, sizeof(myArray), stdin);
    						strtok(myArray, "\n");
   							fflush(stdin);
    						repeat = 0; 
    						for (i = 0; i < 50; ++i) {
    	 					if (strlen(myArray) > 40) {
        					printf("Invalid Input!");
							system("miniproj.exe");;
      						  }
  						  }
					
						sprintf(nArray,"%s,\"%s\"", nArray, myArray);
					
						printf("Enter Product Quantity: ");
   							fgets(myArray, sizeof(myArray), stdin);
   							strtok(myArray, "\n");
   							fflush(stdin);
   							repeat = 0;
						while (myArray[j] != '\0')	{ 
  						if((myArray[j] >= 58 && myArray[j] <= 126) ||  (myArray[j]=='.')||(myArray[j] >= 32 && myArray[j] <= 44)||(myArray[j]=='/')){
  						printf("invalid");  
						system("miniproj.exe");}
						else{
							break;
						}
					}
						for (i = 0; i < 10; ++i) {
    	 					if (strlen(myArray) > 5) {
        					printf("Invalid Input!");
							system("miniproj.exe");
        }
    }
   								
	 					sprintf(nArray,"%s,\"%s\"", nArray, myArray);
 		
    					printf("Enter Product Expiry Date: ");
   						 	fgets(myArray, sizeof(myArray), stdin);
    						strtok(myArray, "\n");
   							fflush(stdin);
    						repeat = 0; 
    						while (myArray[j] != '\0')	{
  						if((myArray[j] >= 58 && myArray[j] <= 126) ||  (myArray[j]=='.')||(myArray[j] >= 32 && myArray[j] <= 44)){
  						printf("invalid");  
						system("miniproj.exe");}
						else{
							break;
						}
						}
    						for (i = 0; i < 15; ++i) {
    	 					if (strlen(myArray) > 10) {
        					printf("Invalid Input!");
							system("miniproj.exe");
        }
    }
						sprintf(nArray,"%s,\"%s\"", nArray, myArray);
					
    					printf("Enter Product Price: ");
   							fgets(myArray, sizeof(myArray), stdin);
    						strtok(myArray, "\n");
   							fflush(stdin);
    						repeat = 0; 
    						while (myArray[j] != '\0')	{
  						if((myArray[j] >= 32 && myArray[j] <= 45) ||  (myArray[j]=='/')||(myArray[j] >= 58 && myArray[j] <= 126)){
  						printf("Invalid Input!");  
						system("miniproj.exe");}
						else{
							break;
						}
						}
    						for (i = 0; i < 15; ++i) {
    	 					if (strlen(myArray) > 10) {
        					printf("Invalid Input!");
							system("miniproj.exe");	
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
									
									if(lines != lineToUpdate){
										
										fprintf(tempFile, "%s", lineReader);
										
									}
									else if (lines==lineToUpdate){
										fprintf(tempFile, "%s", nArray);
									}
								}
								
								fclose(inventory);
								fclose(tempFile);
								remove("Inventory.csv");
								rename("temp.csv", "Inventory.csv");
								printf("Item %s successfully updated!", productID);
							
								
							} else if (confirmation =='N' || confirmation == 'n'){
							
								printf("Item %s was not updated", productID);
								system("miniproj.exe");
								
							} else{
								printf("You entered an invalid input!");
								system("miniproj.exe");
							}
						
						} else {
							printf("You entered an invalid input!");
							system("miniproj.exe");

						}
						
						fflush(stdin); // Reset the input buffer
						
					} while(confirmation != 'Y' && confirmation != 'y' && confirmation !='N' && confirmation != 'n');
					
					break;
				}else {
					
					lineToUpdate++;
				}

			}
			
			if(found == 0){
				printf("Item %d does not exist!", prodID);
				system("miniproj.exe");
			}
			
		} else {
			printf("You entered an invalid input!");
			system("miniproj.exe");
			fclose(inventory);
			fclose(tempFile);
		}
	
	} else{
		
		printf("You entered an invalid input!");
		system("miniproj.exe");
		fclose(inventory);
		fclose(tempFile);
	}
 
}

