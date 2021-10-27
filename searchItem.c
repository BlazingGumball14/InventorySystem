#include <stdio.h>
#include <stdlib.h>

void searchItem();

int main()
{
	searchItem();
};

void searchItem()
{
	// creating pointer type
	FILE *ptr;
	char array[255];
	int productID, i, inputProductID;
	
	printf("Enter Product ID to search: ");
	scanf("%d", &inputProductID );
	//opening file
	ptr = fopen("inventory.txt", "r"); //opening the file
	
	for (i =0; i != EOF; i++)
	{
		//reading file
		fscanf(ptr, "%s", array);
		
		//converting ID string to integer;
		productID = atoi(array);
		
		//check if productID is equal to the input of user
		if (productID = inputProductID)
		{
			fgets(array, 255, (FILE*)ptr); //fgetsused to read the whole line
			printf("%d %s", productID, array);
			break;
		}
	}

	return 0;
}
