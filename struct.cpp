#include <iostream>
#include <string>

using namespace std;

/*
    o Structures definition: collections of objects that need not be of the same type.
 
    Notes about the structures : 
        1) Structures is like a blueprint that you're going to follow when creating an actual object or instance(in the main when you actually store it in memory) 

        2) Why Struct ? 
            o an array is a homogeneous(holds data of the same type) data structure but the struct is heterogeneous(can hold data of different data types).
            o Grouping related fields with each other in one data structure.
            o you don't have to repeat the same related fields many times ex :
                . let's say you're creating 2 Cars and any car can have some common properties but without using a struct you will have to create many variables which are seperated from each other like the following example:
                    // Car 1 
                    int speed1;   
                    string name;        
                    string color; 

                    // Car 2
                    int speed2;   
                    string name2;
                    string color2;
                

        3) How to create a struct and how to use it and how to access the elements (the syntax) ? 
                  ----------------     -------------     -------------------------     
        
            o create it :
        
             struct structure_name  
             {  
                 // member declarations (your related variables).  
             };   


            o use it :

                structure_name some_variable_name; (in the main create the actual Car after building your design or the blueprint of your struct)

            o how to access the elements (by the . dot operator) :

                some_variable_name.some_variable_inside_the_struct

*/

struct Car
{
    string name;
    string color;
    int speed;
};

// if you want to create a function for filling an array of cars 
void addCars(Car cars[], int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << "name ";
        cin >> cars[i].name;
        cout << "color ";
        cin >> cars[i].color;
        cout << "speed ";
        cin >> cars[i].speed;
    }
}

// printing elements in an array of cars 
void printCars(Car cars[], int size)
{
    cout << " ********************" << endl ;
    
    for (int i = 0; i < size; i++)
    {
        cout << "name " << cars[i].name << endl;
        cout << "color " << cars[i].color << endl;
        cout << "speed " << cars[i].speed << endl;
    }
}


/* Other Examples for structures */

struct Employee
{
    string name;
    int age;
    float salary;
};

struct Movie
{
    string name;
    string actors[2]; // i could've used a vector instead of an array in here but i didn't want to complicate the example 
    string genre; 
};

int main()
{

    // Car bmw; // creating an actual Car(one Car it's not an array but remember that the Car has many fields so you'll have to determine which field by the dot . operator) 

    // bmw.name = "BMW";
    // bmw.speed = 1000;
    // bmw.color = "Black";

    // cout << bmw.name;

    // cout << "enter color: "; cin >> bmw.color;
    // cout << "enter name: "; cin >> bmw.name;
    // cout << "enter speed: "; cin >> bmw.speed;

    // cout << bmw.color;
    // cout << bmw.name;

    /* 

Car cars[2]; // Creating an array of type Car (many cars)

imagine that when you're creating an array of Car(with 2 elements in this case) that it has the following shape :


    ------------------------------------
    |                                  |
    |             Car                  |
    |        -------------             | 
    |        |    name    |            | 
  0 |        |------------|            |
    |        |    color   |            |
    |        |------------|            |
    |        |    speed   |            |
    |        |------------|            |
    |--------------------------------- | 
    |             Car                  |
    |        -------------             | 
    |        |    name    |            | 
    |        |------------|            |
    |        |    color   |            |
  1 |        |------------|            |
    |        |    speed   |            |
    |        |------------|            | 
    |                                  | 
    |-----------------------------------
   

    and if you want to set the first car fields to some values then you'll do the following :
     
    cars[0].name = "BMW";
    cars[0].color = "Black";
    cars[0].speed = 1000;

    and the resulted shape will be like this after setting the values 


    ------------------------------------
    |                                  |
    |             Car                  |
    |        -------------             | 
    |   name |   BMW      |            | 
  0 |        |------------|            |
    |  color |   Black    |            |
    |        |------------|            |
    |  speed |   1000     |            |
    |        |------------|            |
    |--------------------------------- | 
    |             Car                  |
    |        -------------             | 
    |        |    name    |            | 
    |        |------------|            |
    |        |    color   |            |
  1 |        |------------|            |
    |        |    speed   |            |
    |        |------------|            | 
    |                                  | 
    |-----------------------------------


   */



/* 

   // setting values without a loop 


    cars[0].name = "BMW";
    cars[0].color = "Black";
    cars[0].speed = 400;
    
    cars[1].name = "Toyota";
    cars[1].color = "blue";
    cars[1].speed = 200;


   // outputting values without a loop 

   cout <<  cars[0].name << endl;
   cout <<  cars[0].color << endl;
   cout <<  cars[0].speed << endl;
   cout <<  cars[1].name << endl;
   cout <<  cars[1].color << endl;
   cout <<  cars[1].speed  << endl;

*/
    

 /*
    // setting values using a loop 

    for (int i = 0; i < 3; i++)
    {
        cout << "enter car name: " << endl; cin >> cars[i].name;
        cout << "enter car color: " << endl; cin >> cars[i].color;
        cout << "enter car speed: " << endl; cin >> cars[i].speed;
    }

*/ 
    // cout << "***************************************" << endl;


/*

    // outputting values using a loop

    for (int i = 0; i < 2; i++)
    {
        cout << cars[i].name << endl;
        cout << cars[i].speed << endl;
        cout << cars[i].color << endl;
    }
    
*/



/*
    // Employee Example
    
    Employee employees[3];


    for (int i = 0; i < 3; i++)
    {
        cout << "name: "; cin >> employees[i].name; 
        cout << "age: "; cin >> employees[i].age; 
        cout << "salary: "; cin >> employees[i].salary; 
    }
    
    cout << employees[0].name;

*/

/* 

    // using functions for inserting new elements to an array of Car 

    int numberOfElements;

    cout << "number of elements" << endl;
    cin >> numberOfElements;

    Car cars[numberOfElements];

    addCars(cars, numberOfElements);

    printCars(cars, numberOfElements);

*/


/*

// filling an array within a structure 

Movie movies[2];


for(int i = 0; i < 2; i++){

    cout << "please enter movie name: " << endl; getline(cin, movies[i].name); // i used the getline in case you entered white space in the movie name or any string to get the whole line
    cout << "please enter movie genre: " << endl; getline(cin, movies[i].genre);
    // a loop to enter the actors names cause it's an array  
    for(int j = 0; j < 2; j++){
        cout << "please enter movie " << i << " actors: " << endl; getline(cin, movies[i].actors[j]);
    }

}

// output the values entered to the array of Movie

for (int i = 0; i < 2; i++)
{
    cout << movies[i].name << endl;
    cout << movies[i].genre << endl;
    cout << movies[i].actors[i] << endl;
}

*/


}

