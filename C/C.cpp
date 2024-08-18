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

signed main()
{
    faster();
    int n,k;
    cin >> n >> k;
    vi D(n);
    FOR(i,0,n) cin >> D[i];
    double result = 0.00;

    if (k == 1) 
    {
        sort(D.begin(), D.end());
        int median = D[n / 2];
        for (int i = 0; i < n; ++i) 
        {
            result += abs(D[i] - median);
        }
    } 
    else if (k == 2) 
    {
        double mean = 0;
        FOR(i,0,n) mean += D[i];
        mean /= n;
        FOR(i,0,n) result += (D[i] - mean) * (D[i] - mean);
    }

    cout << fixed << setprecision(2) << result << endl;

    return 0;
}