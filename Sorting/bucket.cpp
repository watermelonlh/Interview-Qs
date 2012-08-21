#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> num;


int main()
{
	cin >> N;
	vector<vector<int> > b1, b2;
	b1.resize(10, vector<int>(0));
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		b1[0].push_back(x);
	}


	
	b2.resize(10, vector<int>(0));
	for (int bucket = 1; bucket <= 1000000; bucket *= 10)
	{	
		for (int i = 9; i >= 0; i--) 
			b2[i].clear();
		for (int i = 0; i <= 9; i++)
		{
			for (int k = 0; k < b1[i].size(); k++)
			{
				b2[b1[i][k] / bucket % 10].push_back(b1[i][k]);
			}
		}
		b1 = b2;
	}


	for (int i = 0; i <= 9; i++)
		for (int j = 0; j < b1[i].size(); j++)
			cout << b1[i][j] << endl;
	

}






