class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 int distanceA = a[0] * a[0] + a[1] * a[1];
                 int distanceB = b[0] * b[0] + b[1] * b[1];

                 return distanceA < distanceB;
             });

        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};