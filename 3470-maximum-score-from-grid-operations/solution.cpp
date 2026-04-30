using ll=long long;
static ll colSum[100][101]={{0}}; // 1-indexed prefix col sums
// (j%2, num of black items in curr col, cur col score exclusive/inclusive)
static ll dp[2][101][2];
static int n;

class Solution {
public:
    static long long maximumScore(vector<vector<int>>& grid) {
        n=grid.size();
        if (n==1) return 0;

        // compute col prefix sums
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                colSum[j][i+1]=colSum[j][i]+grid[i][j];
            }
        }

        memset(dp[0], 0, sizeof(ll)*(n+1)*2);

        for(int j=1; j<n; j++){
            bool cur=j&1, prv=!cur;
            memset(dp[cur], 0, sizeof(ll)*(n+1)*2);

            for(int b0=0; b0<=n; b0++){
                ll p0=dp[prv][b0][0];
                ll p1=dp[prv][b0][1];

                for(int b1=0; b1<=n; b1++){
                    bool isBigger=b1>b0;
                    
                    ll prvX=isBigger?(colSum[j-1][b1]-colSum[j-1][b0]):0;
                    ll curX=!isBigger?(colSum[j][b0]-colSum[j][b1]):0;
                    
                    // State 0: score in cur col exclusive
                    dp[cur][b1][0]=max(dp[cur][b1][0], max(prvX+p0, p1));
                    
                    // State 1: score in cur col inclusive
                    dp[cur][b1][1]=max(dp[cur][b1][1], curX+max(p1, prvX+p0));
                }
            }
        }

        bool last=(n-1)&1;
        ll ans=0;
        for(int b=0; b<=n; b++) 
            ans=max(ans, dp[last][b][1]);
        
        return ans;
    }
};
