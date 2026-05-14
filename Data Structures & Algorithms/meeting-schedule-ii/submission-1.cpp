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

        vector<int> arr;
        for(auto x: intervals){
            bool flag = false;
            for(int i=0;i<arr.size();i++){
                if(arr[i]<=x.start){
                    arr[i] = x.end;
                    flag = true;
                    break;
                }
            }
            if(flag==false){
                arr.push_back(x.end);
            }
        }
        return arr.size();
        // multiset<int> st;
        // for(auto x: intervals){
        //     if(st.lower_bound(x.start)!=st.end()){
        //         auto it = st.lower_bound(x.start);
        //         if(it!=st.begin()){
        //             it--;
        //             st.erase(it);
        //         }
        //     }
        //     st.insert(x.end);
        // }
        // return st.size();
    }
};
