#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x , y , i;
};


bool compareTwoPoints(Point a, Point b)
{
    if (a.x != b.x )
        return a.x < b.x;

    if (a.y != b.y)
            return a.y < b.y;

    return (a.x <= b.x);
}

void computeRanks(Point D[], int n)
{

    sort(D, D+n, compareTwoPoints);
    for(int i = 0; i < n; i++)
            D[i].i = i;
}

int main()
{
    Point D[301];
    int x, y, i, j, k, l;
    while(1)
    {
        int x , y;
        cin >> x >> y;
        if(x == 0 && y == 0) break;
        D[0].x = x, D[0].y = y;
        int n = 1;

        while(true)
        {
            int x , y;
            cin >> x >> y;
            if(x == 0 && y == 0) break;
            D[n].x = x, D[n].y = y, n++;
        }

        computeRanks(D, n);

        int map[301][301] = {};
        int flag = 0;
        for(i = 0; i < n; i++)
        {
            for(j = i+1; j < n; j++)
            {
                if(map[i][j] == 0)
                {
                    map[i][j] = 1;
                    int ans[301], aidx = 2;
                    ans[0] = i, ans[1] = j;
                    for(k = j+1; k < n; k++)
                    {
                        if((D[i].y-D[j].y)*(D[j].x-D[k].x) == (D[i].x-D[j].x)*(D[j].y-D[k].y))
                        {
                            ans[aidx++] = k;

                        }
                    }

                    if(aidx >= 3)
                    {
                        if(!flag)
                            puts("The following lines were found:");
                        flag = 1;
                        for(k = 0; k < aidx; k++)
                            for(l = 0; l < aidx; l++)
                                map[ans[k]][ans[l]] = 1;
                        for(k = 0; k < aidx; k++)
                            printf("(%4d,%4d)", D[ans[k]].x, D[ans[k]].y);
                        puts("");
                    }
                }
            }
        }
        if(!flag)
            puts("No lines were found");
    }
    return 0;
}


