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

int solve(vi a,int n)
{
    if(n<3) return 0;
    int res=0,left=0;
    // cout<<Min1<<" "<<Min2<<" "<<Max<<endl;
    int Min1,Min2,Max;
    for(int right=2;right<n;right++)
    {
        left=right-2;
        vi tmp(a.begin()+left,a.begin()+right+1);
        sort(tmp.begin(),tmp.end());
        Min1=tmp[0],Min2=tmp[1],Max=tmp[tmp.sz-1];
        int check=0;
        while(Min1+Min2>Max)
        {
            check=1;
            left--;
            if(left<0) break;
            if(a[left]<Min1)
            {
                Min2=Min1;
                Min1=a[left];
            }
            else if(a[left]<Min2)
            {
                Min2=a[left];
            }
            else if(a[left]>Max)
            {
                Max=a[left];
            }
        }
        // cout<<"left: "<<left<<" right: "<<right<<endl;
        if(check) res=max(res,right-left);
    }
    return res;
}

signed main()
{
    faster();
    // if(fopen(task".INP", "r"))
    // {
    //     freopen(task".OUT", "r", stdin);
    //     freopen(task".OUT", "w", stdout);
    // }
    int n;
    cin >> n;
    vi a(n);
    FOR(i,0,n) cin >> a[i];
    cout<<solve(a,n)<<endl;

    return 0;
}