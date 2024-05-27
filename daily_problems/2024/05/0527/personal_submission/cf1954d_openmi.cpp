void solve() {
    const int mod = 998244353;
    int n;
    cin >> n;
    vi a(n);
    in(a);
    srt(a);
    vector<int> cntS(5001); // sum 的个数
    ll ans = 0, s = 0;
    cntS[0] = 1;
    for (int x: a) {
        rb (j, 0, x) {
            ans += 1LL * cntS[j] * x % mod;
            ans %= mod;
        }
        rb (j, x + 1, s) {
            ans += 1LL * cntS[j] * ((x + j + 1) / 2) % mod;
            ans %= mod;
        }
        br (j, s, 0) { // 从大到小枚举
            cntS[j + x] += cntS[j]; cntS[j + x] %= mod;
        }
        s += x;
    } 
    cout << ans << nl;
}
