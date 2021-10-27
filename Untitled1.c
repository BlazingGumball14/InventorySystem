#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 0
#define false 1

struct product{
	char id[10]; char name[20]; int quantity; char expiry[20]; float price;
};
struct product prod[30];
int count = 0;
FILE *f;
int writefile(){
	int i;
	f=fopen("inventory.csv", "w");
	f=fopen("inventory.csv", "a");
	if (f==NULL)
	return -1;
	fprintf(f, "%d\n", count);
	for (i=0; i<count; ++i){
		fputs(prod[i].id, f);
		fprintf(f, "\n");
		fputs(prod[i].name, f);
		fprintf(f, "\n");
		fprintf(f, "%d\n", prod[i].quantity);	
		fputs(prod[i].expiry, f);
		fprintf(f, "\n");
		fprintf(f, "%f\n", prod[i].price);
	
		
	}
	fclose(f);
	return 0;
}
int readFile(){
	int n =0;
	int i;
	f=fopen("inventory.csv", "r");
	if (f==NULL)
	return -1;
	fscanf(f, "%d\n", &n);
	for (i = 0; i < n; ++i){
		fgets(prod[i].id, 10, f);
		
		prod[i].id[strlen(prod[i].id)-1] = 0;
		fgets(prod[i].name, 20, f);
		
		prod[i].name[strlen(prod[i].name)-1] = 0;
		
		fscanf(f, "%d", &prod[i].quantity);
		fgets(prod[i].expiry, 20, f);
		
		prod[i].expiry[strlen(prod[i].expiry)-1] = 0;
		fscanf(f, "%f", &prod[i].price);
	}
	fclose(f);
	return n;
}
void deleteprod(){
	count=readFile();
	char id[10];
	int i, j;
	int z=false;
	printf("Enter the id that you want to delete: ");
	fflush(stdin);
	gets(id);
	
	for (i=0;i<count;i++){
		z=true;
		if(strcmp(prod[i].id,id)==0){
			for(j=i; j<(count-1);j++){
				prod[j]=prod[j+1];
			}
			count--;
		}
	}
	
	if(z==false){
		printf("Cant find product id: %s .", id);
	}
	writefile();
}
void addProd(){
	printf("Enter new products\n");
	readFile();
	if (count>0){
		count=readFile();
		
		IDChecker(0, count);
	}
	
	else{
		printf("\nProduct ID number: ");
		fflush(stdin);
		gets(prod[count].id);
	}
	printf("Product Name: ");
	gets(prod[count].name);
	
	printf("Quantity of the product: ");
	scanf("%d", &prod[count].quantity);
	printf("Expiry date of the product: ");
	scanf("%s",&prod[count].expiry);
	printf("Price of the product: ");
	scanf("%f",&prod[count].price);
	++count;
	writefile();	
}
int IDChecker(int i, int j){
	count=readFile();
	printf("Product ID: ");
	fflush(stdin);
	gets(prod[count].id);
	if (strcmp(prod[i].id, prod[j].id)==0){
		printf("ID number is already taken!");
		return IDChecker (i++, j--);
	}
}
void editProd(){
	char id[10];
	int test;
	int choice;
	int i;
	printf("Edit a product");
	printf("\nEnter the ID of the product you want to edit: ");
	fflush(stdin);
	gets(id);
	test=checkID(id);
	if (test==0){
		printf("The id num %s is not found", id);
	}
	else{
		readFile();
		{
			for (i=0;i<count;i++){
				if(strcmp(id,prod[i].id)!=0)
				writefile();
				else{
					printf("\n1. Update product ID number?");
					printf("\n1. Update product name?");
					printf("\n1. Update product quantity?");
					printf("\n1. Update product expiry date?");
					printf("\n1. Update product price?");
					printf("\nEnter your choice: ");
					fflush(stdin);
					scanf("%d", &choice);
					switch (choice){
						case 1:
							printf("Enter new ID: ");
							fflush(stdin);
							gets(prod[i].id);
							break;
						case 2:
							printf("Enter New Name: ");
							fflush(stdin);
							gets(prod[i].name);
							break;
						case 3:
							printf("Enter new quantity: ");
							scanf("%d", &prod[i].quantity);
							break;
						case 4:
							printf("Enter new expiry date: ");
							fflush(stdin);
							gets(prod[i].expiry);
							break;
						case 5:
							printf("Enter new price: ");
							scanf("%f", &prod[i].quantity);
							break;
							
						default:
							printf("Invalid Selection");
							break;	
					}
					writefile();
				}
			}
		}
		fclose(f);
		f=fopen("inventory.csv","r");
		readFile();
		{
			writefile();
		}
		fclose(f);
		printf("RECORD UPDATED");
	}
}

int checkID(char id[]){
	int i;
	count=readFile();
	readFile();
	for (i=0;i<count;i++){
		if(strcmp(id,prod[i].id)!=0){
			fclose(f);
		}
		return 1;
	}
	fclose(f);
	return 0;	
}

void displayprod(){
	int i;
	count= readFile();
	if (count < 0)
	puts("cannot open file");
	printf("INVENTORY");
	for (i=0;i<count;i++){
		printf("%d   -10%s   %-8d    %-5s    %-6.2f\n", prod[i].id,prod[i].name,prod[i].quantity,prod[i].expiry,prod[i].price);
	}
}
int main(){
	int choice;
	count = readFile();
	if (count < 0)
	printf("Cannot locate file\n");
	do{
		printf("\n");
		printf("Product Inventory\n");
		printf("\n\nPress: \n");
		printf("\n1. Input a new record.\n");
		printf("\n2. Edit a record.\n");
		printf("\n3. Delete record.\n");
		printf("\n4. Display a new record.\n");
		printf("\n5. Exit\n");
		printf("\nChoice: \n");
		scanf("%d", &choice);
		switch(choice){
			case 1: 
				addProd();
				break;
			case 2:
				editProd();
				break;
			case 3:
				deleteprod();
				break;
			case 4:
				displayprod();
				break;
			case 5:
				exit(1);
				break;
			default:
				printf("Your choice is wrong please try again");
				break;
		}		
	}while(choice!=5);
	printf("Thank you");
}
