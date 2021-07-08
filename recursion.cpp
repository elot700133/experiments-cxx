//=============================================
// iterative 
//
//---------------------------------------------
// using stack
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
// using swap
// O(n)
// O(1)
void reverse_string(string& str) {
   int n = str.length();
   for(int i=0; i<n/2; i++) {
      swap(str[i],str[n-1-i]);
   }
}
//---------------------------------------------
// two pointers
// O(n)
// O(1)
void reverse_string(string& str) {
   int n = str.length();
   for(int i=0, int j = n-1; i<j; i++, j--) {
      swap(str[i],str[j]);
   }
}
