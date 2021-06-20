#include <bits/stdc++.h>

using namespace std;

class NumArray {

  private:
    vector<int> data;
    vector<int> cummSum;
    unordered_map<int, int> mp;

  public:
    NumArray(vector<int> &nums) {
        data = nums;

        if (nums.size() > 0) {

            cummSum.push_back(nums[0]);

            for (int i = 1; i < nums.size(); i++) {
                cummSum.push_back(cummSum[i - 1] + nums[i]);
            }
        }
    }

    void update(int index, int val) { mp[index] = val; }

    int sumRange(int left, int right) {
        int sum = 0;
        int ext = 0;
        for (auto it : mp) {
            if (it.first >= left && it.first <= right) {
                ext += it.second - data[it.first];
            }
        }
        return cummSum[right] - cummSum[left] + data[left] + ext;
    }
};

class RLEIterator {
  private:
    vector<int> encoded;
    int currIdx;
    int currNum;

  public:
    RLEIterator(vector<int> &encoding) {
        encoded = encoding;
        currIdx = 0;
    }

    int next(int n) {

        if (currIdx >= encoded.size()) {
            return -1;
        }

        if (encoded[currIdx] > n) {
            encoded[currIdx] -= n;
            return encoded[currIdx + 1];
        } else if (encoded[currIdx] == n) {
            currIdx += 2;
            return encoded[currIdx - 1];
        } else {
            int ct = 0;
            int i = currIdx;
            while (ct < n && currIdx < encoded.size()) {
                ct += encoded[currIdx];
                if (ct > n) {
                    encoded[currIdx] = ct - n;
                    return encoded[currIdx + 1];
                } else if (ct == n) {
                    currIdx += 2;
                    return encoded[currIdx - 1];
                }

                currIdx += 2;
            }

            return -1;
        }
    }
};

int main() {
    vector<int> nums = {3, 8, 0, 9, 5, 2, 3, 4, 1, 2, 1, 2};

    RLEIterator rt(nums);
    // [8, 8, 8, 2, 2, 2, 2, 2, 4, 4, 4, 2, 2]
    cout << rt.next(4) << endl;
    cout << rt.next(2) << endl;
    cout << rt.next(4) << endl;
    cout << rt.next(2) << endl;
}
