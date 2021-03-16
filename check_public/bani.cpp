#include <bits/stdc++.h>
using namespace std;
#define Mod 1000000007

class Bani {
	public:
	void solve() {
		read_input();

		print_output(get_result());
	}

	private:
        int c, n;

        void read_input() {
            ifstream fin("bani.in");
            fin >> c >> n;
            fin.close();
        }
        // generez 2 ^ (n -1)
        unsigned long long fast_power(long long base, int power) {
            long long result = 1;
            while (power > 0) {
                if (power % 2 == 1) {
                    result = (result*base) % Mod;
                }
                base = (base * base) % Mod;
                power = power / 2;
            }
            return result;
        }
        unsigned long long get_result() {
            unsigned long long result = 0;
            if (c == 1) {  // cazul 1
                result = (5 * (fast_power(2, n-1))) % Mod;
                // calculez dupa formula
            } else {  // c azul 2
            unsigned long long dp[6][2];
            int l = 0;
            dp[1][0] = dp[2][0] = dp[3][0] = dp[4][0] = dp[5][0] = 1;
            for (int i=2; i <= n; i++, l = 1 - l) {
                for (int tip=1; tip <= 5; tip++) {
                if (tip == 1) {
                    dp[tip][1 - l] = (dp[2][l] + dp[3][l] + dp[5][l])
                        % Mod;
                    continue;
                }
                if (tip == 2) {
                    dp[tip][1 - l] = (dp[1][l] + dp[4][l])
                        % Mod;
                    continue;
                }
                if (tip == 3) {
                    dp[tip][1 - l] = (dp[1][l] + dp[tip][l] + dp[4][l])
                        % Mod;
                    continue;
                }
                if (tip == 4) {
                    dp[tip][1 - l] = (dp[2][l] + dp[5][l]) % Mod;
                    continue;
                }
                if (tip == 5) {
                    dp[tip][1 - l] = dp[4][l] % Mod;
                    continue;
                }
                }
            }
            result = (dp[1][l] % Mod + dp[2][l] % Mod + dp[3][l] % Mod +
                dp[4][l] % Mod + dp[5][l] % Mod) % Mod;
            }
            return result % Mod;
        }

        void print_output(unsigned long long result) {
            ofstream fout("bani.out");
            fout << result;
            fout.close();
        }
};

int main() {
    Bani *task = new Bani();
    task->solve();
    delete task;
    return 0;
}
