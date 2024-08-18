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
string S, T;
int canTransform() 
{
    int n = S.size();
    unordered_map<char, char> mapStoT, mapTtoS;
    
    for (int i = 0; i < n; i++) 
    {
        char s = S[i];
        char t = T[i];
        
        if (mapStoT.count(s) && mapStoT[s] != t)
            return 0;
        if (mapTtoS.count(t) && mapTtoS[t] != s)
            return 0;
        
        mapStoT[s] = t;
        mapTtoS[t] = s;
    }
    return 1;
}

signed main() 
{
    faster();
    cin >> S >> T;
    if (canTransform()) 
    {
        cout << "Yes" << endl;
    } 
    else 
    {
        cout << "No" << endl;
    }

    return 0;
}
