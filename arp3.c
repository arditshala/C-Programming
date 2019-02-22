#include <stdio.h>
#include <stdlib.h>

struct list
{
    struct list *prev;
    char info;
    struct list *next;
};

struct list* push_front(struct list *my_list, char value )
{
        struct list *newel;
        newel = (struct list*) malloc(sizeof(struct list));
        if (newel == NULL)
        {
            printf("Error allocating memory\n");
            exit(1);
        }
        newel->info = value;
        newel->next = my_list;
        newel -> prev = NULL;
        if (my_list!=NULL)
        {
            my_list -> prev = newel;
        }
        return newel;

}

struct list* remove_elem(struct list *my_list, char value)
{
    int removed_something = 0;

    struct list *current = my_list, *tofree;

    while(current)
    {
        if(current->info == value)
        {
            if(current->next)
                current->next->prev = current->prev;

            if(current->prev)
                current->prev->next = current->next;
            else
                my_list = current->next; // update head of list

            tofree = current;
            current = current->next;
            free(tofree);
            removed_something = 1;
        } else
            current = current->next;
    }

    if(removed_something == 0)
        printf("The element is not in the list!\n");
        //fprintf(stderr, "Node with value '%c' not found\n", value);

    return my_list;
}

void print(struct list *my_list)
{
	struct list *ptr;
	ptr = my_list;
	while (ptr != NULL)
	{
		printf("%c ", ptr->info);
		ptr = ptr->next;
	}
	printf("\n");
}

void rev(struct list *my_list)
{
	struct list *ptr;
	ptr = my_list;
	if (ptr!=NULL)
	{
		while (ptr -> next != NULL)
		ptr = ptr -> next;
		while (ptr != NULL)
		{
            printf("%c ",ptr -> info);
			ptr = ptr -> prev;
		}
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


char readChar()
{
    char c;
    do
    {
        scanf("%c", &c);
    }while (c == ' ' || c == '\n');
    return c;
}

int main()
{
    struct list* new_list = NULL;
    int nr;
    char ch;
    while (nr != 5)
    {
        scanf("%d", &nr);
        switch (nr)
        {
            case 1:
                ch = readChar();
                new_list = push_front(new_list, ch);
                break;
            case 2:
                ch = readChar();
                new_list = remove_elem(new_list, ch);
                break;

            case 3:
                print(new_list);
                //printf("\n");
                break;

            case 4:
                rev(new_list);
                //printf("\n");
                break;

            case 5:

                exit(1);
                break;
        }
    }
    dispose_list(new_list);

    return 0;
}
