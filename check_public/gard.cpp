#include <bits/stdc++.h>
using namespace std;

struct pereche {
	int st, dr;
};
vector<pereche> v;

class Gard {
	public:
	void solve() {
		read_input();

		print_output(get_result());
	}

	private:
		int n;

		void read_input() {
			int x, y;
			ifstream fin("gard.in");
			fin >> n;
			for (int i = 0; i < n; i++) {
				fin >> x >> y;
				v.push_back({x, y});
			}
			fin.close();
		}

		static bool comp(pereche a, pereche b ) {
			return (a.st < b.st);
		}
		int get_result() {
			int extra = 0, st_max, dr_max;
			sort(v.begin(), v.end(), comp);
			st_max = v[0].st;
			dr_max = v[0].dr;
	        for (unsigned int i = 1; i < v.size(); i++) {
				if (v[i].st == st_max) {
					if (v[i].dr <= dr_max) {
						extra++;
					} else {
						extra++;
						dr_max = v[i].dr;
					}
				} else if (v[i].dr <= dr_max) {
					extra++;
				} else if (v[i].st > dr_max) {
					dr_max = v[i].dr;
					st_max = v[i].st;
				} else {
					dr_max = v[i].dr;
					st_max = v[i].st;
				}
			}
			return extra;
		}

		void print_output(int extra) {
			ofstream fout("gard.out");
			fout << extra;
			fout.close();
		}
};

int main() {
	Gard *task = new Gard();
	task->solve();
	delete task;
	return 0;
}
