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

int gcd(int a, int b) 
{
    return b == 0 ? a : gcd(b, a % b);
}

int find(int N, int M) 
{
    int g = 1;
    for (int i = 1; i * i <= M; ++i) 
    {
        if (M % i == 0) 
        {
            if (i * N <= M) g = max(g, i);
            if ((M / i) * N <= M) g = max(g, M / i);
        }
    }

    vector<int> A(N, g);
    A[N-1] = g * (M / g - (N-1));
    return gcd(A[0], A[N-1]);
}

signed main() 
{
    int n,m;
    cin >> n >> m;
    cout << find(n,m) << endl;
    return 0;
}