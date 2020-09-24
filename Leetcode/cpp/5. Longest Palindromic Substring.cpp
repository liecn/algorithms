class Solution {
public:
    string longestPalindrome(string s) {
    int n=s.size();
    if(!n) return "\0";
	bool dp[n][n];
	fill_n(&dp[0][0],n*n,false);//Fill sequence with value
	int max_len=1; 
	int start=0;
	for(int i=0;i<s.size();++i)//from j to i
	{
		for(int j=0;j<=i;++j)
		{
			if(i-j<2)
				dp[j][i]=(s[i]==s[j]);
			else
				dp[j][i]=(s[i]==s[j] && dp[j+1][i-1]);
			if(dp[j][i] && max_len<(i-j+1))
			{
				max_len=i-j+1;
				start=j;
			}
		}
	}
	return s.substr(start,max_len);
    }
};
