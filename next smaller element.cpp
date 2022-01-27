/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
vector<int> nge(int arr[],int n)
{
  vector<int>v;
  stack<int>s;
  for(int i=n-1;i>=0;i--)
  {if(s.size()==0)
     v.push_back(-1);
  else if(s.size()>0 && s.top()<arr[i])
     v.push_back(s.top());
   else if(s.size()>0 && s.top()>=arr[i])
     {
         while(s.size()>0 && s.top()>=arr[i])
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
int arr[]={5,4,3,2,1,6};
int n=sizeof(arr)/sizeof(arr[0]);
vector<int> out=nge(arr,n);
for(auto i:out)
 cout<<i<<" ";
    return 0;
}
