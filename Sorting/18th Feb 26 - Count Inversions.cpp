// Count Inversions

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
            if (first[i] > second[j]) {
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
  
  
  
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        
        result = 0 ; 
        
        mergeSort(arr, 0 , n-1);
        return result; 
        
    }
};