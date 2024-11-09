//INPUT -                  //OUTPUT - 
// . . 3 . 2 . 6 . .       //4 8 3 9 2 1 6 5 7 
// 9 . . 3 . 5 . . 1       //9 6 7 3 4 5 8 2 1 
// . . 1 8 . 6 4 . .       //2 5 1 8 7 6 4 9 3 
// . . 8 1 . 2 9 . .       //5 4 8 1 3 2 9 7 6 
// 7 . . . . . . . 8       //7 2 9 5 6 4 1 3 8 
// . . 6 7 . 8 2 . .       //1 3 6 7 9 8 2 4 5 
// . . 2 6 . 9 5 . .       //3 7 2 6 8 9 5 1 4
// 8 . . 2 . 3 . . 9       //8 1 4 2 5 3 7 6 9 
// . . 5 . 1 . 3 . .       //6 9 5 4 1 7 3 8 2 

#include <bits/stdc++.h>

using namespace std;

// Add the necessary include paths to the compiler flags
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#define nl '\n'
#define sp ' '
#define pi 2 * acos(0.0)
const int INF = 1e9 + 10;

// Control Flow
#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define f0r(i, a) for (int i = 0; i < (a); i++)
#define fOrd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define f0rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto &a : x)

// Types
#define ui unsigned int
#define us unsigned short
#define ull unsigned long long
#define ll long long
#define ld long double
#define vstr vector<string>
#define vll vector<ll>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<pair<int, int>>
#define pii pair<int, int>

// Utils
#define len(x) int((x).size())
#define pb push_back
#define all(n) n.begin(), n.end()
#define rall(n) n.rbegin(), n.rend()

// Constants
const ll MOD = 1e9 + 7;

// Helper Functions
ll nCk(ll n, ll k){
    ll res = 1;
    for (ll i = 0; i < k; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}
ll lcm(ll a, ll b) {
    return a / __gcd(a, b) * b;
}
ll power(ll a, ll b, ll mod) {
    if (b == 0) return 1;
    ll res = power(a, b / 2, mod);
    res = (res * res) % mod;
    if (b % 2 != 0) res = (res * a) % mod;
    return res;
}
/*
    ___        __              __   ______          __        _____ __             __          __  __
   /   | _____/ /___  ______ _/ /  / ____/___  ____/ /__     / ___// /_____ ______/ /______   / / / /__  ________
  / /| |/ ___/ __/ / / / __ `/ /  / /   / __ \/ __  / _ \    \__ \/ __/ __ `/ ___/ __/ ___/  / /_/ / _ \/ ___/ _ \
 / ___ / /__/ /_/ /_/ / /_/ / /  / /___/ /_/ / /_/ /  __/   ___/ / /_/ /_/ / /  / /_(__  )  / __  /  __/ /  /  __/
/_/  |_\___/\__/\__,_/\__,_/_/   \____/\____/\__,_/\___/   /____/\__/\__,_/_/   \__/____/  /_/ /_/\___/_/   \___/
*/
bool canPlace(char num, int rowId, int colId, vector<vector<char>>& board){
    //check for row
    f0r(i, 9){
        if(board[rowId][i] == num) return false;
    }

    //check for col
    f0r(i, 9){
        if(board[i][colId] == num) return false;
    }

    //check for subgrid
    int stgx = (rowId/3)*3;
    int stgy = (colId/3)*3;
    for(int i = stgx; i < stgx + 3; i++){
        for(int j = stgy; j < stgy + 3; j++){
            if(board[i][j] == num) return false;
        }
    }
    return true;
}
bool solve(int rowId, int colId, vector<vector<char>>& board){

    if(rowId == 9) return true; //found a valid solution
    if(colId == 9) return solve(rowId+1, 0, board);

    if(board[rowId][colId] != '.'){//already occupied
        return solve(rowId, colId+1, board);
    }

    //each cell has 9 options
    for(char num = '1'; num <= '9'; num++){
        if(canPlace(num, rowId, colId, board)){
            board[rowId][colId] = num;
            bool res = solve(rowId, colId+1, board);
            if(res) return true;
        }
    }
    board[rowId][colId] = '.';
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t--){
        vector<vector<char>> board(9, vector<char>(9));
        f0r(i, 9){
            f0r(j, 9){
                cin >> board[i][j];
            }  
        }

        solve(0, 0, board);

        f0r(i, 9) {
            f0r(j, 9) {
                cout << board[i][j] << sp;
            }
            cout << nl;
        }
    }
    return 0;
}
