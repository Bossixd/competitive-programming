#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define int long long

template <typename T>
pair<T, T> mp(const T& first, const T& second) {
    return make_pair(first, second);
}

struct Casino {
    int start;
    int end;
    int value;
    int min;
    int max;
    Casino* left;
    Casino* right;
};

queue<int> q;
unordered_set<Casino*> s;
unordered_set<int> sv;

class SegmentTree {
private:
    Casino head;

    Casino* addNode(Casino* node, Casino* c) {
        if (!node)
            return c;
        if (c->start < node->start)
            node->left = addNode(node->left, c);
        else
            node->right = addNode(node->right, c);

        node->min = min(node->min, c->start);
        node->max = max(node->max, c->end);
        return node;
    }
public:
    Casino* addNode(Casino* c) {
        addNode(&this->head, c);
    }

    void traverse() {
        traverse(&this->head);
    }

    void traverse(Casino* node) {
        cout << node->value << ' ' << node->min << ' ' << node->max << '\n';
        if (node->left)
            traverse(node->left);
        if (node->right)
            traverse(node->right);
    }

    void setHead(Casino _head) {
        this->head = _head;
    }

    void search(int value) {
        search(&this->head, value);
    }

    void search(Casino* node, int value) {
        if (value >= node->start && value <= node->end) {
            if (s.find(node) == s.end())
                q.push(node->value);
            s.insert(node);
        }

        if (node->left && value >= node->left->min && value <= node->left->max)
            search(node->left, value);
        if (node->right && value >= node->right->min && value <= node->right->max)
            search(node->right, value);
    }
};

void solve() {
    int n, k;
    cin >> n >> k;

    SegmentTree st = SegmentTree();
    vector<Casino> v(n);
    int a, b, c;
    cin >> a >> b >> c;
    Casino head = {a, b, c, a, b, nullptr, nullptr};
    st.setHead(head);
    for (int i = 1; i < n; ++i) {
        cin >> a >> b >> c;
        v[i] = {a, b, c, a, b, nullptr, nullptr};
        st.addNode(&v[i]);
    }

    // st.traverse();

    int mx = 0;
    q.push(k);
    while (!q.empty()) {
        int cur = q.front();
        mx = max(mx, cur);
        q.pop();

        if (sv.find(cur) != sv.end()) continue;
        sv.insert(cur);

        st.search(cur);
    }
    cout << mx << '\n';

    q = queue<int>();
    s.clear();
    sv.clear();
}

#undef int

int main() {
    int N;
    cin >> N;
    while (N--)
        solve();
}
