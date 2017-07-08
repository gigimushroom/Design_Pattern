#include <iostream>
#include "buildingUtil.h"

class Builder{
public:

    virtual Room* createRoom() { return new Room; }
    virtual Wall* createWall() { return new Wall; }
        
    Building* createBuilding()
    {
        // do sth
        Building *building = new Building;
        Room * room = createRoom();
        Wall * wall = createWall();
        
        if (room != NULL && wall != NULL)
        {
            // building->AddRoom(room);
        }
        
        return building;
    }        
    
};

class SchoolBuilder : public Builder {
    virtual Room* createRoom() { return new Room; }
    virtual Wall* createWall() { return new Wall; }
    
};

class ApartmentBuilder : public Builder {
    virtual Room* createRoom() { return new ApartmentRoom; }
    virtual Wall* createWall() 
    { 
        std::cout << "Creating apartment wall...\n";
        return new ApartmentWall; 
    }    
};

int main()
{
    ApartmentBuilder myBuilder;
    Building* building = myBuilder.createBuilding();
    if (building != NULL)
    {
        //building->printInfo();
    }
    
    
    return 0;
}
