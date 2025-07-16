// Power of k in factorial of n


//mere se to bna hi nhi , copy paste hi h kisi or ka 
class Solution {
  public:
   unordered_map<int, int> primeFactorize(int k) {
        unordered_map<int, int> primeFactors;

        while (k % 2 == 0) {
            primeFactors[2]++;
            k /= 2;
        }

        for (int i = 3; i * i <= k; i += 2) {
            while (k % i == 0) {
                primeFactors[i]++;
                k /= i;
            }
        }

        if (k > 2) {
            primeFactors[k]++;
        }

        return primeFactors;
    }

 int countPrimeInFactorial(int n, int prime) {
        int count = 0;
        for (long long power = prime; power <= n; power *= prime) {
            count += n / power;
        }
        return count;
    }



    int maxKPower(int n, int k) {
        // code here
     unordered_map<int, int> primeFactors = primeFactorize(k);
        int result = INT_MAX;

        for (auto& entry : primeFactors) {
            int prime = entry.first;
            int exponent = entry.second;

            int count = countPrimeInFactorial(n, prime);

            result = min(result, count / exponent);
        }

        return result;
    }
   
    
   
   
};