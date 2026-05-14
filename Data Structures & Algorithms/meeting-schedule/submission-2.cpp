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

    static bool myCmp(const Interval &i1, const Interval &i2) {
        if(i1.start == i2.start){
            return i1.end < i2.end;
        }
        return i1.start < i2.start;
    }


    bool canAttendMeetings(vector<Interval>& intervals) {
        // int rmax=INT_MIN;
        // for(auto &x: intervals){
        //     rmax = max(rmax, x.end);
        // }
        // vector<int> v(rmax+2,0);
        // for(auto &x: intervals){
        //     v[x.start]++;
        //     v[x.end+1]--;
        // }
        // for(int i=1;i<=rmax;i++){
        //     v[i]+= v[i-1];

        //     if(v[i]>1){
        //         return false;
        //     }
        // }
        // return true;
        sort(intervals.begin(), intervals.end(), myCmp);

        for(int i=1;i<intervals.size();i++){
            if(intervals[i].start<intervals[i-1].end){
                return false;
            }
        }
        return true;

    }
};
