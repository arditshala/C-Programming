#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main()
{
    int read, inser;
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
        }
    }while(op != 'q'); //this will iterate for as long as the char is not 'q'

    dispose_listtt(new_list); //now destroy the whole list because we have our result

    return 0;
}
