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

int main()
{
	string user;
	string movies[] = {"jurassic park", "saving private ryan", "the lord of the rings", "star wars", 
					   "harry potter", "mad max", "minority report", "the godfather", "fight club", "the shawshank redemption"};
	map<char, bool> m;

	m = initAlphabet();

	cout << "Enter username : ";
	getline(cin, user);

	cout << "READY PLAYER ZERO!!!" << endl;

	srand(time(NULL));
	string curr = movies[rand() % 10];

	//for (vector<pair<char, bool> >::iterator i = v.begin(); i != v.end(); i++) {
	//	cout << (*i).first << " " << (*i).second << endl;
	//}

	for (int i = 1; i <= 7; i++) {
		cout << m['a'];
	}

	return 0;
}