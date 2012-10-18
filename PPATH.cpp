// Problem: PPATH
// Author: Arapat Jurat
// Date: Oct. 17
// Submission: 3

#include <iostream>
#include <cstring>
using std::cout;
using std::cin;
using std::endl;
const int minn = 1000, maxn = 10000;
const int maxprime = 1000 + 100;
const int len = 4;

int distance[maxprime][maxprime];
bool isPrime[maxn];
int prime[maxn], nprime;

void getPrime() {
        memset(isPrime, true, sizeof(isPrime));
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i < maxn; i++)
                if (isPrime[i])
                        for (int j = i * i; j < maxn; j += i)
                                isPrime[j] = false;

        nprime = 0;
        for (int i = minn; i < maxn; i++)
                if (isPrime[i])
                        prime[nprime++] = i;
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

int findOrder(int k) {
        int l = 0, r = nprime;

        while (l + 1 < r) {
                int mid = (l + r) / 2;
                if (prime[mid] <= k)
                        l = mid;
                else
                        r = mid;
        }

        return prime[l] == k ? l : -1;
}

void initialize() {
        getPrime();
        memset(distance, 0, sizeof(distance));

        int num[len];
        for (int i = 0; i < nprime; i++) {
                int p = prime[i];
                split(p, num);
                for (int k = 0; k <= 4; k++) {
                        int org = num[k];
                        for (int j = (k > 0 ? 0 : 1); j <= 9; j++) {
                                num[k] = j;
                                int r = findOrder(combine(num));
                                if (r >= 0 && r != i)
                                        distance[i][r] = 1;
                        }
                        num[k] = org;
                }
        }
}

int findPath(int a, int b)
{
        if (a == b)
                return 0;

        a = findOrder(a);
        b = findOrder(b);
        bool visited[maxprime];
        memset(visited, false, sizeof(visited));

        while (true) {
                int minr, mincost;
                mincost = maxn;
                for (int i = 0; i < nprime; i++) {
                        if (!visited[i] &&
                                  distance[a][i] && distance[a][i] < mincost) {
                                minr = i;
                                mincost = distance[a][i];
                        }
                }

                if (mincost >= maxn)
                        break;
                visited[minr] = true;

                for (int i = 0; i < nprime; i++) {
                        if (i != a && distance[minr][i])
                        if (!distance[a][i] || mincost + distance[minr][i] < distance[a][i]) {
                                distance[a][i] = mincost + distance[minr][i];
                        }
                }
        }

        return distance[a][b] ? distance[a][b] : -1;
}


int main(void)
{
        int loop;
        cin >> loop;

        initialize();
        while (loop--) {
                int a, b;
                cin >> a >> b;
                int k = findPath(a, b);
                if (k >= 0)
                        cout << k << endl;
                else
                        cout << "Impossible" << endl;
        }
        return 0;
}
