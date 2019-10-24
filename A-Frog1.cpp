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
const int INF = 1e9 + 5;

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;
	cout.tie(NULL) ;

    int n;
    scanf("%d", &n);
    vector<int> h(n);
    for(int i=0; i<n; i++) 
        scanf("%d", &h[i]);

    vector<int> dp(n, INF);
    dp[0] = 0;
    for(int i=0; i<n; ++i) 
    {
        for(int j : {i + 1, i + 2}) 
        {
            if(j < n)
                dp[j] = min(dp[j], dp[i] + abs(h[i] - h[j]));
        }
    }
    printf("%d\n", dp[n-1]);

	return 0;
}
