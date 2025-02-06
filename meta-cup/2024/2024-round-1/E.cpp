#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

void test_case(long long int t);

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
        test_case((long long int) (t));
}

#define int long long int
typedef pair<int, int> pii;

pair<set<int>, pair<int, pair<int, char> > > make_node(int father, int choices, char c) {
    return make_pair(set<int>(), make_pair(father, make_pair(choices, c)));
}

set<int> children(pair<set<int>, pair<int, pair<int, char> > > node) {
    return node.first;
}

int father(pair<set<int>, pair<int, pair<int, char> > > node) {
    return node.second.first;
}
int choices(pair<set<int>, pair<int, pair<int, char> > > node) {
    return node.second.second.first;
}

char character(pair<set<int>, pair<int, pair<int, char> > > node) {
    return node.second.second.second;
}

int rec(unordered_map<int, pair<set<int>, pair<int, pair<int, char> > > > *nodes, int cur, bool last_many) {
    if (father((*nodes)[cur]) == 12 && character((*nodes)[cur]) == '?') {
        cout << "Me!\n";
        (*nodes)[cur].second.second.first = 26;
    }
    cout << character((*nodes)[cur]) << ' ' << choices((*nodes)[cur]) << '\n';
    if (children((*nodes)[cur]).size() == 0) return choices((*nodes)[cur]);
    int total = 1;
    bool many = false;

    if (choices((*nodes)[cur]) > 1) {
        many = true;
        total = choices((*nodes)[cur]);
    }

    for (auto child : children((*nodes)[cur])) {
        if (many) {
            total = (total + (total * rec(nodes, child, true)) % (int) 998244353) % (int) 998244353;
        } else {
            total = (total + rec(nodes, child, false)) % (int) 998244353;
        }
    }
    if (last_many)
        return total;
    else 
        return total % (int) 998244353;
}

void test_case(int t) {
    // node <children, <father, <choices, char>>>
    unordered_map<int, pair<set<int>, pair<int, pair<int, char> > > > nodes;
    int index = 1;
    nodes[0] = make_node(-1, 0, '-');
    int N;
    cin >> N;

    string s;
    for (int n = 0; n < N; ++n) {
        cin >> s;

        pair<set<int>, pair<int, pair<int, char> > > *last = &nodes[0];
        int last_index = 0;
        int cur_index = 0;

        for (auto c : s) {
            bool q_in = false;
            int q_index = -1;
            bool c_in = false;
            int c_index = -1;
            // cout << last_index << "'s children: "; 
            // cout << children(*last).size() << '\n';
            for (auto node_index : children(*last)) {
                if (character(nodes[node_index]) == '?') {
                    q_in = true;
                    q_index = node_index;
                }
                if (character(nodes[node_index]) == c) {
                    c_in = true;
                    c_index = node_index;
                }
            }

            if (!q_in && c == '?') {
                nodes[index] = make_node(last_index, 26 - (*last).first.size(), c);
                (*last).first.insert(index);
                
                // cout << "Here!\n";
                // cout << index << ' ' << character(nodes[index]) << ' ' << father(nodes[index]) << '\n';

                if (children(nodes[father(nodes[father(nodes[index])])]).size() > 1) {
                    // cout << "Add Me!\n";
                    for (auto fc : children(nodes[father(nodes[father(nodes[index])])])) {
                        if (character(nodes[fc]) == '?') continue;
                        nodes[fc].first.insert(index);
                    }
                }

                last = &nodes[index];

                last_index = index;
                index++;
            }
            else if (q_in && c == '?') {
                last_index = q_index;
                last = &nodes[q_index];
            }
            else if (c_in) {
                last_index = c_index;
                last = &nodes[c_index];
            } 
            else if (q_in && !c_in) {
                (*last).first.insert(index);
                nodes[index] = make_node(last_index, 1, c);
                for (auto i : children(nodes[q_index]))
                    nodes[index].first.insert(i);
                --nodes[q_index].second.second.first;
                last = &nodes[index];

                last_index = index;
                index++;
            } 
            else if (!c_in) {
                (*last).first.insert(index);
                nodes[index] = make_node(last_index, 1, c);
                last = &nodes[index];

                last_index = index;
                index++;
            } 
            else {
                cout << "Else???\n";
            }
        }
    }
    cout << rec(&nodes, 0, false) % (int) 998244353 << '\n';
}