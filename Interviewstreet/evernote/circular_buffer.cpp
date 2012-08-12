#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
int L = 0, R = 0;


void insertBuffer(vector<string> &buffer, string &word)
{
	buffer[R % N] = word;
	R++;
	if (R - L > N) L++;
}

void deleteBuffer(vector<string> &buffer, int x)
{
	if (x >= R - L) R = L;
	else 
	{
		L += x;
	}
}

void listBuffer(vector<string> &buffer)
{
	for (int i = L; i < R; i++)
	{
		cout << buffer[i % N] << endl;
	}
}

int main()
{
	cin >> N;
	if (N == 0) return 0;
	vector<string> buffer(N);

	char cmd;
	int x;
	string word;
	bool quit = false;
	while (!quit)
	{
		cin >> cmd;
		switch (cmd)
		{
		case 'A' :
			cin >> x;
			while (x)
			{
				cin >> word;
				insertBuffer(buffer, word);
				x--;
			}
			break;
		case 'R' :
			cin >> x;
			deleteBuffer(buffer, x);
			break;
		case 'L' :
			listBuffer(buffer);
			break;
		case 'Q' :
			quit = true;
			break;
		}
	}
}
