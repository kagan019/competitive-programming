/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int r = 0, c = binaryMatrix.dimensions()[1] - 1;
        int numrows = binaryMatrix.dimensions()[0];
        bool found = false;
        while(r < numrows) {
            cout << r << endl;
            while (c >= 0 && binaryMatrix.get(r, c) == 1) {
                cout << "  " << c << endl; 
                found = true; 
                c--;
            }
            
            r++;
        }
        return found ? c+1 : -1;
    }
};
