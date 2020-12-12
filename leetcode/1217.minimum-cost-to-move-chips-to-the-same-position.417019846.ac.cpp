class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int ecost = 0;
        int ocost = 0;
        for (int i = 0; i < position.size(); i++) {
            if (position[i] % 2) {
                ocost += 1;
            } else {
                ecost += 1;
            }
        }
        return min(ocost,ecost);
    }
};
