class Solution {
public:
    bool isPossible(vector<int>& piles, int h,int mid){
        int temph =0;

        for(int i=0; i<piles.size();i++){

            if(piles[i]%mid == 0){
                temph +=( piles[i]/mid);
            }else{
               temph += ((piles[i]/mid)+1);
            }
            if(temph > h){
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 0;
        for(int i=0; i<piles.size(); i++){
            high = max(high,piles[i]);
        }
        int ans =-1;

        while(low<=high){
            int mid = low+(high - low)/2;

            if(isPossible(piles,h,mid)){
                ans = mid;
                high = mid -1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};
