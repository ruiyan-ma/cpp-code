#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char *value;
    struct Node *next;
};

typedef struct Node *List;

List new_list(void)
{
    return NULL;
}

List add_node(List list, char *string)
{
    List node = (List) malloc(sizeof(struct Node));
    node->value = (char*) malloc(strlen(string) + 1);
    strcpy(node->value, string);
    node->next = NULL;

    if (list == NULL)
    {
        return node;
    }
    else
    {
        List tail = list;
        while (tail->next)
        {
            tail = tail->next;
        }


        tail->next = node;
        return list;
    }
}

void print_list(List list)
{
    int i = 1;
    while (list != NULL)
    {
        printf("Node %d: %s\n", i, list->value);
        list = list->next;
        i += 1;
    }
}

void free_list(List list)
{
    while (list != NULL)
    {
        List next = list->next;
        free(list->value);
        free(list);
        list = next;
    }
}

int main()
{
    List list = new_list();
    list = add_node(list, "abc");
    list = add_node(list, "ma");
    list = add_node(list, "ruiyan");
    print_list(list);
    free_list(list);
    return 0;
}
