#include <bits/stdc++.h>
using namespace std;

int i, j, k, index = 0;
int fault = 0;

void secondChance(vector<int> &page, int frame)
{
    vector<int> tmp;
    map<int, int> mp;
   
    for (i = 0; i < page.size(); i++)
    {
        int val=page[i];
        if(tmp.size()<frame){
            auto ck = find(tmp.begin(), tmp.end(), val);
            if (ck == tmp.end())
            {
                mp[val] = 0;
                tmp.push_back(val);
                fault++;
                // for(auto x:tmp){
                //     cout<<x<<" ";
                // }cout<<endl;
            }
            else
            {
                mp[val]=1;
            }
        }
        else{
            auto ck = find(tmp.begin(), tmp.end(), val);
            if(ck==tmp.end()){
                fault++;
                int flag=0;
                for(k=index;;){
                    for(auto &it:mp){
                        if (tmp[k] == it.first and it.second == 0)
                        {
                            tmp[k] = val;
                            mp[val] = 0;
                            flag=1;
                            break;
                        }
                        else if (tmp[k] == it.first and it.second == 1)
                        {
                            it.second = 0;
                        }
                    }
                    k=(k+1)%frame;
                    if(flag) break;
                }
                index=k;


            }else{
                mp[val]=1;
            }
        }
    }
    cout << endl;
    cout << fault;
}
int main()
{
    int frame, n = 20;
    freopen("secondt.txt", "r", stdin);
    vector<int> page(n); // {2,5,10, 1, 2, 2, 6, 9, 1, 2, 10, 2, 6, 1, 2, 1, 6, 9, 5, 1};// 14
    for (i = 0; i < n; i++)
    {
        cin >> page[i];
    }
    cin >> frame;
    secondChance(page, frame);
}
