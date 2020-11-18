#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static vector<int> runningSum(vector<int>& nums) {
        vector<int> result;
        int floating_sum = 0;
        for(int& elem: nums) {
            floating_sum += elem;
            result.push_back(floating_sum);
        }
        return result;
    }
};


int main() {
    vector<int> input = {3,1,2,10,1};
    for (int &x: Solution::runningSum(input)) {
        cout << x << " ";
    }
}