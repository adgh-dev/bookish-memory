#include <stdio.h>
#include <stdlib.h>

struct listNode {
    int val;
    struct listNode* next;
};

int main() {
    int n;
    char c;
    struct listNode head = {1, NULL};
    struct listNode* currentNode = &head;

    printf("%d %d\n", sizeof(n), sizeof(c));
    printf("%d %d\n", sizeof(head), sizeof(currentNode));
    printf("%d\n", currentNode);

    currentNode->next = (struct listNode*)malloc(sizeof(struct listNode));
    currentNode = currentNode->next;
    currentNode->val = 2;
    currentNode->next = NULL;

    printf("%d\n",(head.next)->val);

    return 0;
}