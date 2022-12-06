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
#include <cmath>
#include "../.h/Database.h"

using namespace std;

bool donate(Database& d);
bool receive(Database& d);
void showData(Database& d);
void loadData(Database& d);
bool validateName(string name);
bool validateAge(string age);

int main()
{	
	Database* d = new Database();

	int input;

	do 
	{
		cout << "Welcome to OrganWatch: the Organ Donation Registry!" << endl;
		cout << "1) Donate an organ" << endl;
		cout << "2) Receive an organ" << endl;
		cout << "3) Show data" << endl;
		cout << "4) Load data" << endl;
		cout << "0) Exit" << endl;

		cin >> input;

		if (input == 0)
		{
			cout << "Thank you for using OrganWatch. Goodbye." << endl;
			delete d;
			return 0;
		}

		else if (input == 1)
		{
			donate(*d);
			continue;
		}

		else if (input == 2)
		{
			receive(*d);
			continue;
		}

		else if (input == 3)
		{
			showData(*d);
			continue;
		}

		else if (input == 4)
		{
			loadData(*d);
			continue;
		}

		else
		{
			cout << "Invalid input. Please enter an integer between 0 and 3." << endl;
			continue;
		}
	} 
	while (input != 0);

	return 0;
}


bool donate(Database& d)
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

	map<int, string> regionsMap;
	regionsMap[1] = "Southeast";
	regionsMap[2] = "Northeast";
	regionsMap[3] = "Southwest";
	regionsMap[4] = "Northwest";
	regionsMap[5] = "Midwest";


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

	int region;

	do
	{
		cout << "Please select your region:" << endl;
		cout << "1) Southeast" << endl;
		cout << "2) Northeast" << endl;
		cout << "3) Southwest" << endl;
		cout << "4) Northwest" << endl;
		cout << "5) Midwest" << endl;
		cout << "0) Cancel and return to the main menu" << endl;

		cin.ignore();
		cin >> region;

		if (region == 0)
			return false;
		else if (region != 1 && region != 2 && region != 3 && region != 4 && region != 5)
		{
			cout << "Invalid input. Enter an integer between 0 and 5." << endl;
			continue;
		}
		else
			break;

	} while (true);
	

	d.donors.push_back(Donor(name, stoi(age), organsMap[organ], regionsMap[region]));

	cout << "Sucessfully entered " << name << " into The Organ Donation Registry to donate their " << organsMap[organ] << "!" << endl;
	cout << endl;
	return true;

	// FIXME: implement matching algorithm here

}

bool receive(Database& d)
{
	map<int, string> organsMap;
	organsMap[1] = "Kidney";
	organsMap[2] = "Liver";
	organsMap[3] = "Lung";
	organsMap[4] = "Heart";

	map<int, string> regionsMap;
	regionsMap[1] = "Southeast";
	regionsMap[2] = "Northeast";
	regionsMap[3] = "Southwest";
	regionsMap[4] = "Northwest";
	regionsMap[5] = "Midwest";

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

	int region;

	do
	{
		cout << "Please select your region:" << endl;
		cout << "1) Southeast" << endl;
		cout << "2) Northeast" << endl;
		cout << "3) Southwest" << endl;
		cout << "4) Northwest" << endl;
		cout << "5) Midwest" << endl;
		cout << "0) Cancel and return to the main menu" << endl;

		cin.ignore();
		cin >> region;

		if (region == 0)
			return false;
		else if (region != 1 && region != 2 && region != 3 && region != 4 && region != 5)
		{
			cout << "Invalid input. Enter an integer between 0 and 5." << endl;
			continue;
		}
		else
			break;

	} while (true);

	/*
		Here, we'd instantiate a Recipient object and place it into our priority queues. 

		Waiting on matching algo before proceeding
	*/

	d.recipientsArr.insert(Recipient(name, stoi(age), organsMap[organ], regionsMap[region], 0));
	// d.recipientsTree.insertRecipient(Recipient(name, stoi(age), organsMap[organ], regionsMap[region], 0));

	// FIXME: implement matching algorithm here
	
	return true;
}

void showData(Database& d)
{
	int choice;

	do
	{	
		cout << "1) List of the top ten people on the waitlist for an organ" << endl;
		cout << "2) List of ten donor patients available for an organ" << endl;
		cout << "3) Print an organ recipient's position on the waitlist" << endl;
		cout << "4) Exit and return to the main menu" << endl;

		cin.ignore();
		cin >> choice;

		if (choice == 1)
		{
			for (int i = 0; i < 10; i++)
				cout << d.recipientsArr.extract().getName() << endl;

			break;
		}
		else if (choice == 2)
		{
			for (int i = 0; i < 10; i++)
				cout << d.donors[i].getName() << endl;

			break;
		}
		else if (choice == 3)
		{
			cout << "Enter the name of the organ recipient: " << endl;
			string name;
			cin.ignore();
			getline(cin, name);
		
			for (int i = 0; i < d.recipientsArr.size; i++)
			{
				if (d.recipientsArr.extract().getName() == name)
					cout << i << endl;
			}

			break;
		}
		else if (choice == 4)
			break;
		else
		{
			cout << "Enter an integer between 1 and 4" << endl;
			continue;
		}
	} while (true);
	
	return;
}

void loadData(Database& d)
{
	d.loadDonorData("../data/donors.csv", d.donors);
	d.loadRecipientData("../data/recipients.csv", d.recipientsArr, d.recipientsTree);
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
	if (stoi(age) < 1 || stoi(age) > 118)
		{
			cout << "Invalid age. Enter an integer between 1 and 118." << endl;
			return false;
		}

	if (std::floor(stoi(age)) != stoi(age))
	{
		cout << "Invalid age. Enter an integer." << endl;
		return false;
	}

	for (char c : age) 
	{
		if (!isdigit(c) && c != ' ') 
			return false;
	}

	return true;
}