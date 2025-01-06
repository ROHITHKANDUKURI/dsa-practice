#include <iostream>
#include <cmath>


bool isPrime(int n)
{

	if(n == 1) {
		return false;
	}
	for(int i = 2;i <= sqrt(n);i++) {
		if(n % i == 0) {
			return false;
		}
	}
	return true;
}

int main()  {
    int n;
    std::cout << "Enter a number" << std::endl;
    std::cin >> n;
    if(isPrime(n)) {
        std::cout << "It is a prime number" << std::endl;
    } else {
        std:: cout << "It isn't a prime number" << std::endl;
    }
    return 0;
}