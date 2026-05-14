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

    static bool myCmp(const Interval &i1, const Interval &i2){
        return i1.start<i2.start;
    }

    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), myCmp);

        // vector<int> arr;
        // for(auto x: intervals){
        //     bool flag = false;
        //     for(int i=0;i<arr.size();i++){
        //         if(arr[i]<=x.start){
        //             arr[i] = x.end;
        //             flag = true;
        //             break;
        //         }
        //     }
        //     if(flag==false){
        //         arr.push_back(x.end);
        //     }
        // }
        // return arr.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto x: intervals){
            if(!pq.empty() && pq.top()<=x.start){
                pq.pop();
            }
            pq.push(x.end);
            
        }
        return pq.size();
    }
};
