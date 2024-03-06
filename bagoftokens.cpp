class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        int score=0;
        int maxscore=0;
        int l=0,r=n-1;
        sort(tokens.begin(),tokens.end());
        while(l<=r){
            if(power>=tokens[l]){
                power-=tokens[l];
                l++;
                score++;
                maxscore=max(maxscore,score);
            }
            else if(score>=1){
                power+=tokens[r];
                r--;
                score--;
            }
            else{
                break;
            }
        }  
        return maxscore;
    }
};
