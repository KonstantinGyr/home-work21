#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

struct Iam{
    std::string name ;
    int health;
    int armor;
    int damage;
    int x;
    int y;
};
struct Soldier{
    std::string name;
    int health;
    int armor;
    int damage;
    int x;
    int y;
};
void initialField(char(&field)[20][20]){
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            field[i][j]=' ';
        }
    }
}

void printField(char(&field)[20][20]){
    for(int i=19;i>=0;i--){
        for(int j=0;j<20;j++){
            char a=field[j][i];
            if(a==' '){
                a='.';
                std::cout<<a<<' '<<' ';
            }
            else {
                std::cout << field[j][i] << ' '<<' ';
            }
        }
        std::cout<<std::endl;
    }
}
void initialEnemy(Soldier (&people)[5],char (&field)[20][20]){
    for(int i=0;i<5;i++){
        people[i].name="Enemy # "+ std::to_string(i+1);
        people[i].armor=(std::rand()%51);
        people[i].health=(std::rand()%101)+50;
        people[i].damage=(std::rand()%16)+15;
        do{
            people[i].x=std::rand()%20;
            people[i].y=std::rand()%20;
        }while (field[people[i].x][people[i].y]!=' ');
        field[people[i].x][people[i].y]='E';

    }
}
void initialMe(Iam &mayform, char (&field)[20][20]){
    std::cout << "Enter parameters players." << std::endl;
    std::cout<<"Enter your name : ";
    std::cin >> mayform.name;
    std::cout<<"Enter your health :";
    std::cin >> mayform.health;
    std::cout<<"Enter your armor : ";
    std::cin >> mayform.armor;
    std::cout<<"Enter your damage : ";
    std::cin >> mayform.damage;
    do {
        std::cout << "Enter your coordinates : ";
        std::cin >> mayform.x >> mayform.y;
    } while (mayform.x < 0 || mayform.x >= 20 || mayform.y < 0 || mayform.y >= 20);
    field[mayform.x][mayform.y]='P';
}
void saveGame(Soldier (&people)[5],char (&field)[20][20],Iam &mayform){
    std::ofstream enemyf("enemy.bin",std::ios::binary);
    for(int i=0;i<5;i++) {
        enemyf.write((char *) &people[i],sizeof (Soldier));
    }
    enemyf.close();
    std::ofstream mayf("mayfile.bin",std::ios::binary);
    mayf.write((char*)&mayform, sizeof(Iam));
    mayf.close();
    std::ofstream fieldf("fieldfile.bin",std::ios::binary);
    fieldf.write((char*)&field,sizeof(field));
    fieldf.close();
}
void loadGame(Soldier (&people)[5],char (&field)[20][20],Iam &mayform){
    std::ifstream enemyf("enemy.bin",std::ios::binary);
    for(int i=0;i<5;i++) {
        enemyf.read((char *) &people[i],sizeof (Soldier));
    }
    enemyf.close();
    std::ifstream mayf("mayfile.bin",std::ios::binary);
    mayf.read((char*)&mayform, sizeof(Iam));
    mayf.close();
    std::ifstream fieldf("fieldfile.bin",std::ios::binary);
    fieldf.read((char*)&field,sizeof(field));
    fieldf.close();
}
bool fieldOk(int x,int y){
    if(x<0||x>=20||y<0||y>=20)return false;
    return true;
}
void battleWithE( int n, Soldier (&people)[5], Iam &mayform, char (&field)[20][20]) {
    people[n].armor -= mayform.damage;
    if (people[n].armor < 0) {
        people[n].health += people[n].armor;
        people[n].armor = 0;
    }
    std::cout<<people[n].name<<" have health: "<<people[n].health<<std::endl;
    if(people[n].health<=0){
        std::cout<<people[n].name<<" is death"<<std::endl;
        field[mayform.x][mayform.y]=' ';
        mayform.x=people[n].x;
        mayform.y=people[n].y;
        field[mayform.x][mayform.y]='P';
        people[n].x=-1;
        people[n].y=-1;
    }
}
void attack(int x, int y, int n, Soldier (&people)[5], Iam &mayform, char (&field)[20][20]){
    std::cout<<"The enemy is attacking!"<<std::endl;
    mayform.armor-=people[n].damage;
    if(mayform.armor<0){
        mayform.health += mayform.armor;
        mayform.armor = 0;
    }
    std::cout<<"May health: "<<mayform.health<<std::endl;
}
void step(int x, int y, int x1, int y1, Soldier (&people)[5], Iam &mayform, char (&field)[20][20],int num){
    if(fieldOk(x1,y1)) {
        if(field[x][y]=='P'&&field[x1][y1]==' ') {
            std::swap(field[x1][y1], field[x][y]);
            mayform.x = x1;
            mayform.y = y1;
        }
        else if(field[x][y]=='E'&&field[x1][y1]==' ') {
                std::swap(field[x1][y1], field[x][y]);
                people[num].x = x1;
                people[num].y = y1;
        }
        else if (field[x1][y1] == 'E' && field[x][y] == 'P') {
                int n;
                for (int i = 0; i < 5; i++) {
                    if (people[i].x == x1 && people[i].y == y1) {
                        n = i;
                        break;
                    }
                }
                battleWithE( n, people, mayform, field);
        }
        else if (field[x1][y1] == 'P' && field[x][y] == 'E'){
            attack(x1, y1, num, people, mayform, field);
        }
    }
}
int main() {
    std::string turn;
    Soldier people[5];
    Iam mayform;
    char field[20][20];
    std::cout<<"initialize data? or load ";
    std::cin>>turn;
    if(turn=="initialize"){
        initialField(field);
        initialMe(mayform, field);
        initialEnemy(people,field);
        printField(field);
    }
    else if(turn=="load"){
        loadGame(people, field, mayform);
        printField(field);
    }
    while (mayform.health > 0 && (people[0].health > 0 || people[1].health > 0 ||
            people[2].health>0 ||people[3].health>0 ||people[4].health>0)){
        std::cout<<"Your turn : ";
        std::cin>>turn;
        if(turn=="save"){
            saveGame(people, field, mayform);
            return 0;
        }
        else if(turn=="l"){
            step(mayform.x, mayform.y, mayform.x - 1, mayform.y, people, mayform, field,0);
        }
        else if(turn=="r"){
            step(mayform.x, mayform.y, mayform.x + 1, mayform.y, people, mayform, field,0);
        }
        else if(turn=="t"){
            step(mayform.x, mayform.y, mayform.x, mayform.y + 1, people, mayform, field,0);
        }
        else if(turn=="b"){
            step(mayform.x, mayform.y, mayform.x, mayform.y - 1, people, mayform, field,0);
        }
        else continue;
        int n;
        for(int i=0;i<5;i++){
            if(people[i].health>0){
                n=rand()%4;
                if(n==0)step(people[i].x, people[i].y,people[i].x-1, people[i].y, people, mayform, field,i);
                else if(n==1)step(people[i].x, people[i].y,people[i].x+1, people[i].y, people, mayform, field,i);
                else if(n==2)step(people[i].x, people[i].y, people[i].x,people[i].y+1, people, mayform, field,i);
                else if(n==3)step(people[i].x, people[i].y, people[i].x,people[i].y-1, people, mayform, field,i);
            }
        }
        printField(field);
    }
    if(mayform.health<=0){
        std::cout<<"The enemy has won!";
    }
    else if(mayform.health>0){
        std::cout<<"Iam won!";
    }
    return 0;
}