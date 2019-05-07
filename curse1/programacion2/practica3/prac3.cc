#include <iostream>
#include <string.h>
#include "Container.h"
#include "Ship.h"
#include "Base.h"
#include "Util.h"

using namespace std;


void printContainer(const Container &c)
{
    cout << "[" << c.id << " " << c.weight << ":" << c.value << "]\n";
}

void printShip(const Ship &s)
{
    int acomulatedValue;
    int numOfShipCont=s.containers.size();
    
    cout << "{" << s.name << ": " << s.weight << " (" << s.maxWeight << "), "
         << numOfShipCont << " (" << s.maxContainers << "), " << s.value  << endl;
    
    for (int j=0; j < numOfShipCont; j++){
        cout << "[" << s.containers[j].id << " " << s.containers[j].weight << ":" << s.containers[j].value << "]";
    }
    cout << endl << "}" << endl << endl;
}

void printBase(const Base &b)
{
    int numOfConts=b.containers.size();
    int numOfShips = b.ships.size();
    
    cout << "Name: " << b.name <<"\n Containers:\n";
    
    for (int j=0; j<numOfConts;j++){
        printContainer(b.containers[j]);
    }

    cout << " Ships:\n";
    for (int j=0; j<numOfShips;j++){
        printShip(b.ships[j]);
    }
    
}

void addContainer(Base &b)
{
    const int weightMin=100;
    const int valueMin=100;
    
    Container inputContainer;
    
    cout << "Container weight:";
    cin >> inputContainer.weight;
    
    if (inputContainer.weight < weightMin)
        error(ERR_CONTAINER_WEIGHT);
    else {
        cout << "Container value:";
        cin >> inputContainer.value;
        if (inputContainer.value < valueMin)
            error(ERR_CONTAINER_VALUE);
        else {
            inputContainer.id = i;
            i++;
            b.containers.push_back(inputContainer);
        }
    }
    
}

void removeContainer(Base &b)
{
    unsigned int inputID;
    int numOfConts=b.containers.size();
    
    bool err = 1;
    
    cout << "Container id:";
    cin >> inputID;
    
    for (int j=0; j < numOfConts; j++){
        if (inputID == b.containers[j].id){
            b.containers.erase (b.containers.begin()+j);
            err = 0;
            
            break;
        }
    }
    if (err==1)
        error(ERR_CONTAINER_ID);
}

void addShip(Base &b)
{
    const int contMin=5;
    const int weightMin=500;
    int numOfShips=b.ships.size();
    bool err = 0;
    
    Ship inputShip;
    
    
    cout << "Ship name:";
    cin >> inputShip.name;
    if (numOfShips>0)
        for (int j=0; j < numOfShips; j++){
            if (inputShip.name == b.ships[j].name){
                err = 1;
                error(ERR_SHIP_NAME);
                            
                break;
            }
        }
    if (err==0) {
        cout << "Ship max. containers:";
        cin >> inputShip.maxContainers;
        if (inputShip.maxContainers < contMin)
            error(ERR_SHIP_MAXCONTAINERS);
        else {
            cout << "Ship max. weight:";
            cin >> inputShip.maxWeight;
            if (inputShip.maxWeight < weightMin)
                error(ERR_SHIP_MAXWEIGHT);
            else{
                inputShip.value=0;
                inputShip.weight=0;
                b.ships.push_back(inputShip);
        
            }
        }
    }
}

void removeShip(Base &b)
{
    string shipName;
    int index;
    int numOfShips=b.ships.size();

    bool err = 1;
    
    cout << "Ship name:";
    cin >> shipName;

    
    for (int j=0; j < numOfShips; j++){
        if (shipName == b.ships[j].name){
            err = 0;
            index = j;
                        
            break;
        }
    }
    if (err == 1)
        error(ERR_SHIP_NAME);
    else{
        int numOfShipCont=b.ships[index].containers.size();
        for (int j=0; j < numOfShipCont; j++){
            b.containers.push_back(b.ships[index].containers[j]);
        }
        b.ships.erase (b.ships.begin()+index);
    }
}

void manualDistribution(Base &b)
{
    int inputID;
    string shipName;
    int contIndex;
    int shipIndex;

    int numOfShips=b.ships.size();
    int numOfConts=b.containers.size();
    bool err = 1;    
    
    cout << "Container id:";
    cin >> inputID;
    
    for (int j=0; j < numOfConts; j++){
        if (inputID == b.containers[j].id){
            err = 0;
            contIndex = j;
            
            break;
        }
    }
    if (err==1)
        error(ERR_CONTAINER_ID);
    else{
        err = 1;
        cout << "Ship name:";
        cin >> shipName;

    
        for (int j=0; j < numOfShips; j++){
            if (shipName == b.ships[j].name){
                err = 0;
                shipIndex = j;
                            
                break;
            }
        }
        if (err == 1)
            error(ERR_SHIP_NAME);
        else{
            int numOfShipCont=b.ships[shipIndex].containers.size();
            err = 0;
            if (numOfShipCont > b.ships[shipIndex].maxContainers){
                err = 1;
                error(ERR_SHIP_NO_MORE_CONTAINERS);
            }
            if ((b.ships[shipIndex].weight+b.containers[contIndex].weight) > b.ships[shipIndex].maxWeight){
                err = 1;
                error(ERR_SHIP_NO_MORE_WEIGHT);
            }
            if (err == 0){
                b.ships[shipIndex].containers.push_back(b.containers[contIndex]);               
                b.containers.erase (b.containers.begin()+contIndex);
            }
        }
    }
    
}


void menu()
{
  cout << "1- Info base" << endl
       << "2- Add container" << endl
       << "3- Remove container" << endl
       << "4- Add ship" << endl
       << "5- Remove ship" << endl
       << "6- Manual distribution" << endl
       << "7- Automatic distribution" << endl
       << "8- Unassign container" << endl
       << "9- Clear assignations" << endl
       << "q- Quit" << endl
       << "Option: " ;
}

int main()
{
  Base base("Logistic Center");
  vector<Ship*> naves;
  
  char option;

  do
  {
    menu();
    cin >> option; cin.get();
        
    switch (option)
    { 
      case '1':
      {
        cout << base;
        break;
      }
      case '2':
      { 
        base.addContainer();
        break;
      }
      case '3':
      {
        base.removeContainer();
        break;
      }
      case '4':
      {
        try
        {
          Ship *nueva=new Ship;
          naves.push_back(nueva);
          base.addShip(nueva);
        }
        catch(Error e)
        {
          Util::error(e);
        }
        break;
      }
      case '5':
      {
        base.removeShip();
        break;
      }
      case '6':
      {
        base.manualDistribution();
        break;
      }
      case '7':
      {
        base.automaticDistribution();
        break;
      }
      case '8':
      {
        base.unassignContainer();
        break;
      }
      case '9':
      {
        base.clearAssignations();
        break;
      }
      case 'q':
      {
        for(int i=0;(unsigned)i<naves.size();i++)
        {
          delete naves[i];
        }
        break;
      }
      default:
      {
        Util::error(ERR_MENU_OPTION); 
        break;
      }
    }
  } while(option != 'q');
   
  return 0;
}
