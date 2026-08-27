class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        int hsh1[26] = {0}, hsh2[26] = {0};

        for (int i = 0; i < s1.length(); i++) {
            hsh1[s1[i] - 'a']++;
            hsh2[s2[i] - 'a']++;
        }

        int matches = 0;

        for (int i = 0; i < 26; i++) {
            if (hsh1[i] == hsh2[i]) {
                matches++;
            }
        }

        int l = 0;

        for (int r = s1.length(); r < s2.length(); r++) {
            if (matches == 26) return true;

            hsh2[s2[r] - 'a']++;

            if (hsh1[s2[r] - 'a'] == hsh2[s2[r] - 'a']) {
                matches++;
            } else if (hsh1[s2[r] - 'a'] + 1 == hsh2[s2[r] - 'a']) {
                matches--;
            }

            hsh2[s2[l] - 'a']--;

            if (hsh1[s2[l] - 'a'] == hsh2[s2[l] - 'a']) {
                matches++;
            } else if (hsh1[s2[l] - 'a'] - 1 == hsh2[s2[l] - 'a']) {
                matches--;
            }

            l++;
        }

        return matches == 26;
    }
};
