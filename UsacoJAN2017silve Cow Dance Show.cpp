#include <bits/stdc++.h>
using namespace std;
int n, m, q[1000001];
inline bool f(int x)
{
    int y = 0;
    int ans = 0;
    priority_queue < int, vector < int >, greater < int > > pru;
    for(register int i = 1; i <= x; ++i)
    {
        pru.push(q[i]);
    }
    for(register int i = x + 1; i <= n; ++i)
    {
        ans += pru.top() - y; 
        y = pru.top();
        pru.pop();
        pru.push(q[i] + y); 
        if(ans > m) 
        {
            return false;
        }
    }
    while(x--)
    {
        ans += pru.top() - y;
        y = pru.top();
        pru.pop();
        if(ans > m)
        {
            return false;
        }
    }
    return ans <= m;
}
inline int half()
{
    int l = 0;
    int r = 100000;
    int ans = 0;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(f(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}
int main()
{
    scanf("%d %d", &n, &m);
    for(register int i = 1; i <= n; ++i)
    {
        scanf("%d", &q[i]);
    }
    printf("%d", half());
    return 0;
}
