class Solution {
public:
    bool winnerOfGame(string s) {
        int cntA=0,cntB=0;
        int cnt=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='A')
                cnt++;
            else
            {
                if(cnt>=3)
                    cntA+=cnt-2;
                cnt=0;
            }
        }
        if(cnt>=3)
            cntA+=cnt-2;
        cnt=0;
        
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='B')
                cnt++;
            else
            {
                if(cnt>=3)
                    cntB+=cnt-2;
                cnt=0;
            }
        }
        if(cnt>=3)
            cntB+=cnt-2;
        cnt=0;
        
        return cntA>cntB;
    }
};