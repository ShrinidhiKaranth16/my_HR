#include<iostream>
#include<vector>
#include<map>
using namespace std;


string organizingContainers(vector<vector<int>> container) {
    vector<int> cMap1;
    for(int i = 0;i<container.size();i++)
    {
        int sum = 0;
        for(int j = 0;j<container.size();j++){
           sum  = sum +container[j][i];
        }
        cMap1.push_back(sum);
    }
    vector<int> containerSize;
    for(int i = 0;i<container.size();i++)
    {
        int sum =0;
        for(int j = 0;j<container[i].size();j++){
           sum += container[i][j];
        }
        containerSize.push_back(sum);
    }
    int x = 0;
    for(int i = 0;i<containerSize.size();i++)
    {
        int s = containerSize[i];
        for(int j = 0;j<cMap1.size();j++){
            if(cMap1[j]==s){
                cMap1[j]=-1;
                x++;
            }
        }

    }
    if(x==container.size())
    return "Possible";
    else
    return "Impossible";

}

int main()
{
    int q;
    cin>>q;
    for(int i = 0;i<q;i++){
        int n;
        cin>>n;
        vector<vector<int>> v;
        for(int j = 0;j<n;j++)
        {
            vector<int> v1;
            for(int k = 0;k<n;k++){
                int num;
                cin>>num;
                v1.push_back(num);
            }
            v.push_back(v1);
        }
        string result = organizingContainers(v);
        cout<<result<<endl;
    }
}