// Longest Bounded-Difference Subarray

// Approach 1

class Solution
{
public:
    vector<int> longestSubarray(vector<int> &arr, int x)
    {
        deque<int> minQueue, maxQueue;

        int n = arr.size(), start = 0, end = 0;

        // Pointers to mark the range of maximum subarray
        int resStart = 0, resEnd = 0;
        while (end < n)
        {

            // Pop the elements greater than current element
            // from min Queue
            while (!minQueue.empty() && arr[minQueue.back()] > arr[end])
                minQueue.pop_back();

            // Pop the elements smaller than current element
            // from max Queue
            while (!maxQueue.empty() && arr[maxQueue.back()] < arr[end])
                maxQueue.pop_back();

            minQueue.push_back(end);
            maxQueue.push_back(end);

            // Check if the subarray has maximum difference less
            // than x
            while (arr[maxQueue.front()] - arr[minQueue.front()] > x)
            {

                // Reduce the length of sliding window by moving
                // the start pointer
                if (start == minQueue.front())
                    minQueue.pop_front();
                if (start == maxQueue.front())
                    maxQueue.pop_front();
                start += 1;
            }

            // Maximize the subarray length
            if (end - start > resEnd - resStart)
            {
                resStart = start;
                resEnd = end;
            }
            end += 1;
        }

        vector<int> res;
        for (int i = resStart; i <= resEnd; i++)
            res.push_back(arr[i]);

        return res;
    }
};

// Approach 2
class Solution
{
public:
    vector<int> longestSubarray(vector<int> &arr, int x)
    {
        int i = 0, j = 0, ans = 0;
        multiset<int> set;
        int l = 0, h = 0;
        while (i < arr.size())
        {
            set.insert(arr[i]);

            while (*set.rbegin() - *set.begin() > x)
            {

                set.erase(set.find(arr[j]));
                j++;
            }
            if (ans < i - j + 1)
            {
                l = j;
                h = i;
                ans = i - j + 1;
            }
            i++;
        }
        vector<int> s;
        for (int i = l; i <= h; i++)
        {
            s.push_back(arr[i]);
        }
        return s;
    }
};