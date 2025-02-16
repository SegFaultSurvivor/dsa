#include <bits/stdc++.h>  
using namespace std; 

class Solution {
    public:
        int fib(int n) {
            // if (n == 0)
            //     return 0;
            // if (n == 1)
            //     return 1;
            // int ans = 0;
            // int a1 = 0, a2 = 1;
            // for (int i = 2; i <= n; i++) {
            //     ans = a1 + a2;
            //     a1 = a2;
            //     a2 = ans;
            // }
            // return a2;
            if (n == 0 || n == 1)
                return n;
            int ans = fib(n - 1) + fib(n - 2);
            return ans;
        }
    };