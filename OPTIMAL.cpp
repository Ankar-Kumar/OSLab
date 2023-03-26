#include<bits/stdc++.h>
using namespace std;
int fault=0;

void LRU(vector<int>&pages,int siz)
{
    set<int>tmp;

    for(int i=0; i<pages.size(); i++)
    {
        map<int,int>ind;
        int val=pages[i];
        if(tmp.size()<siz)
        {
            if(tmp.find(val)==tmp.end())  //not found
            {
                fault++;
                tmp.insert(val);
            }

        }
        else
        {
            if(tmp.find(val)==tmp.end())   //not found
            {
                int mx=0,prev;
                for(auto tt:tmp){
                        ind[tt]=200;
                for(int j=i+1; j<pages.size(); j++)
                {
                    if(tt==pages[j]){
                        ind[tt]=j;
                        break;
                    }
                }
                }
                for(auto it:ind){
                    if(it.second>mx){
                        mx=it.second;
                        prev=it.first;
                    }
                    }
                //cout<<prev<<" "<<val<<endl;
                tmp.erase(prev);
                tmp.insert(val);
                fault++;
            }

        }
    }
    cout<<fault;
}
int main()
{
    vector<int>a= {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};

    int siz;
    cin>>siz;
    LRU(a,siz);
}
