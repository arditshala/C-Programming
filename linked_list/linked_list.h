#ifndef LIST
#define LIST

#include <stdlib.h>

struct list {
    int info;
    struct list *next;
};

struct list* push_front(struct list *my_list, int value);

struct list* push_back(struct list* my_list, int value);

void print_elements(struct list* my_list);

struct list *dispose_list(struct list* my_list);

void dispose_listtt(struct list* my_list);

#endif // LIST
