#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct document{
    std::string firstName;
    std::string secondName;
    std::string data;
    int salary;
};
bool okDate(const std::string& date){
    if(date.length()!=10)return false;
    int year = std::stoi(date.substr(6, 4));
    int month = std::stoi(date.substr(3, 2));
    int day = std::stoi(date.substr(0, 2));
    if (year < 2000 || year > 2022)return false;
    if (month < 1 || month > 12)return false;
    if (day < 0 || day > 31)return false;
    if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))return false;
    if (day > 28 && month == 2 && year % 4 != 0)return false;
    if (day > 29 && month == 2 && year % 4 == 0)return false;
    return true;
}

void add_new(){
    int salary;
    std::string date;
    std::string firstName;
    std::string secondName;
    std::string address;
    std::ofstream list;
    list.open("doc.txt",std::ios::app);
    while(firstName!="stop"){
        std::cout << "Input first name :" << std::endl;
        std::cin>>firstName;
        if(firstName=="stop")break;
        list<<firstName<<" ";
        std::cout << "Input second name :" << std::endl;
        std::cin>>secondName;
        list<<secondName<<" ";
        do {
            std::cout << "Input data :";
            std::cin >> date;
            if (!okDate(date)) {
                std::cout << "Wrong date!" << std::endl;
            }

        }while(!okDate(date));
        list<<date<<" ";
        std::cout<<"Input sum :";
        std::cin>>salary;
        list<<salary<<std::endl;
    }
    list.close();
}
void list(document &person,std::vector<document>& people){
    std::ifstream doc;
    doc.open("doc.txt");
    doc.seekg(0);
    while(!doc.eof()){
        doc>>person.firstName;
        doc>>person.secondName;
        doc>>person.data;
        doc>>person.salary;
        people.push_back(person);
    }
    people.pop_back();
    doc.close();
}
void read_list(std::vector<document> &people){
    for(int i=0;i<people.size();i++) {
        std::cout << people[i].firstName << " " << people[i].secondName << " ";
        std::cout << people[i].data << " " << people[i].salary <<" rub."<< std::endl;
    }
}

int main() {
    document person;
    std::vector<document> people;
    std::string operation;
    std::cout << "Enter operation :";
    std::cin>>operation;
    if(operation=="list"){
         list(person,people);
         read_list(people);
    }
    else if(operation=="add"){
        add_new();
    }
    else {
        return 0;
    }
    return 0;
}
