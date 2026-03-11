
struct pt{
    ll x, y; 
    pt(ll x_ = 0, ll y_ = 0) : x(x_), y(y_) {}
    pt operator - (const pt p) const { return pt(x - p.x, y - p.y); }
    ll operator ^ (const pt p) const { return x*(ll)p.y - y*(ll)p.x; }
};

ll sarea2(pt p, pt q, pt r) {
    return (q-p)^(r-q);
}

bool ccw(pt p, pt q, pt r) {
    return sarea2(p,q,r) > 0;
}

vector<pt> convex_hull(vector<pt> &v) {
    v.erase(unique(v.begin(), v.end()), v.end());
    if(sz(v) <=1) return v;
    vector<pt> l, u;
    forn(i, 0, sz(v)) {
        while(sz(l) > 1 && !ccw(l.end()[-2], l.end()[-1], v[i]))
            l.pop_back();
        l.push_back(v[i]);
    }
    for(ll i = sz(v)-1; i>=0; i--) {
        while(sz(u) > 1 && !ccw(u.end()[-2], u.end()[-1], v[i]))
            u.pop_back();
        u.push_back(v[i]);
    }
    l.pop_back();
    u.pop_back();
    for(pt i : u) l.push_back(i);
    return l;
}