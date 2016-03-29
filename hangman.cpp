#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<char, bool> initAlphabet()
{
	map<char, bool> m;

	for (int i = 'a'; i <= 'z'; i++) {
		m[(char)i] = false;
	}

	return m;
}

string fml(string s)
{
	string dummy;

	for (string::iterator i = s.begin(); i != s.end(); i++) {
		if (*i == ' ') {
			dummy += " ";
		} else {
			dummy += "_";
		}
	}

	return dummy;
}

string gpl(string s, char l, string dummy)
{
	string::iterator it = dummy.begin();
	bool flag = false;

	
	for (string::iterator i = s.begin(); i != s.end(); i++, it++) {
		if (*i == l) {
			replace(it, it + 1, '_', l);
			flag = true;
		} 
	}

	if (flag == false) {
		dummy = "";
	}

	return dummy;
}

int main()
{
	string user;
	string movies[] = {"jurassic park", "saving private ryan", "the lord of the rings", "star wars", 
					   "harry potter", "mad max", "minority report", "the godfather", "fight club", "the shawshank redemption"};
	map<char, bool> m;
	int ctr = 0;

	m = initAlphabet();

	cout << "Enter username : ";
	getline(cin, user);

	cout << "READY PLAYER ONE!!!" << endl;

	srand(time(NULL));
	string curr = movies[rand() % 10];
	string dummy = fml(curr);

	for (int i = 0; i < 26; i++) {
		cout << dummy << endl;
		
		if (dummy.find('_') == string::npos) {
			cout << "YOU WIN!!!" << endl;
			break;
		}

		if (ctr >= 7) {
			cout << "YOU SUCK!!!" << endl;
			break;
		}

		char l;

		for (;;) {
			cout << "Enter a letter : ";
			cin >> l;

			if (l >= 'a' && l <= 'z') {
				if (m[l] == true) {
					cout << "LETTER ALREADY USED!!!" << endl;
					continue;
				} else {
					m[l] = true;
					string tmp = gpl(curr, l, dummy); 
					
					if (tmp == "") {
						ctr++;
						cout << "WRONG LETTER!!!" << endl;
					} else {
						dummy = tmp;
					}
					
					break;
				}
			} else {
				cout << "SPECIAL CHARACTERS NOT ALLOWED!!!" << endl;
				continue;
			}
		}
	}

	cout << endl << "GGWP" << endl;

	return 0;
}
