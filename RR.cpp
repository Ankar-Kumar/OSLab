#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, totalBurst = 0, t_quantum;
    double avg = 0;
    cout << "Enter total number of process\n";
    cin >> n;
    cout << "Enter time quantum ";
    cin >> t_quantum;
    vector<int> v(n), tmp(n), ans;
    int wt[n] = {0}, tat[n] = {0}, check[n] = {0};
    cout << "Enter process burst time\n";
    for (int i = 0; i < n; i++)
    {
        // cout << "p[" << i + 1 << "]: ";
        cin >> v[i]; // burst time
        tmp[i] = v[i];
        totalBurst += v[i];
    }

    int b = 0;

    while (b < totalBurst)
    {

        for (int i = 0; i < n; i++)
        {
            if (v[i] <= t_quantum && v[i] > 0)
            {
                ans.push_back(i + 1);
                wt[i] += b - check[i];
                b += v[i];
                v[i] = 0;
            }
            else if (v[i] > t_quantum)
            {
                ans.push_back(i + 1);
                wt[i] += b - check[i];
                b += t_quantum;
                check[i] = b;
                v[i] -= t_quantum;
            }
        }
    }

    cout << "\nProcess\t\tBurst time\t\twaiting time\n";
    for (int i = 1; i <= n; i++)
    {
        cout << "p[" << i << "]:\t\t\t" << tmp[i - 1] << "\t\t\t" << wt[i - 1] << "\n";
        avg += wt[i - 1];
    }

    cout << "Avarege waiting time :" << avg / n << endl;
    // gantt chart ...

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < min(4, tmp[ans[i] - 1]) - 1; j++)
            cout << " ";
        cout << "p" << ans[i];
        for (int j = 0; j < min(4, tmp[ans[i] - 1]) - 1; j++)
            cout << " ";
        cout << "|";
    }
    cout << endl;
    cout << 0;
    int ans2 = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < min(4, tmp[ans[i] - 1]); j++)
            cout << "  ";
        ans2 += min(4, tmp[ans[i] - 1]);
        if (ans2 > 9)
            cout << "\b";
        cout << ans2;
    }
}

int main()
{
    freopen("rr.txt", "r", stdin);
    solve();
}