#include <iostream>
#include <string>
#include <vector>
struct Room{
    std::string name;
    float area;
};
struct Floor{
    int numFloor;
    float height;
    int quantRoom;
    std::vector<Room>rooms;
};
struct Building{
    std::string purpose;
    float areaBuild;
    bool stoveWithPipe;
    int quantFloors;
    std::vector<Floor>floors;
};
struct Plot{
    std::string name;
    float areaPiece;
    int quantBuild;
    std::vector<Building>buildings;
};
struct Villege{
    std::string nameVillege;
    std::vector<Plot>plots;
};
int main() {
    int n = 1;

    std::vector<Villege> villeges;
    Villege nameVillege;
    std::vector<Plot> plots;
    Plot numPlot;
    std::vector<Building> buildings;
    Building nameBuilding;
    std::vector<Floor> floors;
    Floor numFloor;
    std::vector<Room> rooms;
    Room nameRoom;
    std::cout << "Enter villege name: ";
    std::cin >> nameVillege.nameVillege;
    std::cout << "Enter number of plots in the village" << std::endl;
    std::cin >> n;
    std::string pipe;
    for (int i = 0; i < n; i++) {
        numPlot.name = "Plot number" + (std::to_string(i+1));
        std::cout << "Plot number " << i+1 << std::endl;
        std::cout << "Enter plot area : ";
        std::cin >> numPlot.areaPiece;
        std::cout << "Enter quantity building on a plot: ";
        std::cin >> numPlot.quantBuild;
        for (int j = 1; j <= numPlot.quantBuild; j++) {
            std::cout << "Building # " << j << std::endl;
            std::cout << "Enter type building: ";
            std::cin >> nameBuilding.purpose;
            std::cout << "Enter building area : ";
            std::cin >> nameBuilding.areaBuild;
            std::cout << "Do you have a stove with a pipe?";
            std::cin >> pipe;
            if (pipe == "yes")nameBuilding.stoveWithPipe = true;
            else if (pipe == "no")nameBuilding.stoveWithPipe = false;
            std::cout << "How many floors in the house ?";
            std::cin >> nameBuilding.quantFloors;
            for (int k = 1; k <= nameBuilding.quantFloors; k++) {
                numFloor.numFloor= k;
                std::cout << "Floor # " << k << std::endl;
                std::cout << "Enter height floor :";
                std::cin >> numFloor.height;
                std::cout << "How many rooms on a floor? ";
                std::cin >> numFloor.quantRoom;
                for (int a = 1; a <= numFloor.quantRoom; a++) {
                    std::cout << "Room # " << a << std::endl;
                    std::cout << "What is the purpose of the room? ";
                    std::cin >> nameRoom.name;
                    std::cout << "How many area this room? ";
                    std::cin >> nameRoom.area;
                    numFloor.rooms.push_back(nameRoom);
                }
                nameBuilding.floors.push_back(numFloor);
            }
            numPlot.buildings.push_back(nameBuilding);
        }
        nameVillege.plots.push_back(numPlot);
    }
    villeges.push_back(nameVillege);
    float sum = 0;
    for (int i = 0; i <villeges[0].plots.size();i++){
        numPlot=villeges[0].plots[i];
        for (int j = 0; j < numPlot.buildings.size(); j++) {
            nameBuilding=numPlot.buildings[j];
            sum += nameBuilding.areaBuild;
        }
    }
    std::cout<<"Total area villege buildings: "<<sum<<std::endl;
  //  std::cout<<"Bathroom area, on first floor, in house, on second plot: ";
   // std::cout<<villeges[0].plots[0].buildings[0].floors[0].rooms[0].area;
    return 0;
}
