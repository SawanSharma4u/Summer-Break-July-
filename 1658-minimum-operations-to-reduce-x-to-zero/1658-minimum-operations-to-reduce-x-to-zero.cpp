class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n= nums.size();
        vector<int> ans(n+1);
        ans[0] = 0;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            ans[i+1] = sum;
        }
        
        if(sum < x) return -1;
        if(sum==x) return n;
        x = sum - x;
        int temp = INT_MIN;
        for(int i = 0; i < n; i++){
            int j = i, k = n-1;
            while(j<=k){
                int mid = (j+k)/2;
                if(ans[mid+1]-ans[i] == x){
                    temp = max(temp, mid-i+1);
                    break;
                }
                else if(ans[mid+1]-ans[i] > x){
                    k = mid-1;
                }
                else{
                    j = mid+1;
                }
            }
        }
        if(temp == INT_MIN) return -1;
        return n-temp;
    }
};