class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int it1 = 0;
        int it2 = 0;
        int count = 0;
        if(!n) {
            return;
        }
        while(it1 != m + count && it2 != n) {
            while(nums2[it2] > nums1[it1] && it1 != m + count) {
                it1++;
            }
            if(it1 != m + count) {
                nums1.insert(nums1.begin()+it1, nums2[it2]);
                it1++;
                count++;
                it2++;
            }
        }
        if(it1 == m + count) {
            while(it2 != n) {
                    nums1[it1] = nums2[it2];
                    it2++;
                    it1++;
            }
        }
        nums1.erase(nums1.begin()+m+n, nums1.end());
    }
};
