#include <stdio.h>
#include <stdlib.h>

// �����ַ��ڵ�����
typedef struct char_node {
    char data;
    struct char_node* next;
} char_node;

// �����ַ�������
typedef struct char_string {
    char_node* tail;
    int length;
} char_string;

// ��ʼ���ַ���
void init_string(char_string* s) {
    s->tail = NULL;
    s->length = 0;
}

// �ж��ַ����Ƿ�Ϊ��
int is_empty(char_string* s) {
    return s->length == 0;
}

// ��ȡ�ַ�������
int get_length(char_string* s) {
    return s->length;
}

// ���ַ���ĩβ����ַ�
void append_char(char_string* s, char c) {
    char_node* new_node = (char_node*)malloc(sizeof(char_node));
    new_node->data = c;
    new_node->next = NULL;

    if (s->tail == NULL) {
        s->tail = new_node;
    }
    else {
        char_node* p = s->tail;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = new_node;
    }

    s->length++;
}

// ���ַ���ת��ΪC�ַ���
char* to_c_string(char_string* s) {
    char* c_str = (char*)malloc(s->length + 1);
    char_node* p = s->tail;
    int i = 0;
    while (p != NULL) {
        c_str[i++] = p->data;
        p = p->next;
    }
    c_str[i] = '\0';
    return c_str;
}

// ��ӡ�ַ���
void print_string(char_string* s) {
    char* c_str = to_c_string(s);
    printf("%s", c_str);
    free(c_str);
}

// �ͷ��ַ����ڴ�
void free_string(char_string* s) {
    char_node* p = s->tail;
    while (p != NULL) {
        char_node* temp = p;
        p = p->next;
        free(temp);
    }
    s->tail = NULL;
    s->length = 0;
}

int main() {
    char_string s;
    init_string(&s);
    append_char(&s, 'H');
    append_char(&s, 'e');
    append_char(&s, 'l');
    append_char(&s, 'l');
    append_char(&s, 'o');
    print_string(&s);
    free_string(&s);
    return 0;
}
