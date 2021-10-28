#include <stdio.h>
#include <stdlib.h>

void viewItem(void) //still haven't edited/done mine -Da

//int main()
{
	  FILE *the_file = fopen("Inventory_ST.csv", "r");
	  int  ch;
		if (the_file == NULL){
			perror("Unable to open the file.\n");
			return;
		}

		char line[200];
		
		while (fgets(line, sizeof(line), the_file)){
			
			char *token;
			
			token = strtok(line, ",");
			
			while (token!= NULL){
				
				
				printf("%s, ", token);
				
				token = strtok (NULL, ",");
			}
			
			printf("\n");
			
		}
		//	scanf("%d", n);
			
		/* Flushes input buffer from the newline from scanf() */
		    while ( (ch = getchar()) != '\n' && ch != EOF) ;
		 
		    printf("\n\nPress ENTER to continue.\n");
		    while ( (ch = getchar()) != '\n' && ch != EOF);
} 
