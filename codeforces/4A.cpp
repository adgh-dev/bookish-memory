#include <iostream>

using namespace std;

string watermelon_divs_even(int weight) {
    if (weight > 2 && weight % 2 == 0) {
        weight -= 2;
        if (weight % 2 == 0) {
            return "YES";
        }
    }
    return "NO";
}

int main() {
    int w;
    cin >> w;
    cout << watermelon_divs_even(w) << endl;
    return 0;
}