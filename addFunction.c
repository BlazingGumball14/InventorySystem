#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addItem(void)
{
	FILE* fp = fopen("inventorysample.csv", "a+");
	
    int id, quantity, ch, invcount, idlength, i;
    float price;
    char itemdesc[41], expirydate[11], temp, stringID[5], readcsv[80], idfromcsv[5];
    
    system("cls");
    
    /* Flushes input buffer from the newline from scanf() */
    while ( (ch = getchar()) != '\n' && ch != EOF) ;
    
    invcount = 0; 
    
    printf("ADD INVENTORY ITEM\n\nEnter New Product:\n");
    
	printf("Enter Product ID Number: ");
	if(scanf("%d%c", &id, &temp) != 2 || temp != '\n')	//checks if Product ID is an int
    	{ invcount = 1; goto invalid;}
	else
	{
		if(id < 0 || id > 99999) { invcount = 1; goto invalid; } //checks if Product ID is not less than 0 or greater than 99999
		else
		{
			sprintf(stringID, "%d", id); //converts int id into string and store to stringID
			//fflush(stdin); // Reset the input buffer
			//printf("\n%s", stringID); //tester line
			idlength = strlen(stringID); //gets length of stringID
			//printf("\n%d", idlength);	//tester line
			//if(idlength == 4) // //checks if the ID is not a 5 digit number
			//else { invcount = 1; goto invalid; }
			
			switch(idlength)
			{
				case 5:
					break;
				case 4:
					for(i = 4; i >= 1; i--)
						stringID[i] = stringID[i-1];
					
					stringID[0] = '0';
					//idlength = strlen(stringID); //gets length of stringID	//tester line
					break;
				case 3:
					for(i = 4; i >= 2; i--)
						stringID[i] = stringID[i-2];
					
					stringID[0] = '0'; stringID[1] = '0'; 
					//idlength = strlen(stringID); //gets length of stringID	//tester line
					break;
				case 2:
					for(i = 4; i >= 3; i--)
						stringID[i] = stringID[i-3];
					
					stringID[0] = '0'; stringID[1] = '0'; stringID[2] = '0'; 
					//idlength = strlen(stringID); //gets length of stringID	//tester line
					break;
				case 1:
					stringID[4] = stringID[0];
					stringID[0] = '0'; stringID[1] = '0'; stringID[2] = '0'; stringID[3] = '0'; 
					//idlength = strlen(stringID); //gets length of stringID	//tester line
					break;
				default: { printf("\nUnexpected Error"); invcount = 1; goto invalid; }
			}
			//printf("\n%s", stringID); //tester line
			//printf("\n%d\n", idlength);	//tester line
			
			while(!feof(fp))
			{
				fgets(readcsv, 80, fp); // read each line in the inventory
				//printf("\nThis is read csv: %s", readcsv); //tester line
				strncpy(idfromcsv, readcsv+1,5); // Copy the 5 digit Product ID of the current line
				//printf("\nThis is idfromcsv %s", idfromcsv); //tester line
				if(strcmp(idfromcsv, stringID) == 0) { invcount = 2; goto duplicate; } //compare id from a line in csv to id inputted
				//printf("%d", strcmp(idfromcsv, stringID)); //tester line
			}
		}
	}
    
	printf("Enter Product Name: ");
    scanf("%[^\n]%*c", itemdesc);	//scanf for string with spaces
    itemdesc[40] = '\0';
    
   
    printf("Enter Quantity: ");
    if(scanf("%d%c", &quantity, &temp) != 2 || temp != '\n')
    	{ invcount = 1; goto invalid;}
	else
	{
		if(quantity < 1) { invcount = 1; goto invalid; }
	}
    
	printf("Enter Expiration Date: ");
	scanf("%s", &expirydate);
    //scanf("%[^\n]%*c", expirydate);
    expirydate[10] = '\0'; //cuts the string to make it less than 11
    
	printf("Enter Product Price: ");
    if(scanf("%f%c", &price, &temp) != 2 || temp != '\n')
    	{ invcount = 1; goto invalid;}
	else
	{
		if(price < 0) { invcount = 1; goto invalid; }
	}
    
    //printf("\n\n%d, %s, %d, %s, %f", id, itemdesc, quantity, expirydate, price);  //redisplays inputs, used for testing
 	
 	fprintf(fp, "\"%s\",\"%s\",\"%d\",\"%s\",\"%f\"\n", stringID, itemdesc, quantity, expirydate, price);
 	printf("\nItem Recorded!");
 
 	fclose(fp);
	invalid:
		if(invcount == 1) { printf("\nInvalid Input!"); }
		
	duplicate:
		if(invcount == 2) { printf("\nID Already Exists!"); }
		
    /* Flushes input buffer from the newline from scanf() */
    while ( (ch = getchar()) != '\n' && ch != EOF) ;
 
    printf("\n\nPress ENTER to continue.\n");
    while ( (ch = getchar()) != '\n' && ch != EOF)
        ;
        
    return;
} 
