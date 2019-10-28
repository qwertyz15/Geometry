#include <bits/stdc++.h>
using namespace std;
#define READ(f)         freopen(f, "r", stdin)
#define WRITE(f)        freopen(f, "w", stdout)

struct Point
{
    int x , y , i;
};


//bool compareTwoPoints(Point a, Point b)
//{
//    if (a.x != b.x )
//        return a.x < b.x;
//
//    if (a.y != b.y)
//            return a.y < b.y;
//
//    return (a.x <= b.x);
//}
//
//void computeRanks(Point D[], int n)
//{
//
//    sort(D, D+n, compareTwoPoints);
//    for(int i = 0; i < n; i++)
//            D[i].i = i;
//}

int main()
{

//     READ("input.txt");
//    WRITE("output.txt");
    Point D[701];
	int t;
	int maxi = 2;
	char str[100];
	scanf("%d", &t);
	getchar();
	getchar();
	while(t--) {
        int maxi = 2;
		int n = 0;
		while(gets(str)) {
			if(str[0] == '\0')
				break;
			sscanf(str, "%d %d", &D[n].x, &D[n].y);
			n++;
		}
      //  computeRanks(D, n);

        int map[701][701] = {};
        int flag = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                if(map[i][j] == 0)
                {
                    map[i][j] = 1;
                    int ans[301], aidx = 2;
                    ans[0] = i, ans[1] = j;
                    for(int k = j+1; k < n; k++)
                    {
                        if((D[i].y-D[j].y)*(D[j].x-D[k].x) == (D[i].x-D[j].x)*(D[j].y-D[k].y))
                        {
                            ans[aidx++] = k;

                        }
                    }

                    if(aidx >= 3)
                    {
                        maxi = max(aidx , maxi);
                        flag = 1;
                        for(int k = 0; k < aidx; k++)
                            for(int l = 0; l < aidx; l++)
                                map[ans[k]][ans[l]] = 1;
                    }
                }
            }
        }
        cout << maxi << endl;
        if(t)	puts("");
    }
    return 0;
}


/**
Input
2

1 1
2 2
3 3

1 1
2 2
3 3
3 4
3 5
3 6

Output
3

4
**/



