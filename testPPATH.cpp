// Tester
// Problem: PPATH
// Author: Arapat Jurat
// Date: Oct. 17
// Submission: 

#include <iostream>
#include <cstring>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;
const int minn = 1000, maxn = 10000;
const int len = 4;

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

int main(void)
{
        getPrime();
        /*
        // Random Tests
        int testcases = 1000;
        cout << testcases << endl;
        for (int i = 0; i < testcases; i++) {
                int a = rand() % nprime;
                int b = rand() % nprime;
                cout << prime[a] << ' ' << prime[b] << endl;
        }
        */
        int testcases = nprime * nprime;
        cout << testcases << endl;
        for (int i = 0; i < nprime; i++)
                for (int j = 0; j < nprime; j++)
                        cout << prime[i] << ' ' << prime[j] << endl;
        return 0;
}
