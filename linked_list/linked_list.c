#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"


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
