#include <bits/stdc++.h>

using namespace std;

void printVect(vector<int> vt) {
    for (int i = 0; i < vt.size(); i++) {
        cout << vt[i] << " ";
    }
    cout << endl;
}

string longestPalindrome(string str) {
    int size = str.length();

    if (size == 0) {
        return "";
    }

    bool **dp = new bool *[size];

    int maxlen = 1;
    int stIdx = 0;
    int endIdx = 0;

    for (int i = 0; i < size; i++) {
        dp[i] = new bool[size];
    }

    for (int i = 0; i < size; i++) {
        dp[i][i] = 1;
    }

    int count = 1;
    for (int i = 0; i < size - 1; i++) {
        if (str[i] == str[i + 1]) {
            dp[i][i + 1] = 1;
            if (2 > maxlen) {
                stIdx = i;
                maxlen = 2;
            }
        }
    }

    for (int k = 2; k < size; k++) {
        for (int i = 0; i < size - k; i++) {
            int j = i + k;
            dp[i][j] = (str[i] == str[j]) ? true : false;
            if (dp[i][j]) {
                dp[i][j] = dp[i + 1][j - 1];
            }

            if (dp[i][j]) {
                int diff = abs(j - i) + 1;
                if (diff > maxlen) {
                    maxlen = diff;
                    stIdx = i;
                }
            }
        }
    }

    cout << stIdx << " " << maxlen << endl;
    // bool st[size];
    // for (int i = 0; i < size; i++) {
    //     st[i] = false;
    // }
    // int len = size - 1;
    // int countNonOverlappingSub = 0;
    // for (int i = 0; i < size; i++) {
    //     for (int j = 0; j <= i; j++) {
    //         if (dp[j][j + len] == 1 && !st[j]) {
    //             countNonOverlappingSub++;
    //             cout << "len: " << len + 1 << "  st: " << j
    //                  << " ed: " << j + len << "  " << dp[j][j + len] << endl;
    //             for (int k = j; k <= j + len; k++) {
    //                 st[k] = true;
    //             }
    //         }
    //     }
    //     len--;
    // }

    // cout << countNonOverlappingSub << endl;

    // for (int i = 0; i < size; i++) {
    //     for (int j = 0; j < size; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << stIdx << " " << endIdx << " " << maxlen << endl;

    string res;
    if (maxlen > 0) {
        for (int i = stIdx; i < stIdx + maxlen; i++) {
            res.push_back(str[i]);
        }
    }

    return res;
}

void swap(string &str, int i, int j) {
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}

void reverseString(string &str) {
    int size = str.size();
    for (int i = 0; i < size / 2; i++) {
        swap(str, i, size - i - 1);
    }

    for (int i = 0; i < size; i++) {
        str[i] = (str[i] == ')') ? '(' : ')';
    }
}

int longestValidParenthesis(string str) {
    int size = str.size();

    if (size < 1) {
        return 0;
    }

    int open = 0;
    int close = 0;
    int maxlen = 0;
    int len = 0;
    for (int i = 0; i < size; i++) {
        if (str[i] == '(') {
            open++;
        } else {
            close++;
        }
        len++;

        if (close == open) {
            if (len > maxlen) {
                maxlen = len;
                open = 0;
                close = 0;
            }
        } else if (close > open) {
            open = 0;
            close = 0;
            len = 0;
        }
    }
    return maxlen;
}

int longestValidParenthesisStack(string str) {

    int size = str.length();
    stack<int> index;
    stack<char> parenthesis;

    int len = 0;
    int maxlen = 0;
    for (int i = 0; i < size; i++) {
        if (str[i] == '(') {
            index.push(i);
            parenthesis.push('(');
        } else {
            if (!parenthesis.empty() && parenthesis.top() == '(') {
                index.pop();
                parenthesis.pop();
                len = i - index.top();
            } else {
                index.push(i);
            }
        }

        if (len > maxlen) {
            maxlen = len;
        }
    }

    return maxlen;
}

int longestValidPrenthesisDP(string str) {
    int size = str.size();
    cout << "size " << size << endl;
    if (size < 1) {
        return 0;
    }

    int dp[size] = {0};
    int maxlen = 0;
    for (int i = 1; i < size; i++) {
        if (str[i] == '(') {
            dp[i] = 0;
        } else if (str[i] == ')') {
            if (str[i - 1] == '(') {
                dp[i] = dp[i - 2] + 2;
            } else if (str[i - dp[i - 1] - 1] == '(') {
                dp[i] = dp[i - 1] + 2 + dp[i - dp[i - 1] - 2];
            }
        }
    }
    for (int i = 0; i < size; i++) {
        if (dp[i] > maxlen) {
            maxlen = dp[i];
        }
        cout << dp[i] << " ";
    }
    cout << endl;
    return maxlen;
}

bool isInterleave(string s1, string s2, string s3) {
    // given three str can s3 be formed by interleaving s1 and s2;
    int size1 = s1.size();
    int size2 = s2.size();
    int size3 = s3.size();
    int i = 0, j = 0, k = 0;
    int fst = true;
    int scnd = false;
    while (k < size3) {
        int oldi = i;
        int oldj = j;
        if (fst) {
            if (s1[i] == s3[k]) {
                i++;
                k++;
            } else {
                scnd = true;
                fst = false;
            }
        }
        if (scnd) {
            if (s2[j] == s3[k]) {
                j++;
                k++;
            } else {
                fst = true;
                scnd = false;
            }
        }
    }

    return true;
}

bool isInterleaveDPhelper(string s1, string s2, string s3, int i, int j, int k,
                          int **dp) {
    if (k >= s3.length()) {
        return true;
    }

    if (i < s1.length() && j < s2.length() && dp[i][j] == 1) {
        return (dp[i][j] == 1);
    }

    bool a1 = false, a2 = false;
    if (i < s1.length() && s1[i] == s3[k]) {
        a1 = isInterleaveDPhelper(s1, s2, s3, i + 1, j, k + 1, dp);
    }
    if (j < s2.length() && s2[j] == s3[k]) {
        a2 = isInterleaveDPhelper(s1, s2, s3, i, j + 1, k + 1, dp);
    }

    // cout << a1 << a1 << "  " << i << " " << j << "  " << k << endl;

    if (a1 || a2) {
        if (i < s1.length() && j < s2.length()) {
            dp[i][j] = 1;
        }
        return true;
    }

    return false;
}

bool isInterleaveDP(string s1, string s2, string s3) {
    int m = s1.length();
    int n = s2.length();
    int k = s3.length();

    if (m + n != k) {
        return false;
    }
    if ((s1.empty() && s2 != s3) || (s2.empty() && s1 != s3)) {
        return false;
    }
    int **dp = new int *[m];
    for (int i = 0; i < m; i++) {
        dp[i] = new int[n];
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }
    string res = "";
    bool ans = isInterleaveDPhelper(s1, s2, s3, 0, 0, 0, dp);

    return ans;
}

int countCharacters(vector<string> &words, string chars) {
    // returns max len of words that can be formed using chars of chars only
    // once;

    int size = words.size();
    int len = chars.length();

    if (size == 0) {
        return 0;
    } else if (len == 0) {
        return 0;
    }

    vector<int> hash(26), tempHash;
    for (int i = 0; i < 26; i++) {
        hash[i] = 0;
    }

    for (int i = 0; i < len; i++) {
        hash[chars[i] - 97]++;
    }

    int maxlen = 0;
    for (int i = 0; i < size; i++) {
        int tempLen = words[i].length();
        bool found = true;
        tempHash = hash;

        for (int j = 0; j < tempLen; j++) {
            if (tempHash[words[i][j] - 97] == 0) {
                found = false;
                break;
            } else {
                tempHash[words[i][j] - 97]--;
            }
        }

        if (found) {
            maxlen += tempLen;
        }
    }

    return maxlen;
}

int getNextCharIdx(string s, char c, int current) {
    for (int i = current + 1; i < s.length(); i++) {
        if (s[i] == c) {
            return i;
        }
    }
    return -1;
}

vector<int> shortestToChar(string s, char c) {
    int size = s.length();
    vector<int> res;
    int c1 = -1;
    int c2 = getNextCharIdx(s, c, -1);

    for (int i = 0; i < size; i++) {
        int k1 = abs(c1 - i);
        int k2 = abs(c2 - i);

        if (c1 == -1) {
            res.push_back(k2);
        } else if (c2 == -1) {
            res.push_back(k1);
        } else if (k1 < k2) {
            res.push_back(k1);
        } else {
            res.push_back(k2);
        }

        if (k2 == 0) {
            c1 = c2;
            c2 = getNextCharIdx(s, c, c2);
        }
    }
    // for(int i = 0; i < size; i++) {
    //     cout << res[i] << " ";
    // }
    // cout <<endl;
    return res;
}

int countMatches(vector<vector<string>> &items, string ruleKey,
                 string ruleValue) {

    int searchIdx = 0;

    if (ruleKey == "type") {
        searchIdx = 0;
    } else if (ruleKey == "color") {
        searchIdx = 1;
    } else if (ruleKey == "name") {
        searchIdx = 2;
    }

    int resCount = 0;
    for (int i = 0; i < items.size(); i++) {
        if (items[i][searchIdx] == ruleValue) {
            resCount++;
        }
    }
    return resCount;
}

void letterCasePerUtil(string s, int i, vector<string> &res) {

    if (i == s.length()) {
        cout << "git " << s << " " << endl;
        res.push_back(s);
    }
    if (i >= s.length()) {
        cout << "from 1";
        return;
    }
    while (i < s.length() && s[i] > 47 && s[i] < 58) {
        i++;
    }

    letterCasePerUtil(s, i + 1, res);

    s[i] = s[i] - 32;
    letterCasePerUtil(s, i + 1, res);

    return;
}

vector<string> letterCasePermutation(string S) {
    vector<string> res;

    letterCasePerUtil(S, 0, res);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return res;
}

int minimumLengthEncoding(vector<string> &words) {
    string str = "";
    sort(words.begin(), words.end(),
         [](string &a, string &b) { return a.size() > b.size(); });
    for (int i = 0; i < words.size(); i++) {
        cout << words[i] << " ";
    }
    cout << endl;
    for (string word : words) {
        int found = str.find(word);
        if (found == string::npos || str[found + word.size()] != '#') {
            str += word + "#";
        }
    }
    return str.size();
}

int firstUniqChar(string s) {
    vector<int> hash(27);
    int len = s.length();
    stack<int> st;
    for (int i = len - 1; i >= 0; i--) {
        if (hash[s[i] - 97] == 0) {
            st.push(i);
        }
        hash[s[i] - 97]++;
    }

    while (!st.empty()) {
        int k = st.top();
        if (hash[s[k] - 97] == 1) {
            return k;
        }
        st.pop();
    }

    return -1;
}

bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
        return false;
    }
    vector<int> hash(26);
    for (int i = 0; i < s.length(); i++) {
        hash[s[i] - 97]++;
    }
    for (int i = 0; i < t.length(); i++) {
        hash[t[i] - 97]--;
    }
    for (int i = 0; i < 26; i++) {
        if (hash[i] != 0) {
            return false;
        }
    }

    return true;
}

int strStr(string haystack, string needle) {
    int k = haystack.find(needle);
    return k;
}

string countAndSay(int n) {
    if (n == 1) {
        return "1";
    }

    string tt = countAndSay(n - 1);
    string res = "";
    int count = 1;
    for (int i = 0; i < tt.length() - 1; i++) {
        if (tt[i] == tt[i + 1]) {
            count++;
        } else {
            res += to_string(count) + "" + tt[i];
            count = 1;
        }
    }

    res += to_string(count) + "" + tt[tt.length() - 1];
    return res;
}

string longestCommonPrefix(vector<string> &strs) {

    int size = strs.size();

    if (size == 0) {
        return "";
    }
    if (size == 1) {
        return strs[0];
    }

    string res = "";
    for (int j = 0; j < strs[0].length() && j < strs[1].length(); j++) {
        if (strs[0][j] == strs[1][j]) {
            res += strs[0][j];
        } else {
            break;
        }
    }

    string temp;
    for (int i = 2; i < size; i++) {
        temp = "";
        for (int j = 0; j < strs[i].length() && j < res.length(); j++) {
            if (strs[i][j] == res[j]) {
                temp += res[j];
            } else {
                break;
            }
        }
        res = temp;
    }

    return res;
}

bool hasAllCodes(string s, int k) {
    if (s.length() < k) {
        return false;
    }

    long int count = pow(2, k);
    string temp;
    for (int i = 0; i < k; i++) {
        temp += s[i];
    }
    set<string> hashSet;
    for (int i = 0; i < s.length() - k + 1; i++) {
        temp = s.substr(i, k);
        hashSet.insert(temp);
        if (hashSet.size() >= count) {
            return true;
        }
    }

    return false;
}

int lengthOfLongestSubstring(string s) {
    vector<int> hash(150, -1);
    int len = s.length();
    int maxLen = 0;
    int temp = 0;
    int j = 0;
    int i = 0;
    int last = j;
    while (j < len && i < len) {
        for (i = last; i < s.length(); i++) {
            if (hash[s[i]] == -1) {
                hash[s[i]] = i;
                temp++;
            } else {
                while (j <= hash[s[i]]) {
                    hash[s[j]] = -1;
                    j++;
                }
                last = i;
                break;
            }
        }

        if (temp > maxLen) {
            maxLen = temp;
        }
        temp = last - j;
    }
    return maxLen;
}

bool compareLexographically(string s, int i, int j) {
    while (i < s.length() && j < s.length()) {
        if (s[i] < s[j]) {
            return true;
        } else if (s[i] > s[j]) {
            return false;
        }
        i++;
        j++;
    }

    return true;
}

string smallestSubsequence(string s) {
    int size = s.length();
    int hash[27] = {0};
    int vis[27] = {0};
    string res;
    stack<char> st;
    for (int i = 0; i < size; i++) {
        hash[s[i] - 97] = i;
    }

    for (int i = 0; i < size; i++) {
        if (vis[s[i] - 97]) {
            continue;
        } else {
            while (!st.empty() && st.top() > s[i] && hash[st.top() - 97] > i) {
                vis[st.top() - 97] = 0;
                st.pop();
            }

            st.push(s[i]);
            vis[s[i] - 97] = 1;
        }
    }

    string str = "";
    while (!st.empty()) {
        char ch = st.top();
        str += ch;
        st.pop();
    }
    reverse(str.begin(), str.end());

    return str;
}

int removePalindromeSub(string s) {
    int len = s.length();
    for (int i = 0; i < len / 2; i++) {
        if (s[i] == s[len - i - 1]) {
            continue;
        } else {
            return 2;
        }
    }
    return 1;
}

int longestPalindromeCount(string s) {
    unordered_map<char, int> umap;

    int len = s.length();
    for (int i = 0; i < len; i++) {
        umap[s[i]]++;
    }

    for (auto it : umap) {
        cout << it.first << " -> " << it.second << endl;
    }
    int count = 0;
    int maxOdd = 0;
    bool check = false;
    bool gotOdd = false;
    for (auto it : umap) {
        if (it.second % 2 == 0) {
            count += it.second;
        } else {
            if (it.second == 1 && check == false) {
                count++;
                check = true;
            } else {
                count += it.second - 1;
            }
            gotOdd = true;
        }
    }

    return gotOdd && check == false ? count + 1 : count;
}

bool isPalindrome(string s) {
    int len = s.length();

    for (int i = 0; i < len; i++) {
        if (s[i] >= 65 && s[i] <= 90) {
            s[i] += 32;
        }
    }

    bool check = true;
    int i = 0, j = len - 1;
    while (i < j) {
        if (s[i] >= 97 && s[i] <= 122 || s[i] >= 48 && s[i] <= 57) {
            if (s[j] >= 97 && s[j] <= 122 || s[j] >= 48 && s[j] <= 57) {
                if (s[i] != s[j]) {
                    check = false;
                    break;
                } else {
                    i++;
                    j--;
                }
            } else {
                j--;
            }
        } else {
            i++;
        }
    }

    return check;
}

bool canConstruct(string s, int k) {
    int len = s.length();

    if (len < k) {
        return false;
    }

    int oddCount = 0;
    int evenCount = 0;
    int hash[27] = {0};
    for (int i = 0; i < len; i++) {
        hash[s[i] - 97]++;
    }
    for (int i = 0; i < 27; i++) {
        if (hash[i] % 2 == 1) {
            oddCount++;
        } else if (hash[i] != 0) {
            evenCount++;
        }
    }

    if (oddCount > k) {
        return false;
    }

    return true;
}

int countSubstrings(string s) {
    int len = s.length();
    bool **dp = new bool *[len];

    int res = len;
    for (int i = 0; i < len; i++) {
        dp[i] = new bool[len];
    }

    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (i == j) {
                dp[i][j] = true;
            } else {

                dp[i][j] = false;
            }
        }
    }
    for (int i = 0; i < len - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            res++;
        }
    }

    for (int k = 2; k < len; k++) {
        for (int i = 0; i < len - k; i++) {
            int j = i + k;
            dp[i][j] = (s[i] == s[j]) ? true : false;
            if (dp[i][j]) {
                dp[i][j] = dp[i + 1][j - 1];
            }

            if (dp[i][j]) {
                res++;
            }
        }
    }

    return res;
}

int countSubstringsSol2(string s) {
    int cnt = s.length();
    int n = s.length();
    int j;

    for (int i = 1; i < s.length(); i++) {
        if (s[i - 1] == s[i]) {
            j = 0;
            while (((i + j) < n && (i - 1 - j) >= 0) &&
                   (s[i - 1 - j] == s[i + j])) {
                cnt++;
                j++;
            }
        }
        if ((i < (n - 1)) && (s[i - 1] == s[i + 1])) {
            j = 1;
            while (((i - j) >= 0 && (i + j) < n) && (s[i - j] == s[i + j])) {
                cnt++;
                j++;
            }
        }
    }
    return cnt;
}

int longestPalindromeSubseqRec(string s, int i, int j) {
    if (i == j) {
        return 1;
    }
    if (i > s.length() || j < 0 || i > j) {
        return 0;
    }

    int t1 = 0, t2 = 0;
    if (s[i] == s[j]) {
        t1 = longestPalindromeSubseqRec(s, i + 1, j - 1) + 2;
    } else {
        t2 = max(longestPalindromeSubseqRec(s, i + 1, j),
                 longestPalindromeSubseqRec(s, i, j - 1));
    }

    return max(t1, t2);
}

int longestPalindromeSubseq(string s) {
    int len = s.length();
    int **dp = new int *[len];

    for (int i = 0; i < len; i++) {
        dp[i] = new int[len];
    }

    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (i == j) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = 0;
            }
        }
    }

    for (int k = 1; k < len; k++) {
        for (int i = 0; i < len - k; i++) {
            int j = i + k;
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
    }

    return dp[0][len - 1];
}

int evalRPN(vector<string> &tokens) {
    stack<int> st;
    int size = tokens.size();
    int res = 0;

    for (int i = 0; i < size; i++) {
        string s = tokens[i];
        if (s == "/") {
            int t2 = st.top();
            st.pop();
            int t1 = st.top();
            st.pop();
            int t3 = t1 / t2;
            st.push(t3);
        } else if (s == "*") {
            int t1 = st.top();
            st.pop();
            int t2 = st.top();
            st.pop();
            int t3 = t1 * t2;
            st.push(t3);
        } else if (s == "+") {
            int t1 = st.top();
            st.pop();
            int t2 = st.top();
            st.pop();
            int t3 = t1 + t2;
            st.push(t3);
        } else if (s == "-") {
            int t2 = st.top();
            st.pop();
            int t1 = st.top();
            st.pop();
            int t3 = t1 - t2;
            st.push(t3);
        } else {
            stringstream geek(s);
            int x = 0;
            geek >> x;
            st.push(x);
        }
    }
    return st.top();
}

string breakPalindrome(string s) {
    int size = s.length();
    int mid = size + 1;
    bool gotcha = false;
    if (size % 2 != 0) {
        mid = (size / 2);
    }

    for (int i = 0; i < size; i++) {
        if (s[i] != 'a' && i != mid) {
            s[i] = 'a';
            gotcha = true;
            break;
        }
    }

    if (size >= 2 && gotcha == false) {
        s[size - 1] = 'b';
        gotcha = true;
    }

    return gotcha ? s : "";
}

vector<bool> canMakePaliQueries(string s, vector<vector<int>> &q) {
    int len = s.length();
    int size = q.size();
    vector<vector<int>> vt(len, vector<int>(26, 0));

    for (int i = 0; i < len; i++) {
        if (i != 0) {
            for (int j = 0; j < 26; j++) {
                vt[i][j] += vt[i - 1][j];
            }
        }
        vt[i][s[i] - 97]++;
    }

    vector<bool> res;
    for (int i = 0; i < size; i++) {
        vector<int> hash;
        int tempSize = q[i][1] - q[i][0] + 1;
        int oddCount = 0;
        for (int j = 0; j < 26; j++) {
            int temp;
            if (q[i][0] == 0) {
                temp = vt[q[i][1]][j];
            } else {
                temp = vt[q[i][1]][j] - vt[q[i][0] - 1][j];
            }

            if (temp % 2 == 1) {
                oddCount++;
            }
        }

        if (tempSize % 2 == 0) {
            if (q[i][2] >= oddCount / 2) {
                res.push_back(true);
            } else {
                res.push_back(false);
            }
        } else {
            if (q[i][2] >= oddCount / 2) {
                res.push_back(true);
            } else {
                res.push_back(false);
            }
        }
    }

    return res;
}

int LCSRecursiveUtil(string s1, string s2, int i, int j, int **dp) {
    if (i >= s1.length() || j >= s2.length()) {
        return 0;
    }

    if (dp[i][j]) {
        return dp[i][j];
    }

    cout << "fun call" << endl;

    if (s1[i] == s2[j]) {
        int temp = 1 + LCSRecursiveUtil(s1, s2, i + 1, j + 1, dp);
        dp[i][j] = temp;
        return temp;
    }

    int temp = max(LCSRecursiveUtil(s1, s2, i + 1, j, dp),
                   LCSRecursiveUtil(s1, s2, i, j + 1, dp));
    dp[i][j] = temp;
    return temp;
}

int LCSRec(string s1, string s2) {
    int l1 = s1.length();
    int l2 = s2.length();

    int **dp = new int *[l1];

    for (int i = 0; i < l1; i++) {
        dp[i] = new int[l2];
    }

    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < l2; j++) {
            dp[i][j] = 0;
        }
    }

    return LCSRecursiveUtil(s1, s2, 0, 0, dp);
}

int LCSDp(string s1, string s2) {
    int l1 = s1.length();
    int l2 = s2.length();

    int **dp = new int *[l1 + 1];

    for (int i = 0; i <= l1; i++) {
        dp[i] = new int[l2 + 1];
    }

    for (int i = 0; i <= l1; i++) {
        for (int j = 0; j <= l2; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[l1][l2];
}

bool compareInterval(string i1, string i2) {
    return (i1.length() < i2.length());
}

int maxProduct(vector<string> &words) {
    int size = words.size();

    vector<vector<int>> vt(size, vector<int>(26, 0));

    sort(words.begin(), words.end(), compareInterval);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < words[i].length(); j++) {
            vt[i][words[i][j] - 97]++;
        }
    }

    int max = 0;
    for (int i = size - 1; i > 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            bool check = true;
            for (int k = 0; k < 26; k++) {
                if (vt[i][k] > 0 && vt[j][k] > 0) {
                    check = false;
                    break;
                }
            }

            if (check) {
                int temp = words[i].length() * words[j].length();

                if (temp > max) {
                    max = temp;
                }

                break;
            }
        }
    }

    return max;
}

bool isValid(string s) {
    stack<char> st;
    int len = s.length();
    bool res = true;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        } else {
            if (!st.empty()) {
                if (s[i] == ')') {
                    if (st.top() == '(') {
                        st.pop();
                    } else {
                        res = false;
                        break;
                    }
                } else if (s[i] == '}') {
                    if (st.top() == '{') {
                        st.pop();
                    } else {
                        res = false;
                        break;
                    }
                } else if (s[i] == ']') {
                    if (st.top() == '[') {
                        st.pop();
                    } else {
                        res = false;
                        break;
                    }
                }
            } else {
                res = false;
                break;
            }
        }
    }

    if (res == true && !st.empty()) {
        res = false;
    }

    return res;
}

string simplifyPath(string path) {
    int len = path.length();

    deque<string> qq;
    string res;
    int i = 0;
    while (i < len) {
        string temp;
        if (path[i] == '/') {
            i++;
            continue;
        }

        while (i < len && path[i] != '/') {
            temp += path[i];
            i++;
        }

        cout << temp << endl;
        if (temp == ".") {
            continue;
        } else if (!qq.empty() && temp == "..") {
            qq.pop_back();
        } else if (temp != "..") {
            qq.push_back(temp);
        }
    }

    while (!qq.empty()) {
        res += '/' + qq.front();
        qq.pop_front();
    }

    return res == "" ? "/" : res;
}

int count(string a, string b, int m, int n) {

    if ((m == 0 && n == 0) || n == 0)
        return 1;

    if (m == 0)
        return 0;

    if (a[m - 1] == b[n - 1] || a[m - 1] == 2 && b[n - 1] == 5 ||
        a[m - 1] == 5 && b[n - 1] == 2 || a[m - 1] == 6 && b[n - 1] == 9 ||
        a[m - 1] == 9 && b[n - 1] == 6)
        return count(a, b, m - 1, n - 1) + count(a, b, m - 1, n);
    else
        return count(a, b, m - 1, n);
}

int strToNum(string s) {
    stringstream geek(s);
    int x = 0;
    geek >> x;

    return x;
}

int maximum_count(int N, int S, string M) {
    ostringstream str1;
    str1 << N;
    string num = str1.str();

    // for(int i = 0; i < num.length(); i++) {
    //     if(num[i] == '5') {
    //         num[i] = '2';
    //     } else if(num[i] == '6') {
    //         num[i] = '9';
    //     }
    // }

    // for(int i = 0; i < M.length(); i++) {
    //     if(M[i] == '5') {
    //         M[i] = '2';
    //     } else if(M[i] == '6') {
    //         M[i] = '9';
    //     }
    // }
    cout << M << "  " << num << " " << num.length() << endl;
    int res = count(M, num, S, num.length());

    return res;
}

int numberOfRounds(string startTime, string finishTime) {

    int ht1 = strToNum(startTime.substr(0, 2));
    int mt1 = strToNum(startTime.substr(3, 4));
    int ht2 = strToNum(finishTime.substr(0, 2));
    int mt2 = strToNum(finishTime.substr(3, 4));

    int m1 = (mt1 % 15 == 0 ? mt1 / 15 : mt1 / 15 + 1);
    int m2 = (mt2 % 15 == 0 ? mt2 / 15 : mt2 / 15);

    cout << ht1 << " : " << m1 << "  " << ht2 << " : " << m2 << endl;
    int t = ht1 * 60 + mt1;
    int y = ht2 * 60 + mt2;
    cout << t << " " << y << endl;

    if (t <= y) {
        cout << ht1 * 4 + m1 << "  " << ht2 * 4 + m2 << endl;
        return (ht2 * 4 + m2) - (ht1 * 4 + m1);
    } else {
        cout << 96 - (ht1 * 4 + m1) << "  " << ht2 * 4 + m2 << endl;
        return (96 - (ht1 * 4 + m1)) + (ht2 * 4 + m2);
    }
}

void printStringRec(vector<vector<string>> &str, int i, vector<string> &res) {

    if (i >= str.size()) {
        return;
    }

    for (int j = 0; j < str[i].size(); j++) {
        res.push_back(str[i][j]);
        printStringRec(str, i + 1, res);
        if (i == str.size() - 1) {
            for (int k = 0; k < res.size(); k++) {
                cout << res[k] << " ";
            }
            cout << endl;
        }
        res.pop_back();
    }
}

void printSubsequence(string str, string res) {
    if (str.length() == 0) {
        cout << res << endl;
        return;
    }

    printSubsequence(str.substr(1), res);
    printSubsequence(str.substr(1), res + str[0]);

    return;
}

void printSubsequenceNonRepeat(string str, string res, set<string> &st) {
    if (str.length() == 0) {
        st.insert(res);
        return;
    }

    printSubsequenceNonRepeat(str.substr(1), res, st);
    printSubsequenceNonRepeat(str.substr(1), res + str[0], st);
    return;
}

int editDistance(string s, string t, int i, int j) {
    if (i < 0 || j < 0) {
        return 0;
    }
}

bool areIsomorphic(string str1, string str2) {
    if (str1.length() != str2.length()) {
        return 0;
    }
    int from[150];
    int to[150];
    for (int i = 0; i < 150; i++) {
        from[i] = -1;
        to[i] = -1;
    }
    for (int i = 0; i < str1.length(); i++) {
        if (from[str1[i]] != -1 && str2[i] != from[str1[i]]) {
            return false;
        }
        if (to[str2[i]] != -1 && str1[i] != to[str2[i]]) {
            return false;
        }
        from[str1[i]] = str2[i];
        to[str2[i]] = str1[i];
    }

    return true;
}

int minOps(string &A, string &B) {
    int m = A.length(), n = B.length();

    if (n != m)
        return -1;
    int count[256];
    memset(count, 0, sizeof(count));
    for (int i = 0; i < n; i++)
        count[B[i]]++;
    for (int i = 0; i < n; i++)
        count[A[i]]--;
    for (int i = 0; i < 256; i++)
        if (count[i])
            return -1;

    int res = 0;
    for (int i = n - 1, j = n - 1; i >= 0;) {
        while (i >= 0 && A[i] != B[j]) {
            i--;
            res++;
        }

        if (i >= 0) {
            i--;
            j--;
        }
    }
    return res;
}

vector<vector<string>> Anagrams(vector<string> &vt) {

    int size = vt.size();

    unordered_map<string, vector<string>> mp;

    for (int i = 0; i < size; i++) {
        string s = vt[i];
        sort(s.begin(), s.end());
        mp[s].push_back(vt[i]);
    }

    vector<vector<string>> res;

    for (auto it : mp) {
        res.push_back(it.second);
    }

    return res;
}

vector<int> prefixSuffix(string pt) {
    cout << pt << endl;
    int lp = pt.length();

    vector<int> pref(lp, 0);

    int i = 1, j = 0;
    bool check = false;

    while (j < i && i < lp) {
        if (pt[i] == pt[j]) {
            pref[i] = j + 1;
            i++;
            j++;
        } else {
            if (j != 0) {
                j = pref[j - 1];
            } else {
                i++;
            }
        }
    }

    return pref;
}

string KMPAlgo(string str, string pt) {

    int ls = str.length();
    int lp = pt.length();

    if (ls < lp) {
        return "";
    }
    if (lp == 1) {
        for (int i = 0; i < ls; i++) {
            if (pt[0] == str[i]) {
                return pt;
            }
        }
        return "";
    }

    vector<int> pref = prefixSuffix(pt);

    printVect(pref);

    int j = 0, i = 0;
    while (i < ls) {
        if (pt[j] == str[i]) {
            j++;
            i++;
        }

        if (j == lp) {
            printf("Found pattern at index %d \n", i - j);
            j = pref[j - 1];
        }

        else if (i < ls && pt[j] != str[i]) {
            if (j != 0)
                j = pref[j - 1];
            else
                i = i + 1;
        }
    }

    return "";
}

string smallestWindow(string s, string p) {
    unordered_map<char, int> ump;

    int l1 = p.length();
    int l2 = s.length();
    int uniq = 0;
    for (int i = 0; i < l1; i++) {
        if (ump[p[i]] == 0) {
            uniq++;
        }
        ump[p[i]]++;
    }

    cout << s << endl;
    cout << p << endl;

    for (auto it : ump) {
        cout << it.first << " ===> " << it.second << endl;
    }

    cout << uniq << "\n";

    int resi = -1;
    int resj = -1;
    unordered_map<char, int> hp;
    int i = 0, j = 0;
    while (uniq && i < l2) {
        if (ump[s[i]] != 0) {
            if (hp[s[i]] == 0) {
                uniq--;
            }
            hp[s[i]]++;
        }
        i++;
    }

    for (auto it : hp) {
        cout << it.first << " ==> " << it.second << endl;
    }

    int mint = i - j;
    while (i <= l2) {
        cout << j << " " << s[j] << "--------" << i << " " << s[i] << "   "
             << mint << endl;
        while (j < i) {
            if (ump[s[j]] != 0) {
                cout << s[j] << "  " << hp[s[j]] << endl;
                if (hp[s[j]] == ump[s[j]]) {
                    int l = i - j;
                    if (l < mint) {
                        mint = l;
                        resi = i;
                        resj = j;
                    }
                    break;
                } else if (hp[s[j]] > ump[s[j]]) {
                    hp[s[j]]--;
                    j++;
                    int l = i - j;
                    if (l < mint) {
                        mint = l;
                        resi = i;
                        resj = j;
                    }
                }
            } else {
                j++;
            }
        }

        while (i < l2) {
            if (ump[s[i]] != 0) {
                hp[s[i]]++;
                i++;
                break;
            } else {
                i++;
            }
        }
    }

    for (auto it : hp) {
        cout << it.first << " ==> " << it.second << endl;
    }

    cout << resi << "  " << resj << " " << endl;
    return "res";
}

bool areRotations(string str1, string str2) {
    string temp = "aaarcbd";

    cout << temp.find(str1) << "  " << string::npos << endl;

    return false;
}

int main() {

    vector<string> vt = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    vector<vector<string>> st = {
        {"foo", "bar", "baz"}, {"he", "she"}, {"i", "am", "ullu", "yeah"}};

    string str = "poohrmtaxrykrzqxfctchjpxcqwn";
    string parenthesis = "()(((()())(";
    string s = "ecfbefdcfca";
    string v = "bcfbefdcfc";
    string t;

    // cin >> s;
    // cin >> v;
    // cin >> t;
    cout << s << endl;
    cout << v << endl;
    vector<string> res;

    // smallestWindow(s, v);

    // set<string> resSt;
    // printSubsequenceNonRepeat(s, "", resSt);
    // areRotations(s, v);
    // KMPAlgo(s, v);
    // cout << areIsomorphic(s, v) << endl;
    // printStringRec(st, 0, res);
    // cout << numberOfRounds(s, v);
    // cout << maximum_count(56, 6, "245769") << endl;
    // cout << simplifyPath(s) << endl;
    // cout << isValid(s) << endl;
    // cout << maxProduct(vt) << endl;
    // cout << LCSDp(s, v) << endl;
    // vector<vector<int>> queries = {
    //     {3, 3, 0}, {1, 2, 0}, {0, 3, 1}, {0, 3, 2}, {0, 4, 1}};
    // canMakePaliQueries(s, queries);
    // cout << breakPalindrome(s);
    // cout << evalRPN(pt);
    // cout << longestPalindromeSubseq(s) << endl;
    // cout << longestPalindromeSubseqRec(s, 0, s.length() - 1) << endl;
    // cout << countSubstrings(s) << endl;
    // cout << canConstruct(s, 2) << endl;
    // cout << isPalindrome(s) << endl;
    // cout << removePalindromeSub(s);
    // cout << lengthOfLongestSubstring(s) << endl;

    // cout << hasAllCodes(str, 2) << endl;
    // cout << longestCommonPrefix(pt) << endl;
    // cout << countAndSay(2) << endl;
    // cout << strStr(str, "") << endl;
    // cout << isPalindrome(str) << endl;
    // cout << firstUniqsr(str) << endl;
    // cout << minimumLengthEncoding(vt) << endl;
    // cout << longestPalindrome(str) << endl;
    // cout << str << endl;
    // reverseString(str)
    // cout << str << endl;
    // cout << longestValidPrenthesisDP(str)<< endl;
    // cout << longestValidParenthesis(str) << endl;
    // reverseString(str);
    // cout << longestValidParenthesis(str) << endl;
    // vector<vector<string>> items = {
    // {"phone","silver","pixel"},{"computer","silver","lenovo"},{"phone","gold","iphone"}
    // }; string ruleKey = "type"; string ruleValue = "phone"; cout <<
    // countMatches(items, ruleKey, ruleValue) << endl;
    // letterCasePermutation(s);
    // cout << "parenthieses: " << longestValidParenthesisStack(parenthesis)
    // << endl; cout << countCharacters(vt, s) << endl;

    // shortestToChar(s, 'e');
}