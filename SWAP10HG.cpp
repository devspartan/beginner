#include<bits/stdc++.h>

using namespace std;

void swap(string &s1, int i, int j) {
    char temp = s1[i];
    s1[i] = s1[j];
    s1[j] = temp;
}

int main() {
    int tst;

    cin >> tst;
    while(tst--) {
        string s1, s2;
        int len;
        cin >> len;
        cin >> s1;
        cin >> s2;
        
        int i = 0;
        int j = s1.length() - 1;
        bool check = true;
        while(i <= j) {


            if( s1[j] == s2[j]) {
                j--;
                continue;
            }
            else if(s1[i] == s2[i]) {
                i++;
                continue;
            }
            else if( i == j) {
                check = false;
                break;
            }
            else if(s1[j] == '1' || s1[i] == '0') {
                check = false;
                break;
            }
            else if(s1[j] == '0' && s1[i] == '1') {
                swap(s1, i, j);
                i++;
                j--;
            }
            
        }

        if(check) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}