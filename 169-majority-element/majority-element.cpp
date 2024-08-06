class Solution {
public:
    void merge_sort(vector<int> &arr, int l, int r)
    {
        if (l >= r)
            return;

        int m = (l + r) / 2;

        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
        merge(arr, l, m, r);
    }

    void merge(vector<int> &arr, int l, int m, int r)
    {
        vector<int> lsa(arr.begin() + l, arr.begin() + m + 1);
        vector<int> rsa(arr.begin() + m + 1, arr.begin() + r + 1);

        int i = l;
        int lp = 0, rp = 0;

        while(lp < lsa.size() && rp < rsa.size())
        {
            if(lsa[lp] >= rsa[rp])
                arr[i] = rsa[rp++];
            else 
                arr[i] = lsa[lp++];
            i++;
        }

        while(lp < lsa.size())
            arr[i++] = lsa[lp++];
        while(rp < rsa.size())
            arr[i++] = rsa[rp++];    
    }

    int majorityElement(vector<int>& nums)
    {
        merge_sort(nums, 0, nums.size() - 1);
        return nums[nums.size()/2];
    }
};