class Solution {
public:
    int dot(vector<int> a, vector<int> b) {
        if (!a.size())
            return 0;
        if (b.size()<a.size()){
            return 0;
        }
        int s = 0;
        for (int i = 0; i<a.size();i++){
            s += a[i]*b[i];
        }
        return s;
    }
    vector<int> column(vector<vector<int>> &x, int c){
        vector<int> ret(x.size());
        for (int i = 0; i < x.size(); i++){
            ret[i] = x[i][c];
        }
        return ret;
    }
    
    vector<vector<int>> mat_mul(vector<vector<int>> &a, vector<vector<int>> &b){
        const int m = a[0].size();
        
        vector<vector<int>> bcol(b[0].size());
        for (int i = 0; i < bcol.size(); i++){
            bcol[i] = column(b, i);
        }
            
        vector<vector<int>> ret(a.size());
        
        for (int row = 0; row < a.size(); row++){
            ret[row] = vector<int>(b.size());
            for(int col = 0; col < bcol.size(); col++){
                ret[row][col] = dot(a[row], bcol[col]);
            }
            
        }
        
        return ret;
    }
    
    int fib(int N) {
        if (N <= 1){
            return N;
        }
        N--;
        // fast exponentiation + matrix exponentiation = fast matrix exponentiation
        vector<vector<int>> A0 {{0, 1}, {1, 1}};
        vector<vector<int>> f0 {{0}, {1}};
        int pow = 1;
        vector<vector<int>> A = A0; 
        while(2*pow <= N){
            A = mat_mul(A, A);
            pow *= 2;
        }
        while(pow < N){
            A = mat_mul(A0, A);
            pow++;
        }
        return mat_mul(A, f0)[1][0];
    }
};
