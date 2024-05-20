#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(2*m);
    int sum = 0;
    for (int i = 0; i < 2*m; i+=2)
    {
        cin >> a[i];
        a[i+1] = a[i];
        sum += 2*a[i];
    }
    sort(a.begin(), a.end());
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    vector<int> prev(n + 1, -1);
    for (int i = 0; i < 2*m; ++i)
    {
        for (int j = n; j >= a[i]; --j)
        {
            if (dp[j - a[i]] != -1 && dp[j] == -1)
            {
                dp[j] = dp[j - a[i]] + 1;
                prev[j] = i;
            }
        }
    }
    if(sum < n)
    {
        cout << -1;
        return 0;
    }
    if (dp[n] == -1)
    {
        cout << "0\n";
        return 0;
    }
    vector<int> ans;
    int cur = n;
    while (cur > 0)
    {
        ans.push_back(a[prev[cur]]);
        cur -= a[prev[cur]];
    }
    cout << ans.size() << "\n";
    for (int x : ans)
    {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}


/*vector<int> mirror_z_function(string s)
{
    int n = s.length();
    vector<int> z(n, 0);
    int L = 0, R = 0;
    for (int i = 1; i < n; i++)
    {
        if (i > R)
        {
            L = R = i;
        }
        int k = i - L;
        if (z[k] < R - i + 1)
        {
            z[i] = z[k];
        }
        else
        {
            L = i;
            while (R < n && s[R - L] == s[R])
            {
                R++;
            }
            z[i] = R - L;
            R--;
        }
    }
    return z;
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> z = mirror_z_function(s);
    for (int i = 0; i < n; i++)
    {
        cout << z[i] << "    ";
    }
    cout << endl;
    return 0;
}
*/
/*int n;
int Z[10001];

int main()
{
    string S;
    cin >> n >> S;
    int l = 0, r = 0;
    for(int i = 1; i <= n; i++)
    {
        if (i > r)
        {
            l = i;
            r = i;
        }
        int j = i - l;
        if (Z[j] < r - i + 1)
            Z[i] = Z[j];
        else
        {
            l = i;
            while(r < n && S[r-l] == S[r])
                r += 1;
            Z[i] = r - l;
            r -= 1;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        cout << Z[i];
    }
}*/
