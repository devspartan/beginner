#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        string s;
        cin >> s;
        long long int ttl = 0, sm = 0;
        for (long long int i = 0; i < n; i++) {
            if (s[i] == '1') {
                sm++;
            } else {
                ttl++;
            }
        }
        vector<long long int> factors;
        for (long long int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                if (n / i == i) {
                    factors.push_back(i);
                } else {
                    factors.push_back(n / i);
                    factors.push_back(i);
                }
            }
        }
        long long int ans = 1e9;
        for (auto it : factors) {
            vector<long long int> freq(it);
            for (long long int i = 0; i < it; i++) {
                for (long long int j = i; j < n; j += it) {
                    if (s[j] == '1') {
                        freq[i]++;
                    }
                }
            }
            long long int req = n / it;
            for (long long int i = 0; i < it; i++) {
                long long int to_convert = req - freq[i];
                to_convert += (sm - freq[i]);
                ans = min(ans, to_convert);
            }
        }
        cout << ans << endl;
    }
}
