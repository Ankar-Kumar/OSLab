#include<bits/stdc++.h>
using namespace std;
int i,j,k;

int n=17,m=6,fault=0;
int frame[17],modify[6];
void enhance(int siz)
{
    vector<int>tmp;
    map<int,string>mp;

    for(i=0; i<n; i++)
    {
        string s="10";
        int val=frame[i];
        if(tmp.size()<siz)
        {
            auto ind=find(tmp.begin(),tmp.end(),val);
            if(ind==tmp.end())
            {
                fault++;
                tmp.push_back(val);
                for(auto f:modify)
                {
                    if(f==val)
                    {
                        s="11";
                    }
                }
                mp[val]=s;
            }

        }
        else
        {
            auto ind=find(tmp.begin(),tmp.end(),val);
            if(ind==tmp.end())
            {
                fault++;
                string s1="10";
                for(auto f:modify)
                {
                    if(f==val)
                    {
                        s1="11";
                    }
                }
                mp[val]=s1;
            }
            else
            {
                string s1="10";
                for(auto f:modify)
                {
                    if(f==val)
                    {
                        s1="11";
                    }
                }
                mp[val]=s1;
            }
        }
    }
}
int main()
{
    freopen("enhance.txt","r",stdin);


    for(i=0; i<n; i++) cin>>frame[i];
    for(i=0; i<m; i++) cin>>modify[i];
    int siz;
    cin>>siz;

    enhance(siz);

}
