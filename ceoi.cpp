/*
 * https://github.com/stefdasca/CompetitiveProgramming/blob/master/CEOI/CEOI%2013-treasure2.cpp
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 547
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ll mod=1e9+7;
const ld pai=acos(-1);
#include "treasure.h"
int num [109][109] ;
void findTreasure ( int N ) {
	int half = N / 2 ;
	for ( int i = N ; i > 0 ; i -- ) {
		for ( int j = N ; j > 0 ; j -- ) {
			if ( i > half && j > half ) num [i][j] = countTreasure ( 1 , 1 , i , j ) ;
			if ( i <=half && j > half ) num [i][j] = num [N][j] - countTreasure ( i+1 , 1 , N , j ) ;
			if ( i > half && j <=half ) num [i][j] = num [i][N] - countTreasure ( 1 , j+1 , i , N ) ; 
			if ( i <=half && j <=half ) num [i][j] = num [N][j] + num [i][N] - num [N][N] + countTreasure ( i+1 , j+1 , N , N ) ;
		}
	}
	for ( int i = 1 ; i <= N ; i ++ ) {
		for ( int j = 1 ; j <= N ; j ++ ) {
			if ( num [i][j] > num [i-1][j] + num [i][j-1] - num [i-1][j-1] ) Report ( i , j ) ;
		}
	}
}
