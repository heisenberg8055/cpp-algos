#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

vector<int> countSort(vector<int> &arr) {
    int n = arr.size();
    int maxi = *max_element(arr.begin(), arr.end());
    vector<int>countArray(maxi + 1, 0);
    for(int i = 0; i < n; i++)
    {
        countArray[arr[i]]++;
    }
    vector<int>outputArray;
    for(int i = 0; i <= maxi; i++)
    {
        int cnt = countArray[i];
        while(cnt--)
        {
            outputArray.push_back(i);
        }
    }
    return outputArray;
}

int main() {
  vector<int> arr = {4, 3, 12, 1, 5, 5, 3, 9};
  // min = 1 && max = 8

  vector<int> count = countSort(arr);

for(auto it: count)
{
    cout << it << " "; 
}

  cout << "\n";
  return 0;
}