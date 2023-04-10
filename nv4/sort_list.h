#ifndef SORT_LIST_H
#define SORT_LIST_H
#include <stdlib.h>

typedef struct    s_list
{
    struct s_list   *next;
    int             *data;
}                 t_list;

#endif