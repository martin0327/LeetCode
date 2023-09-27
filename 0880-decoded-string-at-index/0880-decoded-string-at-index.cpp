class Solution {
public:
    string decodeAtIndex(string S, int K) {
        int n = S.length();
        long long size = 0;
        
        for(char ch:S) { // finding size of input string
            if(isdigit(ch)) {//isdigit is function in c/c++, which used to check if the passed character is a digit or not.
                size = size*(ch-'0');
            } else {
                size++;// if it is not digit then simplly size will be inc. by 1
            }
        }
        
        for(int i = n-1; i>=0; i--) { // we will traverse from last that will be help to decode effectively
            K = K%size;
            if(K == 0  && isalpha(S[i]))// isalpha is used to check if the passed character is an alphabet or not.
                return string(1, S[i]);
            
            if(isalpha(S[i]))
                size--;
            else
                size = size/(S[i]-'0');
        }
        
        return "";
    }
};
