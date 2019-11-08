#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
int main()
{
    double s,a;
    string str;

    while(cin >> s >> a >> str) {
            s += 6440;
            if(str == "deg") {
                cout << 2 * s * sin(a * pi / 180) << endl;
            }
            else cout << 2 * s * sin(a * pi / (60 * 180)) << endl;
    }
}

