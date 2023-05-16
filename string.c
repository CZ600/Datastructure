#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#define MAXSIZE 255

typedef struct char_node
{
	char data;
	struct char_node* next;
	
}char_node;

typedef struct char_string
{
	char_node* tail, * head;
	int length;
}lstring;

void initstring(lstring* s)
{
	s->tail = NULL;
	s->head = NULL;
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

int normal_index(lstring main, lstring model)
{
	int i, j, flag = 0;
	lstring s, p;
	s = main;
	p = model;
	if (main.tail == NULL || model.tail == NULL)
	{
		return -1;
	}
	else
	{
		for (i = 0; i < main.length; i++)
		{
			for (j = 0; j < model.length; j++)
			{
				if (s.tail->data = p.tail->data)
				{
					if (s.tail->next == NULL || p.tail->next == NULL)
					{
						break;
					}
					else
					{
						s.tail = s.tail->next;
						p.tail = p.tail->next;
						flag = 1;
					}
					
					
				}
				else
				{
					s.tail = main.tail;
					p.tail = model.tail;
					flag = 0;
					break;
				}
			}
		}
		if (flag)
		{
			return i;
		}
		else
		{
			return -1;
		}
	}
}

void getNext(lstring s, int* next[])
{
	int k = -1, j = 0;
	next[0] = -1;
	
	while (s.tail->next!=NULL && s.tail->next->next != NULL)
	{
		if (k == -1 || s.tail->next->data == s.tail->next->next->data)
		{
			k++;
			j++;
			next[j] = k;
			s.tail = s.tail->next;
		}
		else
		{
			k = next[k];
			s.tail = s.tail->next;
		}
	}
}

int KMP(lstring main, lstring model)
{
	int i = 0, j = 0, flag = 0;
	int len_main = main.length;
	int len_model = model.length;
	int* next = (int*)malloc(sizeof(int) * (model.length + 1));
	getNext(model, next);

	while (main.tail->next != NULL && model.tail->next != NULL)
	{
		if (j == -1 || main.tail->data == model.tail->data)
		{
			main.tail = main.tail->next;
			model.tail = model.tail->next;
			flag = 1;
			i++;
			j++;
		}
		else
		{
			j = next[j];
			model.tail = model.tail->next;
		}
		if (model.tail->next == NULL && j == model.length)
		{
			free(next);
			return i - j;
		}
	}
	free(next);
	return -1;
}




int main()
{
	int x, y;
	char array1[] = {'a','b','c','d','e','f'};
	char array2[] = { 'd','e','f'};
	lstring main, model;

	initstring(&main);
	initstring(&model);

	stringassign(&main, array1, 6);
	stringassign(&model, array2, 3);

	x = normal_index(main, model);
	//y = KMP(main, model);
	printf_s("使用普通匹配方法，查找到模式串在主串中的位置是%d \n", x);
	//printf_s("使用KMP方法，查找到模式串在主串中的位置是%d", y);

	return 0;
}