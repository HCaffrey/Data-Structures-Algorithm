class Solution {
public:
  string longestPalindrome(string s) {
    /*loop through the string
     *check if (1)()*s[i]()* or (2)()*s[i]s[i+1]()*, record length and compare
     *return longest length
     */
    if(s.length()<2) return s;
    int maxLen = 1;
    string res = s.substr(0,1);
    int midIndex = 0;

    for(int i=0;i<s.length()-1;i++){
      int len1 = getPalindromeLen(s, i, i);
      int len2 = getPalindromeLen(s, i, i+1);
      int curlen = max(len1, len2);
      if(maxLen<curlen){
	maxLen = curlen;
	midIndex = i;
      }
    }

    res = s.substr(midIndex-(maxLen-1)/2,maxLen);
    return res;
  }


  int getPalindromeLen(string s, int start, int next){
    int len = s.length();
    // if(start<0 || next >len-1) return 0;
    while(start>=0 && next<len){
      if(s[start]!=s[next]) break;
      else{
	start--;
	next++;
      }
    }

    return next-start -1;
  }
};
