#include <bits/stdc++.h>

using namespace std;

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
            stIdx = i;
            maxlen = 2;
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
    // int lastJ = 0;
    // for(int i = 0; i < size; i++) {
    //     int temp = size - i - 1 + lastJ;
    //     for(int j = temp; j < size; j++) {
    //         if(dp[j-temp][j] == 1) {
    //             lastJ = j;
    //         }
    //         cout << dp[j - temp][j] << " ";
    //     }
    //     cout << endl;
    // }

    bool st[size];
    for (int i = 0; i < size; i++) {
        st[i] = false;
    }
    int len = size - 1;
    int countNonOverlappingSub = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= i; j++) {
            if (dp[j][j + len] == 1 && !st[j]) {
                countNonOverlappingSub++;
                cout << "len: " << len + 1 << "  st: " << j
                     << " ed: " << j + len << "  " << dp[j][j + len] << endl;
                for (int k = j; k <= j + len; k++) {
                    st[k] = true;
                }
            }
        }
        len--;
    }

    cout << countNonOverlappingSub << endl;

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
        // cout << "i " << i << "  op: " << open << " " << "clos: " << close <<
        // " mxl " << maxlen << endl;
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

bool isInterleaveDPhelper(string s1, string s2, string s3, int i, int j,
                          string res, int **dp) {
    if (res == s3 && i == s1.length() && j == s2.length()) {
        return true;
    }

    if (dp[i][j] != -1) {
        return (dp[i][j] == 1);
    }

    bool ans = false;
    if (i < s1.length()) {

        ans = isInterleaveDPhelper(s1, s2, s3, i + 1, j, res + s1.at(i), dp) &&
              true;
    }
    if (j < s2.length()) {
        ans = isInterleaveDPhelper(s1, s2, s3, i, j + 1, res + s2.at(j), dp) &&
              true;
    }

    dp[i][j] = ans == true ? 1 : 0;
    return ans;
}

bool isInterleaveDP(string s1, string s2, string s3) {
    int m = s1.length();
    int n = s2.length();
    int k = s3.length();
    cout << "im herer ";

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
            dp[i][j] = -1;
        }
    }

    string res = "";
    bool ans = isInterleaveDPhelper(s1, s2, s3, 0, 0, res, dp);

    return true;
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

bool isPalindrome(string s) {
    int length = s.length();

    int i = 0, j = length - 1;
    while (i <= j) {
        if (s[i] < 48 || s[i] > 57 && s[i] < 65 || s[i] > 90 && s[i] < 97 ||
            s[i] > 122) {
            cout << s[i] << " got 1 " << s[j] << endl;
            i++;
        } else if (s[j] < 48 || s[j] > 57 && s[j] < 65 ||
                   s[j] > 90 && s[j] < 97 || s[j] > 122) {
            cout << s[i] << " got 2 " << s[j] << endl;
            j--;
        } else if (s[i] == s[j] || s[i] + 32 == s[j] || s[j] + 32 == s[i]) {
            cout << "got 3" << endl;
            i++;
            j--;
        } else {
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

int main() {

    vector<string> vt = {"time", "me", "ime", "bell", "be", "ell"};
    string str = "hello world!";
    string parenthesis = "()(((()())(";
    string cha = "a1b4";
    vector<string> pt = {"car", "cir"};

    cout << str << endl;
    cout << longestCommonPrefix(pt) << endl;
    // cout << countAndSay(2) << endl;
    // cout << strStr(str, "") << endl;
    // cout << isPalindrome(str) << endl;
    // cout << firstUniqChar(str) << endl;
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
    // letterCasePermutation(cha);
    // cout << "parenthieses: " << longestValidParenthesisStack(parenthesis) <<
    // endl; cout << countCharacters(vt, cha) << endl;

    cout << cha << endl;
    shortestToChar(cha, 'e');
}