
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> charIndex;
        int maxLength = 0;
        int start = 0;  // Start index of the current substring

        for (int end = 0; end < s.length(); ++end) {
            char currentChar = s[end];

            // If the character is already in the substring
            if (charIndex.find(currentChar) != charIndex.end()) {
                // Move the start index to one position right of the last occurrence
                start = std::max(start, charIndex[currentChar] + 1);
            }

            // Update the last seen index of the character
            charIndex[currentChar] = end;

            // Calculate the length of the current substring
            maxLength = std::max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};