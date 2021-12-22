#include <iostream>
#include <chrono>
#include <algorithm>
#include <fstream>
#include<math.h>

using namespace std::chrono;
using namespace std;


int Linear(int Arr[], int length, int key)
{
  int i;
  for (i = 0; i < length; i++)
    if (Arr[i] == key)
      return i;
  return -1;
}


int Bin_exam(int arr[], int size, int key)
{
	int lowest = 0;
	int highest = size;

	int middle;
	while (lowest < highest)
	{
		middle = (lowest + highest) / 2;

		if (key == arr[middle])
		{
			return middle;
		}
		else if (key > arr[middle])
		{
			lowest = middle + 1;
		}
		else
		{
			highest = middle - 1;
		}
	}
	return -1; //when it doesn't find it
}


int Jump(const int Arr[], int length, int key) {

  int left = 0;
  int right = sqrt(length);

  while (right < length && Arr[right] <= key) {

    left = right;
    right += sqrt(length);

    if (right > length - 1) {
      right = length;
    }

  }

  for (int i = left; i < right; i++) {

    if (Arr[i] == key) {

      return i;

    }

  }
  return -1;
}
int interPol_exam(int set[], int value, int keyy)
{
	int low = 0;
	int high = (value - 1);

	while (low <= high && keyy >= set[low] && keyy <= set[high])
	{
		if (low == high)
		{
			if (set[low] == keyy) return low;
			return -1;
		}

		int position = low + (((double)(high - low) / (set[high] - set[low])) * (keyy - set[low]));
	
		if (set[position] == keyy)
			return position;

		if (set[position] < keyy)
			low = position + 1;
		else
			high = position - 1;
	}
	return -1;
}

int main()
{
	int seaBA[1000000];
	cout << "\nARRAY WITH 1000000 RANDOM INTEGERS"<< endl;

	ofstream myfile;
	myfile.open("Search.csv");


	for (int i = 0; i < 1000000; i++)
	{
		seaBA[i] = rand();
	}

	int userInput;
	sort(seaBA, seaBA +1000000);


	cout<< "\nENTER AN INTEGER: ";
	cin >> userInput;
	duration<double> elapsed_seconds;
	int result = 0;
	int result2 = 0;
  int result3 = 0;
  int result4 = 0;



  cout << "\n\nLinear Search" << endl;
  myfile << "\nLinear Search" << endl;
  myfile <<"\nRange , Time Taken,\n";

  for (int i = 0; i < 1000001; i+=1000) {
    auto start = system_clock::now();


    result = Linear(seaBA, i, userInput);
    cout << "\nFor range 0 - "<<i<<" the Runtime is: " << elapsed_seconds.count() << endl;
    myfile << i <<","<< elapsed_seconds.count()<<",\n";
    


    auto end = system_clock::now();
    elapsed_seconds = end - start;
  }

	
	cout << "\n\nBinary Search" << endl;
	myfile << "\nBinary Search" << endl;
	myfile <<"Range , Time Taken,\n";

	for (int i = 0; i < 1000001; i+=1000) {
		auto start = system_clock::now();


		result = Bin_exam(seaBA, i, userInput);
		cout << "\nFor range 0 - "<<i<<" the Runtime is: " << elapsed_seconds.count() << endl;
		myfile << i <<","<< elapsed_seconds.count()<<",\n";
		


		auto end = system_clock::now();
		elapsed_seconds = end - start;
	}

	cout << endl;
	cout << endl;

  cout << "\n\nJump Search" << endl;
  myfile << "\nJump Search" << endl;
  myfile <<"Range , Time Taken,";

  for (int i = 0; i < 1000001; i+=1000) {
    auto start = system_clock::now();


    result = Jump(seaBA, i, userInput);
    cout << "\nFor range 0 - "<<i<<" the Runtime is: " << elapsed_seconds.count() << endl;
    myfile << i <<","<< elapsed_seconds.count()<<",\n";
    


    auto end = system_clock::now();
    elapsed_seconds = end - start;
  }

  cout << endl;
  cout << endl;

	
	cout << "\n\nInterpolation Search" << endl;
	
	myfile << "\nInterpolation Search" << endl;
	myfile << "Range , Time Taken,";
	for (int i = 0; i < 1000001; i += 1000) {
		auto start = system_clock::now();

		result2 = interPol_exam(seaBA, i, userInput);
		cout << "\nFor range 0 - " << i << " the Runtime is: " << elapsed_seconds.count() << endl;

		myfile << i << "," << elapsed_seconds.count() << ",\n";


		auto end = system_clock::now();
		elapsed_seconds = end - start;
	}

	if (result >= 0)
	{
		cout << seaBA[result] << "\n is at index " << result << endl;
	}
	else
	{
		cout << "\n\nThe element " << userInput << " was not part of the original list of elements. " << endl;
	}


	return 0;
}