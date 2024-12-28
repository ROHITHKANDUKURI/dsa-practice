#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n = 20, p = 15;
    int gcd;    
    for(int i = 1; i <= (n/2); i++ ) {
        if(n % i == 0 && p % i == 0) {
            gcd = i;
        }
    }
    cout << gcd << endl;
}