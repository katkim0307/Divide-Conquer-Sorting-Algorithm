
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// User defined vector
vector<int> readVec();
// Using an input vector, returning a vector of max and min values
vector<int> divAndConqMinMax(vector<int> numVec, int low, int high);

// Better written function
vector<int> betterDivAndConq(vector<int> numVec, int low, int high);

// using an input array, output the reference of max and min
void divAndConqMaxMin(int arr[], int low, int high, int& max, int& min);

int main()
{
	vector<int> v = {37, -12, 99, 152, -46, -82};
	//v = readVec();

	vector<int> minAndMax = divAndConqMinMax(v, 0, v.size() - 1);

	cout << "Initial vector is { ";
	for (unsigned int i = 0; i < v.size(); i++) {
		if (i == v.size() - 1)
			cout << v[i] << " }" << endl;
		else
			cout << v[i] << ", ";
	}
	cout << "Min and Max Vector = { " 
		<< minAndMax[0] << ", " << minAndMax[1] << " }" << endl << endl;


	///////////////////////////////////////////////////////////////
	////////////////////// using an array /////////////////////////
																///
	int arr[] = { 54, 21, 78, -14, -43, 68 };					///
	int arrSize = 6;											///
																///
	cout << "Initial Array = { ";								///
	for (int i = 0; i < arrSize; i++) {							///
		if (i == arrSize - 1)									///
			cout << arr[i] << " }" << endl;						///
		else													///
			cout << arr[i] << ", ";								///
	}															///
																///
	int max, min;												///
																///
	divAndConqMaxMin(arr, 0, arrSize - 1, max, min);			///
	cout << "Max: " << max << endl;								///
	cout << "Min: " << min << endl;								///
																///
	///////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////

	return 0;
}

vector<int> readVec()
{
	vector<int> numVec;
	int currNum;

	cout << "Please enter a sequence of integers separated by a space. \n";
	cout << "End the list by entering 'X': \n";

	while (cin >> currNum) {
		numVec.push_back(currNum);
	}
	return numVec;
}

vector<int> divAndConqMinMax(vector<int> numVec, int low, int high)
{
	int min, max;
	vector<int> minmaxRes;
	vector<int> minmaxLower, minmaxUpper;

	// Base Case 1 - when there is only 1 # in the vector
	if (low == high) {		// if (numVec.size() == 1)
		min = max = numVec[low];
		minmaxRes.push_back(min);
		minmaxRes.push_back(max);
		return minmaxRes;
	}

	// Base Case 2 - when there are 2 #/s in the vector
	// if use #include <algorithm>, you can do
	// minmaxRes.push_back(min(numVec[low], numVec[high]));
	// minmaxRes.push_back(max(numVec[low], numVec[high]));
	else if (low == high - 1) {	// else if(numVec.size() == 2)
		if (numVec[low] < numVec[high]) {
			min = numVec[low];
			max = numVec[high];
			minmaxRes.push_back(min);
			minmaxRes.push_back(max);
		}
		else {
			min = numVec[high];
			max = numVec[low];
			minmaxRes.push_back(min);
			minmaxRes.push_back(max);
		}
		return minmaxRes;
	}

	// Recursive Steps for more than 2 #s
	else {
		int mid = (low + high) / 2;
		minmaxLower = divAndConqMinMax(numVec, low, mid);
		minmaxUpper = divAndConqMinMax(numVec, mid + 1, high);

		if (minmaxLower[0] < minmaxUpper[0]) { min = minmaxLower[0]; }
		else { min = minmaxUpper[0]; }

		if (minmaxLower[1] > minmaxUpper[1]) { max = minmaxLower[1]; }
		else { max = minmaxUpper[1]; }

		minmaxRes.push_back(min);
		minmaxRes.push_back(max);
		return minmaxRes;
	}
}

vector<int> betterDivAndConq(vector<int> numVec, int low, int high)
{
	// Base Case - when there is upto 1 # in the vector
	if (low - high <= 1) {		// if (numVec.size() <= 1)
		return { min(numVec[low], numVec[high]), max(numVec[low], numVec[high]) };
	}

	// Recursive Steps for more than 2 #s
	else {
		int mid = (low + high) / 2;
		vector<int>minmaxLower = betterDivAndConq(numVec, low, mid);
		vector<int>minmaxUpper = betterDivAndConq(numVec, mid + 1, high);
		return { min(minmaxLower[0], minmaxUpper[0]), max(minmaxLower[1], minmaxUpper[1]) };
	}
}

void divAndConqMaxMin(int arr[], int low, int high, int& max, int& min) 
{
	// Base Case 1 - when there is only 1 element in the array
	if (low == high) {
		max = min = arr[low];
	}
		
	// Base Case 2 - when there are 2 elements in the array
	else if (low == high - 1) {
		if (arr[low] < arr[high]) {
			max = arr[high];
			min = arr[low];
		}
		else {
			max = arr[low];
			min = arr[high];
		}
	}

	// Recursive Steps for more than 2 #s
	else {
		int mid = (low + high) / 2;
		int lowMax, lowMin, upMax, upMin;

		divAndConqMaxMin(arr, low, mid, lowMax, lowMin);
		divAndConqMaxMin(arr, mid+1, high, upMax, upMin);

		if (lowMax > upMax) { max = lowMax; }
		else { max = upMax; }

		if (lowMin < upMin) { min = lowMin; }
		else { min = upMin; }
	}
}
