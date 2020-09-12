#include <bits/stdc++.h>
using namespace std;

struct Point {
	int x, y;
	Point(int a, int b) : x(a), y(b) {};
};

struct Vector {
	int dx, dy;
	Vector(int a, int b) : dx(a), dy(b) {};
	double len() {
		return sqrt(dx*dx + dy*dy);
	}
};

struct Line { //actually a line segment
	Point start;
	Vector v;
	Line(Point a, Vector b) : start(a), v(b) {};
	
};

int main() {
	cout << fixed << setprecision(2);

	int n; cin >> n;
	while (n--) {
		int x1, y1, x2, y2, x3, y3, x4, y4;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		Line l1 = Line(Point(x1, y1), Vector(x2-x1, y2-y1));
		Line l2 = Line(Point(x3, y3), Vector(x4-x3, y4-y3));
		// l1.start + l1.v*t1 = l2.start + l2.v*t2 for both ]x ]y
		// t2 = (l1.start - l2.start +l1.v*t1) / l2.v ]x
		//    = (l1.start - l2.start +l1.v*t1) / l2.v ]y
		// (l1.start.y - l2.start.y) + l1.v.dy*t1 - l1.v.dx*t1 * l2.v.dy / l2.v.dx  = (l1.start.x - l2.start.x) * l2.v.dy / l2.v.dx
		// (not horizontal nor vertical)

		//cases
		const double len1 = l1.v.len();
		const double len2 = l2.v.len();
		if (l1.v.dx / len1 == l2.v.dx / len2 && l1.v.dy / len1 == l2.v.dy / len2) { // parallel	
			
			if (l2.v.dx == 0 && l1.v.dx == 0) { // | |
				if (l1.start.x == l2.start.x) {
					Line lower, higher;
					if (l1.start.y < l2.start.y) {
						lower = l1;
						higher = l2;
					}
					else {
						lower = l2;
						higher = l1;
					}

					if (lower.start.y + lower.v.dy >= higher.start.y) {
						//intersect
						p1 = Point(higher.start.x, higher.start.y);
						p2 = Point(higher.start.x, lower.start.y + lower.v.dy);
						cout << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << endl;
					}
					else {
						// none
						cout << "none" << endl;
					}
				}
				else {
					//none
					cout << "none" << endl;
				}
				continue;
			}
			else if (l2.v.dy == 0 && l1.v.dy == 0) { // - -
				if (l1.start.y == l2.start.y) {
					Line lefter, righter;
					if (l1.start.x < l2.start.x) {
						lefter = l1;
						righter = l2;
					}
					else {
						lefter = l2;
						righter = l1;
					}

					if (lefter.start.x + lefter.v.dx >= righter.start.x) {
						p1 = Point(righter.start.x, righter.start.y);
						p2 = Point(righter.start.x, righter.start.y + righter.v.dy);
						cout << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << endl;
					}
					else {
						// none
						cout << "none" << endl;
					}
				}
				else {
					//none
					cout << "none" << endl;
				}
				continue;
			}
			else { // not degenerate
				const int ildx = (l1.start.x - l2.start.x)
				const int ildy = (l1.start.y - l2.start.y)
				const double illen = sqrt(ildx*ildx + ildy*ildy);
				Line lower, higher;
				if (ildx / illen == l1.v.dx / len1 && ildy / illen == l1.v.dy / len1) {
					if (l1.start.y <) {

					}
					else {

					}

					p1 = Point(righter.start.x, righter.start.y);
					p2 = Point(righter.start.x, righter.start.y + righter.v.dy);
					cout << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << endl;
				}
				else if (ildx / illen == -l1.v.dx / len1 && ildy / illen == -l1.v.dy / len1) {

				}
				else {
					cout << "none" << endl;
				}
				continue;
			}
		} 
		else if (l1.v.dx == 0 && l2.v.dy == 0) { // | -
			int hor_begin, hor_end;
			if (l2.v.dx > 0) {
				hor_begin = l2.start.x;
				hor_end = l2.start.x + l2.v.dx;
			}
			else if (l2.v.dx < 0) {
				hor_begin = l2.start.x + l2.v.dx;
				hor_end = l2.start.x;
			}

			if (hor_begin <= l1.start.x
				&& hor_end >= l1.start.x) {
				//intersection
				cout << l1.start.x << " " << l2.start.y << endl;
			}
			else {
				//none
				cout << "none" << endl;
			}
			continue;
		}
		else if (l1.v.dy == 0 && l2.v.dx == 0) { // - |
			int hor_begin, hor_end;
			if (l1.v.dx > 0) {
				hor_begin = l1.start.x;
				hor_end = l1.start.x + l1.v.dx;
			}
			else if (l1.v.dx < 0) {
				hor_begin = l1.start.x + l1.v.dx;
				hor_end = l1.start.x;
			}

			if (hor_begin <= l2.start.x
				&& hor_end >= l2.start.x) {
				//intersection
				cout << l2.start.x << " " << l1.start.y << endl;
			}
			else {
				//none
				cout << "none" << endl;
			}
			continue;
		} 
		else if (l2.v.dx != 0 && l2.v.dy != 0) {
			double t1 = 
				( ((l1.start.x - l2.start.x) / (double)l2.v.dx) - ((l1.start.y - l2.start.y) / (double)l2.v.dy) ) 
				/ ( (l1.v.dy / (double)l2.v.dy) - (l1.v.dx / (double)l2.v.dx) );
			if (t1 < 0.0 || t1 > 1.0) {
				//no intersect
				cout << "none" << endl;
				continue;
			}
			double t2 = (l1.start.x - l2.start.x + l1.v.dx * t1) / (double)l2.v.dx;
			if (t2 < 0.0 || t2 > 1.0) {
				//no intersect
				cout << "none" << endl;
				continue;
			}
			//intersect
			double px = l1.start.x + l1.v.dx * t1;
			double py = l1.start.y + l1.v.dy * t1;

			cout << px << " " << py << "\n";
			continue;
		}
		else if (l1.v.dx != 0 && l1.v.dy != 0) {
			double t2 = 
				( ((l2.start.x - l1.start.x) / (double)l1.v.dx) - ((l2.start.y - l1.start.y) / (double)l1.v.dy) ) 
				/ ( (l2.v.dy / (double)l1.v.dy) - (l2.v.dx / (double)l1.v.dx) );
			if (t2 < 0.0 || t2 > 1.0) {
				//no intersect
				cout << "none" << endl;
				continue;
			}
			double t1 = (l2.start.x - l1.start.x + l2.v.dx * t2) / (double)l1.v.dx;
			if (t1 < 0.0 || t1 > 1.0) {
				//no intersect
				cout << "none" << endl;
				continue;
			}
			//intersect
			double px = l2.start.x + l2.v.dx * t2;
			double py = l2.start.y + l2.v.dy * t2;

			cout << px << " " << py << "\n";
			continue;
		}
		
	}
}