// Problem: PPATH
// Author: Arapat Jurat
// Date: Oct. 17
// Submission: 
// TLE version

#include <iostream>
#include <cstring>
using std::cout;
using std::cin;
using std::endl;
const int minn = 1000, maxn = 10000;
const int len = 4;

bool isPrime[maxn];

void getPrime() {
        memset(isPrime, true, sizeof(isPrime));
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i < maxn; i++)
                if (isPrime[i])
                        for (int j = i * i; j < maxn; j += i)
                                isPrime[j] = false;
}

void split(int n, int num[]) {
        for (int i = len - 1; i >= 0; i--) {
                num[i] = n % 10;
                n /= 10;
        }
}

int combine(int num[]) {
        int result = 0;
        for (int i = 0; i < len; i++)
                result = result * 10 + num[i];
        return result;
}

bool dfs(int a, int b, int depth) {
        if (a == b)
                return true;
        if (!depth)
                return false;

        int num[len];
        split(a, num);

        for (int i = 0; i < len; i++) {
                int r = num[i];
                for (int j = (i ? 0 : 1); j <= 9; j++) {
                        num[i] = j;
                        int k = combine(num);
                        if (isPrime[k])
                                if (dfs(k, b, depth - 1))
                                        return true;
                }
                num[i] = r;
        }

        return false;
}

int findPath(int a, int b) {
        if (a == b)
                return 0;

        int l = 0, r = 10;
        while (l + 1 < r) {
               int mid = (l + r) / 2;
               if (dfs(a, b, mid))
                       r = mid;
               else
                       l = mid;
        }
        return r;
}

int main(void)
{
        int loop;
        cin >> loop;

        getPrime();
        while (loop--) {
                int a, b;
                cin >> a >> b;
                cout << findPath(a, b) << endl;
        }
        return 0;
}
