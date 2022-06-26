class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        
        for(char x: s) {
            
            if( x==')' && !st.empty()) {
                
                if(st.top() != '(') {
                    
                    return false;
                }
                
                st.pop();
            } 
            
            else if(x=='}' && !st.empty()) {
                
                if(st.top() != '{') {
                    
                    return false;
                }
                
                st.pop();
            } 
            
            else if(x==']' && !st.empty()) {
                
                if(st.top() != '[') {
                    
                    return false;
                }
                
                st.pop();
            } 
            
            else {
                st.push(x);
            }
        }
        
        return st.empty();
    }
};