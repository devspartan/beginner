#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void util() {
    int n, q;

    cin >> n >> q;
    string s;
    cin >> s;
    int len = s.length();
    vector<int> arr(len);
    for (int i = 0; i < len; i++) {
        arr[i] = s[i] == '+' ? 1 : -1;
    }

    int temp = q;
    while (temp--) {
        int l1, r1;
        cin >> l1 >> r1;

        bool check = true;
        int sum = 0;
        for (int i = l1 - 1; i < r1; i++) {
            sum += check ? 1 * arr[i] : -1 * arr[i];
            check = !check;
        }

        cout << sum << endl;
    }
    return;
}

int main() {

    int tst;
    cin >> tst;
    while (tst--) {
        util();
    }
    return 0;
}