#include <bits/stdc++.h>

using namespace std;

vector<int> nge(int arr[],int n)
{
  vector<int>v;
  stack<pair<int,int>>s;
  int pseudoindex=-1;
  for(int i=0;i<n;i++)
  {if(s.size()==0)
     v.push_back(pseudoindex);
  else if(s.size()>0 && s.top().first<arr[i])
     v.push_back(s.top().second);
   else if(s.size()>0 && s.top().first>=arr[i])
     {
         while(s.size()>0 && s.top().first>=arr[i])
         {
             s.pop();
         }
         if(s.size()==0)
           v.push_back(pseudoindex);
         else 
           v.push_back(s.top().second);
     }
     s.push({arr[i],i});
  }
  return v;
}
int main()
{
int arr[]={1,2,2,4,5};
int n=sizeof(arr)/sizeof(arr[0]);
vector<int> out=nge(arr,n);
for(auto i:out)
 cout<<i<<" ";
    return 0;
}
