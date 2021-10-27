#include <stdio.h>
#include <stdlib.h>



void addItem(void)
{
	FILE* fp = fopen("inventorysample.csv", "a+");
	
    int id, quantity, ch, invcount;
    float price;
    char itemdesc[80], expirydate[80], temp;
    
    system("cls");
    
    /* Flushes input buffer from the newline from scanf() */
    while ( (ch = getchar()) != '\n' && ch != EOF) ;
    
    invcount = 0; 
    
    printf("ADD INVENTORY ITEM\n\nEnter New Product:\n");
    
	printf("Enter Product ID Number: ");
	if(scanf("%d%c", &id, &temp) != 2 || temp != '\n')
    	{ invcount = 1; goto invalid;}
	else
	{
		if(id < 0 || id > 99999) { invcount = 1; goto invalid;}
	}
    
	printf("Enter Product Name: ");
    scanf("%[^\n]%*c", itemdesc);
   
    printf("Enter Quantity: ");
    if(scanf("%d%c", &quantity, &temp) != 2 || temp != '\n')
    	{ invcount = 1; goto invalid;}
	else
	{
		if(quantity < 1) { invcount = 1; goto invalid; }
	}
    
	printf("Enter Expiration Date: ");
    scanf("%[^\n]%*c", expirydate);
    
	printf("Enter Product Price: ");
    if(scanf("%f%c", &price, &temp) != 2 || temp != '\n')
    	{ invcount = 1; goto invalid;}
	else
	{
		if(price < 0) { invcount = 1; goto invalid; }
	}
    
    //printf("\n\n%d, %s, %d, %s, %f", id, itemdesc, quantity, expirydate, price);  //redisplays inputs, used for testing
 	
 	fprintf(fp, "\"%d\",\"%s\",\"%d\",\"%s\",\"%f\"\n", id, itemdesc, quantity, expirydate, price);
 	printf("\nItem Recorded!");
 
 	fclose(fp);
	invalid:
		if(invcount == 1) { printf("\nInvalid Input!"); }
	
    /* Flushes input buffer from the newline from scanf() */
    while ( (ch = getchar()) != '\n' && ch != EOF) ;
 
    printf("\n\nPress ENTER to continue.\n");
    while ( (ch = getchar()) != '\n' && ch != EOF)
        ;
        
    return;
} 
