#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int toInt(char c)
{
        return int(c - '0');
}

int main(void)
{
        int n;

        cin >> n;
        for (int loop = 0; loop < n; loop++) {
                string a, b;
                cin >> a >> b;

                string c;
                int k = 0;
                for (int i = 0; i < max(a.length(), b.length()); i++) {
                        int ax = (i < a.length() ? toInt(a[i]) : 0);
                        int bx = (i < b.length() ? toInt(b[i]) : 0);
                        int cx = ax + bx + k;
                        k = 0;
                        if (cx > 9) {
                                k = 1;
                                cx = cx - 10;
                        }

                        c.push_back(char(cx + '0'));
                }
                if (k == 1)
                        c.push_back(char(k + '0'));

                while (c.length() && c[0] == '0')
                        c.erase(c.begin());

                cout << c << endl;
        }
        return 0;
}
