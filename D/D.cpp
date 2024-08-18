#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define int long long
#define sz size()
#define FOR(i,a,b) for(long long i = a; i < b; i++)
#define FORD(i,a,b) for(long long i = a; i > b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define vll vector<long long>
#define endl '\n'
#define MOD 1000000007
// #define task "Fernandez"

#ifdef FERNANDEZ
   #include "debug.h"
#else
   #define debug(...) 04
#endif

signed main()
{
    faster();
    int n,k;
    cin >> n >> k;
    vi a(n);
    FOR(i,0,n) cin >> a[i];
    sort(a.begin(),a.end());
    int min_diff = INT_MAX;
    
    // Duyệt qua tất cả các dãy con liên tiếp có K phần tử
    for(int i = 0; i <= n-k; ++i) 
    {
        min_diff = min(min_diff, a[i+k-1] - a[i]);
    }
    
    cout << min_diff << endl;
    return 0;

    return 0;
}