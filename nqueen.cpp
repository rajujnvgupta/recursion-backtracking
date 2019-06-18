#include<bits/stdc++.h>

using namespace std;
int cnt = 0;

///checking safe position
bool isSafe(int in[1000][1000], int i, int j, int n)
{
    ///for column
    for(int row = 0; row < i; row++)
    {
        if(in[row][j] == 1)
        {
            return false;
        }
    }
    int x = i;
    int y = j;
    /// for right digonal
    while(x >= 0 && y <= n)
    {
        if(in[x][y] == 1)
            return false;

        x--;
        y++;
    }
    ///for left diagonal
    x = i, y = j;
    while(x >= 0 && y >= 0)
    {
        if(in[x][y] == 1)
            return false;

        x--;
        y--;
    }

    return true;
}

bool solve(int in[1000][1000], int i, int n)
{
    if(i == n)
    {
        for(int k = 0; k < n; k++)
        {
            for(int l = 0; l < n; l++)
            {
                 if(in[k][l] == 1)
                    cout<<"Q";

                  else
                    cout<<"-";
            }

            cout<<endl;
        }
        cnt++;
        return false; ///very efficient hack for returning false is carry out for next valid configuration
    }

    for(int j = 0; j < n; j++)
    {
        if(isSafe(in, i, j, n))
        {
            in[i][j] = 1;
            bool nextqueenrakhpaye = solve(in, i + 1, n);
            if(nextqueenrakhpaye)
            {
                return true;
            }
            in[i][j] = 0;
        }
    }

   ///if next row is not safe after checking all column of that row
    return false;
}

int main()
{
    int n;
    cin>>n;
    int in[1000][1000] = {0};
    solve(in, 0, n);
    cout<<"total number of configuration"<<cnt;
    return 0;
}

