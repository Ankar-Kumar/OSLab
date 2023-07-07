#include <bits/stdc++.h>
using namespace std;
void ganttChart(vector<int>&ans,int nn)
{
    vector<int>processor;
    vector<int>total;
    processor.push_back(ans[0]);
    //total.push_back(0);
    int c=1;
    for(int i=1;i<ans.size();i++){
        if(ans[i]==ans[i-1]){
            c++;
        }else{
            total.push_back(c);
            processor.push_back(ans[i]);
            c=1;
        }
    }
    total.push_back(c);
    for(auto x:total) cout<<x<< " ";
    cout<<endl<<endl;
    int i, j;
    cout << " ";
    int n = total.size(),sum=0;
     for (i = 0; i < n; i++)
    {
        int tmp=total[i];
        for (j = 0; j <tmp; j++)
        {
            cout << "--";
        }
        cout << " ";
    }
    printf("\n|");
    for (i = 0; i <n; i++)
    {
        int tmp = total[i];
        for (j = 0; j < tmp-1; j++)
        {
            cout << " ";
        }
        cout<<"P"<<processor[i];
        
        for (j = 0; j < tmp-1; j++)
        {
            cout << " ";
        }
        cout << "|";
    }
    cout<<endl;
    cout<<" ";
        for (i = 0; i <n; i++)
        {
            int tmp = total[i];
            for (j = 0; j < tmp; j++)
            {
                cout << "--";
            }
            cout << " ";
        }

        cout << endl;
        cout<<0;
        for (i = 0; i < n; i++)
        {
            int tmp=total[i];
            sum += tmp;
            for (j = 0; j < tmp; j++)
            {
                cout << "  ";
                
            }
            if (sum > 9)
                printf("\b"); // backspace : remove 1 space
            cout << sum;
        }

///eassy way->
        // cout<<"  ";
        // for(auto x:processor){
        //     cout<<"P"<<x<<"    ";
        // }
        // cout<<endl;
        // cout << 0 << "--";
        // for (int i = 1; i < total.size(); i++)
        // {
        //     total[i] += total[i - 1];
        //     cout << total[i] << "----";
        // }
    }
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
        tmp[i] = v[i]; ///remaining time
        totalBurst += v[i];
    }

    int b = 0;

    while (b < totalBurst)
    {

        for (int i = 0; i < n; i++)
        {
            if (v[i] <= t_quantum && v[i] > 0)
            {
                for(int tm=0;tm<v[i];tm++)
                ans.push_back(i + 1);
                wt[i] += b - check[i]; // total burst time theke start burst time bad
                b += v[i]; // burst time added
                v[i] = 0;
            }
            else if (v[i] > t_quantum)
            {
                for (int tm = 0; tm < t_quantum; tm++)
                ans.push_back(i + 1);
                wt[i] += b - check[i];
                b += t_quantum;
                check[i] = b; //first start burst time store
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
    ganttChart(ans,n);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     for (int j = 0; j < min(t_quantum, tmp[ans[i] - 1]) - 1; j++)
    //         cout << " ";
    //     cout << "p" << ans[i];
    //     for (int j = 0; j < min(t_quantum, tmp[ans[i] - 1]) - 1; j++)
    //         cout << " ";
    //     cout << "|";
    // }
    // cout << endl;
    // cout << 0;
    // int ans2 = 0;
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     for (int j = 0; j < min(t_quantum, tmp[ans[i] - 1]); j++)
    //         cout << "  ";
    //     ans2 += min(t_quantum, tmp[ans[i] - 1]);
    //     if (ans2 > 9)
    //         cout << "\b";
    //     cout << ans2;
    // }
}

int main()
{
    freopen("rr.txt", "r", stdin);
    solve();
}