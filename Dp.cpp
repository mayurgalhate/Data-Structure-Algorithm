#include <iostream>
#include <vector>
using namespace std;
// int f(int n, vector<int> &dp){
//     if(n <= 1) return n;

//     if(dp[n] != -1) return dp[n];

//     return dp[n] = f(n-1, dp) + f(n-2, dp);
// }

int main()
{
    int n;
    cout << "enter the no. :";
    cin >> n;

    // vector<int> dp(n+1, -1);
    // cout << f(n, dp);
    int prev2 = 0;
    int prev = 1;
    for (int i = 2; i <= n; i++)
    {
        int curri = prev + prev2;
        prev2 = prev;
        prev = curri;
    }
    cout << prev;

    return 0;
}