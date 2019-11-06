		// AUTHOR - SANDEEP PRADHAN
#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <iomanip>
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

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    
    int n;
    cin>>n;

    vector<double> a(n);
    for(int i = 0; i < n; i++)
        cin>>a[i];

    vector<double> dp(n + 1);  // dp[i] - probability that there are i heads so far
    dp[0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j >= 0; j--) {   //j - no. of heads till now
            dp[j] = (j == 0 ? 0 : dp[j-1] * a[i]) + dp[j] * (1 - a[i]);
        }
    }

    double answer = 0;
    for(int heads = ceil(n/2.0); heads <= n; heads++) {
            answer += dp[heads];
    }

    cout << fixed << setprecision(9) << answer;

    return 0;
}
