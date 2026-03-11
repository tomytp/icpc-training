v64 pi(string& s) {
    v64 p(sz(s));
    for(ll i = 1, j = 0; i < sz(s); i++) {
        while(j && s[j] != s[i]) j = p[j-1];
        if(s[j] = s[i]) j++;
        p[i] = j;
    }
    return p;
}