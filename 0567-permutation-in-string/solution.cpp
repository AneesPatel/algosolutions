class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        
        // Use vectors of size 26 for O(1) access (assuming lowercase English letters)
        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);
        
        // Frequency of s1 characters
        for (char c : s1) {
            s1Count[c - 'a']++;
        }
        
        // Initial Window: Check the first s1.length() characters of s2
        for (int i = 0; i < s1.length(); i++) {
            s2Count[s2[i] - 'a']++;
        }
        
        if (s1Count == s2Count) return true;
        
        // Sliding Window
        int l = 0;
        for (int r = s1.length(); r < s2.length(); r++) {
            // Add the new character (right side of window)
            s2Count[s2[r] - 'a']++;
            
            // Remove the old character (left side of window)
            s2Count[s2[l] - 'a']--;
            l++;
            
            // Compare the frequency vectors
            if (s1Count == s2Count) return true;
        }
        
        return false;
    }
};
