/* Name: Diya Jain U81673988 */
/* This contains all the main functions related to the list for the tshirts. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "tshirt.h"
#include "readline.h"

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
                inventory = new_node;
		return new_node;
	}
        else
        {
            struct tshirt *prev = NULL;
            struct tshirt *cur = inventory;
            while((cur != NULL) && (strcmp(cur -> org_name, new_node -> org_name) <= 0))
            {
				prev = cur;
                cur = cur -> next;
            }
			if((cur != NULL) && (strcmp(cur -> org_name, new_node -> org_name) == 0))
			{
            	if(strcmp(cur -> size, new_node -> size) < 0)
            	{
                	new_node->next = cur->next;
					cur->next = new_node;
            	}
				else
				{
					if(prev==NULL)
					{
						new_node->next = cur;
						inventory = new_node;
					}
					else
					{
						new_node->next = cur;
						prev->next = new_node;
					}
				}
			}
			else
			{
				new_node->next = cur;
            	if(prev == NULL)
            	{
                	return new_node;
            	}
            	else
            	{
                	prev -> next = new_node;
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