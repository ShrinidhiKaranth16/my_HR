#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int pairs(int k, vector<int> arr) {
    map<int,int> mapVal;
    int count = 0;
    for(int i = 0;i<arr.size();i++){
        mapVal[arr[i]] = i;
    }
    for(int j = 0;j<arr.size();j++)
    {
        int num = arr[j];
        int pair = k-num;
        map<int,int> :: iterator currentMapVal = mapVal.find(pair);
        if(currentMapVal!=mapVal.end())
        count++;
    }
    return count;
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> v;
    for(int i = 0;i<n;i++)
    {
        int temp
        cin>>temp;
        v.push_back(temp);
    }
    int result = pairs(k,v);
    cout<<result<<endl;
}