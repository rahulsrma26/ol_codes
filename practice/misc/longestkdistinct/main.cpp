#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int findLength(const string& str, int k) {
    int windowStart = 0, maxLength = 0;
    unordered_map<char, int> charFrequencyMap;
    // in the following loop we'll try to extend the range [windowStart,
    // windowEnd]
    for (int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
        char rightChar = str[windowEnd];
        charFrequencyMap[rightChar]++;
        // shrink the sliding window, until we are left with 'k' distinct
        // characters in the frequency map
        while ((int)charFrequencyMap.size() > k) {
            char leftChar = str[windowStart];
            charFrequencyMap[leftChar]--;
            if (charFrequencyMap[leftChar] == 0) {
                charFrequencyMap.erase(leftChar);
            }
            windowStart++; // shrink the window
        }
        maxLength = max(maxLength, windowEnd - windowStart +
                                       1); // remember the maximum length so far
    }
    return maxLength;
}

int findLength2(const string& str, int k) {
    const int n = str.length();
    if(n < 1)
        return 0;
    if(k >= n)
        return n;

    int last[26] = {};
    last[str[0]] = 1;
    int windowStart = 0, windowEnd = 1;
    int maxLength = 0, unique = 0;

    while(windowEnd < n){
        const auto c = str[windowEnd];
        if(!last[c]){
            if(unique < k)
                unique++;
            else{
                // we need to remove a char from start
                const int newWindowStart = last[str[windowStart]];
                for(int i = windowStart; i < newWindowStart)
                windowStart = last[str[windowStart]];
            }
        }
        last[c] = ++windowEnd;
    }

    for (int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
        char rightChar = str[windowEnd];
        charFrequencyMap[rightChar]++;
        // shrink the sliding window, until we are left with 'k' distinct
        // characters in the frequency map
        while ((int)charFrequencyMap.size() > k) {
            char leftChar = str[windowStart];
            charFrequencyMap[leftChar]--;
            if (charFrequencyMap[leftChar] == 0) {
                charFrequencyMap.erase(leftChar);
            }
            windowStart++; // shrink the window
        }
        maxLength = max(maxLength, windowEnd - windowStart +
                                       1); // remember the maximum length so far
    }
    return maxLength;
}

int main() {
    string s = "araaci";
    cout << findLength(s, 2) << '\n';
}
