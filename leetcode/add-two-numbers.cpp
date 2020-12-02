#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // if one number is 0 return the other number as linked list
        if (l1->val == 0 && l1->next == NULL)
            return l2;
        if (l2->val == 0 && l2->next == NULL)
            return l1;

        ListNode* rez = new ListNode();
        ListNode* _ = rez;
        int rem = 0;

        while (true) {
            int a, b, sum = 0;
            if (l1 != NULL) {
                a = l1->val;
                l1 = l1->next;
            }
            else
                a = 0;
            if (l2 != NULL) {
                b = l2->val;
                l2 = l2->next;
            }
            else
                b = 0;

            sum = a + b + rem;
            rem = 0;
            if (sum > 9) {
                sum -= 10;
                rem = 1;
            }
            // cout << sum << " ";

            _->next = new ListNode(sum);
            _ = _->next;

            if (l1 == NULL && l2 == NULL) {
                // cout << endl;
                break;
            }
        }
        if (rem > 0)
            _->next = new ListNode(rem);
        return rez->next;
    }
};

void print_list(ListNode* listHead) {
    ListNode* currentNode = listHead;
    while (currentNode != NULL) {
        cout << currentNode->val << " ";
        currentNode = currentNode->next;
    }
    cout << endl;
}

int main() {
    int _a[] = {0,8,6,5,6,8,3,5,7};
    int _b[] = {6,7,8,0,8,5,8,9,7};
    ListNode* a = new ListNode();
    ListNode* b = new ListNode();
    ListNode* c_tmp;

    c_tmp = a;
    for (int x: _a) {
        c_tmp->next = new ListNode(x);
        c_tmp = c_tmp->next;
    }

    c_tmp = b;
    for (int x: _b){
        c_tmp->next = new ListNode(x);
        c_tmp = c_tmp->next;
    }

    print_list(a->next);
    print_list(b->next);

    print_list(
        Solution::addTwoNumbers(a->next, b->next)
    );

    return 0;
}