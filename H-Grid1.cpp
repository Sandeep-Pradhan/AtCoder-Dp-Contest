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

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    
    int h, w;
    cin >> h >> w;
    vector< string > a(h);
    vector< vector<int> > dp(h+1, vector<int> (w+1, 0));
    for(int i=0; i<h; i++)
            cin >> a[i];

    dp[1][1]=1;
    for(int i=1; i<=h; i++)
    {
        for(int j=1; j<=w; j++)
        {
            if(a[i-1][j-1] == '.')
                dp[i][j] = max(dp[i][j], dp[i-1][j] + dp[i][j-1]) % bs;
            else
                dp[i][j] = 0;
        }
    }
 
    cout << dp[h][w] << endl;

    return 0;
}
