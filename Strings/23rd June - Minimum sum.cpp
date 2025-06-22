// Minimum sum

class Solution {
public:
    string addString(string &num1, string &num2) {
        string result = "" ;
        
        int i = num1.length() - 1; 
        int j = num2.length() - 1;
        int carry = 0; 
        
        while(i >= 0 || j >= 0 || carry) {
            int sum = carry; 
            int n1 = (i >= 0) ? num1[i--] - '0' : 0;
            int n2 = (j >= 0) ? num2[j--] - '0' : 0;

            sum += n1 + n2;
            carry = sum / 10;
            result += to_string(sum % 10);
        }

        reverse(result.begin(), result.end());
        return result; 
    }

    string minSum(vector<int> &arr) {
        int n = arr.size();
        string result = "";

        sort(arr.begin(), arr.end());

        string s1 = "", s2 = "";

        for (int i = 0; i < n; i += 2) {
            s1 += to_string(arr[i]);
            if (i + 1 < n) {
                s2 += to_string(arr[i + 1]);
            }
        }

        int i = 0, j = 0;
        while (i < s1.length() && s1[i] == '0') i++;
        while (j < s2.length() && s2[j] == '0') j++;

        string num1 = s1.substr(i);
        string num2 = s2.substr(j);

        return addString(num1, num2);
    }
};
