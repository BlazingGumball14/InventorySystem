#include <stdio.h>
#include <stdlib.h>



void addItem(void) //still haven't edited/done mine -Da
{
	FILE* fp = fopen("inventorysample.csv", "a+");
	
    //int ch;
    int id, quantity, ch, invcount;
    //unsigned char quantity, ch, invcount;
    float price;
    char itemdesc[80], expirydate[80], temp;
    
    system("cls");
    
    /* Flushes input buffer from the newline from scanf() */
    while ( (ch = getchar()) != '\n' && ch != EOF) ;
    
    invcount = 0; 
    
	printf("Enter Product ID Number: ");
	if(scanf("%d%c", &id, &temp) != 2 || temp != '\n')
    	{ invcount = 1; goto invalid;}
	else
	{
    	//scanf("%d", &id); 
		if(id < 0 || id > 99999) { invcount = 1; goto invalid;}
	}
    
	printf("Enter Product Name: ");
    //scanf("%c", &temp); //temp statement to clear buffer
    scanf("%[^\n]%*c", itemdesc);
   
    printf("Enter Quantity: ");
    if(scanf("%d%c", &quantity, &temp) != 2 || temp != '\n')
    	{ invcount = 1; goto invalid;}
	else
	{
    	//scanf("%d", &quantity);
		if(quantity < 1) { invcount = 1; goto invalid; }
	}
    
	printf("Enter Expiration Date: ");
    //scanf("%c", &temp); //temp statement to clear buffer
    scanf("%[^\n]%*c", expirydate);
    
	printf("Enter Product Price: ");
    scanf("%f", &price);
    
    printf("\n\n%d, %s, %d, %s, %f", id, itemdesc, quantity, expirydate, price);
 	
 	fprintf(fp, "%d,%s,%d,%s,%f\n", id, itemdesc, quantity, expirydate, price);
 	printf("\n\nItem recorded!");
 
 	fclose(fp);
 	//printf("\n\n%u", id);	//tester line
	invalid:
		if(invcount == 1) { printf("\nInvalid Input!"); }
	
    /* Flushes input buffer from the newline from scanf() */
    while ( (ch = getchar()) != '\n' && ch != EOF) ;
 
    printf("\n\nPress ENTER to continue.\n");
    while ( (ch = getchar()) != '\n' && ch != EOF)
        ;
        
    return;
} 

/*this is a recycle bin


    //id = enterID();

int enterID()
{
	unsigned int loID;
	scanf("%u", &loID);
	printf("%u", loID);
	return loID;
}

*/
