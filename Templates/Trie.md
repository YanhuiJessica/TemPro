```cpp
const int SIZE = 26E5 + 5;
int Tire[SIZE][26], tot = 1, isEnd[SIZE];
void Insert( string &s )
{
    int p = 1;
    for( int i = 0; i < s.length(); ++ i )
    {
        int ch = s[i] - 'a';
        if( Tire[p][ch] == 0 ) Tire[p][ch] = ++ tot;
        p = Tire[p][ch];
    }
    isEnd[p] ++;
}
int Find( string &s )
{
    int p = 1;
    int ans = 0;
    for( int i = 0; i < s.length(); ++ i )
    {
        int ch = s[i] - 'a';
        if( Tire[p][ch] == 0 ) return ans;
        p = Tire[p][ch];
        ans += isEnd[p];
    }
    return ans;
}
```