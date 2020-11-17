#include <iostream>

using namespace std;

int main() {
    int n, group_s; 
    int groups[5] = {0};
    int num_taxis = 0;
    cin >> n;
    while (n > 0) {
        n--;
        cin >> group_s;
        groups[group_s]++;
    }
    for (const int &e : groups) {
        cout << e << " ";
    }
    cout << endl;

    num_taxis += groups[4] + groups[3] + groups[2] / 2;
    groups[2] %= 2;
    groups[1] -= groups[3];
    if (groups[1] < 0)
        groups[1] = 0;

    int remainder = groups[1] + groups[2];
    if (remainder % 4 == 0)
        num_taxis += remainder / 4;
    else
        num_taxis += remainder / 4 + 1;

    cout << num_taxis << endl;

    return 0;
}