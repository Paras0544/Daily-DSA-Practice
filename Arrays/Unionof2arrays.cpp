#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    vector<int> Unionoftwoarrays(int arr1[], int arr2[], int n, int m){
        vector<int> Union;
        int i = 0;
        int j = 0;

        while(i < n && j < m){
            if(arr1[i] < arr2[j]){
                if(Union.empty() || Union.back() != arr1[i]){
                    Union.push_back(arr1[i]);
                }
                i++;
            }
            else if(arr1[i] > arr2[j]){
                if(Union.empty() || Union.back() != arr2[j]){
                    Union.push_back(arr2[j]);
                }
                j++;
            }
            else{
                if(Union.empty() || Union.back() != arr1[i]){
                    Union.push_back(arr1[i]);
                }
                i++;
                j++;
            }
        }

        while(i < n){
            if(Union.empty() || Union.back() != arr1[i]){
                Union.push_back(arr1[i]);
            }
            i++;
        }

        while(j < m){
            if(Union.empty() || Union.back() != arr2[j]){
                Union.push_back(arr2[j]);
            }
            j++;
        }

        return Union;
    }
};

int main(){
    int arr1[] = {1, 2, 4, 5, 6};
    int arr2[] = {2, 3, 5, 7};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    Solution obj;
    vector<int> result = obj.Unionoftwoarrays(arr1, arr2, n, m);

    cout << "Union of the two arrays is: ";
    for(int num : result){
        cout << num << " ";
    }
    cout << endl;

    return 0;
};