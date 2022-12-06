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

void Database::loadRecipientData(std::string file, vector<Recipient>& recipients)
{
   {
       ifstream inFile(file);

       std::string lineFromFile;
       getline(inFile, lineFromFile); // skip header

       while (getline(inFile, lineFromFile)) {
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

           recipients.push_back(Recipient(name, stoi(ageStr), organToReceive, location, stoi(urgency), 101 - stoi(ageStr) + stoi(urgency))); // have to go over twice and assign prio
       }
   }
}

bool Database::isValid(Donor &donor, Recipient &recipient) {
    bool age = true;
    if ((donor.age >= 1 && donor.age <= 12) && (recipient.age >= 13 && recipient.age <= 100)) {
        age = false;
    } else if ((donor.age >= 13 && donor.age <= 100) && (recipient.age >= 1 && recipient.age <= 12)) {
        age = false;
    }

    bool region;
    if (donor.region == recipient.region) {
        region = true;
    } else {
        region = false;
    }

    if (age && region) {
        return true;
    } else {
        return false;
    }
}

//this is used for loading demo data, otherwise we calculate priorities manually

// void Database::calculatePriorities(vector<Recipient>& recipients) 
// {
//     // priority for recipients = 101 - age + urgency 
//     // prio for donors = 101 - age

//     for (auto i : recipients)
//         i.setPriority(101 - i.getAge() + i.getUrgency());
// }