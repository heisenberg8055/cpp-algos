#include<bits/stdc++.h>
using namespace std;

int LIS(vector<int> arr)
{
    int n = arr.size();
    vector<int>dp(n, 1);
    vector<int>sol(n, 1);
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(arr[j] < arr[i])
            {
                if(dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    //storing previous smallest number before me
                    sol[i] = j;
                }
            }
        }
    }

    int maxIndex = 0;
    for(int i = 0; i < n; i++)
    {
        if(dp[maxIndex] < dp[i])
        {
            maxIndex = i;
        }
    }

    //print lcs

    int i = maxIndex;
    int newI = maxIndex;

    do{
        i = newI;
        cout << arr[i] << " ";
        newI = sol[i];
    }while(i != newI);

    cout << "\n";
    return dp[maxIndex];
}

int main()
{
    vector<int>arr = {23,10,22,5,33,8,9,21,50,41,60,80,99, 22,23,24,25,26,27};
    int ans = LIS(arr);
    cout << "Answer: "<< ans<<"\n";
}