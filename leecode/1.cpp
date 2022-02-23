class Solution {
public:
    void quickSort(vector<int>& nums,vector<int>& position,int start,int end){
        int tag = nums.at(position.at(end));
        int i = start;
        int j = end-1;
        {

        }
    }
    vector<int> sort(vector<int>& nums,int target){
        vectot<int> position;
        for(int i =0;i<nums.size();i++){
            position.push_back(i);
        }
        quickSort(nums,position,0,nums.size()-1);
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        
    }
};

