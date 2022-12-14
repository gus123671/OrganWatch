/*
	Author: Augustus Rodriguez
	Email: augustusrodriguez007@gmail.com
	Github: gus123671
	Created: 11/24/22
*/

#include "../.h/Database.h"
#include <fstream>
#include <sstream>

Database::Database() 
{
    this->donors = vector<Donor>();
}

void Database::loadDonorData(std::string file, std::vector<Donor>& donors)
{
   ifstream inFile(file);

   std::string lineFromFile;
   getline(inFile, lineFromFile); // skip header

   while (getline(inFile, lineFromFile)) 
   {
       istringstream stream(lineFromFile);

       string name;
       string ageStr;
       string organToDonate;
       string location;

       getline(stream, name, ',');
       getline(stream, ageStr, ',');
       getline(stream, organToDonate, ',');
       getline(stream, location, '\n');

       donors.push_back(Donor(name, stoi(ageStr), organToDonate, location));
   }
}

void Database::loadRecipientData(std::string file)
{
    ifstream inFile(file);

    std::string lineFromFile;
    getline(inFile, lineFromFile); // skip header

    while (getline(inFile, lineFromFile)) 
    {
        istringstream stream(lineFromFile);

        string name;
        string ageStr;
        string organToReceive;
        string location;
        string urgency;

        getline(stream, name, ',');
        getline(stream, ageStr, ',');
        getline(stream, organToReceive, ',');
        getline(stream, location, ',');
        getline(stream, urgency, ',');

        this->recipientsArr.insert(Recipient(name, stoi(ageStr), organToReceive, location, stoi(urgency), 101 - stoi(ageStr) + stoi(urgency)));
        this->recipientsTree.insert(Recipient(name, stoi(ageStr), organToReceive, location, stoi(urgency), 101 - stoi(ageStr) + stoi(urgency)));
    }
}