#include <stdio.h>
#include <stdlib.h>

void addItem(void) //still haven't edited/done mine -Da
{
    int ch;
    int id, quantity;
    float price;
    char itemdesc[80], expirydate[80], temp;
    
    /* Flushes input buffer from the newline from scanf() */
    while ( (ch = getchar()) != '\n' && ch != EOF) ;
    
    printf("Enter Product ID Number: ");
    scanf("%d", &id);
    printf("Enter Product Name: ");
    scanf("%c", &temp); //temp statement to clear buffer
    scanf("%[^\n]%*c", itemdesc);
    printf("Enter Quantity: ");
    scanf("%d", &quantity);
    printf("Enter Expiration Date: ");
    scanf("%c", &temp); //temp statement to clear buffer
    scanf("%[^\n]%*c", expirydate);
    printf("Enter Product Price: ");
    scanf("%f", &price);
    
    printf("\n\n%d %s %d %s %f", id, itemdesc, quantity, expirydate, price);
 
 
    /* Flushes input buffer from the newline from scanf() */
    while ( (ch = getchar()) != '\n' && ch != EOF) ;
 
    printf("\n\nPress ENTER to continue.\n");
    while ( (ch = getchar()) != '\n' && ch != EOF)
        ;
 
    return;
} 
