#include<bits/stdc++.h>
std::ifstream fin, fout, fans;

namespace judge{
	int scr = 0;
	
	const int N = 500000;
	
	std::vector<std::pair<int, int> >v[N + 5];
	std::set<std::pair<int, int> >st1, st2;
	int main() {
		int ans, res; fans >> ans, fout >> res;
		if( ans != res ) {
			std::cerr << "A wrong number of robots.";
			return scr;
		}
		scr += 5;
		
		int n; fin >> n;
		for(int i=1,s,t;i<=n;i++)
			fin >> s >> t, st1.insert(std::make_pair(s, t));
		
		for(int i=1,s,t,w;i<=n;i++) {
			fout >> s >> t >> w;
			if( w < 1 || w > ans ) {
				std::cerr << "Invalid robot's number. It should be between 1 and " << ans << ".";
				return scr;
			}
			if( !st1.count(std::make_pair(s, t)) ) {
				if( !st2.count(std::make_pair(s, t)) ) {
					std::cerr << "Invalid candy. Such a candy doesn't exist.";
					return scr;
				} else {
					std::cerr << "Invalid candy. Such a candy is used again.";
					return scr;
				}
			}
			st1.erase(std::make_pair(s, t)), st2.insert(std::make_pair(s, t));
			v[w].push_back(std::make_pair(t, s));
		}
		
		for(int i=1;i<=ans;i++) {
			std::sort(v[i].begin(), v[i].end());
			if( !v[i].empty() ) {
				for(int j=1;j<(int)v[i].size();j++) {
					if( !(v[i][j].first - v[i][j - 1].first >= std::abs(v[i][j].second - v[i][j - 1].second)) ) {
						std::cerr << "The robot " << i << " can't catch all candies.";
						return scr;
					}
				}
			}
		}
		return scr += 5;
	}
}

int main ( int argc, char* argv[] ) {
	fin.open("input"), fans.open("answer"), fout.open("user_out");
	std::cout<<judge::main()*10;
    fin.close(), fout.close(), fans.close();
	return 0;
}
