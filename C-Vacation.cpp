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
    vector<int> dp(3,0);

    for(int i1 = 0; i1 < n; i1++) 
    {
        vector<int> new_dp(3, 0);
        vector<int> c(3);
        for(int i = 0; i < 3; i++) 
            scanf("%d", &c[i]);

        for(int i = 0; i < 3; i++)   //Parent Possibility
        {
            for(int j = 0; j < 3; j++)   // Current Child Possibility
            {
                if(i != j && (new_dp[j] < dp[i] + c[j])) 
                    new_dp[j] =  dp[i] + c[j];
            }
        }
        dp = new_dp;
    }
    printf("%d\n", max({dp[0], dp[1], dp[2]}));

    return 0;
}
