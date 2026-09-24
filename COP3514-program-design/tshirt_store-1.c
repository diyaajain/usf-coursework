/* Name: Diya Jain U81673988 */
/* This code is creating a databse for students organizations to store their t-shirts inventory. */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ORG_NAME_LEN 50
#define SIZE_LEN 3

struct tshirt 
{
	char org_name[ORG_NAME_LEN+1];
	char size[SIZE_LEN+1];
	double price;
	int quantity;
	struct tshirt *next;
};

struct tshirt * add_to_inventory(struct tshirt *inventory);
void search_by_organization(struct tshirt *inventory);
void search_by_size(struct tshirt *inventory);
void print_inventory(struct tshirt *inventory);
void clear_inventory(struct tshirt *inventory);
int read_line(char str[], int n);
void help();


int main() {
	char code;
	struct tshirt *inventory = NULL;
	help();
	printf("\n");

	for (;;) {
		printf("Enter operation code: ");
		scanf(" %c", &code);
		while(getchar() != '\n') 
			;
		switch (code) {
			case 'a':
				inventory = add_to_inventory(inventory);
				break;
			case 'h':
				help();
				break;
			case 'o':
				search_by_organization(inventory);
				break;
			case 's':
				search_by_size(inventory);
				break;
			case 'p':
				print_inventory(inventory);
				break;
			case 'q':
				clear_inventory(inventory);
				return 0;
			default:
				printf("Illegal operation code!\n");
		}
		printf("\n");
	}
}

void help() {
	printf("List of operation codes:\n");
	printf("\t'a' for adding a t-shirt to the inventory;\n");
	printf("\t'h' for help;\n");
	printf("\t'o' for searching t-shirts by organization;\n");
	printf("\t's' for searching t-shirts by size;\n");
	printf("\t'p' for printing the inventory;\n");
	printf("\t'q' for quit.\n");
}

struct tshirt * add_to_inventory(struct tshirt *inventory) 
{
	struct tshirt *a;
	char new_org_name[ORG_NAME_LEN + 1];
	char new_size[SIZE_LEN + 1];
	struct tshirt *new_node = malloc(sizeof(struct tshirt));
	printf("Enter your student organization name: ");
	read_line(new_org_name, ORG_NAME_LEN);
	printf("Enter the shirt size: ");
	scanf("%s", new_size);
	strcpy(new_node -> org_name, new_org_name);
	strcpy(new_node -> size, new_size);
	for (a = inventory; a != NULL; a = a -> next) 
	{
		if (strcmp (a -> org_name, new_org_name) == 0)
		{
			if (strcmp (a -> size, new_size) == 0) 
			{
				printf("T-shirt already exists in the inventory! \n");
				return inventory;
			}
		}
	}
	printf ("Enter the price: "); 
	scanf("%lf", &new_node -> price);
	printf("Enter the quantity: ");
	scanf("%d", &new_node -> quantity);
	new_node -> next = NULL;
	if (inventory == NULL) 
	{
		return new_node;
	}
	else
	{
	for (a = inventory; a != NULL; a = a -> next)
	{
		if(a -> next == NULL)
		{
			a -> next = new_node;
			break;
		}
	}
	}
	return inventory;
}

void search_by_organization(struct tshirt *inventory) 
{
	struct tshirt *a; /* searching by orgaization */
	int flag = 0;
	char new_org_name[ORG_NAME_LEN + 1];
	printf("Enter the organization name: ");
	read_line(new_org_name, ORG_NAME_LEN);
	printf("\n");
	a = inventory;
	while(a != NULL) /* runs till inventory doesnt reach the end */
	{
		if (strcmp(a -> org_name, new_org_name) == 0)
		{
			if (flag == 0)
			{
				flag = 1;
				printf("|----------------------------------------------------|-----|-------|------|\n");
				printf("| Student organization                               | Sz. | Price | Qty. |\n");
				printf("|----------------------------------------------------|-----|-------|------|\n");
			}
			printf("| %-50s | %-3s | %5.2f | %4d |\n", a-> org_name, a -> size, a -> price, a -> quantity);
		}
		a = a -> next;
	}
	if (flag != 0)
	{
		printf("|----------------------------------------------------|-----|-------|------|\n");
	}
	else
	{
		printf("No t-shirt found! \n");
	}
}

void search_by_size(struct tshirt *inventory) 
{
	struct tshirt *a; /* searching by size in the inventory */
	int flag = 0;
	char new_size[SIZE_LEN + 1];
	printf("Enter t-shirt size: ");
	scanf("%s", new_size);
	printf("\n");
	a = inventory;
	while(a != NULL)
	{
		if(strcmp(a -> size, new_size) == 0)
		{
			if (flag == 0)
			{
				flag = 1;
				printf("|----------------------------------------------------|-----|-------|------|\n");
				printf("| Student organization                               | Sz. | Price | Qty. |\n");
				printf("|----------------------------------------------------|-----|-------|------|\n");
			}
			printf("| %-50s | %-3s | %5.2f | %4d |\n", a -> org_name, a -> size, a -> price, a -> quantity);
		}
		a = a -> next;
	}
	if(flag != 0) 
	{
		printf("|----------------------------------------------------|-----|-------|------|\n");
	}
	else
	{
		printf("No t-shirt found! \n");
	}
}

void print_inventory(struct tshirt *inventory) 
{
	struct tshirt *a; /* printing the inventory */
	int flag = 0;
	a = inventory;
	while (a != NULL)
	{
		if(flag == 0)
		{
		printf("\n");
		printf("|----------------------------------------------------|-----|-------|------|\n");
		printf("| Student organization                               | Sz. | Price | Qty. |\n");
		printf("|----------------------------------------------------|-----|-------|------|\n");
		}
		flag = 1;
		printf("| %-50s | %-3s | %5.2f | %4d |\n", a-> org_name, a -> size, a -> price, a -> quantity);
		a= a -> next;
	}
	if(flag != 0)
	{
		printf("|----------------------------------------------------|-----|-------|------|\n");
	}
	else
	{
		printf("No t-shirt found! \n");		
	}
}


void clear_inventory(struct tshirt *inventory) 
{
	struct tshirt *p;
	while(inventory != NULL)
	{
		p = inventory;
		inventory = inventory -> next;
		free(p);

	}

}

int read_line(char str[], int n) {
	int ch, i=0;

	while (isspace(ch = getchar()))
		;
	str[i++] = ch;
	while ((ch = getchar()) != '\n') {
		if (i < n)
			str[i++] = ch;    
	}
	str[i] = '\0';
	return i;
}

