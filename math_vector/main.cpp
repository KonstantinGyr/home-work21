#include <iostream>
#include <cmath>

int main() {
    std::string oper;
    float x1,x2,y1,y2,scale;
    std::cout << "Enter vector operation :";
    std::cin>>oper;
    if(oper=="add"||oper=="subtract"){
        std::cout<< "Input  first vector coordinates :";
        std::cin>>x1>>y1;
        std::cout<< "Input  second vector coordinates :";
        std::cin>>x2>>y2;
        if(oper=="add"){
            std::cout<<"Coordinates sum of vectors : "<<x1+x2<<" , "<<y1+y2;
        } else{
            std::cout<<"Coordinates sum of vectors : "<<x1-x2<<" , "<<y1-y2;
        }
    }
    else if(oper=="scale"){
        std::cout<< "Input vector coordinates :";
        std::cin>>x1>>y1;
        std::cout<< "Input scalar :";
        std::cin>>scale;
        std::cout<<"Coordinates  of result : "<<x1*scale<<" , "<<y1*scale;
    }
    else if(oper=="length"){
        std::cout<< "Input vector coordinates :";
        std::cin>>x1>>y1;
        std::cout<<"Length of vector : "<<sqrt(x1*x1 + y1*y1);
    }
    else if (oper=="normalize"){
        std::cout<< "Input vector coordinates :";
        std::cin>>x1>>y1;
        std::cout<<"Coordinates of Normalized Vector: "<<x1/ sqrt(x1*x1 + y1*y1)<<" , "<<y1/ sqrt(x1*x1 + y1*y1);
    }
    return 0;
}
