#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>
using namespace std;

class Solution {
    public:
    int countStudents(vector<int>& arr, int pages){
        int n = arr.size();
        int students = 1;
        int pagesStudent = 0;
        for(int i=0; i<n; i++){
            if(pagesStudent + arr[i] <= pages){
                pagesStudent += arr[i];
            }
            else{
                students++;
                pagesStudent = arr[i];
            }
        }
        return students;
    }

    int findPages(vector<int>& arr, int m, int n) {

        if(m>n){
            return -1;
        }
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);

        while(low<=high){
            int mid = (low+high)/2;
            int students = countStudents(arr, mid);
            if(students <= m){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};
int main() {
    vector<int> arr = {10, 20, 30, 40};
    int m = 2;
    int n = arr.size();

    Solution sol;
    cout << sol.findPages(arr, m, n) << "\n";

    return 0;
}
