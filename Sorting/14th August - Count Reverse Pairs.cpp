// Count Reverse Pairs



// Approach1 using merge sort 

class Solution {
  public:
  int result ;
  void merge(vector<int> &arr, int l , int r){
      int mid = l + (r - l)/2; 
      
      int len1 = mid - l  + 1; 
      int len2 =  r - mid; 
      
      vector<int>first(len1);
      vector<int>second(len2);
       int mainIdx = l ; 
      for(int i = 0 ; i < len1; i++){
          first[i] = arr[mainIdx++];
      }
       mainIdx = mid+ 1; 
      for(int i = 0 ; i < len2; i++ ){
          second[i]  = arr[mainIdx++];
      }
      
      
       int i = 0 ; 
       int j = 0 ; 
       
       while(i <len1&&j < len2){
            if ((long long)first[i] > 2LL * second[j]) {
                result += (len1 - i); 
                j++;
            } else {
                i++;
            }
       }
       
       i = 0 ; 
       j = 0 ; 
     mainIdx = l;
        while (i < len1 && j < len2) {
            if (first[i] <= second[j]) {
                arr[mainIdx++] = first[i++];
            } else {
                arr[mainIdx++] = second[j++];
            }
        }
        while (i < len1) arr[mainIdx++] = first[i++];
        while (j < len2) arr[mainIdx++] = second[j++];
  }
  
  
  
  void mergeSort(vector<int> &arr, int l, int r){
      if(l >= r) return; 
      
      int mid = l + (r-l)/2;
      
      mergeSort(arr, l, mid);
      mergeSort(arr, mid + 1, r);
      
      merge(arr, l, r);
  }
  
  
  
    int countRevPairs(vector<int> &arr) {
        int n = arr.size();
        
        result = 0 ; 
        
        mergeSort(arr, 0 , n-1);
        return result; 
        
    }
};









// Approach 2 using ordered set 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pair<long,long>, null_type, less<pair<long,long>>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        ordered_set st;
        long ans = 0, n = nums.size();
        for(long i=n-1; i>=0; i--){
            ans += st.order_of_key({nums[i],INT_MIN});
            st.insert({2ll*nums[i],i});
        }
        return ans;
    }
};