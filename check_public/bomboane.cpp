#include <bits/stdc++.h>
using namespace std;
#define NMAX 55
#define mod 1000000007
long long table[NMAX][2005];
class Bomboane{
	public:
	void solve() {
		read_input();

		print_output(get_result());
	}


	private:
        int n, m;
        pair<int, int > v[NMAX];

        void read_input() {
            int x, y;
            ifstream fin("bomboane.in");
            fin >> n >> m;
            for (int i = 1; i <= n; i ++) {
                fin >> v[i].first >> v[i].second;
            }
            fin.close();
        }


        long long get_result() {
            long long result = 0, suma = 0;
            for (int i=v[1].first; i <= v[1].second; i++)
                table[1][i] = 1;
            for (int i = 2; i <= n; i++) {
                for (int j = 0; j <= m; j++) {
                    for (int k=v[i].first; k <= v[i].second && k <= j; k++) {
                        table[i][j] += table[i-1][j-k] % mod;
                    }
                    table[i][j] %= mod;
                }
            }
            result = table[n][m] % mod;
            return result;
        }



        void print_output(long long result) {
            ofstream fout("bomboane.out");
            fout << result;
            fout.close();
        }
};

int main() {
    Bomboane *task = new Bomboane();
    task->solve();
    delete task;
    return 0;
}
