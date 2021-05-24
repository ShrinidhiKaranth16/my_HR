#include<bits/stdc++.h>
using namespace std;


string gridSearch(vector<string> G, vector<string> P) {
    int gSize = G.size();
    int pSize = P.size();
    int valSize = P[0].size();
    for(int x=0;x<gSize;x++)
    {
        int h;
        int found = G[x].find(P[0]);
        string s = G[x];
        if(found != string::npos)
        {
            int ref = x;
            int u = 1;
            for(int q =1; q<pSize;q++)
            {
                ref =  ref + 1;
                string a = G[ref].substr(found,valSize);
                if(a ==P[q])
                {
                    u++;
                }else
                {
                    break;
                }
            }
            if(u==pSize){
            return "YES";
            }
            else{
                for( h=found+1;h<G[x].size();h++)
                {
                        if(G[x].size() - h >= pSize)
                    {
                    string r = s.substr(h,valSize);
                    if(r==P[0]){
                     int ref2 = x;
                     int v = 1;
                     for(int q1 =1; q1<pSize;q1++)
                     {
                         ref2 = ref2 + 1;
                         string b = G[ref2].substr(h,valSize);
                         if(b ==P[q1])
                        {
                            v++;
                        }
                     }
                     if(v == pSize)
                     return "YES";
                    }
                    }
                }
            }
            
        }
    }
    return "NO";
}
int main()
{
    int t;
    int i,j,k;
    cin>>t;
    for(i=0;i<t;i++)
    {
        int R,C,r,c;
        cin>>R;
        cin>>C;
        vector<string> values;
        for(j=0;j<R;j++)
        {
            string num;
            cin>>num;
            values.push_back(num);
        }
        cin>>r;
        cin>>c;
        vector<string> searchVal;
        for(k=0;k<r;k++)
        {
            string sv;
            cin>>sv;
            searchVal.push_back(sv);
        }
        string result = gridSearch(values,searchVal);
        cout<<result;
    }

    
}