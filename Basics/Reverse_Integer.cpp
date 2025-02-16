#include <bits/stdc++.h>  
using namespace std;  
#define ll long long

class Solution {
public:
    int reverse(int x) {
        ll ans = 0;
        while (x) {
            int rem = x % 10;
            ans = ans * 10 + rem;
            x /= 10;
        }
        if (ans > INT_MAX || ans < INT_MIN) {
            return 0;
        }
        return int(ans);
    }
};