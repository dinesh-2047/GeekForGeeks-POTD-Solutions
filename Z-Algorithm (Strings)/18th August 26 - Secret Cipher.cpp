// Secret Cipher



class Solution {
  public:
      vector<int> dp;
      vector<int> parent;
      vector<char> choice;
      vector<int> z;
      string str;

      int solve(int i) {
          if (i == 0)
              return 0;

          if (dp[i] != -1)
              return dp[i];

          dp[i] = solve(i - 1) + 1;
          parent[i] = i - 1;
          choice[i] = 'c';

          if (i % 2 == 0) {
              int half = i / 2;

              if (z[half] >= half) {
                  int val = solve(half) + 1;

                  if (val <= dp[i]) {
                      dp[i] = val;
                      parent[i] = half;
                      choice[i] = '*';
                  }
              }
          }

          return dp[i];
      }

      string compress(string &s) {
          str = s;
          int n = str.length();

          z.assign(n, 0);

          for (int i = 1, l = 0, r = 0; i < n; i++) {
              if (i <= r)
                  z[i] = min(r - i + 1, z[i - l]);

              while (i + z[i] < n &&
                     str[z[i]] == str[i + z[i]]) {
                  z[i]++;
              }

              if (i + z[i] - 1 > r) {
                  l = i;
                  r = i + z[i] - 1;
              }
          }

          dp.assign(n + 1, -1);
          parent.assign(n + 1, -1);
          choice.assign(n + 1, 0);

          solve(n);

          string result;
          int i = n;

          while (i > 0) {
              if (choice[i] == '*') {
                  result += '*';
                  i = parent[i];
              } else {
                  result += str[i - 1];
                  i = parent[i];
              }
          }

          reverse(result.begin(), result.end());

          return result;
      }
  };