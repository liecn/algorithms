#include <iostream>
#include <new>
#include <string>
#include <algorithm>

using namespace std;

void PrintMatrix(int** arr,int m,int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }

        // Newline for new row
        cout << endl;
    }
}

int main()
{
    int n, m;
    char cha;
    int ans = 0;
    cin >> m >> n;

    int val_max = max(m, n);
    // read input matrix
    int **p = new int *[m];
    for (int i = 0; i < m; i++)
    {
        p[i] = new int[n];
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>cha;
            // cha = char_arr[i][j];
            if (cha == 'G')
                p[i][j] = val_max;
            else
                p[i][j] = 0;
        }
    }
    // PrintMatrix(p,m,n);
    // set index matrix
    int **p_index = new int *[m];
    for (int i = 0; i < m; i++)
    {
        p_index[i] = new int[n]{0};
    }

    //find the distribution of the max. plus symbol centering at each cell
    for (int i = 0; i < m; i++)
    {
        for (int j = 0, k = n - 1, l = 0, r = 0; j < n; j++, k--)
        {
            p[i][j] = min(p[i][j], l = (p[i][j] == 0 ? 0 : l + 1));
            p[i][k] = min(p[i][k], r = (p[i][k] == 0 ? 0 : r + 1));
        }
    }
    for (int j = 0; j < n; j++)
    {
        for (int i = 0, k = m - 1, u = 0, d = 0; i < m; i++, k--)
        {
            p[i][j] = min(p[i][j], u = (p[i][j] == 0 ? 0 : u + 1));
            p[k][j] = min(p[k][j], d = (p[k][j] == 0 ? 0 : d + 1));
        }
    }
    // PrintMatrix(p,m,n);
    //find the optimal two plus which are not overlap
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //set occupied cells
            for (int key=1;key<p[i][j]+1;key++)
            {
                p_index[i][j] = 1;
                for (int a = 1; a < key; a++)
                {
                    p_index[i][j + a] = 1;
                    p_index[i][j - a] = 1;
                    p_index[i + a][j] = 1;
                    p_index[i - a][j] = 1;
                }

                int key_2 = 0;

                for (int a = 0; a < m; a++)
                {
                    for (int b = 0; b < n; b++)
                    {
                        if (p_index[a][b] == 0)
                        {
                            int cur_key_2 = p[a][b];
                            int new_key_2 = 0;
                            for (int c = 0; c < cur_key_2; c++)
                            {
                                //detection of occupied cells
                                int flag = p_index[a][b + c] + p_index[a][b - c] + p_index[a + c][b] + p_index[a - c][b];
                                if (flag == 0)
                                    new_key_2++;
                                else
                                    break;
                            }
                            key_2 = max(key_2, new_key_2);
                        }
                    }
                }
                if((key!=0) && (key_2!=0))
                ans = max(ans, ((key-1)*4+1) * ((key_2-1)*4+1));
                //reset index matrix
                p_index[i][j] = 0;
                for (int a = 0; a < key; a++)
                {
                    p_index[i][j + a] = 0;
                    p_index[i][j - a] = 0;
                    p_index[i + a][j] = 0;
                    p_index[i - a][j] = 0;
                }
            }
        }
    }
    delete[] p;
    delete[] p_index;
    cout << ans << endl;
    return 0;
}