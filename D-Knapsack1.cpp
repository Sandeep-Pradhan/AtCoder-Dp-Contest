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
    
    int n, w;
    scanf("%d%d", &n, &w);
    vector<ll> dp(w + 1); 
    
    for(int i1 = 0; i1 < n; i1++) 
    {
        int weight, value;
        scanf("%d%d", &weight, &value);

        for(int i = w - weight; i >= 0; i--) 
        {
            dp[i + weight] = max(dp[i + weight], dp[i] + value);
        }
    }

    ll answer = 0;
    for(int i = 0; i <= w; ++i) 
        answer = max(answer, dp[i]);

    printf("%lld\n", answer);

    return 0;
}
