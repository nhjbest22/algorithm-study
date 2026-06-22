#include <execution>

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if(start > destination) swap(start, destination);
        
        int total = reduce(execution::par_unseq, distance.begin(), distance.end(), 0);
        int dist = reduce(execution::par_unseq, distance.begin()+ start, distance.begin() + destination, 0);

        return min(total - dist, dist);
    }
};