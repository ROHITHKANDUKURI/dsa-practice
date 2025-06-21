#include <iostream>
#include <vector>

using namespace std;

void recurPermutation(vector<int> ds, vector<int> &nums, vector<vector<int>> &ans, int freq[]) {
    if(ds.size() == nums.size()) {
        ans.push_back(ds);
        return;
    }
    for(int i = 0; i < nums.size(); i++) {
        if(!freq[i]) {
            ds.push_back(nums[i]);
            freq[i] = 1;
            recurPermutation(ds, nums, ans, freq);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}
vector<vector<int>> permutations(vector<int> &nums) {
    vector<vector<int>> ans;
    vector<int> ds;
    int freq[nums.size()] = {0};
    recurPermutation(ds, nums, ans, freq);
    return ans;
}

int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = permutations(nums);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j] << ' ';
        }
        cout << "\n";
    }
}