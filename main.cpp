/*
	Author: Augustus Rodriguez
	Email: augustusrodriguez007@gmail.com
	Github: gus123671
	Created: 11/20/22
*/

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <regex>

using namespace std;

bool donate();
bool receive();
// bool showData();
// bool loadData();
bool validateName(string name);
bool validateAge(string age);


int main()
{
	cout << "Welcome to the Organ Donation Registry!" << endl;

	int input;

	do 
	{
		cout << "1) Donate an organ" << endl;
		cout << "2) Receive an organ" << endl;
		cout << "3) Show Data" << endl;
		cout << "0) Exit" << endl;

		cin >> input;

		if (input == 0)
		{
			cout << "Thank you for using OrganWatch. Goodbye." << endl;
			return 0;
		}

		else if (input == 1)
		{
			donate();
			continue;
		}

		else if (input == 2)
		{
			cout << "FIXME" << endl;
			continue;
		}

		else if (input == 3)
		{
			cout << "FIXME" << endl;
			continue;
		}

		else
		{
			cout << "Invalid input. Please enter an integer between 0 - 3." << endl;
			continue;
		}
	} 
	while (input != 0);

	return 0;
}


bool donate()
{
	/*
		We can easily modify this section to accept input from a csv file. For development purposes, I have
		it accepting input manually. 
	*/

	map<int, string> organsMap;
	organsMap[1] = "Kidney";
	organsMap[2] = "Liver";
	organsMap[3] = "Lung";
	organsMap[4] = "Heart";

	string name = "";

	do 
	{
		cout << "Enter the patient's NAME: ";
		cin.ignore();

		getline(cin, name);
		if (validateName(name) == false)
			cout << "Name invalid. Enter alphabetical characters only." << endl;
	} while (validateName(name) == false);

	cout << endl;

	string age;

	do
	{
		cout << "Enter the patient's AGE: ";		
		cin.ignore();
		cin >> age;
		
		if (validateAge(age) == false)
			cout << "Age invalid. Enter an integer." << endl;
	}
	while (validateAge(age) == false);

	cout << endl;

	int organ;

	do
	{
		cout << "What organ does the patient wish to donate? " << endl;
		cout << "1) Kidney" << endl;
		cout << "2) Liver" << endl;
		cout << "3) Lung" << endl;
		cout << "4) Heart" << endl;
		cout << "0) Cancel and return to the main menu" << endl;
		
		cin.ignore();
		cin >> organ;

		if (organ == 0)
			return false;
		else if (organ != 1 && organ != 2 && organ != 3 && organ != 4)
		{
			cout << "Invalid input. Enter an integer between 0 and 4." << endl;
			continue;
		}
		else
			break;

	} while (true);

	cout << "Sucessfully entered " << name << " into The Organ Donation Registry to donate their " << organsMap[organ] << "!" << endl;
	cout << endl;
	return true;

	// FIXME: implement matching algorithm here

}

bool receive()
{
	map<int, string> organsMap;
	organsMap[1] = "Kidney";
	organsMap[2] = "Liver";
	organsMap[3] = "Lung";
	organsMap[4] = "Heart";

	string name = "";

	do 
	{
		cout << "Enter the patient's NAME: ";
		cin.ignore();

		getline(cin, name);
		if (validateName(name) == false)
			cout << "Name invalid. Enter alphabetical characters only." << endl;
	} while (validateName(name) == false);

	cout << endl;

	string age;

	do
	{
		cout << "Enter the patient's AGE: ";		
		cin.ignore();
		cin >> age;
		
		if (validateAge(age) == false)
			cout << "Age invalid. Enter an integer." << endl;
	}
	while (validateAge(age) == false);

	cout << endl;

	int organ;

	do
	{
		cout << "What organ does the patient wish to receive? " << endl;
		cout << "1) Kidney" << endl;
		cout << "2) Liver" << endl;
		cout << "3) Lung" << endl;
		cout << "4) Heart" << endl;
		cout << "0) Cancel and return to the main menu" << endl;
		
		cin.ignore();
		cin >> organ;

		if (organ == 0)
			return false;
		else if (organ != 1 && organ != 2 && organ != 3 && organ != 4)
		{
			cout << "Invalid input. Enter an integer between 0 and 4." << endl;
			continue;
		}
		else
			break;

	} while (true);

	int urgency;

	do
	{
		cout << "On a scale from 1 to 5 (with 1 being least urgent and 5 being most urgent), please enter the medical urgency for the transplant surgery." << endl;
		cout << "Enter 0 to cancel." << endl;
		cin.ignore();
		cin >> urgency;

		if (urgency == 0)
			return false;
		else if (urgency != 1 && urgency != 2 && urgency != 3 && urgency != 4 && urgency != 5)
		{
			cout << "Invalid input. Enter an integer between 1 and 5." << endl;
			continue;
		}
		else
			break;
	}
	while(true);

	/*
		Here, we'd instantiate a Recipient object and place it into our priority queues. 

		Waiting on matching algo before proceeding
	*/

	// FIXME: implement matching algorithm here
	

}

bool validateName(string name)
{
	for (char c : name)
	{
		if (!isalpha(c) && c != 32) 
			return false;
	}

	return true;
}

bool validateAge(string age)
{

	for (char c : age) 
	{
		if (!isdigit(c) && c != ' ') 
			return false;
	}

	return true;
}