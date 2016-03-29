#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>

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
}

int main()
{
	string user;
	string movies[] = {"jurassic park", "saving private ryan", "the lord of the rings", "star wars", 
					   "harry potter", "mad max", "minority report", "the godfather", "fight club", "the shawshank redemption"};
	map<char, bool> m;

	m = initAlphabet();

	cout << "Enter username : ";
	getline(cin, user);

	cout << "READY PLAYER ONE!!!" << endl;

	srand(time(NULL));
	string curr = movies[rand() % 10];
	string dummy = fml(curr);

	for (int i = 0; i < 26; i++) {
		cout << dummy << endl;
		
		char l;

		for (;;) {
			cout << "Enter a letter : ";
			cin >> l;

			if (l >= 'a' && l <= 'z') {
				if (m[l] == true) {
					continue;
				} else {
					m[l] = true;

				}
			} else {
				continue;
			}
		}
	}

	return 0;
}
