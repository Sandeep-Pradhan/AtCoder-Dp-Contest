		// AUTHOR - SANDEEP PRADHAN
#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <assert.h>
#include<limits.h>


#define eps 1e-8
#define PI 3.141592653589793
#define bsize 512

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define bs 1000000007
const long INF = 1e15 + 5;

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    
    int n, W;
    scanf("%d%d", &n, &W);
    vector<int> weight(n), value(n);
    for(int i = 0; i < n; ++i) {
        scanf("%d%d", &weight[i], &value[i]);
    }
    
    const int MAX_VALUE = 100 * 1000 + 1; // n * max_value + 1
    vector<long> dp(MAX_VALUE, INF);
    dp[0] = 0;

    int answer = 0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = MAX_VALUE - 1; j >= value[i]; j--) 
        {
            if (dp[j - value[i]] + weight[i] <= W) 
            {
                dp[j] = min(dp[j], dp[j - value[i]] + weight[i]);
                answer = max(answer, j);
            }
        }
    }
    printf("%d\n", answer);

    return 0;
}
