#include <iostream>

using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

void print_list(ListNode* listHead);
void delete_node(int mark, ListNode* listHead);
ListNode* pass_list_rec(ListNode* listNode);

ListNode* new_head;

int main() {
    ListNode head = ListNode(1);
    ListNode* currentNode = &head;

    for(int i=head.val+1; i<10; i++) {
        currentNode->next = new ListNode(i);
        currentNode = currentNode->next;
    }

    print_list(&head);
    // delete_node(4, &head);
    pass_list_rec(&head);
    print_list(new_head);

    return 0;
}

void delete_node(int mark, ListNode* listHead) {
    ListNode* currentNode = listHead;

    if (currentNode->val == mark) {
        currentNode = currentNode->next;
        return;
    }

    while (currentNode->next != NULL) {
        if (currentNode->next->val == mark)
            currentNode->next = currentNode->next->next;
        currentNode = currentNode->next;
    }
}

void print_list(ListNode* listHead) {
    ListNode* currentNode = listHead;
    while (currentNode != NULL) {
        cout << currentNode->val << " ";
        currentNode = currentNode->next;
    }
    cout << endl;
}

ListNode* pass_list_rec(ListNode* listNode){
    static int counter = 0;
    if(listNode->next != NULL) {
        counter++;
        ListNode* nextNode = pass_list_rec(listNode->next);
        nextNode->next = listNode;
        counter--;
    }
    else {
        new_head = listNode;
    }
    if (counter == 0)
        listNode->next = NULL;
    return listNode;
}