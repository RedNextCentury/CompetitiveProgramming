/*

    Sort Problems greedily with a compare function that assumes only two problems exist and finds the optimal one to start with
    Then DP pick or leave to decide which problems to solve after determining the best order.

*/
#include<bits/stdc++.h>
using namespace std;
int n,t;
pair<long long,long long> a[100];
vector<long long> mx;
vector<long long> ppm;
vector<long long> rt;
long long dp[51][100005];
bool comp(pair<long long,long long> A,pair<long long,long long> B)
{
    return A.first+ppm[B.second]*(rt[A.second]+rt[B.second])>B.first+ppm[A.second]*(rt[A.second]+rt[B.second]);
}
long long solve(int i,int j)
{
    if (j>t)
        return -1e8;
    if (i<0)
        return 0;
    if (dp[i][j]!=-1)
        return dp[i][j];
    long long c1 = max(0LL,solve(i-1,j));
    long long c2 = solve(i-1,j+rt[a[i].second])+mx[a[i].second]-(j+rt[a[i].second])*1LL*ppm[a[i].second];
    return dp[i][j]=max(c1,c2);
}
struct TheProgrammingContestDivOne
{
    long long find(int T, vector <int> maxPoints, vector <int> pointsPerMinute, vector <int> requiredTime)
    {
        n=maxPoints.size();
        t=T;
        ppm.resize(n);
        mx.resize(n);
        rt.resize(n);
        for (int i=0;i<n;i++)
            ppm[i]=pointsPerMinute[i],mx[i]=maxPoints[i],rt[i]=requiredTime[i];
        for (int i=0;i<n;i++)
            a[i] = {ppm[i]*rt[i],i};
        sort(a,a+n,comp);
        memset(dp,-1,sizeof(dp));
        return solve(n-1,0);
    }
};
