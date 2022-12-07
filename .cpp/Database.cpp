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

        recipientsArr.insert(Recipient(name, stoi(ageStr), organToReceive, location, stoi(urgency), 101 - stoi(ageStr) + stoi(urgency)));
        recipientsTree.insert(Recipient(name, stoi(ageStr), organToReceive, location, stoi(urgency), 101 - stoi(ageStr) + stoi(urgency)));
    }
}

 void Database::matchDonor(Donor& donor, PQTree& tree) {
    vector<Recipient> vector = tree.createVector();
    PQTree temp = tree;
    PQTree newTree;
    if (isValid(donor, tree.extract())) {
        tree.deleteTopPriority();
        return;
    }
    else {
        while (!isValid(donor, temp.extract())) {
            PQTree t = temp;
            t.extract();
            temp = t;
        }
        TreeNode* remove = temp.getRoot();
        Recipient r = remove->recipient;
        temp.deleteTopPriority();
        for (int i = 0; i < vector.size(); i++) {
            if (isSame(vector[i], r)) {
                vector.erase(vector.begin() + i);
            }
            for (int j = 0; j < vector.size(); j++) {
                newTree.insert(vector[i]);
                return;
            }
        }
    }
}

bool Database::isSame(Recipient a, Recipient b) {
    if (a.getAge() == b.getAge() && a.getName().compare(b.getName()) == 0 && a.getOrgan().compare(b.getOrgan()) == 0 && a.getRegion().compare(b.getRegion()) == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool Database::isValid(Donor a, Recipient b) {
    if ((a.getAge() >= 13 && b.getAge() >= 13)  && a.getOrgan() == b.getOrgan() && a.getRegion() == b.getRegion()) {
        return true;
    }
    else {
        return false;
    }
}