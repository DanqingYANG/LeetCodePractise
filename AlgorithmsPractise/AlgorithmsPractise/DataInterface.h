#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>

using namespace std;

//from https://www.hackerrank.com/challenges/frog-in-maze/problem
vector<string> split_string(string input_string) {

	//remove consecutive spaces
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
		return x == y and x == ' ';
	});

	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	vector<string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != string::npos) {
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}

	splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}



//read a txt file and return a vector<string>
vector <string> readFile(const string &path) {

	vector <string> input;
	ifstream inputfile;
	string line;

	inputfile.open(path);//open file

	if (inputfile.is_open())
	{
		while (getline(inputfile, line)) {
			input.push_back(line);
		}
		inputfile.close();//close file
	}
	return input;
}


void printToFile(vector<string> & sv, string filepath = "./result.txt", int n_setw = 0)
{
	ofstream outputStream;

	outputStream.open(filepath);
	if (n_setw = 0) {
		for (auto it : sv) {
			outputStream << it << endl;
		}
	}
	else {
		for (auto it : sv) {
			outputStream << setw(n_setw) << it << endl;
		}
	}

	return;
}



bool IsTheSame(const string &path, vector <string> result, int n_item = 10)
//compare the result with the ans.txt from webs, exp. "HackerRank.com"
{

	bool isSame = true;
	ifstream Ans{ path };
	string line;
	int i = 0;
	vector<string> ans;

	if (Ans.is_open())
	{
		while (getline(Ans, line)) {
			ans.push_back(line);
		}
	}
	if (ans.size() != result.size()) {
		isSame = false;
	}
	else {
		vector<string> falseElementCollector;
		for (int i = 0; i < ans.size(); i++) {
			if (ans[i] != result[i]) {
				isSame = false;

				falseElementCollector.push_back(result[i]);
				cout << "Line: " << i << " ";
			}
		}
		cout << endl;

		int n_output_item =
			(n_item < falseElementCollector.size() ? n_item : falseElementCollector.size());
		if (n_output_item > 0) {
			cout << n_output_item << " error examples: " << endl;
			for (int i = 0; i < n_output_item; i++) {
				cout << ans[i] << endl << falseElementCollector[i] << endl << endl;
			}
		}
		else {
			cout << "Congraduations" << endl;
		}
	}

	cout << endl;
	return isSame;
}



vector <pair <int, int> > stringToGraph_edge(string &input_st) //example: input_st = "[[0, 3], [12, 345]]", output = (0,3),(12,345)
{
	vector <pair <int, int> > result;

	string input_dlmt; // input string with delimiters

	for (int i = 0; i < input_st.size(); i++) {
		if (input_st[i] != '[' && input_st[i] != ']' && input_st[i] != ' ') {
			input_dlmt.append(1, input_st[i]);
		}
	}

	vector <string> input_nums;
	char delimiter = ',';

	//size_t is better than int, long, long long long ...for it can store the maximum size of a theoretically possible object of any type (including array), and moreover it is the default output type of string::find()
	size_t i = 0;
	size_t pos = input_dlmt.find(delimiter);

	while (pos != string::npos) {
		input_nums.push_back(input_dlmt.substr(i, pos - i));

		i = pos + 1;
		pos = input_dlmt.find(delimiter, i);
	}

	input_nums.push_back(input_dlmt.substr(i, min(pos, input_dlmt.length()) - i + 1)); // last one

	for (int i = 0; i < input_nums.size(); i = i + 2) {
		pair<int, int> p{ stoi(input_nums[i]), stoi(input_nums[i + 1]) };
		result.push_back(p);
	}

	return result;
}



void testDataInterface() {

	string path_input = "./dataInterface/input01.txt";
	string path_ans = "./dataInterface/output01.txt";

	vector<string> input = readFile(path_input);

	long n = 0;
	n = stol(input[0]);

	map<string, long> phoneBook;

	for (int i = 0; i<n; i++) {
		string name;
		long int phoneNumber;

		name = split_string(input[i + 1])[0];
		phoneNumber = stol(split_string(input[i + 1])[1]);

		phoneBook[name] = phoneNumber;
	}

	vector <string> result;
	string query = "";

	for (int i = n + 1; i < input.size(); i++)
	{
		query = input[i];

		if (phoneBook.find(query) != phoneBook.end()) {
			result.push_back(query.append("=").append(to_string(phoneBook[query])));
		}
		else {
			result.push_back("Not found");
		}
	}

	IsTheSame(path_ans, result);

	//test stringToGraph_edge()
	string input_string = "[[0, 3343], [1, 23], [2, 3], [4, 3], [5, 4]]";
	vector <pair <int, int> > output_v = stringToGraph_edge(input_string);
	cout << "\nResult: " << endl;
	for (auto it : output_v) {
		cout << it.first << " " << it.second << ",   ";
	}

	return;
}
