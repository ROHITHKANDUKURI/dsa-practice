#include <iostream>
using namespace std;

int IntLength(int a) {
    int cnt = 0;
    while (a > 0) {
        cnt++;
        a = a / 10;
    }
    return cnt;
}

int power(int a, int l) {
    int sum = 1; // Initialize sum to 1
    while (l > 0) {
        sum *= a;
        l--;
    }
    return sum;
}

int main() {
    int Originaln = 1634; // Change this to test with other numbers
    int l = IntLength(Originaln), n = Originaln;
    int sum = 0, x;

    while (n > 0) {
        x = n % 10;
        sum += power(x, l);
        n = n / 10;
    }

    if (sum == Originaln) {
        cout << "Yes, it is an Armstrong number." << endl;
    } else {
        cout << "No, it is not an Armstrong number." << endl;
    }

    return 0;
}
