//==================================================
// Find longest palindomic string
// tags: dynamic programming, two pointer
// tricky: anchor can be in between letters
class Solution {
public:
    string longestPalindrome(string s) {
        // two pointer approach
        string ans = "";
        int anchor = 0;
        while(anchor < s.size()) {
            // on anchor
            {
                int i1 = anchor;
                int i2 = anchor;
                int start = 0;
                int max_len = 0;
                string tmp_ans;
                while(i1 > -1 && i2 < s.size()) {
                    if (s[i1] == s[i2]) {
                        //printf("1: %d %d %c %c\n",i1,i2,s[i1],s[i2]);
                        start = i1;
                        max_len = i2-i1+1;
                        i1--; i2++;
                    }
                    else
                        break;
                }

                if(ans.size() < max_len )  {
                    //printf("%d\n",max_len);
                    ans = s.substr(start, max_len);
                }
            }
            
            // between anchor
            {
                int i1 = anchor;
                int i2 = anchor+1;
                int start = 0;
                int max_len = 0;
                string tmp_ans;
                while(i1 > -1 && i2 < s.size()) {
                    if (s[i1] == s[i2]) {
                        //printf("1: %d %d %c %c\n",i1,i2,s[i1],s[i2]);
                        start = i1;
                        max_len = i2-i1+1;
                        i1--; i2++;
                    }
                    else
                        break;
                }

                if(ans.size() < max_len )  {
                    //printf("%d\n",max_len);
                    ans = s.substr(start, max_len);
                }
            }
            anchor++; 
        }
        return ans;
    }
    // others' best solution
    string longestPalindrome1(string s) {
        if (s.empty()) return "";
        if (s.size() == 1) return s;
        int min_start = 0, max_len = 1;
        for (int i = 0; i < s.size();) {
            printf("anchor %d\n",i);
          if (s.size() - i <= max_len / 2) break;
          int j = i, k = i;
          while (k < s.size()-1 && s[k+1] == s[k]){               // <========= don't understand this line
              printf("%d %d %c %c\n",k+1, k, s[k+1], s[k]);
              ++k; // Skip duplicate characters.
          }
          i = k+1;
          while (k < s.size()-1 && j > 0 && s[k + 1] == s[j - 1]) {
              printf("2: %d %d %c %c\n",k+1, j-1, s[k+1], s[j-1]);
              ++k; --j; 
          } // Expand.
          int new_len = k - j + 1;
          if (new_len > max_len) { min_start = j; max_len = new_len; }
        }
        return s.substr(min_start, max_len);
    }
};

//=========================================================================
// Generate Well Formed Parenthesis
// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// tags: recur
// explain: using int n and m to track open and closed paren
// 
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        
        // n will track number of "(" available
        // m is init to 0 because first time it cannot add an ")"
        addParen(result,"",n,0);
        return result;
    }
    
    // m - 
    void addParen(vector<string>& result, string str, int n, int m) {
        if(n==0 && m==0){
            result.push_back(str);
            return;
        }
        
        if(m>0) addParen(result, str+")", n, m-1);
        if(n>0) addParen(result, str+"(", n-1, m+1);
    }
};


