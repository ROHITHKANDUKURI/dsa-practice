// Q2. A database contains userCreated, shortUrl, actualUrl. There are 0 to m-1 users. And q Queries. Each query i cantains short url. Return the list of actualUrl and noOfQueries got to the userCreated till.

// Example:
// Database:
// [[0, axdf, www.google.com],
// [1, xybg, www.google.com],
// [0, gsjb, kaggle.com]]

// Queries:
// [axdf,xybg,gsjb]

// Output:
// [[www.google.com, 1],
// [www.google.com, 1],
// [kaggel.com, 2]]

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    // Sample database
    vector<vector<string>> database = {
        {"0", "axdf", "www.google.com"},
        {"1", "xybg", "www.google.com"},
        {"0", "gsjb", "kaggle.com"}
    };

    vector<string> queries = {"axdf", "xybg", "gsjb"};

    unordered_map<string, pair<string, int>> urlMap;  // shortUrl → (actualUrl, userCreated)
    int m = 0; // Maximum user ID to initialize the query count

    // Populate the map and find max user ID
    for (const auto& entry : database) {
        int user = stoi(entry[0]);  // Convert string to integer
        urlMap[entry[1]] = {entry[2], user};
        m = max(m, user);
    }

    vector<int> queryCount(m + 1, 0);  // Track query count for users

    vector<vector<string>> result;
    
    // Process queries
    for (const string& shortUrl : queries) {
        if (urlMap.find(shortUrl) != urlMap.end()) {
            string actualUrl = urlMap[shortUrl].first;
            int userCreated = urlMap[shortUrl].second;
            queryCount[userCreated]++;

            // Convert count to string for result formatting
            result.push_back({actualUrl, to_string(queryCount[userCreated])});
        }
    }

    // Print output
    for (const auto& entry : result) {
        cout << "[" << entry[0] << ", " << entry[1] << "]" << endl;
    }

    return 0;
}
