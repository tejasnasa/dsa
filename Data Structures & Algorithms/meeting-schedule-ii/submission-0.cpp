/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int time[1000005] = {0}, rooms = 0;
        for (auto x: intervals) {
            time[x.start]++;
            time[x.end]--;
        }
        for (int i = 1; i < 1000005; i++) {
            time[i] += time[i-1];
            rooms = max(rooms, time[i]);
        }

        return rooms;
    }
};
