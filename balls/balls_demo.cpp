#include <bits/stdc++.h>

using namespace std;

// Complete the organizingContainers function below.
string organizingContainers(vector<vector<int>> container) {
  int x,y,z;
  int sizeOfContainers1[container.size()];
  vector<int> numberOfBalls;
  int totalContainers = container.size();
  int totalBalls;
  for(y=0;y<totalContainers;y++)
  {
      int sum =0;
    for(z=0;z<totalContainers;z++)
    {
     totalBalls = container[z][y];
    if(y==0)
      sizeOfContainers1[z] = totalBalls;
    else
      sizeOfContainers1[z] =sizeOfContainers1[z] + totalBalls;
     sum = sum + totalBalls;
    }
    numberOfBalls.push_back(sum);
  }
  for(int u:numberOfBalls)
  {
    bool flag = false;
    int key = u;
    for(int tr1=0;tr1<container.size();tr1++)
    {
      if(!flag && key == sizeOfContainers1[tr1] )
      {
        sizeOfContainers1[tr1] = 0;
        flag = true;
      }
    }
  }
  int t =0;
  for(int tr=0;tr<container.size();tr++)
  {
    t = t + sizeOfContainers1[tr]; 
  }
  if(t == 0)
  return "Possible";
  else
  return "Impossible";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> container(n);
        for (int i = 0; i < n; i++) {
            container[i].resize(n);

            for (int j = 0; j < n; j++) {
                cin >> container[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = organizingContainers(container);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
