#include<bits/stdc++.h>
using namespace std;
int fault=0;

void LRU(vector<int>&pages,int siz)
{
    set<int>tmp;
    map<int,int>ind;
    for(int i=0;i<pages.size();i++)
    {
        int val=pages[i];
        if(tmp.size()<siz)
        {
            if(tmp.find(val)==tmp.end())  //not found
            {
                fault++;
                tmp.insert(val);
            }
            ind[val]=i;
        }
        else
        {
            if(tmp.find(val)==tmp.end())   //not found
            {
                int mn=INT_MAX,str;
                for(auto it:tmp){
                    if(mn>ind[it]){
                        mn=ind[it];
                        str=it;
                    }
                }
                tmp.erase(str);
                tmp.insert(val);
                fault++;
            }
            ind[val]=i;
        }
    }
    cout<<fault;
}
int main()
{
    vector<int>a= {7,0,1,2,0,3,0,4,2,3,0,3,0,3,2,1,2,0,1,7,0,1};


    while(1){
    int siz;
    cout<<"FRAME SIZE ";
    cin>>siz;
    LRU(a,siz);
    }
}
