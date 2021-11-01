#include <stdio.h>
#include <stdlib.h>

void viewItem(void) //features made by caloy

//int main()
{
		printf("\t\t\t *****************************************\n");	
		printf("\t\t\t This is the Page 1 of the Inventory List\n");
		printf("\t\t\t *****************************************\n");
			
	  FILE *the_file = fopen("Inventory.csv", "r");
	  int  ch;
		if (the_file == NULL){
			perror("Unable to open the file.\n"); 
			return;
		}

		char line[200];
		//Newly added code
		int limit = 50;
		int limit2 = 100;
		int limit3 = 150;
		int limit4 = 200;
		int limitCounter = 0;
		char selection[1];
		char selection2[1];
		char selection3[1];
		char selection4[1];
		 
	
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
	    	while (fgets(line, sizeof(line), the_file) && limitCounter < limit2){

			char *token;
						
			token = strtok(line, ",");
	
			limitCounter++; //Displays loop count
			printf("%d: ", limitCounter);		
			
			if(limitCounter > 50) {
			
				while (token!= NULL){				
							
					printf("%s, ", token);
					token = strtok (NULL, ",");
		
				}
			}	
			
		}	
		}  
		
	  	printf("\n\nPress any key to view more items: ");
	    scanf("%s", selection2);
	    printf("\t\t\t *****************************************\n");	
	    printf("\t\t\t This is the Page 3 of the Inventory List\n");
		printf("\t\t\t *****************************************");	
	    printf("\n");	
	    
	    //Prints remaining data
	    if(selection != ""){ //Display remaining data when button is pressed
	    	while (fgets(line, sizeof(line), the_file) && limitCounter < limit3){

			char *token;
						
			token = strtok(line, ",");
	
			limitCounter++; //Displays loop count
			printf("%d: ", limitCounter);		
			
			if(limitCounter > 100){
			
				while (token!= NULL){				
							
					printf("%s, ", token);
					token = strtok (NULL, ",");
		
				}
			}	
			
		}	
		}
		
		
		printf("\n\nPress any key to view more items: ");
	    scanf("%s", selection3);
	    printf("\t\t\t *****************************************\n");	
	    printf("\t\t\t This is the Page 4 of the Inventory List\n");
		printf("\t\t\t *****************************************");	
	    printf("\n");	
	    
	    //Prints remaining data
	    if(selection != ""){ //Display remaining data when button is pressed
	    	while (fgets(line, sizeof(line), the_file) && limitCounter < limit4){

			char *token;
						
			token = strtok(line, ",");
	
			limitCounter++; //Displays loop count
			printf("%d: ", limitCounter);		
			
			if(limitCounter > 150){
			
				while (token!= NULL){				
							
					printf("%s, ", token);
					token = strtok (NULL, ",");
		
				}
			}	
			
		}	
		}
		
		printf("\n\nPress any key to view more items: ");
	    scanf("%s", selection4);
	    printf("\t\t\t *****************************************\n");	
	    printf("\t\t\t This is the Page 5 of the Inventory List\n");
		printf("\t\t\t *****************************************");	
	    printf("\n");	
	    
	    //Prints remaining data
	    if(selection != ""){ //Display remaining data when button is pressed
	    	while (fgets(line, sizeof(line), the_file)){

			char *token;
						
			token = strtok(line, ",");
	
			limitCounter++; //Displays loop count
			printf("%d: ", limitCounter);		
			
			if(limitCounter > 150){
			
				while (token!= NULL){				
							
					printf("%s, ", token);
					token = strtok (NULL, ",");
		
				}
			}	
			
		}	
		}
		
		/* Flushes input buffer from the newline from scanf() */
	    while ( (ch = getchar()) != '\n' && ch != EOF) ;
	 	
		printf("\n\nPress any key to view more items: ");
		
	    while ( (ch = getchar()) != '\n' && ch != EOF);
		    
	    
} 

