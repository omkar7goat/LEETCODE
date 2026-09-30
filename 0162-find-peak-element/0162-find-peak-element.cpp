class Solution {
public:
    int findPeakElement(vector<int>& v) {
        int lo = 0, hi = v.size() - 1;
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (v[mid] < v[mid + 1]) {
                lo = mid + 1; // Uphill to the right -> search right
            } else {
                hi = mid;     // Uphill to the left or mid is peak -> search left
            }
        }
        
        return lo; // lo == hi, converged on a peak
    }
};