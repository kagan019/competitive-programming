#include <bits/stdc++.h>
using namespace std;

struct Fleck{
  float x,y,z;
};

struct Point {
  float x, y;
  bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

struct pair_point_hash {
    inline std::size_t operator()(const std::pair<Point,Point> & v) const {
        return v.first.x*31+v.second.y+19*v.first.y + 3*v.second.x*v.second.x;
    }
};

// A global point needed for  sorting points with reference 
// to  the first point Used in compare function of qsort() 
Point p0; 
  
// A utility function to find next to top in a stack 
Point nextToTop(vector<Point> &S) 
{ 
    Point p = S.back(); 
    S.pop_back(); 
    Point res = S.back(); 
    S.push_back(p); 
    return res; 
} 
  
// A utility function to swap two points 
void swap(Point &p1, Point &p2) 
{ 
    Point temp = p1; 
    p1 = p2; 
    p2 = temp; 
} 
  
// A utility function to return square of distance 
// between p1 and p2 
int distSq(Point p1, Point p2) 
{ 
    return (p1.x - p2.x)*(p1.x - p2.x) + 
          (p1.y - p2.y)*(p1.y - p2.y); 
} 
  
// To find orientation of ordered triplet (p, q, r). 
// The function returns following values 
// 0 --> p, q and r are colinear 
// 1 --> Clockwise 
// 2 --> Counterclockwise 
int orientation(Point p, Point q, Point r) 
{ 
    float val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
  
    if (abs(val) < 0.0001) return 0;  // colinear 
    return (val > 0)? 1: 2; // clock or counterclock wise 
} 
  
// A function used by library function qsort() to sort an array of 
// points with respect to the first point 
int compare(const void *vp1, const void *vp2) 
{ 
   Point *p1 = (Point *)vp1; 
   Point *p2 = (Point *)vp2; 
  
   // Find orientation 
   int o = orientation(p0, *p1, *p2); 
   if (o == 0) 
     return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1; 
  
   return (o == 2)? -1: 1; 
} 
  
// Prints convex hull of a set of n points. 
vector<Point>* convexHull(vector<Point> &points) 
{ 
   const int n = points.size();
   // Find the bottommost point 
   int ymin = points[0].y, min = 0; 
   for (int i = 1; i < n; i++) 
   { 
     int y = points[i].y; 
  
     // Pick the bottom-most or chose the left 
     // most point in case of tie 
     if ((y < ymin) || (ymin == y && 
         points[i].x < points[min].x)) 
        ymin = points[i].y, min = i; 
   } 
  
   // Place the bottom-most point at first position 
   swap(points[0], points[min]); 
  
   // Sort n-1 points with respect to the first point. 
   // A point p1 comes before p2 in sorted output if p2 
   // has larger polar angle (in counterclockwise 
   // direction) than p1 
   p0 = points[0]; 
   qsort(&points[1], n-1, sizeof(Point), compare); 
  
   // If two or more points make same angle with p0, 
   // Remove all but the one that is farthest from p0 
   // Remember that, in above sorting, our criteria was 
   // to keep the farthest point at the end when more than 
   // one points have same angle. 
   int m = 1; // Initialize size of modified array 
   for (int i=1; i<n; i++) 
   { 
       // Keep removing i while angle of i and i+1 is same 
       // with respect to p0 
       while (i < n-1 && orientation(p0, points[i], 
                                    points[i+1]) == 0) 
          i++; 
  
  
       points[m] = points[i]; 
       m++;  // Update size of modified array 
   } 

  
   // If modified array of points has less than 3 points, 
   // convex hull is not possible 
   if (m < 3) return nullptr; 
  
   // Create an empty stack and push first three points 
   // to it. 
   vector<Point> *Sptr = new vector<Point>(); 
   vector<Point> S = *Sptr;
   S.push_back(points[0]); 
   S.push_back(points[1]); 
   S.push_back(points[2]); 
  
   // Process remaining n-3 points 
   for (int i = 3; i < m; i++) 
   { 
      // Keep removing top while the angle formed by 
      // points next-to-top, top, and points[i] makes 
      // a non-left turn 
      while (orientation(nextToTop(S), S.back(), points[i]) != 2) 
         S.pop_back(); 
      S.push_back(points[i]); 
   } 
  
   return Sptr;
} 

float signedarea(Point p1, Point p2, Point p3) {
  return ((p2.x - p1.x)*(p3.y - p1.y) - (p3.x - p1.x)*(p2.y - p1.y))/2.0;
}

// returns the smallest diameter needed to drill the flecks
float smallestdiam(vector<Point> v){
  vector<Point> p = *convexHull(v);
  const int m = p.size()- 1;
  unordered_set<pair<Point,Point>, pair_point_hash> A;
  int k = 1;

  while(signedarea(p[m],p[0],p[k+1]) > signedarea(p[m],p[1],p[k])){
    k++;
  }
  int i = 0; int j = k;
  while(i <= k && j <= m) {
    A.insert(make_pair(p[i],p[j]));
    while(signedarea(p[i],p[i+1],p[j+1]) > signedarea(p[i],p[i+1],p[j]) && j<m) {
      A.insert(make_pair(p[i],p[j]));
      j++;
    }
    i++;
  }

  auto x = A.begin();
  int maxdist = distSq(x->first, x->second);
  while(x != A.end()) {
    maxdist = max(maxdist, distSq(x->first,x->second));
    x++;
  }
  return sqrt(maxdist);
}

int main() {
  int n; cin >> n;
  vector<Fleck> flecks(n);
  
  for (int i = 0; i < n; i++) {
    cout << i << "hi" << n << " ";
    float a,b,c;
    cin >> a >> b >> c;
    
    flecks.push_back(Fleck{.x=a, .y=b, .z=c});
  }

  vector<Point> xy;
  vector<Point> xz;
  vector<Point> yz;
  for (Fleck &f : flecks) {


    xy.push_back(Point{.x=f.x,.y=f.y});
    xz.push_back(Point{.x=f.x,.y=f.z});
    yz.push_back(Point{.x=f.y,.y=f.z});
  }

  float minxyd = smallestdiam(xy);
  float minxzd = smallestdiam(xz);
  float minyzd = smallestdiam(yz);

  cout << min(minxyd, min(minxzd, minyzd));
}