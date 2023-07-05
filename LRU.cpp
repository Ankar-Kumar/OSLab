#include <bits/stdc++.h>
using namespace std;
int fault = 0;

void LRU(vector<int> &pages, int siz)
{
    set<int> tmp;
    map<int, int> ind;
    for (int i = 0; i < pages.size(); i++)
    {
        int val = pages[i];
        if (tmp.size() < siz)
        {
            if (tmp.find(val) == tmp.end()) // not found
            {
                fault++;
                tmp.insert(val); //  frame set e current value push hbe
            }
            ind[val] = i; //   location index current value te store hbe
            for (auto x : tmp)
                cout << x << " ";
            cout << endl;
        }
        else
        {
            if (tmp.find(val) == tmp.end()) // not found
            {
                int mn = INT_MAX, prev;
                for (auto it : tmp)
                {
                    if (ind[it] < mn)
                    {                 // frame  er kun element age asche seta check ,,,
                        mn = ind[it]; //  mp er oi index e valuer sathe compare
                        prev = it;
                    }
                }
                tmp.erase(prev);
                tmp.insert(val);
                fault++;
                for (auto x : tmp)
                    cout << x << " ";
                cout << endl;
            }
            ind[val] = i; // location index current value te store hbe
        }
    }
    cout << fault;
}
int main()
{
    vector<int> a = {2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2}; //{7,0,1,2,0,3,0,4,2,3,0,3,0,3,2,1,2,0,1,7,0,1};

    int siz;
    cout << "FRAME SIZE ";
    cin >> siz;
    LRU(a, siz);
}
