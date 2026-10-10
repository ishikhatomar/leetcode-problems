class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        unordered_map<int,int> mp;
        stack<int> st;
        for(int i =0; i<n; i++){
            if(s[i]=='(')
                st.push(i);
            else if(s[i]== ')'){
                int j = st.top();
                st.pop();
                mp[i] = j;
                mp[j] = i;
            }
        }
       

        int flag = 1; //1 : leftto right; -1:righttoleft
        string result ;
        for(int i =0; i<n; i += flag){
            if(s[i]=='(' || s[i]==')'){
                i = mp[i];
                flag = -flag;
            }
            else
                result.push_back(s[i]);
        }
        return result;
    }
};
