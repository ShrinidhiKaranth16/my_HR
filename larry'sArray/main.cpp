#include<bits/stdc++.h>
using namespace std;

string larrysArray(vector<int> A) {
    if(A.size()==1) return "YES";
    if(A.size()==2) return "NO";
    int count =0;
    for(int i = 0;i<A.size();i++)
    {
        for(int j = i+1;j<A.size();j++)
        {
            if(A[i]>A[j])
            count++;
        }
    }
    if(count%2==0)
    return "YES";
    else
    return "NO";
}

int main()
{
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)
    {
        int n;
        vector<int> lArray;
        cin>>n;
        for(int j = 0;j<n;j++)
        {
            int a;
            cin>>a;
            lArray.push_back(a);
        }
        string result = larrysArray(lArray);
        cout<<result<<endl;
    }
}