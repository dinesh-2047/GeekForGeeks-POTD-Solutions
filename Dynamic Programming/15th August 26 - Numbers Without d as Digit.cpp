// Numbers Without d as Digit

class Solution {
  public:
      int dp[11][2][2];

      int solve(string &s, int d, int idx, int tight, int started) {
          if (idx == s.length())
              return 1;

          if (dp[idx][tight][started] != -1)
              return dp[idx][tight][started];

          int limit = tight ? s[idx] - '0' : 9;
          int result = 0;

          for (int i = 0; i <= limit; i++) {
              int newTight = tight && (i == s[idx] - '0');

              if (!started && i == 0) {
                  result += solve(s, d, idx + 1, newTight, 0);
              } else {
                  if (i == d)
                      continue;

                  result += solve(s, d, idx + 1, newTight, 1);
              }
          }

          return dp[idx][tight][started] = result;
      }

      int countWithout(int n, int d) {
          if(n == 0 ) return 0 ; 
          if(d == 0 && n < 10 ) return n;
          if(n == 10 && d== 0 ) return n-1; 
          memset(dp, -1, sizeof(dp));
          string s = to_string(n);
          int result = solve(s, d, 0, 1, 0);

          
          return result-1;
      }
  };