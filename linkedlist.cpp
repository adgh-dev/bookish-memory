#include <iostream>

using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

void print_list(ListNode& listHead);
void delete_node(int mark, ListNode& listHead);

int main() {
    ListNode head = ListNode(1);
    ListNode* currentNode = &head;

    for(int i=head.val+1; i<10; i++) {
        currentNode->next = new ListNode(i);
        currentNode = currentNode->next;
    }

    print_list(head);
    delete_node(4, head);
    print_list(head);

    return 0;
}

void delete_node(int mark, ListNode& listHead) {
    ListNode* currentNode = &listHead;

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

void print_list(ListNode& listHead) {
    ListNode* currentNode = &listHead;
    while (currentNode != NULL) {
        cout << currentNode->val << " ";
        currentNode = currentNode->next;
    }
    cout << endl;
}