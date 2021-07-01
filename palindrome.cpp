//==================================================
// Find longest palindomic string
// tags: dynamic programming, two pointer
// tricky: anchor can be in between letters
class Solution {
public:
    string longestPalindrome(string s) {
        // two pointer approach
        string ans;
        int anchor = 0;
        while(anchor < s.size()) {
            // on anchor
            {
                int i1 = anchor;
                int i2 = anchor;
                string tmp_ans;
                while(i1 > -1 && i2 < s.size()) {
                    if (s[i1] == s[i2]) {
                        tmp_ans = s.substr(i1, i2-i1+1);
                    }
                    else
                        break;
                    i1--; i2++;
                }
                //printf("1 %s\n",tmp_ans.c_str());
                if (ans.size() < tmp_ans.size()) {
                    ans = tmp_ans;
                }
            }
            
            // between anchor
            {
                int i1 = anchor;
                int i2 = anchor+1;
                string tmp_ans;
                while(i1 > -1 && i2 < s.size()) {
                    if (s[i1] == s[i2]) {
                        //printf("2: %d %d %c %c\n",i1,i2,s[i1],s[i2]);
                        tmp_ans = s.substr(i1, i2-i1+1);
                    }
                    else
                        break;
                    i1--; i2++;
                }
                //printf("2 %s\n",tmp_ans.c_str());
                if (ans.size() < tmp_ans.size()) {
                    ans = tmp_ans;
                }    
            }
            anchor++;
        }
        return ans;
    }
};
