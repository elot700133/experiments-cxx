//=============================================
// iterative 
//
// using stack
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
