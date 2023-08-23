Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
Return any possible rearrangement of s or return " " if not possible.

 Example 1:

Input: s = "aab"
Output: "aba"


Example 2:
Input: s = "aaab"
Output: ""



  Code:-
  class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size(); // Get the length of the input string.
        vector<int> counts(26, 0); // Initialize an array to count the occurrences of each character (a-z).
        int maxCount = 0; // Initialize a variable to track the maximum character count.
        char maxChar = 'a'; // Initialize a variable to track the character with the maximum count.

        // Count the occurrences of each character in the string.
        for (char c : s) {
            counts[c - 'a']++;
            if (counts[c - 'a'] > maxCount) {
                maxCount = counts[c - 'a'];
                maxChar = c;
            }
        }

        // Check if the character with the maximum count exceeds half of the string length.
        if (maxCount > (n + 1) / 2) {
            return ""; // If it does, it's impossible to rearrange, so return an empty string.
        }

        string result(n, ' '); // Initialize a result string with spaces.
        int i = 0; // Initialize an index variable for filling the result string.

        // Fill the result string with the character with the maximum count.
        while (counts[maxChar - 'a'] > 0) {
            result[i] = maxChar;
            i += 2; // Move to the next even index.
            counts[maxChar - 'a']--; // Decrease the count of the character.
        }

        // Fill the result string with the remaining characters.
        for (int j = 0; j < 26; j++) {
            char ch = 'a' + j;
            while (counts[j] > 0) {
                if (i >= n) {
                    i = 1; // If the index exceeds the string length, move to the next odd index.
                }
                result[i] = ch;
                i += 2; // Move to the next even index.
                counts[j]--; // Decrease the count of the character.
            }
        }

        return result; // Return the rearranged string.
    }
};
