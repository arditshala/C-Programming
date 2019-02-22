#include <stdio.h>
#include <stdlib.h>

struct list {
    int info;
    struct list *next;
};

struct list* push_front(struct list *my_list, int value)
{
    struct list *newel;
    newel = (struct list*) malloc(sizeof(struct list));
    if (newel == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }
    newel->info = value;
    newel->next = my_list;
    return newel;
}


/* Like the previous one, but inserts at the end */
struct list* push_back(struct list* my_list, int value)
{
	struct list *cursor, *newel;

	cursor = my_list;
	newel = (struct list*) malloc(sizeof(struct list));
	if (newel == NULL) {
		printf("Error allocating memory\n");
		exit(1);
	}
	newel->info = value;
	newel->next = NULL;
	if (my_list == NULL)
		return newel;
	while (cursor->next != NULL)
      cursor = cursor->next;
  cursor->next = newel;
  return my_list;
}



void print_elements(struct list* my_list)
{
	while (my_list != NULL) {
		printf("%d ", my_list->info);
		my_list = my_list->next;
	}
	printf("\n");
}

struct list *dispose_list(struct list* my_list)
{
   struct list *removedList;
   struct list *returnlist;
   if (my_list == NULL)
   {
        return 0;
   }else
   {
       removedList = my_list->next;
        my_list = removedList;
        returnlist = my_list;
   }


   return returnlist;
}


void dispose_listtt(struct list* my_list)
{
   struct list *nextelem;
   while (my_list != NULL) {
      nextelem = my_list->next;
      free(my_list);
      my_list = nextelem;
   }
}

int len_list(struct list* my_list)
{
    int count = 0;
    while(my_list!=NULL)
    {
        count++;
        my_list = my_list->next;
    }
    return count;

}

struct list* add_elem (struct list* my_list, int x, int n)
{
    struct list *newel;
    newel = (struct list*) malloc(sizeof(struct list));
    if (newel == NULL)
    {
        printf("Error allocating memory\n");
        exit(1);
    }
    struct list *cursor = my_list;

    if (x == 0)
    {
        my_list = push_front(my_list, n);
        return my_list;
    }
    else if (x < 0 || x > len_list(my_list))
    {
        printf("Invalid position!\n");
        return my_list;
    }
    else
    {
    while(x!=1)
    {
        cursor = cursor->next;
        x--;
    }
    newel->next = cursor->next;
    cursor->next = newel;
    newel->info = n;
    }
    return my_list;
}

struct list* rev(struct list* my_list)
{
    //struct list *left, *current, *right;
    struct list* rv = 0;
    while (my_list)
    {
        struct list* next = my_list->next;
        my_list->next = rv;
        rv = my_list;
        my_list = next;
    }
    return rv;

}

int main()
{
    int read, inser, num1, num2;
    struct list *new_list = NULL;
    char op;

    do
    {
        scanf("%c", &op); //scans the character
        switch(op)
        {
            case 'a': { //the case if the input is 'a'
               scanf("%d", &read);
               new_list = push_back(new_list, read);
            }break;
            case 'b': { //the case if the input is 'b'
               scanf("%d", &inser);
               new_list = push_front(new_list, inser);
            }break;
            case 'r': { //the case if the input is 'r'
               new_list = dispose_list(new_list);
            }break;
            case 'p': { //the case if the input is 'p'
               print_elements(new_list);
            }break;
            case 'R': {
                new_list = rev(new_list);
            }break;
            case 'i': {
                scanf("%d", &num1);
                scanf("%d", &num2);
                new_list = add_elem(new_list, num1, num2);
            }
        }
    }while(op != 'q'); //this will iterate for as long as the char is not 'q'

    dispose_listtt(new_list); //now destroy the whole list because we have our result

    return 0;
