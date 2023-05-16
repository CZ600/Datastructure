#include <stdio.h>
#include <stdlib.h>

typedef struct char_node {
    char data;
    struct char_node* next;
} char_node;

typedef struct char_string {
    char_node* head;
    char_node* tail;
    int length;
} lstring;

void initstring(lstring* s)
{
    s->head = NULL;
    s->tail = NULL;
    s->length = 0;
}

void stringassign(lstring* s, char a[], int n)
{
    char_node* p;
    int i;
    p = s->head;

    for (i = 0; i < n; i++) {
        p = (char_node*)malloc(sizeof(char_node));
        p->data = a[i];
        if (s->head == NULL) {
            s->head = p;
            s->tail = s->head;
            s->length++;
        }
        else {
            s->head->next = p;
            s->head = p;
            s->length++;
        }
    }
    s->head->next = NULL;
}

void destroynode(char_node* p)
{
    if (p != NULL) {
        destroynode(p->next);
        free(p);
    }
}

void destroystring(lstring* s)
{
    destroynode(s->head);
    s->head = NULL;
    s->tail = NULL;
    s->length = 0;
}

int index(lstring* s, lstring* t)
{
    char_node* p = s->head;
    char_node* q = t->head;
    char_node* r = NULL;

    while (p != NULL && q != NULL) {
        if (p->data == q->data) {
            if (r == NULL) {
                r = p;
            }
            p = p->next;
            q = q->next;
        }
        else {
            r = NULL;
            p = p->next;
            q = t->head;
        }
    }

    if (q == NULL) {
        return s->length - r->data + 1 - t->length;
    }
    else {
        return -1;
    }
}

int main()
{
    lstring main_str, model_str;
    char main_arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    char model_arr[] = { 'd', 'e' };

    initstring(&main_str);
    initstring(&model_str);

    stringassign(&main_str, main_arr, 6);
    stringassign(&model_str, model_arr, 2);

    int pos = index(&main_str, &model_str);

    if (pos != -1) {
        printf("Match found at position %d\n", pos);
    }
    else {
        printf("Match not found\n");
    }

    destroystring(&main_str);
    destroystring(&model_str);

    return 0;
}
