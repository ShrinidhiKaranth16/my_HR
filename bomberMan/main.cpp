#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bomberMan' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING_ARRAY grid
 */
bool addBomb( queue<vector<int>>& q, vector<string>& grid)
{
   int numBombs = 0;
    for(int i = 0;i<grid.size();i++)
   {
       for(int j = 0;j<grid[i].size();j++)
       {
           if(grid[i][j]== 'O'){
            q.push({i,j});
            numBombs++;
           }
           else
           grid[i][j] = 'O';
       }
   }
   if(numBombs == 0)
   return false;
   else 
   return true;
}

vector<string> bomberMan(int n, vector<string> grid) {
    if(n==1) return grid;
        vector<vector<int>> directions {
        {-1,0},
        {0,1},
        {1,0},
        {0,-1}
    };
   int numberOfBombs = 0;
   queue<vector<int>> q;

    bool bombs = addBomb(q,grid);
    if(!bombs)
    return grid;
    
   if(n%2==0)
   return grid;
   
int i = 0;
while(i<2){
    i++;
   while(q.size()>0)
   {
       vector<int> currentBomb = q.front();
       q.pop();
       int row = currentBomb[0];
       int col = currentBomb[1];
       grid[row][col] = '.';
         for(int k = 0; k < directions.size(); k++) {
            vector<int> currentDir = directions[k];
            int nextRow = row + currentDir[0];
            int nextCol = col + currentDir[1];
            if(nextRow < 0 || nextRow >= grid.size() || nextCol < 0 || nextCol >= grid[0].size())
            continue;

            if (grid[nextRow][nextCol] != '.') 
            grid[nextRow][nextCol] = '.';
            }
   }
   if(n%4==3)
   return grid;
   if(i==1)
   addBomb(q,grid);
}
    return grid;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int r = stoi(first_multiple_input[0]);

    int c = stoi(first_multiple_input[1]);

    int n = stoi(first_multiple_input[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
