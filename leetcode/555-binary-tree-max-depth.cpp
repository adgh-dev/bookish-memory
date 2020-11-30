#include <iostream>
#include <queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct BinaryTree {
    TreeNode* head;
    BinaryTree(): head(NULL) {}

    void insert(int x) {
        if (head == NULL) {
            head = new TreeNode(x);
            return;
        }
        TreeNode* currentNode = head;
        while (currentNode != NULL) {
            if (x < currentNode->val) {
                if (currentNode->left != NULL)
                    currentNode = currentNode->left;
                else {
                    currentNode->left = new TreeNode(x);
                    return;
                }
            }
            else {
                if (currentNode->right != NULL)
                    currentNode = currentNode->right;
                else {
                    currentNode->right = new TreeNode(x);
                    return;
                }
            }
        }
    }

    void printDFS(TreeNode *node) {
        if (node->left != NULL)
            printDFS(node->left);
        cout << node->val << endl;
        if (node->right != NULL) {
            printDFS(node->right);
        }
    }

    void printBFS() {
        TreeNode* currentNode;
        queue<TreeNode *> q;
        q.push(head);

        while (! q.empty()) {
            currentNode = q.front();
            q.pop();
            cout << currentNode->val << endl;
            if(currentNode->left != NULL)
                q.push(currentNode->left);
            if(currentNode->right != NULL)
                q.push(currentNode->right);
        }
    }

};

class Solution {
public:
    static int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return max(leftDepth, rightDepth) + 1;
    }
};

int main() {
    BinaryTree tree = BinaryTree();
    int _[] = {8, 3, 10, 1, 6, 14, 4, 7, 13, 90, 3, 432, 2, 21};
    for (int x: _) {
       tree.insert(x);
    }
    // tree.printDFS(tree.head);
    tree.printBFS();
    cout << "max depth: " << Solution::maxDepth(tree.head) << endl;
    return 0;
}
