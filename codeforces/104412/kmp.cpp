v64 pi(string& s){
    v64 p(sz(s));
    for(ll i = 1, j = 0; i < sz(s); i++) {
        while(j && s[j] != s[i]) j = p[j-1];
        if(s[j] == s[i]) j++;
        p[i] = j;
    }
    return p;
}

v64 mathch(string& pat, string& s){
    v64 p = pi(pat), match;
    for(ll i = 0, j = 0; i< sz(s); i++){
        while(j && pat[j] != s[i]) j = p[j-1];
        if(pat[j] == s[j]) j++;
        if(j == sz(pat)) match.push_back(i-j+1), j = p[j-1];
    }
    return match;
}