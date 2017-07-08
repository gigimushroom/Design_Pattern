#include <iostream>
#include "buildingUtil.h"

class BuildingFactory{
public:

    virtual Building* makeBuilding() const { return new Building; }
    virtual Room* createRoom() const { return new Room; }
    
    virtual Wall* createWall() const { return new Wall; }
       

};

class ApartmentFactory : public BuildingFactory {
public:
    ApartmentFactory() {};
    virtual Room* createRoom() const { 
        std::cout << "Creating apartment room...\n";
        return new ApartmentRoom;
    }
    
    virtual Wall* createWall() const { 
        std::cout << "Creating apartment wall...\n";
        return new ApartmentWall; 
    }

};

class ClassroomFactory : public BuildingFactory {
public:
    ClassroomFactory() {};
    virtual Room* createRoom() const { 
        std::cout << "Creating classroom...\n";
        return new Room; 
    }
    
    virtual Wall* createWall() const { 
        std::cout << "Creating classwall...\n";
        return new Wall; 
    }

};


class Builder{
public:
    Building* createBuilding(BuildingFactory& factory)
    {
        // do sth
        Building* building = factory.makeBuilding();
        factory.createRoom();
        factory.createWall();
        
        return building;
    }        
    
};

int main()
{
    Builder myBuilder;
    ApartmentFactory aptFactory;
    Building* building = myBuilder.createBuilding(aptFactory);
    if (building != NULL)
    {
        //building->printInfo();
    }
    
    
    return 0;
}

