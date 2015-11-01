class Solution {
public:
    int numDistinct(string s, string t) {
        if(t.length() == 0) return 0;
        if(s.length() == 0) return 0;
        if(t.length() > s.length()) return 0;
        if(t.length() == s.length()) return (t == s);
        int ** arr = new int*[s.length()];
        for(int i = 0; i < s.length(); i ++){
            arr[i] = new int[t.length()];
            for(int j = 0; j < t.length(); j++){
                arr[i][j] = 0;
            }
        }//end init
        arr[0][0] = (s[0] == t[0])? 1:0;
        for(int i = 0; i < t.length() ; i ++ ){
            for(int j = i; j < s.length(); j ++){
                if(i== 0 && j > 0){
                    arr[j][i] = arr[j-1][i];
                    if(t[i] == s[j]) arr[j][i]++;
                    continue;
                }
                if(j-i>=0 && i > 0){
                     arr[j][i] =  arr[j-1][i] ;
                     if( t[i] == s[j]) arr[j][i] +=  arr[j-1][i - 1];
                }
            }//end for j
        }//end for i
        return arr[s.length()-1][t.length()-1];
    }
};
