#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ������ʽ���ṹ��
typedef struct LString {
    char ch;  // �洢��ǰ�ַ�
    struct LString* next;  // �洢��һ���ڵ��ָ��
} LString;

// ��ʼ����ʽ��
LString* InitLString() {
    LString* head = (LString*)malloc(sizeof(LString));  // ����ͷ�ڵ��ڴ�
    head->next = NULL;
    return head;
}

// ���ַ���ת��Ϊ��ʽ��
LString* StrToLString(char* str) {
    LString* head = InitLString();  // ��ʼ��ͷ�ڵ�
    LString* p = head;  // ����ָ��pָ��ͷ�ڵ�
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        LString* node = (LString*)malloc(sizeof(LString));  // �����½ڵ��ڴ�
        node->ch = str[i];  // �洢�ַ�
        node->next = NULL;
        p->next = node;  // ���½ڵ���뵽������
        p = node;  // �ƶ�ָ��p
    }
    return head;
}

// �ͷ���ʽ���ڴ�
void FreeLString(LString* head) {
    LString* p = head;
    while (p != NULL) {
        LString* q = p;
        p = p->next;
        free(q);
    }
}

// �����ʽ��
void PrintLString(LString* head) {
    LString* p = head->next;
    while (p != NULL) {
        printf("%c", p->ch);
        p = p->next;
    }
    printf("\n");
}

// ����next����
void GetNext(LString* T, int* next) {
    int i = 0, j = -1;
    next[0] = -1;
    while (T->next != NULL && T->next->next != NULL) {
        if (j == -1 || T->next->ch == T->next->next->ch) {
            i++;
            j++;
            next[i] = j;
            T = T->next;
        }
        else {
            j = next[j];
            T = T->next;
        }
    }
}

// KMP�㷨
int KMP(LString* S, LString* T) {
    int i = 0, j = 0;
    int* next = (int*)malloc(sizeof(int) * (strlen(T) + 1));
    GetNext(T, next);  // ����next����
    while (S->next != NULL && T->next != NULL) {
        if (j == -1 || S->next->ch == T->next->ch) {
            i++;
            j++;
            S = S->next;
            T = T->next;
        }
        else {
            j = next[j];
            T = T->next;
        }
        if (T->next == NULL && j == strlen(T)) {  // ƥ��ɹ�
            free(next);
            return i - j;
        }
    }
    free(next);
    return -1;  // ƥ��ʧ��
}

int main()
{
    char* text_str = "ababcabcacbab";
    char* pattern_str = "abcac";
    LString* text = StrToLString(text_str);  // ���ı���ת��Ϊ��ʽ��
    LString* pattern = StrToLString(pattern_str);  // ��ģʽ��ת��Ϊ��ʽ��
    int pos = KMP(text, pattern);  // ����ģʽ�����ı����е�λ��
    if (pos == -1) {
        printf("Not found!\n");
    }
    else {
        printf("Pattern found at position: %d\n", pos);
    }
    FreeLString(text);  // �ͷ���ʽ���ڴ�
    FreeLString(pattern);
    return 0;
}