#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

long long int pw(long long int n1, long long int p) {
    long long int res = 1;
    for (long long int i = 0; i < p; i++) {
        res *= n1;
    }
    return res;
}

long long int lenOfNum(long long int num) {
    long long int len = 0;
    while (num) {
        num /= 10;
        len++;
    }
    return len;
}

long long int util() {
    long long int n, d;
    cin >> n >> d;

    long long int len = lenOfNum(n);

    long long int res = 0, oN = n;
    bool if9 = true;
    if (d == 0) {
        long long int temp = n;
        long long int tempLen = len - 1;
        bool check = false;
        while (tempLen + 1) {
            long long int power10 = pw(10, tempLen);
            long long int q1 = temp / power10;
            if (q1 == 0 || check) {
                res += 1 * power10;
                check = true;
            } else {
                res += q1 * power10;
            }
            temp = temp % power10;
            tempLen--;
        }
    } else if (d == 9) {
        while (if9) {
            res = 0;
            long long int temp = n;
            long long int tempLen = lenOfNum(n) - 1;
            bool check = false;
            while (tempLen + 1) {
                long long int power10 = pw(10, tempLen);
                long long int q1 = temp / power10;
                if (check) {
                    res += 0 * power10;
                } else if (q1 == d) {
                    res += (d + 1) * power10;
                    check = true;
                } else {
                    res += q1 * power10;
                }
                temp = temp % power10;
                tempLen--;
            }

            long long int tempRes = res;
            long long int resLen = lenOfNum(tempRes);
            while (resLen) {
                long long int power10 = pw(10, resLen);
                long long int q1 = tempRes / power10;
                if (q1 == 9) {
                    if9 = true;
                    break;
                } else {
                    if9 = false;
                }
                tempRes = tempRes % power10;
                resLen--;
            }
            n = res;
        }
    } else {
        long long int temp = n;
        long long int tempLen = len - 1;
        bool check = false;
        while (tempLen + 1) {
            long long int power10 = pw(10, tempLen);
            long long int q1 = temp / power10;
            if (check) {
                res += 0 * power10;
            } else if (q1 == d) {
                res += (d + 1) * power10;
                check = true;
            } else {
                res += q1 * power10;
            }
            temp = temp % power10;
            tempLen--;
        }
    }
    return res - oN;
}

long int util(vector<vector<int>> &arr, int i, int j) {
    int m = arr.size();
    int n = arr[0].size();

    if (arr[i][j] == -1) {
        return INT32_MAX;
    }
    if (arr[i][j] == 0) {
        return 1;
    }
    if (arr[i][j] > 1 || arr[i][j] == 0) {
        return arr[i][j];
    }

    long int t1 = INT32_MAX, t2 = INT32_MAX, t3 = INT32_MAX, t4 = INT32_MAX;

    arr[i][j] = -1;
    if (i + 1 < m) {
        t1 = util(arr, i + 1, j) + 1;
    }
    if (i - 1 >= 0) {
        t2 = util(arr, i - 1, j) + 1;
    }
    if (j + 1 < n) {
        t3 = util(arr, i, j + 1) + 1;
    }
    if (j - 1 >= 0) {
        t4 = util(arr, i, j - 1) + 1;
    }
    arr[i][j] = 1;
    long int minRes = min(min(t1, t2), min(t3, t4));
    cout << i << " " << j << " -> " << minRes << endl;
    cout << t1 << " " << t2 << " " << t3 << " " << t4 << endl << endl;
    arr[i][j] = minRes;

    return minRes;
}

int fn(vector<vector<int>> arr) {
    int m = arr.size();
    int n = arr[0].size();

    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 2) {
                q.push(make_pair(i, j));
            }
        }
    }
    q.push(make_pair(-1, -1));
    while (q.front().first != -1) {
        pair<int, int> p;
        while (q.front().first != -1) {
            p = q.front();
            q.pop();
            int i = p.first;
            int j = p.second;

            if (i - 1 >= 0 && arr[i - 1][j] == 1) {
                q.push(make_pair(i - 1, j));
                arr[i - 1][j] += arr[i][j];
            }
            if (i + 1 < m && arr[i + 1][j] == 1) {
                q.push(make_pair(i + 1, j));
                arr[i + 1][j] += arr[i][j];
            }
            if (j - 1 >= 0 && arr[i][j - 1] == 1) {
                q.push(make_pair(i, j - 1));
                arr[i][j - 1] += arr[i][j];
            }
            if (j + 1 < n && arr[i][j + 1] == 1) {
                q.push(make_pair(i, j + 1));
                arr[i][j + 1] += arr[i][j];
            }
        }
        q.pop();
        q.push(make_pair(-1, -1));
    }

    int minRes = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 1) {
                return -1;
            }
            minRes = max(minRes, arr[i][j]);
        }
    }

    return minRes - 2;
}

int finalWeight(int input1, int input2, int input3, int input4, int input5[]) {
    vector<int> cumSum;

    int tempK = input2;
    int tempS = 0;
    int k = 0;
    while (tempK--) {
        tempS += input5[k];
        k++;
    }
    cumSum.push_back(tempS);
    int j = 0;
    for (int i = k; i < input1; i++) {
        tempS = tempS + input5[i] - input5[j];
        cumSum.push_back(tempS);
        j++;
    }

    int res = 0;
    for (auto cal : cumSum) {
        if (cal < input3) {
            res--;
        } else if (cal > input4) {
            res++;
        }
    }

    return res;
}

int startPoint(int input1, int input2[]) {

    vector<int> res;

    res.push_back(input2[0]);
    for (int i = 1; i < input1; i++) {
        int count = input2[i];
        for (int j = 0; j < i; j++) {
            if ((i + 1) % (j + 1) == 0) {
                count -= res[j];
            }
        }

        if (count > 0) {
            res.push_back(count);
        } else {
            res.push_back(0);
        }
    }

    for (auto it : res) {
        cout << it << " ";
    }

    return 0;
}

int sum(vector<int> &curr) {
    int tempSum = 0;
    int size = curr.size();
    for (auto it : curr) {
        tempSum += it;
    }
    return tempSum;
}

void pop_front(vector<int> &v) {
    if (v.size() > 0) {
        v.erase(v.begin());
    }
}

int max_length(int s[], int n, int k) {

    vector<int> current;

    int max_len = -1;

    for (int i = 0; i < n; i++) {
        current.push_back(s[i]);
        while (sum(current) > k) {
            // pop_front(current);
            if (sum(current) == k) {
                if (current.size() > max_len) {
                    max_len = current.size();
                }
                // max_len = max(max_len, current.size());
            }
        }
    }

    return max_len;
}
int atMostSum(int arr[], int n, int k) {
    int sum = 0;
    int cnt = 0, maxcnt = 0;

    for (int i = 0; i < n; i++) {

        if ((sum + arr[i]) <= k) {
            sum += arr[i];
            cnt++;
        }

        else if (sum != 0) {
            sum = sum - arr[i - cnt] + arr[i];
        }

        maxcnt = max(cnt, maxcnt);
    }
    return maxcnt;
}

long long int sn(long long int a, long long int s) {
    if (a == 2) {
        ++s;
        return s;
    } else if (a == 3) {
        ++s;
        return sn(2, s);
    }

    if (a % 2 == 0) {
        for (int i = 3;; ++i) {
            if (a % i != 0) {

                ++s;
                return sn(i, s);
            }
        }
    }

    ++s;
    return sn(2, s);
}

const long long int TIER1 = 6;              // lcm up to prime < 4
const long long int TIER2 = 420;            // lcm up to prime < 8
const long long int TIER3 = 360360;         // lcm up to prime < 16
const long long int TIER4 = 72201776446800; // lcm up to prime < 32

long long int strengthUpto(long long int n) {
    long long int even = n / 2;   // too lazy to exclude 2
    long long int odd = n - even; // too lazy to exclude 1

    long long int tier1 = n / TIER1;
    long long int tier2 = n / TIER2;
    long long int tier3 = n / TIER3;
    long long int tier4 = n / TIER4;

    tier1 = tier1 - tier1 / 2;
    tier2 = tier2 - tier2 / 2;
    tier3 = tier3 - tier3 / 2;
    tier4 = tier4 - tier4 / 2;

    return odd * 2 + even * 3 + (tier1 + tier2 + tier3 + tier4);
}

long long int sumStrength_f(long long int a, long long int b) {
    return strengthUpto(b) - strengthUpto(a - 1);
}

int maxTime(int n, int k, vector<int> &arr) {

    sort(arr.begin(), arr.end());

    int c = n / k;
    int r = n % k;

    int i = 0;

    int maxTime = 0;
    while (k--) {
        if (k == 0) {
            int t1 = arr[c * i];
            int t2 = arr[((i + 1) * c) - 1 + r];
            int t3 = (t1 + t2) / 2;

            maxTime = max(maxTime, max(t3 - t1, t2 - t3));

        } else {
            int t1 = arr[c * i];
            int t2 = arr[((i + 1) * c) - 1];
            int t3 = (t1 + t2) / 2;
            maxTime = max(maxTime, max(t3 - t1, t2 - t3));
        }
        i++;
    }

    return maxTime;
}

// user-defined data-types
struct pr {
    int first;
    int second;
};

// user-defined function to
// design a set
bool operator<(pr a, pr b) {
    if (a.second == b.second)
        return a.first > b.first;
    return a.second > b.second;
}

set<pr> s1, s2;

unordered_map<int, int> m;

void type1(int num) {

    if (m[num]) {
        int cnt = m[num];

        auto it1 = s1.find({num, cnt});

        s1.erase(it1);
        s2.erase(it2);

        s1.insert({num, m[num] + 1});
    }

    else {
        s1.insert({num, 1});
    }

    m[num] += 1;
}

// Function to process the query
// of type-2
void type2(int num) {
    // if the element exists
    if (m[num]) {

        // get the frequency of the element
        int cnt = m[num];

        // returns an iterator pointing to
        // position where the pair is
        auto it1 = s1.find({num, cnt});
        auto it2 = s2.find({cnt, num});

        // deletes the pair from sets
        s1.erase(it1);
        s2.erase(it2);

        // re-insert the pair by increasing
        // frequency
        s1.insert({num, m[num] - 1});
        s2.insert({m[num] - 1, num});

        // decrease the count
        m[num] -= 1;
    }
}

// Function to process the query
// of type-3
int type3() {
    // if the set is not empty
    // return the first element
    if (!s1.empty()) {
        auto it = s1.begin();
        int num = it->first;
        cout << it->first << " " << it->second << " ot " << endl;
        type2(it->first);
        return num;
    } else
        return -1;
}

int main() {

    int t;
    // cin >> t;

    vector<int> vt;
    type1(1);
    type1(4);
    type1(2);
    type1(5);
    type1(3);
    type1(6);

    for (auto it : s1) {
        cout << it.first << " " << it.second << endl;
    }
    cout << type3() << endl;

        return 0;
}