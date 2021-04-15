#include <bits/stdc++.h>
using namespace std;

struct Point {
	double x, y;
	Point(double a, double b) : x(a), y(b) {};
	Point() : x(0), y(0) {};
	bool operator <=(Point other) {
		if (abs(x - other.x) < 0.001) 
			return y <= other.y;
		else
			return x <= other.x;
	}
};

struct Vector {
	double dx, dy;
	bool nan;
	Vector(double a, double b) : dx(a), dy(b) {nan = false;};
	Vector() : nan(true) {};
	double dot(Vector &o) {
		return dx*o.dx+dy*o.dy;
	};
	double cross (Vector o) {
		return dx*o.dy-dy*o.dx;
	}
	double mag() {
		return sqrt(this->dot(*this));
	};
	Vector norm() {
		double m = this->mag();
		if (abs(m) < 0.0001)
			return Vector();
		return Vector(dx/m,dy/m);
	};
};

struct Line { //actually a line segment
	Point start;
	Point end;
	Vector v;
	Line(Point a, Point b) {
		start = (a <= b) ? a : b;
		end = (a <= b) ? b : a;
		v = Vector(end.x-start.x,end.y-start.y);
	};
	
};

bool colinear(Line &l, Point &a) {
	Line l2(l.start, a);
	return abs(l.v.cross(l2.v)) < 0.0001;
}


double parallel(Line l1, Line l2) {
	return abs(l1.v.cross(l2.v)) < 0.0001;
}

int main() {
	cout << fixed << setprecision(2);

	int n; cin >> n;
	while (n--) {
		int x1, y1, x2, y2, x3, y3, x4, y4;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		Line l1 = Line(Point(x1, y1), Point(x2,y2));
		Line l2 = Line(Point(x3, y3), Point(x4,y4));


		if (l1.v.mag() < 0.001 && l2.v.mag() > 0.001) {
			//(just) l1 is a point. singularities abound.
			if (colinear(l2,l1.start)
			&& l2.start <= l1.start && l1.start <= l2.end) {
				cout << l1.start.x << " " << l1.start.y << endl;
			} else {
				cout << "none" << endl;
			}

			continue;
		}

		// if l1 is a point, l2 is a point
		assert(l1.v.mag() > 0.001 || l2.v.mag() < 0.001);

		if (parallel(l1,l2)) {
			if (colinear(l1,l2.start)) {
				//find min x				
				if (l2.start <= l1.end && l1.start <= l2.end) {
					Point mxs = (l1.start <= l2.start) ? l2.start : l1.start;
					Point mne = (l1.end <= l2.end) ? l1.end : l2.end;
					if (Line(mxs,mne).v.mag() < 0.001) {
						// coincide at one point
						cout << mxs.x << " " << mxs.y << endl;
					} else {
						// coincide at line
						cout << mxs.x << " " << mxs.y << " " << mne.x << " " << mne.y << endl;
					}
				} else {
					cout << "none" << endl;
				}
			}
			else {
				cout << "none" << endl;
			}
			continue;			
		}

		// l1 and l2 are not points
		assert(l2.v.mag() > 0.001);

		//solve for t1
		double t1 = (l2.v.dx*(l1.start.y-l2.start.y)-l2.v.dy*(l1.start.x -l2.start.x))
						/ (l1.v.dx*l2.v.dy-l1.v.dy*l2.v.dx) ;
		Point findme(l1.start.x+t1*l1.v.dx,l1.start.y+t1*l1.v.dy);
		assert(colinear(l2,findme));

		//solve for t2	
		double t2 = (findme.x-l2.start.x) / l2.v.dx;
		//check if t1 and t2 correspond to points on the lines
		if (0 <= t1 <= 1.00 && 0 <= t2 <= 1.00) {
			cout << findme.x << " " << findme.y << endl;
		} else
			cout << "none" << endl;


	}
}