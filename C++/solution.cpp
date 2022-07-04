#include <iostream>
#include <vector>

using namespace std;

#define ll long long

ll n;
vector<ll> h;
ll seg[1000001];
ll ans;

int init(int node, int s, int e){
    if(s==e) return seg[node]=s;
    int mid=(s+e)/2;
    int left=init(node*2, s, mid);
    int right=init(node*2+1, mid+1, e);

    return seg[node]=h[left]<h[right] ? left : right;
}

int query(int node, int s, int e, int l, int r){
    if(e<l || s>r) return 2e9;
    if(l<=s && r>=e) return seg[node];
    int mid=(s+e)/2;
    int left=query(2*node, s, mid, l, r);
    int right=query(2*node+1, mid+1, e, l, r);

    if(left==2e9) return right;
    if(right==2e9) return left;
    else return h[left]<h[right] ? left : right;
}

void solve(ll left, ll right){
    if(left > right) return;

    ll idx=query(1, 0, n-1, left, right);

    ans=max(ans, h[idx]*(right-left+1));

    solve(left, idx-1);
    solve(idx+1, right);
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(1){
        cin >> n;
        if(n==0) break;
        for(int i=0; i<n; i++){
            int a;
            cin >> a;
            h.push_back(a);
        }
        init(1, 0, n-1);
        solve(0, n-1);
        cout << ans << "\n";
        h.clear();
        ans=0;
    }
}