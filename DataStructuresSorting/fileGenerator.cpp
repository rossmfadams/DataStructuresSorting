/*--fileGenerator.cpp----------------------------------------------------------
	This program creates a text file of 5000 non-repeating integers separated
	by spaces
-------------------------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int main() {
	int i = 0;
	int j = 0;
	const int CAPACITY = 5000;
	int rand_word = 0;
	int* data = new int[CAPACITY];
	bool duplicate;

	fstream out_file("dataSet.txt", ios::out);

	if (!out_file)
	{
		cout << "Cannot open out.txt for writing" << endl;
		return 0;
	}

	srand(time(0));

	for (i = 0; i < CAPACITY; i++) {
		data[i] = rand() % CAPACITY + 1;
		do {
			duplicate = false;
			for (j = 0; j < i; j++) {
				if (data[i] == data[j]) {
					data[i] = (rand() % CAPACITY) + 1;
					duplicate = true;
				}
			}
		} while (duplicate);
	}

	for (i = 0; i < 5000; i++) {
		out_file << data[i] << " ";
	}
	out_file.close();

	return 0;
}