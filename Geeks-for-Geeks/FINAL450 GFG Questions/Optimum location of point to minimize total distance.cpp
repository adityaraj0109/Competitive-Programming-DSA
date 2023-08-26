#include <bits/stdc++.h>
using namespace std;

void debugMode()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

double solution(tuple<int, int, int> l, vector<pair<int, int>> p,double x){
    double a=get<0>(l);
    double b=get<1>(l);
    double c=get<2>(l);
    double y=-(a*x+c)/b;
    double dist=0;
    for (auto i :p){
        double x1=i.first;
        double y1=i.second;
        dist+=sqrt((x1-x)*(x1-x)+(y1-y)*(y1-y));
    }
    return dist;
}

double findOptimumCost(tuple<int, int, int> l, vector<pair<int, int>> p, int n)
{
    double high=1e3+10;
    double low=-1e3-10;
    double diff=1e-3;
    while (high-low>diff)
    {
        double mid1=low+(high-low)/3;
        double mid2=high-(high-low)/3;
        double dist1=solution(l,p,mid1);
        double dist2=solution(l,p,mid2);
        if(dist1>dist2){
            low=mid1;
        }
        else if(dist1<dist2) high= mid2;
        else{
            low=mid1;
            high=mid2;
        }
    }
    return solution(l,p,low);
}

int main()
{
    debugMode();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}












