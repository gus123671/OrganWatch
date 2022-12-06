//#include "Database.h"
//
//Database::Database() {}
//
//void Database::showData()
//{
//    // FIXME
//}
//
//void Database::loadData(std::string file, std::vector<Donor>& donors)
//{
//    ifstream inFile(file);
//
//    std::string lineFromFile;
//    getline(inFile, lineFromFile); // skip header
//
//    while (getline(inFile, lineFromFile)) {
//        istringstream stream(lineFromFile);
//
//        string name;
//        string ageStr;
//        string organToDonate;
//        string location;
//
//        getline(stream, name, ',');
//        getline(stream, ageStr, ',');
//        getline(stream, organToDonate, ',');
//        getline(stream, location, '\n');
//
//        Donor d = new Donor(name, stoi(ageStr), organToDonate, location);
//        donors.push_back(d);
//    }
//}
//
//void DataBas::loadRecipientData(std::string file, vector<Recipient>& recipients)
//{
//    {
//        ifstream inFile(file);
//
//        std::string lineFromFile;
//        getline(inFile, lineFromFile); // skip header
//
//        while (getline(inFile, lineFromFile)) {
//            istringstream stream(lineFromFile);
//
//            string name;
//            string ageStr;
//            string organToRecieve;
//            string location;
//
//            getline(stream, name, ',');
//            getline(stream, ageStr, ',');
//            getline(stream, organToDonate, ',');
//            getline(stream, location, ',');
//
//            Recipient r = new Recipient(name, stoi(ageStr), organToRecieve, location, 0);
//            recipients.push_back(r);
//        }
//    }
//}
