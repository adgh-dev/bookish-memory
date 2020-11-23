#include <iostream>

using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    static ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* currentNode = head;
        int counter = 0;

        // get list size
        while (currentNode!= NULL) {
            currentNode=currentNode->next;
            counter++;
        }
        int to_remove = counter - n;
        // cout << counter << endl;
        // cout << to_remove << endl;

        // remove nth node
        currentNode = head;
        counter = 0;
        while (currentNode!= NULL) {
            currentNode=currentNode->next;
            counter++;
        }
        return head;
    }
};

void print_list(ListNode& listHead);
void delete_node(int mark, ListNode& listHead);

int main() {
    ListNode head = ListNode(1);
    ListNode* currentNode = &head;

    for(int i=head.val+1; i<6; i++) {
        currentNode->next = new ListNode(i);
        currentNode = currentNode->next;
    }

    print_list(head);
    Solution::removeNthFromEnd(&head, 2);

    // print_list(head);

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