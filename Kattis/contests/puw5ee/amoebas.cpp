#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int readpx() {
    char c;
    while (true) {
        cin.get(c);
        if (c == '.') return 0;
        else if (c == '#') return -1;
    }

}

vector<vector<int>> px;
int nextsec = 1;
int loops = 0;
int m, n, m_, n_;



inline bool isblack(int dm_, int dn_, int m_, int n_) {
    if (m_ + dm_ < m && m_ + dm_ >= 0 && n_ + dn_ < n && n_ + dn_ >= 0) {
        if (px[m_ + dm_][n_ + dn_] == -1) {
            return true;
        }
    }
    return false;
}

void prt() {
    for (int m_ = 0; m_ < m; m_++) {
        for (int n_ = 0; n_ < n; n_++) {
            cout << px[m_][n_];
        }
        cout << "\n";
    }
}


void follow(int cm_, int cn_, int lm_, int ln_, int fm_, int fn_) {
    if (cm_ == fm_ && cn_ == fn_) {
        return;
    }
    px[cm_][cn_] = px[lm_][ln_];

    auto testfol = [=](int dm_, int dn_) {
        if ((lm_ != cm_ + dm_ || ln_ != cn_ + dn_) && isblack(dm_, dn_, cm_, cn_)) {
            follow(cm_ + dm_, cn_ + dn_, cm_, cn_, fm_, fn_);
            return;
        }
    };

    testfol(-1, -1);
    testfol(-1, 0);
    testfol(-1, 1); 
    testfol(0, -1); 
    testfol(0, 1); 
    testfol(1, -1); 
    testfol(1, 0); 
    testfol(1, 1); 
}

int main() {
    cin >> m >> n;
    px.resize(m, vector<int>(n));

    cin.get();
    for (m_ = 0; m_ < m; m_++) {
        for (n_ = 0; n_ < n; n_++)
            px[m_][n_] = readpx();
        cin.get();
    }

    // count concave sections, subtract at overlap
    for (m_ = 0; m_ < m; m_++) {
        for (n_ = 0; n_ < n; n_++) {
            
            if (px[m_][n_] == -1) {
                loops++;
                px[m_][n_] = loops;
                auto testfol = [=](int dm_, int dn_) {
                    if (isblack(dm_, dn_, m_, n_)) {
                        follow(m_ + dm_, n_ + dn_, m_, n_, m_, n_);
                        return false;
                    }
                    return true;
                };
                if (testfol(-1, -1))
                    if (testfol(-1, 0))
                        if (testfol(-1, 1)) 
                            if (testfol(0, -1)) 
                                if (testfol(0, 1)) 
                                    if (testfol(1, -1)) 
                                        if (testfol(1, 0)) 
                                            testfol(1, 1); 
            }
        }
    }

    //prt();
    cout << loops;

    
    return 0;

}