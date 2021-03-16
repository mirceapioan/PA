#include <bits/stdc++.h>
using namespace std;
struct pereche{
        int greutate, repetari;
};
vector<pereche> v;

class Sala{
	public:
	void solve() {
		read_input();

		print_output(get_result());
	}

	private:
        int nr_gantere, max_gantere;


        void read_input() {
            int x, y;
            ifstream fin("sala.in");
            fin >> nr_gantere >> max_gantere;
            for (int i = 0; i <= nr_gantere; i++) {
                fin >> x >> y;
                v.push_back({x, y});
            }
            fin.close();
        }

        static bool comp(pereche a, pereche b ) {
            return (a.greutate > b.greutate);
        }
        int get_result() {
            int rep = 0, maxim = 0;
            sort(v.begin(), v.end(), comp);
            multiset<int> myset;
            multiset<int>::iterator it;
            for (int i=0; i < nr_gantere; i++) {
                rep = v[i].repetari;
                myset.clear();
                for (int j=i-1; j >= 0; j--) {
                    if (myset.size() < max_gantere -1) {
                        rep += v[j].repetari;
                        myset.insert(v[j].repetari);
                    } else {
                        it = myset.begin();
                        if (v[j].repetari > *it) {
                        rep -= *it;
                        myset.erase(myset.begin());
                        myset.insert(v[j].repetari);
                        rep += v[j].repetari;
                        }
                    }
                }
                rep = rep * v[i].greutate;
                if (rep > maxim) {
                    maxim = rep;
                }
            }
            return maxim;
        }



        void print_output(int result) {
            ofstream fout("sala.out");
            fout << result << "\n";
            fout.close();
        }
};

int main() {
    Sala *task = new Sala();
    task->solve();
    delete task;
    return 0;
}
