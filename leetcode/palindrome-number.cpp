#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> num;
        if (x < 0)
            return false;
        while (x > 0) {
            num.push_back(x % 10);
            x /= 10;
        }
        int n = num.size();
        for (int i = 0; i < n; i++) {
            if (num[i] != num[n - i - 1]) {
                return false;
            }
            // cout << num[i] << " " << num[n - i - 1] << endl;
        }
        // cout << "length: " << num.size() << endl;
        return true;
    }
};

int main() {
    Solution s = Solution();
    // s.isPalindrome(12321);
    cout << s.isPalindrome(12321) << endl;
    return 0;
}