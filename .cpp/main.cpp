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
#include <chrono>
#include "../.h/Database.h"

using namespace std;

bool donate(Database& d);
bool receive(Database& d);
void showData(Database& d);
void loadDemoData(Database& d);
bool validateName(string name);
bool validateAge(string age);
void debug(Database& d);

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
		cout << "4) Load demo data" << endl;
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
			loadDemoData(*d);
			continue;
		}

		else if (input == 6)
		{
			debug(*d);
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

	Recipient r;
	Recipient s;
	Donor donor;

	int pos;
	for (pos = 0; pos < d.donors.size(); pos++)
	{
		donor = d.donors[pos];
		auto start = chrono::steady_clock::now();
		r = d.recipientsArr.extractValid(d.donors[pos]);
		auto end = chrono::steady_clock::now();
		double elapsed_time = double (std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
		cout << "PQArray took: " << elapsed_time << " nanoseconds" << endl;


		auto start2 = chrono::steady_clock::now();
		// r = d.recipientsTree.extractValid(d.donors.at(pos));
		auto end2 = chrono::steady_clock::now();
		double elapsed_time2 = double (std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2).count());
		cout << "PQTree took: " << elapsed_time2 << endl;

		if (r.getAge() != -1)
			break;
	}

	if (r.getAge() != -1)
	{
		cout << donor.getName() << "'s " << donor.getOrgan() << " has been matched to " << r.getName() << "!" << endl;
		cout << "Organ Recipient:" << endl;
		cout << "Name: " << r.getName() << endl;
		cout << "Age: " << r.getAge() << endl;
		cout << "Needed organ: " << r.getOrgan() << endl;
		cout << "Transplant surgery will now commence. " << donor.getName() << " and " << r.getName() << " have been removed from the registry." << endl;
		return true;
	}
	else
	{
		cout << "There is no available recipient for " << donor.getName() << "'s " << donor.getOrgan() << ". Transplant surgery will wait until one is found." << endl;
		return false;
	}

	cout << endl;

	return true;
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

	Recipient r(name, stoi(age), organsMap[organ], regionsMap[region], urgency, 101 - stoi(age) + urgency);

	d.recipientsArr.insert(Recipient(name, stoi(age), organsMap[organ], regionsMap[region], urgency, 101 - stoi(age) + urgency));
	d.recipientsTree.insert(Recipient(name, stoi(age), organsMap[organ], regionsMap[region], urgency, 101 - stoi(age) + urgency));

	Recipient rec;
	Recipient s;
	Donor donor;

	int pos;
	for (pos = 0; pos < d.donors.size(); pos++)
	{
		donor = d.donors[pos];

		auto start = chrono::steady_clock::now();
		rec = d.recipientsArr.extractValid(d.donors[pos]);
		auto end = chrono::steady_clock::now();
		double elapsed_time = double (std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
		cout << "PQArray took: " << elapsed_time << "nanoseconds" << endl;

		auto start2 = chrono::steady_clock::now();
		// rec = d.recipientsTree.extractValid(d.donors.at(pos));
		auto end2 = chrono::steady_clock::now();
		double elapsed_time2 = double (std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2).count());
		cout << "PQTree took: " << elapsed_time2 << endl;

		if (rec.getAge() != -1)
			break;
	}

	if (rec.getAge() != -1)
	{
		cout << donor.getName() << "'s " << donor.getOrgan() << " has been matched to " << rec.getName() << "!" << endl;
		cout << "Organ Recipient:" << endl;
		cout << "Name: " << rec.getName() << endl;
		cout << "Age: " << rec.getAge() << endl;
		cout << "Needed organ: " << rec.getOrgan() << endl;
		cout << "Transplant surgery will now commence. " << donor.getName() << " and " << rec.getName() << " have been removed from the registry." << endl;
		return true;
	}
	else
	{
		cout << "There is no available recipient for " << donor.getName() << "'s " << donor.getOrgan() << ". Transplant surgery will wait until one is found." << endl;
		return false;
	}

	cout << endl;

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
				cout << d.recipientsArr.queue[i].getName() << endl;

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
			bool found = false;
		
			for (int i = 0; i < d.recipientsArr.queue.size(); i++)
			{
				if (d.recipientsArr.queue[i].getName() == name)
				{
					cout << d.recipientsArr.queue[i].getName() << " is at position " << i << " in the waitlist." << endl;
					found = true;
				}
			}
			
			if (found == false)
				cout << "Name not found." << endl;
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

void loadDemoData(Database& d)
{
	d.loadDonorData("../data/donors.csv", d.donors);
	d.loadRecipientData("../data/recipients.csv");
	cout << endl;
}

void debug(Database& d)
{
	d.recipientsTree.insert(Recipient("foo", 12, "lung", "Southeast", 5, 40));
	d.recipientsTree.insert(Recipient("foo", 12, "lung", "Southeast", 5, 9001));

	d.donors.push_back(Donor("bar", 12, "lung", "Southeast"));

	Recipient re = d.recipientsTree.extractValid(d.donors[0]);
	cout << re.getPriority() << endl;
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