/*
User:Kevinrzy103874
oier:任思瑞
age:13
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
/*文件读写*/
#define fre(c) freopen(c".in","r",stdin);freopen(c".out","w",stdout);
/*调试优化*/
#define frets(c) freopen(c".in","r",stdin);
#define scts(x) cout << x << endl;
#define sckgts(x) cout << x << ' ';
/*变量名优化*/
#define ll long long
#define cst const
#define pii(x, y, z) pair<x, y> z;
#define vct(x, y) vector<x> y;
#define dl(x, y) queue<x> y;
#define sddl(x, y) deque<x> y;
#define zhan(x, y) stack<x> y;
#define dgd(x, y) priority_queue<x> y;
#define xgd(x, y) priority_queue<x, vector<x>, greater<x>> y;
#define geng(x) greater<x>
#define ys(x, y, z) map<x, y> z;
#define jh(x, y) set<x> y;
#define dcjh(x, y) multiset<x> y;
#define dcys(x, y, z) multimap<x, y> z;
#define wgl unordered_
#define zfc(x) string s;
#define Fors(lei, x, y, z) for (lei x = y; x <= z; x ++)
#define Forx(lei, x, y, z) for (lei x = y; x >= z; x --)
#define fwFor(name, all) for (auto name : all)
#define why(x) while (x)
#define px(name, start, end) sort(name + start, name + start + end);
#define lowef(name, start, end, x) lower_bound(name + start, name + start + end, x) - name  // 第一个 >= x 的下标
#define upef(name, start, end, x) upper_bound(name + start, name + start + end, x) - name   // 第一个 > x 的下标
#define maxef(name, start, end) max_element(name + start, name + start + end) - name        // 最大值下标
#define minef(name, start, end) min_element(name + start, name + start + end) - name        // 最小值下标
/*函数优化*/
#define rd read()
#define cr(x, y) x.push(y)
#define cw(x, y) x.push_back(y)
#define ct(x, y) x.push_front(y)
#define sc(x) x.pop()
#define st(x) x.pop_front()
#define sw(x) x.pop_back()
#define tou(x) x.front()
#define ding(x) x.top()
#define wei(x) x.back()
#define del(x) x.clear()
#define dxlen(x) x.size()
#define ks(x) x.begin()
#define js(x) x.end()
#define crz(x, y) x.insert(y)
#define shu(x, y) x.count(y)
#define lowef(be, en, x) lower_bound(be, en, x)
#define upef(be, en, x) upper_bound(be, en, x)
#define zfjq(zf, x, y) zf.substr(x - 1, y - x) // 下标1开始
#define zfcz(zf, x) zf.find(x) // x带双引号
#define zfdel(zf, x, y) zf.erase(x - 1, y - x) // 下标1开始
#define zffz(zf, x, y) reverse(zf.begin() + x - 1, zf.begin() + y) // 下标1开始
/*速度优化*/
#define endl '\n'
#define ios ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
/*数据结构*/
#define mid ((l + r) >> 1)
#define ls (x << 1)
#define rs (x << 1 | 1)
#define lowbit(x) x & -x
/*PBDS平衡树*/
// 红黑树（自动排序，能查排名）
template<typename T>
using Tree_pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// 可重复红黑树（允许相同元素）
template<typename T>
using MultiTree_pbds = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define shu_pbds(T, name) Tree_pbds<T> name // 声明一个平衡树
#define duoshu_pbds(T, name) MultiTree_pbds<T> name // 声明一个可重复平衡树
#define jia_pbds(tr, x) tr.insert(x) // 插入一个数
#define shan_pbds(tr, x) tr.erase(x) // 删除一个数
#define paiming_pbds(tr, x) tr.order_of_key(x) // 查x的排名（有几个数比x小，从0开始）
#define dishuk_pbds(tr, k) *tr.find_by_order(k) // 查排名为k的数（k从0开始）
#define qian_pbds(tr, x) *(--tr.lower_bound(x)) // 查x的前一个数（比x小的最大数）
#define hou_pbds(tr, x) *tr.upper_bound(x) // 查x的后一个数（比x大的最小数）
#define you_pbds(tr, x) (tr.find(x) != tr.end()) // 查x是否存在（1有0无）
#define daxiao_pbds(tr) tr.size() // 树的大小
#define qing_pbds(tr) tr.clear() // 清空树
#define zuixiao_pbds(tr) *tr.begin() // 最小的数
#define zuida_pbds(tr) *tr.rbegin() // 最大的数
/*数学常量*/
cst int INF = 0x3f3f3f3f;
cst ll LINF = 0x3f3f3f3f3f3f3f3fLL;
cst double PI = acos(-1.0);
cst double EPS = 1e-9;
/*方向数组*/
cst int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
cst int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
cst ll INV = 1e5 + 5, MOD = 1e9 + 7;
/*链式前项星*/
cst ll EDGEMA = 2 * 1e5 + 5, FLO_MA = 1e2 + 5;
ll tot, head[EDGEMA];
struct Edge {
	ll nxt, to, val;
} e[EDGEMA];
inline void link(ll x, ll y, ll z) {
	tot ++;
	e[tot].to = y;
	e[tot].nxt = head[x];
	e[tot].val = z;
	head[x] = tot;
}
ll dis_for_dij[EDGEMA], dis_for_flo[FLO_MA][FLO_MA], s, t, n_for_dij, n_for_flo;
bool vis[EDGEMA];
inline void dijkstra() {
	Fors(ll, i, 1, n_for_dij) {
		dis_for_dij[i] = INF;
		vis[i] = false;
	}
	dis_for_dij[s] = 0;
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
	pq.push({0, s});
	while (!pq.empty()) {
		ll u = pq.top().second;
		pq.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (ll i = head[u]; i; i = e[i].nxt) {
			ll v = e[i].to;
			ll w = e[i].val;
			if (dis_for_dij[v] > dis_for_dij[u] + w) {
				dis_for_dij[v] = dis_for_dij[u] + w;
				pq.push({dis_for_dij[v], v});
			}
		}
	}
}
inline void flo() {
	Fors(ll, k, 1, n_for_flo) {
		Fors(ll, i, 1, n_for_flo) {
			Fors(ll, j, 1, n_for_flo) {
				dis_for_flo[i][j] = min(dis_for_flo[i][j], dis_for_flo[i][k] + dis_for_flo[k][j]);
			}
		}
	}
}
/*并查集*/
cst ll BCJMA = 2 * 1e5 + 5;
ll fa[BCJMA];
inline void init_BCJ() {
	Fors(ll, i, 0, BCJMA - 1) {
		fa[i] = i;
	}
}
inline ll find_fa(ll x) {
	return fa[x] == x ? x : fa[x] = find_fa(fa[x]);
}
inline void join_BCJ(ll x, ll y) {
	ll u = find_fa(x), v = find_fa(y);
	if (u != v) {
		fa[u] = v;
	}
}
/*Kruskal*/
cst ll KRUSKAL_MA = 2 * 1e5 + 5;
struct Edge_kruskal {
	ll u, v, w;
	bool operator < (cst Edge_kruskal &other) cst {
		return w < other.w;
	}
} e_kruskal[KRUSKAL_MA];
ll fa_kruskal[KRUSKAL_MA];
ll n_kruskal, m_kruskal, cnt_kruskal;
ll ans_kruskal;  // 最小生成树总权值
bool vis_kruskal[KRUSKAL_MA];
inline void init_kruskal() {
	Fors(ll, i, 1, n_kruskal) {
		fa_kruskal[i] = i;
	}
	cnt_kruskal = 0;
	ans_kruskal = 0;
	memset(vis_kruskal, 0, sizeof(vis_kruskal));
}
inline ll find_kruskal(ll x) {
	return fa_kruskal[x] == x ? x : fa_kruskal[x] = find_kruskal(fa_kruskal[x]);
}
inline bool merge_kruskal(ll x, ll y) {
	ll u = find_kruskal(x), v = find_kruskal(y);
	if (u != v) {
		fa_kruskal[u] = v;
		return true;
	}
	return false;
}
inline bool kruskal() {
	init_kruskal();
	sort(e_kruskal + 1, e_kruskal + m_kruskal + 1);
	Fors(ll, i, 1, m_kruskal) {
		if (merge_kruskal(e_kruskal[i].u, e_kruskal[i].v)) {
			cnt_kruskal++;
			ans_kruskal += e_kruskal[i].w;
			vis_kruskal[i] = true;
			if (cnt_kruskal == n_kruskal - 1) break;
		}
	}
	return cnt_kruskal == n_kruskal - 1;
}
/*线段树（屎山）*/
cst ll SegTreeMA = 2 * 1e5 + 5;
struct Segtree {
	// 基础信息
	ll sum[SegTreeMA << 2];      // 区间和
	ll maxx[SegTreeMA << 2];     // 区间最大值
	ll minn[SegTreeMA << 2];     // 区间最小值
	ll xorv[SegTreeMA << 2];     // 区间异或值
	// 懒标记
	ll add[SegTreeMA << 2];      // 加法懒标记
	ll hadd[SegTreeMA << 2];     // 历史最大加法标记
	// 动态开点专用数组
	ll lson[SegTreeMA << 2];     // 动态左儿子
	ll rson[SegTreeMA << 2];     // 动态右儿子
	ll rt, cnt;                  // 根节点，节点计数
	ll a[SegTreeMA];             // 原数组
	// 向上更新（静态）
	inline void push_up(ll x) {
		sum[x] = sum[ls] + sum[rs];
		maxx[x] = max(maxx[ls], maxx[rs]);
		minn[x] = min(minn[ls], minn[rs]);
		xorv[x] = xorv[ls] ^ xorv[rs];
	}
	// 动态向上更新
	inline void push_up_dynamic(ll x) {
		sum[x] = sum[lson[x]] + sum[rson[x]];
		maxx[x] = max(maxx[lson[x]], maxx[rson[x]]);
		minn[x] = min(minn[lson[x]], minn[rson[x]]);
		xorv[x] = xorv[lson[x]] ^ xorv[rson[x]];
	}
	// 建树（静态）
	inline void build(ll x, ll l, ll r) {
		if (l == r) {
			sum[x] = maxx[x] = minn[x] = xorv[x] = a[l];
			return ;
		}
		build(ls, l, mid);
		build(rs, mid + 1, r);
		push_up(x);
	}
	// 应用加法标记（通用）
	inline void apply_add(ll x, ll l, ll r, ll v, ll hv) {
		sum[x] += v * (r - l + 1);
		maxx[x] += v;
		minn[x] += v;
		if ((r - l + 1) & 1) xorv[x] ^= v;
		add[x] += v;
	}
	// 向下传递懒标记（静态，用宏）
	inline void push_down(ll x, ll l, ll r) {
		if (add[x] || hadd[x]) {
			apply_add(ls, l, mid, add[x], hadd[x]);
			apply_add(rs, mid + 1, r, add[x], hadd[x]);
			add[x] = hadd[x] = 0;
		}
	}
	// 动态向下传递
	inline void push_down_dynamic(ll x, ll l, ll r) {
		if (!lson[x]) lson[x] = ++cnt;
		if (!rson[x]) rson[x] = ++cnt;
		if (add[x] || hadd[x]) {
			apply_add(lson[x], l, mid, add[x], hadd[x]);
			apply_add(rson[x], mid + 1, r, add[x], hadd[x]);
			add[x] = hadd[x] = 0;
		}
	}
	// 区间加法（静态，用宏）
	inline void update_add(ll x, ll l, ll r, ll ql, ll qr, ll v) {
		if (ql <= l && r <= qr) {
			apply_add(x, l, r, v, v);
			return ;
		}
		push_down(x, l, r);
		if (ql <= mid) update_add(ls, l, mid, ql, qr, v);
		if (qr > mid) update_add(rs, mid + 1, r, ql, qr, v);
		push_up(x);
	}
	// 单点赋值（动态开点）
	inline void set_val(ll &x, ll l, ll r, ll pos, ll v) {
		if (!x) x = ++cnt;
		if (l == r) {
			sum[x] = maxx[x] = minn[x] = xorv[x] = v;
			return ;
		}
		if (pos <= mid) set_val(lson[x], l, mid, pos, v);
		else set_val(rson[x], mid + 1, r, pos, v);
		push_up_dynamic(x);
	}
	// 区间求和（静态，用宏）
	inline ll query_sum(ll x, ll l, ll r, ll ql, ll qr) {
		if (ql <= l && r <= qr) return sum[x];
		push_down(x, l, r);
		ll res = 0;
		if (ql <= mid) res += query_sum(ls, l, mid, ql, qr);
		if (qr > mid) res += query_sum(rs, mid + 1, r, ql, qr);
		return res;
	}
	// 区间最大值（静态，用宏）
	inline ll query_max(ll x, ll l, ll r, ll ql, ll qr) {
		if (ql <= l && r <= qr) return maxx[x];
		push_down(x, l, r);
		ll res = -LINF;
		if (ql <= mid) res = max(res, query_max(ls, l, mid, ql, qr));
		if (qr > mid) res = max(res, query_max(rs, mid + 1, r, ql, qr));
		return res;
	}
	// 区间最小值（静态，用宏）
	inline ll query_min(ll x, ll l, ll r, ll ql, ll qr) {
		if (ql <= l && r <= qr) return minn[x];
		push_down(x, l, r);
		ll res = LINF;
		if (ql <= mid) res = min(res, query_min(ls, l, mid, ql, qr));
		if (qr > mid) res = min(res, query_min(rs, mid + 1, r, ql, qr));
		return res;
	}
	// 区间异或值（静态，用宏）
	inline ll query_xor(ll x, ll l, ll r, ll ql, ll qr) {
		if (ql <= l && r <= qr) return xorv[x];
		push_down(x, l, r);
		ll res = 0;
		if (ql <= mid) res ^= query_xor(ls, l, mid, ql, qr);
		if (qr > mid) res ^= query_xor(rs, mid + 1, r, ql, qr);
		return res;
	}
	// 线段树合并（动态）
	inline ll merge(ll x, ll y, ll l, ll r) {
		if (!x || !y) return x | y;
		if (l == r) {
			sum[x] += sum[y];
			maxx[x] = max(maxx[x], maxx[y]);
			minn[x] = min(minn[x], minn[y]);
			xorv[x] ^= xorv[y];
			return x;
		}
		push_down_dynamic(x, l, r);
		push_down_dynamic(y, l, r);
		lson[x] = merge(lson[x], lson[y], l, mid);
		rson[x] = merge(rson[x], rson[y], mid + 1, r);
		push_up_dynamic(x);
		return x;
	}
	// 线段树分裂（动态）
	inline void split(ll x, ll &y, ll l, ll r, ll k) {
		if (!x) return ;
		y = ++cnt;
		if (l == r) {
			if (k > 0) return ;
			else {
				swap(sum[x], sum[y]);
				swap(maxx[x], maxx[y]);
				swap(minn[x], minn[y]);
				swap(xorv[x], xorv[y]);
				return ;
			}
		}
		push_down_dynamic(x, l, r);
		ll left_sz = mid - l + 1;
		if (k >= left_sz) {
			split(rson[x], rson[y], mid + 1, r, k - left_sz);
		} else {
			swap(rson[x], rson[y]);
			split(lson[x], lson[y], l, mid, k);
		}
		push_up_dynamic(x);
		push_up_dynamic(y);
	}
	
	// 初始化
	inline void init() {
		cnt = 0;
		rt = 0;
		memset(lson, 0, sizeof(lson));
		memset(rson, 0, sizeof(rson));
		memset(sum, 0, sizeof(sum));
		memset(maxx, 0, sizeof(maxx));
		memset(minn, 0, sizeof(minn));
		memset(xorv, 0, sizeof(xorv));
		memset(add, 0, sizeof(add));
		memset(hadd, 0, sizeof(hadd));
	}
};
/*快读*/
inline ll read() {
	char c;
	ll sum = 0;
	int f = 1;
	c = getchar();
	while (!isdigit(c)) {
		if (c == '-')
			f *= -1;
		c = getchar();
	}
	while (isdigit(c)) {
		sum = sum * 10 + (c - '0');
		c = getchar();
	}
	return sum * f;
}
/*数论*/
inline ll fastPow(ll a, ll b, ll m) {
	ll res = 1;
	a %= m;
	while (b > 0) {
		if(b & 1) {
			res = (res * a) % m;
		}
		a = (a * a) % m;
		b >>= 1;
	}
	return res;
}
inline ll exgcd(ll a, ll b, ll &x, ll &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	ll d = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}
ll inv[INV];
inline void workinv(ll n) {
	inv[1] = 1;
	for (ll i = 2; i <= n; i ++) {
		inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
	}
}
/*Tarjan*/
cst ll SCC_MA = 2 * 1e5 + 5;
ll dfn_scc[SCC_MA], low_scc[SCC_MA], stk_scc[SCC_MA], top_scc;
ll col_scc[SCC_MA], cnt_scc, num_scc;
bool vis_scc[SCC_MA];
vct(ll, e_scc[SCC_MA]);
inline void tarjan_scc(ll u) {
	dfn_scc[u] = low_scc[u] = ++num_scc;
	stk_scc[++top_scc] = u;
	vis_scc[u] = true;
	fwFor(v, e_scc[u]) {
		if (!dfn_scc[v]) {
			tarjan_scc(v);
			low_scc[u] = min(low_scc[u], low_scc[v]);
		} else if (vis_scc[v]) {
			low_scc[u] = min(low_scc[u], dfn_scc[v]);
		}
	}
	if (dfn_scc[u] == low_scc[u]) {
		cnt_scc++;
		ll v;
		do {
			v = stk_scc[top_scc--];
			vis_scc[v] = false;
			col_scc[v] = cnt_scc;
		} while (v != u);
	}
}
/*缩点建新图*/
vct(ll, new_e_scc[SCC_MA]);
ll in_scc[SCC_MA], val_scc[SCC_MA], new_val_scc[SCC_MA];
inline void build_new_scc(ll n) {
	Fors(ll, u, 1, n) {
		fwFor(v, e_scc[u]) {
			if (col_scc[u] != col_scc[v]) {
				cw(new_e_scc[col_scc[u]], col_scc[v]);
				in_scc[col_scc[v]]++;
			}
		}
	}
}
/*全局变量区*/
		
int main() {
//	ios
//	fre("")
	
	return 0;
}
/*
模板来源:https://github.com/Kevinrzy103874/c_main_head_file_for_contest
作者:Kevinrzy103874(任思瑞)
遵循MIT开源原则
*/
