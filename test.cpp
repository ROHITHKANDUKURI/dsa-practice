#include <iostream>
#include <vector>
#include <sstream>
int maxProfit(std::vector<int>& prices) {
	int profit;
	int buy = prices[0];
	for(int i = 0;i < prices.size();i++) {
		if(prices[i] < buy) {
			buy = prices[i];
		} else if(profit < prices[i] - buy){
			profit = prices[i] - buy;
		}
	}
	return profit;
}
int main() {
    std::vector<int> nums;
    std::string line;
    
    std::getline(std::cin, line);
    std::stringstream ss(line);
    int num;
    
    while(ss >> num) {
        nums.push_back(num);
    }
    std::cout << maxProfit(nums);
    
}
