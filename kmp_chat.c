#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义链式串结构体
typedef struct LString {
    char ch;  // 存储当前字符
    struct LString* next;  // 存储下一个节点的指针
} LString;

// 初始化链式串
LString* InitLString() {
    LString* head = (LString*)malloc(sizeof(LString));  // 分配头节点内存
    head->next = NULL;
    return head;
}

// 将字符串转化为链式串
LString* StrToLString(char* str) {
    LString* head = InitLString();  // 初始化头节点
    LString* p = head;  // 定义指针p指向头节点
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        LString* node = (LString*)malloc(sizeof(LString));  // 分配新节点内存
        node->ch = str[i];  // 存储字符
        node->next = NULL;
        p->next = node;  // 将新节点插入到链表中
        p = node;  // 移动指针p
    }
    return head;
}

// 释放链式串内存
void FreeLString(LString* head) {
    LString* p = head;
    while (p != NULL) {
        LString* q = p;
        p = p->next;
        free(q);
    }
}

// 输出链式串
void PrintLString(LString* head) {
    LString* p = head->next;
    while (p != NULL) {
        printf("%c", p->ch);
        p = p->next;
    }
    printf("\n");
}

// 计算next数组
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

// KMP算法
int KMP(LString* S, LString* T) {
    int i = 0, j = 0;
    int* next = (int*)malloc(sizeof(int) * (strlen(T) + 1));
    GetNext(T, next);  // 计算next数组
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
        if (T->next == NULL && j == strlen(T)) {  // 匹配成功
            free(next);
            return i - j;
        }
    }
    free(next);
    return -1;  // 匹配失败
}

int main()
{
    char* text_str = "ababcabcacbab";
    char* pattern_str = "abcac";
    LString* text = StrToLString(text_str);  // 将文本串转化为链式串
    LString* pattern = StrToLString(pattern_str);  // 将模式串转化为链式串
    int pos = KMP(text, pattern);  // 查找模式串在文本串中的位置
    if (pos == -1) {
        printf("Not found!\n");
    }
    else {
        printf("Pattern found at position: %d\n", pos);
    }
    FreeLString(text);  // 释放链式串内存
    FreeLString(pattern);
    return 0;
}