/**
 * cf351A
 * x = a.b
 * 向上取整 <=> x - b + 1 when b != 0; x - b when x = 0
 * 向下取整 <=> x - b
 * ans = abs(sum(x) - (sum(b) + k)), k为向上取整的个数
 * 需要结合 b 为 0 的个数 cnt0 和 k 的取值来求 min(ans), k 属于 [max(0, n - cnt0), min(n, 2 * n - cnt0)]
 *  */ 
void solve() {
    int n;
    cin >> n;
    int tot = 0, cnt0 = 0, ans = inf<int>;
    rep (i, 0, 2 * n) {
        string s;
        int b;
        cin >> s;
        b = stoi(s.substr(s.find('.') + 1));
        tot += b; 
        cnt0 += !b;
    }
    rb (k, max(0, n - cnt0), min(2 * n - cnt0, n)) {
        ans = min(ans, abs(tot - k * 1000));
    }
    cout << ans / 1000 << '.' << ans % 1000/100 << ans % 100/10 << ans % 10;
}

// dp解法
void solve2() {
    int n;
    scanf("%d", &n);
    vector<int> delta(2 * n);
    memset(dp, 0x3f, sizeof dp);
    for (int i = 0; i < 2 * n; i++) {
        int tmp;
        scanf("%d.%d", &tmp, &delta[i]);
    }
    // dp[n][m] 表示前n个数选择了m个数向下取整
    dp[0][0] = 0;
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j <= n; j++) {
            int cel = dp[i][j] + ((1000 - delta[i]) % 1000);
            int flo = dp[i][j] - delta[i];
            // 在选择了j个向下取整的基础上尝试再来一个向下取整
            if (abs(flo) < abs(dp[i + 1][j + 1])) {
                dp[i + 1][j + 1] = flo;
            }
            // 更新处理完第 i 个数后，j 个向下取整的最小值
            if (abs(cel) < abs(dp[i + 1][j])) {
                dp[i + 1][j] = cel;
            }
        }
    }
    // 答案为从2*n个元素中取n个向下取整
    dp[2 * n][n] = abs(dp[2 * n][n]);
    double ans = double(dp[2 * n][n]) / 1000.000;
    printf("%.3f", ans);
}
