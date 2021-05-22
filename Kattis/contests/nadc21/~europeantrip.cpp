#include <bits/stdc++.h>
using namespace std;

struct Point{
    int x; int y;
};

struct Line{
    int sx; int sy;
    int dx; int dy;

};
class U {
public:
    Point a; Point b; Point c;
    double distfromp(Point test) {
        double ssq = 0;
        for (Point p : {a,b,c}) {
            ssq += (test.x-p.x)*(test.x-p.x)+(test.y-p.y)*(test.y-p.y);
        }

        return ssq;
    }

    Point ternaryx(Point top, Point bot) {
        double lastbest = -1;
        Point mid = Point{(top.x+bot.x)/2., (top.y+bot.y)/2.};
        double best = distfromp(mid);
        while (abs(best - lastbest) < 0.00001) {
            Point midb = Point{(mid.x+bot.x)/2., (mid.y+bot.y)/2.};
            Point midt = Point{(mid.x+top.x)/2., (mid.y+top.y)/2.};
            double mb = distfromp(midb);
            double mt = distfromp(midt);
            if (mb < mt) {
                top = midt;
            } else if (mt < mb) {
                bot = midb;
            } else {
                top = midt;
                bot = midb;
            }
            mid = Point{(top.x+bot.x)/2., (top.y+bot.y)/2.};
            best = distfromp(mid);
        }
        return mid;
    }

    double tryy(double y) {
        Point trytop = {max(a.x,max(b.x,c.x)),y};
        Point trybot = {min(a.x,min(b.x,c.x)),y};
        return distfromp(ternaryx(trytop,trybot));
    }

    Point ternaryy(double top, double bot) {
        double lastbest = -1;
        double mid = (top + bot)/2.;
        double best = tryy(mid);
        while (abs(best - lastbest) < 0.00001) {
            double midb = (bot+mid)/2.;
            double midt = (top+mid)/2.;
            double mb = tryy(midb);
            double mt = tryy(midt);
            if (mb < mt) {
                top = midt;
            } else if (mt < mb) {
                bot = midb;
            } else {
                top = midt;
                bot = midb;
            }
            mid = (top + bot) / 2.;
            best = tryy(mid);
        }
        Point trytop = {max(a.x,max(b.x,c.x)),best};
        Point trybot = {min(a.x,min(b.x,c.x)),best};
        return ternaryx(trytop,trybot);
    }

};
int main() {
    cout << setprecision(6);
    int x1,y1; cin >> x1 >> y1;
    int x2,y2; cin >> x1 >> y1;
    int x3,y3; cin >> x1 >> y1;
    U myU = U();
    myU.a = Point{x1,y1};
    myU.b = Point{x2,y2};
    myU.c = Point{x3,y3};

    //create the line from p1 to p2

    //find the shortest distance 
    double maxy = max(myU.a.y,max(myU.b.y,myU.c.y));
    double miny = min(myU.a.y,min(myU.b.y,myU.c.y));

    Point bestp = myU.ternaryy(maxy,miny);
    cout << bestp.x << " " << bestp.y;

}