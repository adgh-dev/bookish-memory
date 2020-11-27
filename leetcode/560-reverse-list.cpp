#include <iostream>

using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    static ListNode* reverseList(ListNode* listNode){
        // WIP
        if(listNode == NULL)
            return NULL;

        while (listNode != NULL) {
            ListNode* prev = listNode;
            listNode = listNode->next;
            ListNode* tmp = listNode->next;
        }

        return listNode;
    }

    static ListNode* reverseListRec(ListNode* listNode){
        static int counter = 0;
        static ListNode* head;

        if(listNode == NULL)
            return NULL;

        if(listNode->next != NULL) {
            counter++;
            ListNode* nextNode = reverseListRec(listNode->next);
            nextNode->next = listNode;
            counter--;
        }
        else {
            head = listNode;
        }
        if (counter == 0) {
            listNode->next = NULL;
            return head;
        }
        return listNode;
    }
};

void printList(ListNode* listHead) {
    ListNode* currentNode = listHead;
    while (currentNode != NULL) {
        cout << currentNode->val << " ";
        currentNode = currentNode->next;
    }
    cout << endl;
}

int main() {
    ListNode head = ListNode(1);
    ListNode* currentNode = &head;

    for(int i=head.val+1; i<10; i++) {
        currentNode->next = new ListNode(i);
        currentNode = currentNode->next;
    }

    printList(&head);
    ListNode* newHead = Solution::reverseListRec(&head);
    printList(newHead);

    return 0;
}