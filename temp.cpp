#include <bits/stdc++.h>

using namespace std;

int main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        vector<int> vt;
        long long int sum = 0;
        for (int i = 0; i < n + 2; i++) {
            int temp;
            cin >> temp;
            sum += temp;
            vt.push_back(temp);
        }
        long int res = -1;
        long int idx = -1;
        sort(vt.begin(), vt.end());
        long long int x1 = sum - 2 * vt[n + 1];
        long long int x2 = sum - 2 * vt[n];

        // cout << x1 << " " << x2 << endl;
        for (int i = 0; i < n + 2; i++) {
            if (x1 == vt[i] && i != n + 1) {
                res = i;
                idx = n + 1;
                break;
            } else if (x2 == vt[i] && i != n) {
                res = i;
                idx = n;
                break;
            }
        }

        // cout << res  << " " << idx << " " << endl;

        if (res == -1) {
            cout << "-1" << endl;
        } else {
            for (int i = 0; i < vt.size(); i++) {
                if (i == res || i == idx) {
                    continue;
                } else {
                    cout << vt[i] << " ";
                }
            }
            cout << endl;
        }
    }
}

// int a, b;
//         string str;
//         cin >> a >> b;
//         cin >> str;

//         int ret = 0;

//         int length = str.length();

//         if (a % 2 == 1 && b % 2 == 1) {
//             ret = 1;
//         } else {
//             for (int i = 0; i < length; i++) {
//                 if (str[i] == '1') {
//                     b--;
//                 } else if (str[i] == '0') {
//                     a--;
//                 }
//             }

//             if (a < 0 || b < 0) {
//                 ret = 1;
//             } else {
//                 for (int i = 0; i <= length / 2; i++) {

//                     if (a < 0 || b < 0) {
//                         ret = 1;
//                         break;
//                     }

//                     if (str[i] == '1' && str[length - i - 1] == '1' ||
//                         str[i] == '0' && str[length - i - 1] == '0') {
//                         continue;
//                     } else if (str[i] == '1' && str[length - i - 1] == '?' ||
//                                str[i] == '?' && str[length - i - 1] == '1') {
//                         str[i] = '1';
//                         str[length - i - 1] = '1';
//                         b--;
//                     } else if (str[i] == '0' && str[length - i - 1] == '?' ||
//                                str[i] == '?' && str[length - i - 1] == '0') {
//                         str[i] = '0';
//                         str[length - i - 1] = '0';
//                         a--;
//                     } else if (str[i] == '?' && str[length - i - 1] == '?') {
//                         if (a < b) {
//                             if (i == length - i - 1) {
//                                 str[i] = '1';
//                                 b -= 1;
//                             } else {
//                                 str[i] = '1';
//                                 str[length - i - 1] = '1';
//                                 b -= 2;
//                             }
//                         } else {
//                             if (i == length - i - 1) {

//                                 str[i] = '0';
//                                 a -= 1;
//                             } else {
//                                 str[i] = '0';
//                                 str[length - i - 1] = '0';
//                                 a -= 2;
//                             }
//                         }
//                     } else {
//                         ret = 1;
//                         break;
//                     }
//                 }
//             }
//         }

//         if (ret) {
//             cout << "-1" << endl;
//         } else {
//             cout << str << endl;
//         }
