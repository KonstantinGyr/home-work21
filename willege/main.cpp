#include <iostream>
#include <string>

struct Villege{
    std::string name;
    float areaHouse;
    float areaGarage=0;
    float areaBathhouse=0;
    bool pipeHouse;
    bool pipeBath;
    int floors;
    struct House{
        std::string num;
        float height;
        float hall=0;
        float bedroom=0;
        float bathroom=0;
        float kitchen=0;
        float playroom=0;
    };
};
int main() {
    int n=0;
    int floors=0;
    std::cout << "Enter number of plots in the village" << std::endl;
    std::cin>>n;
    Villege piece[100] ;
    Villege::House floor[10];
    std::string pipe;
    for(int i=1;i<=n;i++){
        piece[i].name="Plot number"+ (std::to_string(i));
        std::cout<<"Plot number "<<i<<std::endl;
        std::cout<<"Enter house area : ";
        std::cin>>piece[i].areaHouse;
        std::cout<<"Enter garage area,if any : ";
        std::cin>>piece[i].areaGarage;
        std::cout<<"Enter bathhouse area,if any : ";
        std::cin>>piece[i].areaBathhouse;
        std::cout<<"In the house a stove with a pipe?";
        std::cin>>pipe;
        if(pipe=="yes")piece[i].pipeHouse= true;
        else if(pipe=="no")piece[i].pipeHouse= false;
        std::cout<<"In the bath a stove with a pipe?";
        std::cin>>pipe;
        if(pipe=="yes")piece[i].pipeBath= true;
        else if(pipe=="no")piece[i].pipeBath= false;
        std::cout<<"How many floors in the house ?";
        std::cin>>floors;
        for(int j=1;j<=floors;j++){
            floor[j].num="Floor number "+std::to_string(j);
            std::cout<<floor[j].num<<std::endl;
            std::cout<<"Enter height floor :";
            std::cin>>floor[j].height;
            std::cout<<"Enter hall area,if any :";
            std::cin>>floor[j].hall;
            std::cout<<"Enter bedroom area,if any :";
            std::cin>>floor[j].bedroom;
            std::cout<<"Enter bathroom area,if any :";
            std::cin>>floor[j].bathroom;
            std::cout<<"Enter kitchen area,if any :";
            std::cin>>floor[j].kitchen;
            std::cout<<"Enter playroom area,if any :";
            std::cin>>floor[j].playroom;
        }
    }
    std::cout<<"Total building area ";
    float sum=0;
    for(int i=1;i<=n;i++){
        sum+=(piece[i].areaHouse+piece[i].areaGarage+piece[i].areaBathhouse);
    }
    std::cout<<sum;
    return 0;
}
