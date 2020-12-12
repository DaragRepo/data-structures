#include <iostream>

using namespace std;

struct Car
{
    string name;
    string color;
    int speed;
};

struct NodeOfCar
{
    Car car;
    NodeOfCar *next;
};

NodeOfCar *headCar = NULL;

void insertToFrontCar(Car carObj)
{
    NodeOfCar *pNode = new NodeOfCar;

    pNode->car = carObj;

    if (headCar)
    { // if not null
        pNode->next = headCar;
    }
    else
    { // if this is the first element in the list
        pNode->next = NULL;
    }

    headCar = pNode;
}


void printNodes(){

    NodeOfCar* temp = headCar;

    while(temp != NULL){
        
        cout << "Car name: " <<  temp->car.name << endl;
        cout << "Car color: " <<  temp->car.color << endl;
        cout << "Car speed: " <<  temp->car.speed<< endl;

        temp = temp->next;

    }


}



int main()
{
    Car car;

    car.name = "BMW";
    car.speed = 1000;
    car.color = "Black";
    

    insertToFrontCar(car);

    printNodes();



}