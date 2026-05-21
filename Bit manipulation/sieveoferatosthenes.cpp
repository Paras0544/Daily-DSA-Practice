#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> primesInRange(vector<vector<int>>& queries) {
        if (queries.empty()) {
            return {};
        }

        // Find the maximum value in the queries 
        // to determine the sieve range
        int maxVal = 0;
        for (const auto& query : queries) {
            maxVal = max(maxVal, query[1]);
        }

        // Step 1: Use the Sieve of Eratosthenes 
        // to find all primes up to maxVal
        vector<bool> isPrime(maxVal + 1, true);
        isPrime[0] = isPrime[1] = false;  // 0 and 1 are not primes
        for (int p = 2; p * p <= maxVal; ++p) {
            if (isPrime[p]) {
                for (int i = p * p; i <= maxVal; i += p) {
                    isPrime[i] = false;
                }
            }
        }

        // Step 2: Create a prefix sum array 
        // to count primes up to each number
        vector<int> primeCount(maxVal + 1, 0);
        for (int i = 1; i <= maxVal; ++i) {
            primeCount[i] = primeCount[i - 1];
            if (isPrime[i]) {
                primeCount[i]++;
            }
        }

        // Step 3: Process each query to find the number of primes 
        // in the given range
        vector<int> result;
        for (const auto& query : queries) {
            int start = query[0];
            int end = query[1];
            if (start == 0) {
                result.push_back(primeCount[end]);
            } else {
                result.push_back(primeCount[end] - primeCount[start - 1]);
            }
        }

        return result;
    }
};

int main() {
    // Example usage
    
    
    // Create an instance of the Solution class
    Solution solution;
    
    // Call the function and store the result
    auto result = solution.primesInRange(queries);
    
    // Output the result
    cout << "The number of primes in the given ranges are: ";
    for (int count : result) {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}
