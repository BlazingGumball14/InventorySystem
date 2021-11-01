#include <stdio.h>
#include <stdlib.h>

void viewItem(void) //features made by caloy

//int main()
{
		printf("\t\t\t *****************************************\n");	
		printf("\t\t\t This is the Page 1 of the Inventory List\n");
		printf("\t\t\t *****************************************\n");
			
	  FILE *the_file = fopen("Inventory_ST_NoBOM.csv", "r");
	  int  ch;
		if (the_file == NULL){
			perror("Unable to open the file.\n"); 
			return;
		}

		char line[200];
		//Newly added code
		int limit = 50;
		int limitCounter = 0;
		char selection[1]; 
	
		//Prints limited data
		while (fgets(line, sizeof(line), the_file) && limitCounter < limit){ 

			char *token;
						
			token = strtok(line, ",");
	
			limitCounter++;
			printf("%d: ", limitCounter); //Displays loop count
			
			while (token!= NULL){				
						
				printf("%s, ", token);
				token = strtok (NULL, ",");
	
			}		
			
		}	
				
	    printf("\n\nPress any key to view more items: ");
	    scanf("%s", selection);
	    printf("\t\t\t *****************************************\n");	
	    printf("\t\t\t This is the Page 2 of the Inventory List\n");
		printf("\t\t\t *****************************************");	
	    printf("\n");	
	    
	    //Prints remaining data
	    if(selection != ""){ //Display remaining data when button is pressed
	    	while (fgets(line, sizeof(line), the_file)){

			char *token;
						
			token = strtok(line, ",");
	
			limitCounter++; //Displays loop count
			printf("%d: ", limitCounter);		
			
			if(limitCounter > 50){
			
				while (token!= NULL){				
							
					printf("%s, ", token);
					token = strtok (NULL, ",");
		
				}
			}	
			
		}	
		}
		
		
		/* Flushes input buffer from the newline from scanf() */
	    while ( (ch = getchar()) != '\n' && ch != EOF) ;
	 

	    while ( (ch = getchar()) != '\n' && ch != EOF);
		    
	    
} 

