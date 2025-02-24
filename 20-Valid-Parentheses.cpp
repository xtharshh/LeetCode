
class Solution {
public:
    bool isValid(string s) {
        stack<char> str;
            if(s.size()==1 || s.size()==0) return false;
        for(char br : s) {
            if(br == '(' || br == '{' || br == '[') {
                str.push(br);
            } else if(br == ')' || br == '}' || br == ']') {
                if(str.empty()) {
                    return false; 
                }
                char top = str.top();
                if((br == ')' && top == '(') || 
                   (br == '}' && top == '{') || 
                   (br == ']' && top == '[')) {
                    str.pop(); 
                } else {
                    return false; 
                }
            }
        }
        return str.empty();//or yaha str.empty() bhiuse karskhte hai!!
    }
};
