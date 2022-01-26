#include <bits/stdc++.h>
using namespace std;
vector<int> nextsmallerelement(vector<int>&arr,int n)
{
    vector<int>v;
    stack<int>s;
    for(int i=n-1;i>=0;i--)
    {
        if(s.size()==0)
        {
            v.push_back(-1);
        }
        else if(s.size()>0 && s.top()>arr[i])
        {
            v.push_back(s.top());
        }
        else if(s.size()>0 && s.top()<=arr[i])
        {
            while(s.size()>0 && s.top()<=arr[i])
            {
                s.pop();
            }
            if(s.size()==0)
              v.push_back(-1);
            else
             v.push_back(s.top());
        }
          
         s.push(arr[i]);
    }
    reverse(v.begin(),v.end());
    return v;

}

int main()
{
vector<int> nums={1,3,0,0,1,2,4};
vector<int>out=nextsmallerelement(nums,nums.size());
for(auto i:out)
 cout<<i<<" ";
return 0;
}
