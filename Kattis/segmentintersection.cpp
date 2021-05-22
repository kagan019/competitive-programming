#include <bits/stdc++.h>
using namespace std;


struct Point {
	double x, y;
	Point(double a, double b) : x(a), y(b) {};
	Point() : x(0), y(0) {};
	bool operator <=(Point other) {
		if (abs(x - other.x) < 0.0001) 
			return y - 0.0001 <= other.y;
		else
			return x - 0.0001 <= other.x;
	}
	bool operator ==(Point other) {
		return *this <= other && other <= *this;
	}
	
};

struct Vector {
	double dx, dy;
	Vector(double a, double b) : dx(a), dy(b) {};
	Vector(Point p) {
		dx = p.x;
		dy = p.y;
	};
	Vector() : dx(0), dy(0) {};
	double dot(Vector o) {
		return dx*o.dx+dy*o.dy;
	};
	double cross (Vector o) {
		return dx*o.dy-dy*o.dx;
	};
	double mag() {
		return sqrt(this->dot(*this));
	};
	Vector norm() {
		double m = this->mag();
		if (abs(m) < 0.0001)
			return *this;
		return Vector(dx/m,dy/m);
	};
	Point pt() {
		return Point(dx,dy);
	};
	Vector operator +(Vector other) {
		return Vector(dx+other.dx, dy+other.dy);
	};
	Vector operator -(Vector other) {
		return *this + (other * -1);
	};
	Vector operator *(double other) {
		return Vector(dx*other,dy*other);
	};
	
};

struct Line { //actually a line segment
	Point start;
	Point end;
	Vector v;
	Line(Point a, Point b) {
		start = (a <= b) ? a : b;
		end = (a <= b) ? b : a;
		v = Vector(end) - Vector(start);
	};
	double length() {
		return v.mag();
	}

	bool ispoint() {
		return length() < 0.0001;
	}
	
};

bool colinear(Line &l, Point &a) {
	Line l2(l.start, a);
	return abs(l.v.cross(l2.v)) < 0.0001;
}


double parallel(Line &l1, Line &l2) {
	return abs(l1.v.cross(l2.v)) < 0.0001;
}

int ret_empty() {
	cout << "none" << endl;
	return 0;
}
int ret_pt(Point p) {
	cout << p.x << " " << p.y << endl;
	return 0;
}
int ret_ln(Line l) {
	cout << l.start.x << " " << l.start.y << " " << l.end.x << " " << l.end.y << endl;
	return 0;
}

int main() {
	cout << fixed << setprecision(2);
	int n; cin >> n;
	while (n--) {
		int x1, y1, x2, y2, x3, y3, x4, y4;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		Line l1 = Line(Point(x1,y1),Point(x2, y2));
		Line l2 = Line(Point(x3,y3), Point(x4,y4));
		if (l2.length() > l1.length()) {
			Line temp = l1;
			l1 = l2;
			l2 = temp;
		}
		Point p1 = l1.start;
		Point p2 = l1.end;
		Point q1 = l2.start;
		Point q2 = l2.end;
		double dx1 = l1.v.dx;
		double dy1 = l1.v.dy;
		double dx2 = l2.v.dx;
		double dy2 = l2.v.dy;

		// both are points
		if (l1.ispoint()) {
			assert (l2.ispoint());
			if (p1 == q1) {
				ret_pt(p1); continue;
			}
			ret_empty(); continue;
		}
		//l1 is a line
		if (l2.ispoint()) {
			if (!colinear(l1,q1)) {
				ret_empty(); continue;
			}
			double t;
			if (abs(dx1) > 0.0001) {
				t = (q1.x-p1.x)/dx1;
			} else { assert(abs(dy1) > 0.0001); //l1 is not a point
				t = (q1.y-p1.y)/dy1;
			} 
			if (0.0000 <= t && t <= 1.0000) {
				ret_pt(q1); continue;
			}
			ret_empty(); continue;
		}
		//both l1 and l2 are lines
		if (parallel(l1,l2)) {
			if (colinear(l1,q1)) {
				Point ostart = (p1 <= q1) ? q1 : p1; //largest start
				Point oend = (p2 <= q2) ? p2 : q2; //smallest end
				// touch at one point
				if (oend == ostart) { 
					ret_pt(ostart); continue;
				}
				// no overlap 
				else if (oend <= ostart) { 
					ret_empty(); continue;
				}
				//overlap as line
				assert(ostart <= oend); 
				ret_ln(Line(ostart,oend)); continue;
			} 
			ret_empty(); continue;
		}
		//the full lines l1 and l2 intersect somewhere, 
		//even if not at a point on both segments

		//find the point on the full line l2 that is colinear with l1.
		double t2 = (Vector(p1)-Vector(q1)).cross(l1.v) / (l2.v.cross(l1.v));
		Point u = (Vector(q1) + l2.v*t2).pt();
		assert(colinear(l1,u));
		assert(colinear(l2,u)); // trivially
		//t is a parameter along l2.
		if (t2 < 0 || t2 > 1) {
			ret_empty(); //t represents a point collinear with l1 but
			continue;    // not on segment l2
		}
		// u is on line segment l2
		if (p1 <= u && u <= p2) {
			ret_pt(u); continue;
		}
		ret_empty(); continue;
	}
}
