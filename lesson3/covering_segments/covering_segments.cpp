#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  long long start, end;
};

bool sortSegments(Segment seg1, Segment seg2){
  return (seg1.start < seg2.start);
};

vector<long long> optimal_points(vector<Segment> &segments) {
  vector<long long> points;
  //write your code here
  std::sort(segments.begin(), segments.end(), sortSegments);

  size_t passedSegment = 0;
  long long lastPoint = -1;
  if (segments.size() != 0){
//    points.push_back(segments[0].end);
    lastPoint = segments[0].end;
  }
  for (size_t i = 0; i < segments.size(); ++i) {
    if (segments[i].start <= lastPoint && segments[i].end >= lastPoint)
      continue;
    else{
      if (segments[i].start <= lastPoint && segments[i].end <= lastPoint)
        lastPoint = segments[i].end;
      else{
        points.push_back(lastPoint);
        lastPoint = segments[i].end;
      }
    }
//    points.push_back(segments[i].start);
//    points.push_back(segments[i].end);
  }

  if (lastPoint != -1)
    points.push_back(lastPoint);

  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<long long> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
  std::cout << std::endl;
}
