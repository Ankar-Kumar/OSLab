
#include<bits/stdc++.h>
using namespace std;
int fault=0;

void LRU(vector<int>&pages,int siz)
{
    set<int>tmp;
    map<int,int>freq;
    vector<int>first;
    for(int i=0; i<pages.size(); i++)
    {
        int val=pages[i];
        //cout<<val <<" -> "<<endl;
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
                int mn=INT_MAX,str;
                vector<int>tm;
                for(auto x:freq){
                    if(x.second<mn and x.second>0){
                        mn=x.second;
                    }
                }
                for(auto x:freq){
                    if(mn==x.second){
                        tm.push_back(x.first);
                        //cout<<x.first<<" ";
                    }
                }
               // cout<<endl;
                if(tm.size()>1)
                  {
                      for(int kk=0;kk<i;kk++){
                            int flag=0;
                        for(auto x:tm){
                            if(pages[kk]==x){
                            str=pages[kk];
                            //cout<<str;
                            flag=1;
                            pages[kk]=-1;
                            break;
                          }
                        }
                      if(flag==1) break;
                      }
                  }else{
                      str=tm[0];
                      for(int kk=0;kk<i;kk++){
                          if(str==pages[kk]){
                            pages[kk]=-1;
                            break;
                          }
                      }
                  }
                 // cout<<str<<endl;
                  freq[str]=0;
                tmp.erase(str);
                tmp.insert(val);
                fault++;
            }


        }
        freq[val]++;
    }
//    for(auto x:pages){
//        cout<<x<<" ";
//    }
    cout<<fault;
}
int main()
{
//    vector<int>a= {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2};
    vector<int>a={7, 0, 2, 4, 3, 1, 4, 7, 2, 0, 4, 3, 0, 3, 2, 7};
    int siz;
    cin>>siz;
    LRU(a,siz);
}

// 12
