class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        int n= arr.size(), m = dep.size();
        int maxcount = 0, count = 0;
        
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());   
        
        int i = 0, j = 0;
        while(i<n && j<m){
            if(arr[i]<= dep[j]){
                count ++;
                maxcount = max(maxcount , count);
                i++;
            }else {
                j++;
                count --;
            }
        }
        return maxcount ;
    }
};

