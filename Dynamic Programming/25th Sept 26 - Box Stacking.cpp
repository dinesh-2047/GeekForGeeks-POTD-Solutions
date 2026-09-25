// Box Stacking

class Solution {
public:
    struct Box {
        int h, l, w;
    };

    vector<Box> boxes;
    vector<int> dp;

    int solve(int i) {
        if (dp[i] != -1)
            return dp[i];

        int result = 0;

        for (int j = 0; j < boxes.size(); j++) {
            if (boxes[j].l < boxes[i].l &&
                boxes[j].w < boxes[i].w) {
                result = max(result, solve(j));
            }
        }

        return dp[i] = boxes[i].h + result;
    }

    int maxHeight(vector<int> &height,
                  vector<int> &width,
                  vector<int> &length) {

        int n = height.size();

        for (int i = 0; i < n; i++) {
            boxes.push_back({
                height[i],
                max(width[i], length[i]),
                min(width[i], length[i])
            });

            boxes.push_back({
                width[i],
                max(height[i], length[i]),
                min(height[i], length[i])
            });

            boxes.push_back({
                length[i],
                max(height[i], width[i]),
                min(height[i], width[i])
            });
        }

        dp.assign(boxes.size(), -1);

        int result = 0;

        for (int i = 0; i < boxes.size(); i++) {
            result = max(result, solve(i));
        }

        return result;
    }
};