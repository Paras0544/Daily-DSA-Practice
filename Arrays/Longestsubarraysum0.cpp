#include <iostream>
#include <unordered_map>
using namespace std;

int maxLen(int A[], int n) {

  unordered_map<int, int> mpp; // to store the first occurrence of a particular sum as prefix sum can be repeated and we want to find the longest subarray with sum 0

  int maxi = 0; // to store the length of the longest subarray with sum 0
  int sum = 0; // to store the prefix sum of the array

  for (int i = 0; i < n; i++) { // calculating the prefix sum of the array
    sum += A[i];

    if (sum == 0) {
      maxi = i + 1; // if the prefix sum is 0 then we can update the maximum length of the subarray with sum 0 as the current index + 1
    }
   
    else {
 
      if (mpp.find(sum) != mpp.end()) { // if the prefix sum is already present in the map then we can update the maximum length of the subarray with sum 0 as the current index - the index of the first occurrence of the prefix sum
        maxi = max(maxi, i - mpp[sum]);
      }
      else {
        mpp[sum] = i;
      }
    }
  }

  return maxi;
}

int main() {

  int A[] = {9, -3, 3, -1, 6, -5};

  int n = sizeof(A) / sizeof(A[0]);
  cout << maxLen(A, n) << endl;

  return 0;
}
