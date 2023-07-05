
#include<bits/stdc++.h>
using namespace std;
int fault=0;

void LFU(vector<int>&pages,int siz)
{
    set<int>tmp;
    map<int,int>freq;
    vector<int>first;
    for(int i=0; i<pages.size(); i++)
    {
        int val=pages[i];
        
        if(tmp.size()<siz)
        {
            if(tmp.find(val)==tmp.end())  //not found
            {
                fault++;
                tmp.insert(val);
            }
            // for(auto x:tmp){
            //     cout<<x<<" ";
            // }
            // cout<<endl;
        }
        else
        {
            if(tmp.find(val)==tmp.end())   //not found
            {
                int mn=INT_MAX,str;
                vector<int>tm;
                for(auto x:freq){  // for minimum frequency finding ...
                    if(x.second<mn and x.second>0){  // frequency 0 theke boro hoite hobe
                        mn=x.second;
                    }
                }
                for(auto x:freq){   // store minimum frequency values to the vector
                    if(mn==x.second){
                        tm.push_back(x.first);
                        //cout<<x.first<<" ";
                    }
                }
               // cout<<endl;
                if(tm.size()>1)    // size beshi hole fifo apply krte hbe
                  {
                      for(int kk=0;kk<i;kk++){
                            int flag=0;
                        for(auto x:tm){
                            if(pages[kk]==x){
                            str=pages[kk];
                            //cout<<str;
                            flag=1;
                            pages[kk]=-1;  //oi page disable krte hbe
                            break;
                          }
                        }
                      if(flag==1) break;
                      }
                  }else{    // ektai minimum value pele oitai
                      str=tm[0];
                      for(int kk=0;kk<i;kk++){
                          if(str==pages[kk]){
                            pages[kk]=-1;  //oi page disable krte hbe
                            break;
                          }
                      }
                  }
                // cout<<str<<endl;
                freq[str]=0;  // frequency of previous value will be 0
                tmp.erase(str);  // previous value delete and new value insert to set
                tmp.insert(val);
                fault++;

                // for (auto x : tmp)
                // {
                //       cout << x << " ";
                // }
                // cout << endl;
            }


        }
        freq[val]++;
    }

    cout<<fault;
}
int main()
{
   vector<int>a= {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2};
    // vector<int>a={7, 0, 2, 4, 3, 1, 4, 7, 2, 0, 4, 3, 0, 3, 2, 7};
    int siz;
    cin>>siz;
    LFU(a,siz);
}

// 12
