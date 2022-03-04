#include <iostream>
#include <cmath>
struct Vec{
    float x;
    float y;
};
void add(Vec data[3]){
    std::cout<<"Coordinates sum of vectors : "<<data[0].x+data[1].x;
    std::cout<<" , "<<data[0].y+data[1].y;
}
void substract(Vec data[3]){
    std::cout<<"Coordinates sum of vectors : "<<data[0].x-data[1].x;
    std::cout<<" , "<<data[0].y-data[1].y;
}
void scale(Vec data[3]) {
    std::cout << "Coordinates  of result : " << data[0].x * data[2].x;
    std::cout << " , " << data[0].y * data[2].x;
}
void length(Vec data[3]){
    std::cout<<"Length of vector : "<<sqrt(pow(data[0].x,2) + pow(data[0].y,2));
}
void normalaize(Vec data[3]){
    std::cout<<"Coordinates of Normalized Vector: ";
    std::cout<<data[0].x/ sqrt(pow(data[0].x,2) + pow(data[0].y,2));
    std::cout<<" , "<<data[0].y/ sqrt(pow(data[0].x,2) + pow(data[0].y,2));
}
int main() {
    Vec data[3];
    std::string oper;
    std::cout << "Enter vector operation :";
    std::cin>>oper;
    if(oper=="add"||oper=="subtract") {
        std::cout << "Input  first vector coordinates :";
        std::cin >> data[0].x >> data[0].y;
        std::cout << "Input  second vector coordinates :";
        std::cin >> data[1].x >> data[1].y;
        if (oper == "add") {
            add(data);
        } else {
            substract(data);
        }
    }
    else if(oper=="scale"){
        std::cout<< "Input vector coordinates :";
        std::cin>>data[0].x>>data[0].y;
        std::cout<< "Input scalar :";
        std::cin>>data[2].x;
        scale(data);
    }
    else if(oper=="length"){
        std::cout<< "Input vector coordinates :";
        std::cin>>data[0].x>>data[0].y;
        length(data);
    }
    else if (oper=="normalize"){
        std::cout<< "Input vector coordinates :";
        std::cin>>data[0].x>>data[0].y;
        normalaize(data);
    }
    return 0;
}
