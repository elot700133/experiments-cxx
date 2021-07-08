//=============================================
// Reverse a string
//
//---------------------------------------------
// iterative using stack
// O(n)
// O(n)
void reverse_string(string &str)
{
   stack<char> st;
   for (int i=0; i<str.length(); i++)
       st.push(str[i]);
 
   for (int i=0; i<str.length(); i++) {
       str[i] = st.top();
       st.pop();
   }      
}
//---------------------------------------------
// iterative using swap
// O(n)
// O(1)
void reverse_string(string& str) {
   int n = str.length();
   for(int i=0; i<n/2; i++) {
      swap(str[i],str[n-1-i]);
   }
}
//---------------------------------------------
// iterative two pointers
// O(n)
// O(1)
void reverse_string(string& str) {
   int n = str.length();
   for(int i=0, int j = n-1; i<j; i++, j--) {
      swap(str[i],str[j]);
   }
}
//---------------------------------------------
// recursive
// O(n)
// O(1)
// note: this recursive method is very similar
// to swapping method
void reverse_string(string& str, int i=0) {
   // base case
   int n = str.length();
   if (i == n/2)
      return;
   swap(str[i], str[n-i-1]);
   reverse_string(str,i+);
}
