#include <stdio.h>
#include <stdlib.h>



//
//void viewItem(void) 

int main()
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
				int count = 0;
				int i;
					for( i=0; i < 50; i++ )	{
			
						printf("%s, ", token);
						
						token = strtok (NULL, ",");
						count++;

							/* Page break after every fifty repetition */
							if( count == 50 )
							{
								/* Reset counter, print 2 newlines */
								count = 0;   
								printf("\n\n");
							}

					}
		}
		//	scanf("%d", n);
			
		/* Flushes input buffer from the newline from scanf() */
		    while ( (ch = getchar()) != '\n' && ch != EOF) ;
		 
		    printf("\n\nPress ENTER to continue.\n");
		    while ( (ch = getchar()) != '\n' && ch != EOF);
} 
}



