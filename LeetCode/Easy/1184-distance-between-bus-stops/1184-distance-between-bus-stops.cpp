#include <execution>

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if(start > destination) swap(start, destination);
        
        int total = reduce(distance.begin(), distance.end(), 0);
        int dist = reduce(distance.begin()+ start, distance.begin() + destination, 0);

        return min(total - dist, dist);
    }
};