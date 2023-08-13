class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int nn = m + n - 1;
        int n1 = m - 1;
        int n2 = n - 1;

        while (n1 >= 0 && n2 >= 0) {
            if (nums1[n1] > nums2[n2]) {
                nums1[nn] = nums1[n1];
                --n1;
            } else {
                nums1[nn] = nums2[n2];
                --n2;
            }

            --nn;
        }

        while (n1 >= 0) {
            nums1[nn] = nums1[n1];
            --n1;
            --nn;
        }

        while (n2 >= 0) {
            nums1[nn] = nums2[n2];
            --n2;
            --nn;
        }
    }
};
