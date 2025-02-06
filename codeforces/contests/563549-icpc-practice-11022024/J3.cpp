#include <iomanip>
#include <iostream>
#include <vector>
#include <array>
using namespace std;
typedef long long ll;
template<class T1,class T2> bool cmin(T1 &x,const T2 &y) { if (y<x) { x=y; return 1; }return 0; }
template<class T1,class T2> bool cmax(T1 &x,const T2 &y) { if (x<y) { x=y; return 1; }return 0; }
#define all(x) (x).begin(),(x).end()
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<fixed<<setprecision(15);
	int n,i,j;
	cin>>n;
	vector<array<int,3> > a(n);
	vector<int> X(n);
	i=0;
	for (auto &[l,r,id]: a)
	{
		cin>>l>>r;
		X[i]=l+r;
		r=-r;
		id=i++;
	}
	sort(all(X)); 
    for (auto I : X) {
        cout << I << ' ';
    } cout << '\n';
    X.resize(unique(all(X))-X.begin());
	vector<int> b(n+1,-1);
	sort(all(a));
	vector<int> ans(n);

    for (auto I : X) {
        cout << I << ' ';
    } cout << '\n';
    for (auto I : a) {
        cout << I[0] << ' ' << I[1] << ' ' << I[2] << '\n';
    } cout << '\n';

	for (auto [l,r,id]: a)
	{
        r=-r;
		r+=l;
        cout << l << ' ' << r << ' ' << id << '\n';
		int x=lower_bound(all(X),r)-X.begin()+1,y; // Find Index of right
        cout << *lower_bound(all(X),r) << ' ' << x << '\n';
		y=x;
		r=b[y];
        cout << r << '\n';

		while ((y+=y&-y)<=n) 
            cmax(r,b[y]);

		ans[id]=++r;
		cmax(b[x],r);

		while (x^=x&-x) 
            cmax(b[x],r);
        

	}

	for (i=0; i<n; i++) 
        cout << ans[i] << " \n" [i+1 == n];
}