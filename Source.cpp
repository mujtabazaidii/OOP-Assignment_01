#include<iostream>
#include<string>
#include<fstream>
using namespace std;
ifstream gh("finalfile.txt");
int main() {
	string s, line[30], xx;
	int h, k = 0, b = 0, z = 0, tt[20];
	cout << endl << "Enter Text: " << endl;
	getline(cin, s);
	cout << endl << "String after tokenization: " << endl;
	h = s.length();
	char** t = new char* [h];
	for (int i = 0; i < h; i++) {
		if (s[i] == 32)
			k = k + 1;
	}
	k = k + 1;
	for (int j = 0; j < k; j++) {
		t[j] = new char[20];
	}
	for (int i = 0; i < h; i++) {
		if (s[i] != 32) {
			t[z][b] = s[i];
			b = b + 1;
		}
		else {
			b = 0;
			z = z + 1;
		}
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < 10; j++) {
			if (t[i][j] == 46 || t[i][j] >= 65 && t[i][j] <= 90 || t[i][j] >= 97 && t[i][j] <= 122)
				cout << t[i][j];

		}
		cout << endl;
	}
	cout << endl << "Array of words: " << endl;
	int p = 0;
	while (getline(gh, line[p])) {
		p = p + 1;
	}
	int l = 0, mm[20], u = 0;
	bool q;
	for (int g = 0; g < p; g++) {
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < 10; j++) {
				if (t[i][j] == 46 || t[i][j] >= 65 && t[i][j] <= 90 || t[i][j] >= 97 && t[i][j] <= 122) {
					if (t[i][j] == line[g][l])
						q = true;
					else {
						q = false;
						break;
					}
					l = l + 1;
				}
			}
			l = 0;
			if (q == true) {
				for (int j = 0; j < 10; j++) {
					if (t[i][j] == 46 || t[i][j] >= 65 && t[i][j] <= 90 || t[i][j] >= 97 && t[i][j] <= 122)
						cout << t[i][j];

				}
				tt[u] = i;
				mm[u] = g;
				u = u + 1;
				cout << endl;
				break;
			}
		}
	}
	int y, n = 0;
	cout << endl << "Array of synonyms : " << endl;
	for (int i = 0; i < u; i++) {
		for (int j = 0; j < p; j++) {
			if (mm[i] == j) {
				y = line[j].length();
				for (int w = 0; w < y; w++) {
					if (n != 0)
						cout << line[j][w];
					if (line[j][w] == 32)
						n = n + 1;

				}
			}

		}
		cout << endl;
		n = 0;
	}
	cout << endl << "String After Parapharasing: " << endl;
	int c = 0;
	for (int i = 0; i < u; i++) {
		for (int j = 0; j < p; j++) {
			if (mm[i] == j) {
				y = line[j].length();
				for (int w = 0; w < y; w++) {
					if (n != 0 && n != 2 && n != 3) {
						t[tt[i]][c] = line[j][w];
						c = c + 1;
					}
					if (line[j][w] == 32)
						n = n + 1;

				}
			}

		}
		t[tt[i]][c + 1] = 0;
		t[tt[i]][c] = 0;
		c = 0;
		n = 0;
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < 10; j++) {
			if (t[i][j] == 46 || t[i][j] >= 65 && t[i][j] <= 90 || t[i][j] >= 97 && t[i][j] <= 122)
				cout << t[i][j];
		}
		cout << "  ";
	}
	cout << endl << endl << endl << endl;
	return 0;
}



