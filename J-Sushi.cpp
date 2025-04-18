#include<bits/stdc++.h>

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

int n;
double dp[301][301][301];

double func(int x, int y, int z) {
	if(x < 0 || y < 0 || z < 0) return 0;
	if(x == 0 && y == 0 && z == 0) return 0;
    
	if(dp[x][y][z] > 0) return dp[x][y][z];

	long double ret = n 
                    + x * func(x - 1, y, z)
					+ y * func(x + 1, y - 1, z)
					+ z * func(x, y + 1, z - 1);

	return dp[x][y][z] = ret / (x + y + z);
}

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    cin >> n;
	vector<int> freq(3);
	for(int i=0; i<n; i++){
        int x;
        cin>>x;
        freq[x - 1]++;
    }

	memset(dp, -1, sizeof dp);

	cout << fixed << setprecision(10) << func(freq[0], freq[1], freq[2]) << endl;

    return 0;
}