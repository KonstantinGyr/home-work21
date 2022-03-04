#include <iostream>
#include <string>
#include <vector>

struct Villege{
    std::string name;
    float areaPiece;
    int quantBuild;
    struct Building{
        std::string purpose;
        float areaBuild;
        bool stoveWithPipe;
        int quantFloors;
        struct Floor{
            int numFloor;
            float height;
            int quantRoom;
            struct Room{
                std::string name;
                float area;
            };
        };
    };
};
int main() {
    int n=1;
    std::cout << "Enter number of plots in the village" << std::endl;
    std::cin>>n;
    std::vector<Villege> piece ;
    Villege numPiece;
    std::vector<Villege::Building> type;
    Villege::Building building;
    std::vector<Villege::Building::Floor>floors;
    Villege::Building::Floor floor;
    std::vector<Villege::Building::Floor::Room>use;
    Villege::Building::Floor::Room room;
    std::string pipe;
    for(int i=1;i<=n;i++){
        numPiece.name="Plot number"+ (std::to_string(i));
        std::cout<<"Plot number "<<i<<std::endl;
        std::cout<<"Enter plot area : ";
        std::cin>>numPiece.areaPiece;
        std::cout<<"Enter quantity building on a plot: ";
        std::cin>>numPiece.quantBuild;
        for(int j=1;j<=numPiece.quantBuild;j++){
            std::cout<<"Building # "<<j<<std::endl;
            std::cout<<"Enter type building: ";
            std::cin>>building.purpose;
            std::cout<<"Enter building area : ";
            std::cin>>building.areaBuild;
            std::cout<<"Do you have a stove with a pipe?";
            std::cin>>pipe;
            if(pipe=="yes")building.stoveWithPipe= true;
            else if(pipe=="no")building.stoveWithPipe= false;
            std::cout<<"How many floors in the house ?";
            std::cin>>building.quantFloors;
            for(int k=1;k<=building.quantFloors;k++) {
                floor.numFloor = k;
                std::cout<<"Floor # "<<k<<std::endl;
                std::cout << "Enter height floor :";
                std::cin >> floor.height;
                std::cout << "How many rooms on a floor? ";
                std::cin >> floor.quantRoom;
                for (int a = 1; a <= floor.quantRoom; a++) {
                    std::cout<<"Room # "<<a<<std::endl;
                    std::cout << "What is the purpose of the room? ";
                    std::cin >> room.name;
                    std::cout << "How many area this room? ";
                    std::cin >> room.area;
                    use.push_back(room);
                }
              floors.push_back(floor);
            }
           type.push_back(building);
        }
       piece.push_back(numPiece);
    }
    std::cout<<"Total building area ";
    float sum=0;
    for(int j=0;j<type.size();j++) {
        sum += type[j].areaBuild;
    }
    std::cout<<sum;
    return 0;
}
