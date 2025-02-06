#include <iostream>
#include <list>
using namespace std;

void run(int t) {
    #define start first
    #define finish second
    int N, G, E;
    cin >> N >> G;
    list<pair<int, int> > intervals;
    for (int n = 0; n < N; ++n) {
        cin >> E;

        list<pair<int, int> >::iterator it = intervals.begin();
        int momentum = E;
        int position = 0;
        while (it != intervals.end() && position + momentum >= it->start) {
            // cout << momentum << ' ' << position << '\n';
            momentum = momentum + position - it->start + 1;
            position = it->finish;

            // Shift Interval Down
            it->start = it->start - 1;
            it->finish = it->finish - 1;

            // Check for previous Interval
            if (distance(prev(it), intervals.begin()) >= 0 && prev(it)->finish == it->start - 1) {
                prev(it)->start = it->start - 1;
                it = intervals.erase(it);
                it--;
            }

            it++;
        }
        position += max(momentum, 0);
        // cout << distance(intervals.begin(), it) << '\n';
        // cout << "Momentum: " << momentum << '\n';
        // cout << "Position: " << position << '\n';
        // it--;
        // I - N - I
        if (distance(prev(it), intervals.begin()) >= 0 && (prev(it))->finish == position - 1 && 
            distance(next(it), intervals.end()) > 0 && (next(it))->start == position + 1) {
            // cout << "INI\n";
            (prev(prev(it)))->finish = (next(it))->finish;
            intervals.erase(next(it));
            // intervals.erase(it);
        }
        // I - N
        else if (distance(prev(it), intervals.begin()) >= 0 && (prev(it))->finish == position - 1) {
            // cout << "IN\n";
            prev(it)->finish = position;
            // intervals.erase(it);
        }
        // N - I
        else if (distance(it, intervals.end()) > 0 && (it)->start == position + 1) {
            // cout << "NI\n";
            (it)->start = position;
            // intervals.erase(next(it));
        }
        // N
        else {
            // cout << "N\n";
            // if (distance(it, intervals.end()) >= 0)
            //     intervals.insert(prev(it), make_pair(position, position));
            // else
                intervals.insert(it, make_pair(position, position));
        }

        // for (auto p : intervals) {
        //     cout << p.start << '-' << p.finish << ' ';
        // } cout << '\n';
    }

    list<pair<int, int> >::iterator it = intervals.begin();
    int min = 10000000;
    int cnt = 0;
    int d = G;
    bool done = false;
    // Edge Case before first
    if (G < intervals.begin()->start) {
        cout << "Case #" << t + 1 << ": " << N << ' ' << intervals.begin()->start - G << '\n'; 
        return;
    }
    // Edge Case after last
    if (G > prev(intervals.end())->finish) {
        cout << "Case #" << t + 1 << ": " << 1 << ' ' << G - prev(intervals.end())->finish << '\n'; 
        return;
    }


    while (distance(it, intervals.end()) > 0) {
        if (G >= it->start && G <= it->finish) { // Inside Current Interval
            cnt += G - it->start;
            d = 0;
            done = true;
            break;
        }
        if (G < it->start) { // Behind Interval -> Found and passed -> Check between last interval and current interval
            break;
        }
        cnt += it->finish - it->start + 1;
        it = next(it);
    } 
    if (done) {
        cout << "Case #" << t + 1 << ": " << N - cnt << ' ' << 0 << '\n'; 
        return;
    }
    // cout << distance(intervals.begin(), it) << ' ' << cnt << ' ' << '\n';
    int prevd = G - prev(it)->finish;
    int nextd = it->start - G;
    if (nextd <= prevd) { // Choose next
        // cout << "Ball Index:" << N - cnt << "  Distance: " << nextd << '\n';
        cout << "Case #" << t + 1 << ": " << N - cnt << ' ' << nextd << '\n'; 
    } else {
        // cout << "Ball Index: " << N - cnt + 1 << "  Distance: " << prevd << '\n';
        cout << "Case #" << t + 1 << ": " << N - cnt + 1 << ' ' << prevd << '\n';
    }
    // cout << prevd << ' ' << nextd << '\n';


    // int l = 0, h = intervals.size() - 1;
    // int target = -1;
    // int m, lastm = 0;
    // int index;
    // int d;

    // list<pair<int, int> >::iterator it = intervals.begin();
    // while (l < h) {
    //     m = l + (h - l + 1) / 2;
    //     it = next(it, lastm - m);
    //     if (G < it->start) h = m - 1;
    //     else if (G > it->finish) l = m;
    //     else {
    //         target = m;
    //         index = G - it->start;
    //         d = 0;
    //     }
    // }
    
    // if (target == -1) {
    //     // Check if it is 0
    //     if (l == 0) {
    //         cout << "Zero\n";
    //         target = l;
    //         index = 0;
    //         d = it->first - G;
    //     }
    //     // Else check between last interval and this interval (this interval will always be more than the target)
    //     else {
    //         // Choose last interval
    //         cout << G << ' ' << it->start << ' ' << prev(it)->finish << '\n';
    //         if (it->start - G < G - prev(it)->finish) {
    //             cout << "Previous\n";
    //             it = prev(it);
    //             target = l - 1;
    //             index = it->finish - it->start + 1;
    //             d = it->finish - G;
    //         } 
    //         // Choose current interval
    //         else {
    //             cout << "Cur\n";
    //             target = l;
    //             index = 0;
    //             d = it->start - G;
    //         }
    //     }
    // }
    // cout << G << ' ' << target << ' ' << d << '\n';
    // for (auto p : intervals) {
    //     cout << p.start << '-' << p.finish << ' ';
    // } cout << '\n' << '\n';
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
        run(t);
}