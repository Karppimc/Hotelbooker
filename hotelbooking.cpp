// Hotel room reservation system
// Santeri Karppinen 2203820
// Grade 4 
// I have commented throughout this code what everything does
// 
// 
//importing libraries 
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <string>
using namespace std;

// total number of rooms in hotel 
const int ROOMS_COUNT = 80;

// function prototypes 
void print_reservation(int room_index);
void register_room(int room_index);
void search_by_id(int booking_id);
void search_by_name(string booker_name);
void print_bill(int room_index);


// a struct to hold the details of a room reservation
struct room {
    bool is_booked;
    bool is_double;
    int booking_num;
    int night_stays;
    string booker_name;

};

//array of structs to hold the data for rooms in hotel
room hotel_rooms[ROOMS_COUNT];

int main() {
    //user welcome message 
    cout << "\nWELCOME TO HOTEL ROOM RESERVATION PROGRAM";

    // to know which rooms are booked and book the next empty one
    int singles_index = 0; // first half will be single rooms 
    int doubles_index = ROOMS_COUNT / 2; //second half will be double rooms

    int user_choice;

    do {
        // menu for the program
        cout << "\n===== MENU ==============================="
            << "\n\t1. Register a room"
            << "\n\t2. Search room by booking number"
            << "\n\t3. Search room by name of booker"
            << "\n\t4. Exit"
            << "\nSelect: ";
        cin >> user_choice;

        switch (user_choice) {
            // if user selects to register a room
        case 1: {
            // ask they want a single or double room
            cout << "\nWhat type of room would you like: "
                << "\n1. Single Room"
                << "\n2. Double Room" << endl;

            // verify user selects a valid option
            do {
                cout << "Select: ";
                cin >> user_choice;
            } while (user_choice > 2 || user_choice < 1);

            // if user selects a single room
            if (user_choice == 1)
            {
                // if we have single rooms available 
                if (singles_index < ROOMS_COUNT / 2) {
                    cout << "\nRegistering a single bed room" << endl;
                    // call the function to get the details for registeration
                    register_room(singles_index);
                    // increase the index of registered single room by one 
                    singles_index++;

                    // if no single rooms are available 
                }
                else {
                    cout << "No single room available!" << endl;
                }

            }

            //if user chose a double room
            else if (user_choice == 2)
            {
                // check if we have double rooms available 
                if (doubles_index < ROOMS_COUNT) {
                    cout << "\nRegistering a double bed room" << endl;
                    // call the function to get the details for registeration
                    register_room(doubles_index);
                    // increase the index of registered double room by one 
                    doubles_index++;

                    // if no rooms are available 
                }
                else {
                    cout << "No double room available!" << endl;
                }
            }

            break;
        }

              // if user selects to find a reservation by booking id 
        case 2: {
            int b_id;
            // get booking id from user 
            cout << "\nEnter booking ID: ";
            cin >> b_id;

            //call the function to print registeration with booking id 
            search_by_id(b_id);
            break;
        }

              // if user selects to find a reservation by booker name
        case 3: {
            string name;

            // get name from user 
            cin.ignore();
            cout << "\nEnter name: ";
            getline(cin, name);

            // call the function to print reservations made by person with this name 
            search_by_name(name);
            break;
        }

              // if user chooses to exit the program 
        case 4: {
            cout << "Exiting...";
            break;
        }

              // if user enters any other than the valid command
        default: {
            cout << "Invalid choice." << endl;
        }
        }
        // keep allowing the user to select different options from the menu till user exits 
    } while (user_choice != 4);


    return 0;
}


// function to get the details for registeration of a room
void register_room(int room_index)
{
    // found these online. You can use current time as seed for random function
    srand(time(0));

    // assign a random bookin id between range 10000 to 99999
    hotel_rooms[room_index].booking_num = (rand() % (99999 - 10000 + 1)) + 10000;


    // check if room is from the indexes of single rooms or double rooms 
    if (room_index >= (ROOMS_COUNT / 2)) {
        // set it to true so it can be printed as double and billed correctly
        hotel_rooms[room_index].is_double = true;
    }
    else {
        // if it comes back as false user has selected single room and it prints that out later
        hotel_rooms[room_index].is_double = false;
    }

    // get name of the booker 
    cin.ignore();
    cout << "Enter name: ";
    getline(cin, hotel_rooms[room_index].booker_name);

    // ask for number of nights user stays 
    cout << "How many nights will you be spending: ";
    cin >> hotel_rooms[room_index].night_stays;

    // let user know room was booked
    cout << "\nROOM BOOKED!" << endl;

    // call function to show reservation details 
    print_reservation(room_index);

    //call function to display a bill for room
    print_bill(room_index);
}

// function to print the reservation details of a room
void print_reservation(int room_index)
{
    cout << "------------------------------------------";
    cout << "\nBooking ID: " << hotel_rooms[room_index].booking_num
        << "\nRoom Number: " << room_index + 1
        << "\nBooked by: " << hotel_rooms[room_index].booker_name;

    // check if room is double or not and print accordingly 
    if (hotel_rooms[room_index].is_double) {
        cout << "\nRoom type: Double Bed" << endl;
    }
    else {
        cout << "\nRoom type: Single Bed" << endl;
    }

    cout << "Night stays: " << hotel_rooms[room_index].night_stays << endl;
    cout << "------------------------------------------";
}


// function to search from rooms based on booking id 
void search_by_id(int booking_id)
{
    cout << "Reservation with booking ID: " << booking_id << endl;

    // loop through rooms 
    for (int i = 0; i < ROOMS_COUNT; i++)
    {
        // if we found a match for booking id 
        if (hotel_rooms[i].booking_num == booking_id)
        {
            // print the details of the reservation 
            print_reservation(i);
            
        }
    }
}

// function to search the rooms by booker name 
void search_by_name(string booker_name)
{
    cout << "Rooms booked by: " << booker_name << endl;

    // loop through the rooms 
    for (int i = 0; i < ROOMS_COUNT; i++)
    {
        // check if a match booker name matches the name passed to function
        if (hotel_rooms[i].booker_name == booker_name)
        {
            // print the room details 
            print_reservation(i);
        }
    }
}

// function to generate and print a bill for customer
void print_bill(int room_index)
{
    
    int price, total_price;

    // if room is double price is 150
    if (hotel_rooms[room_index].is_double)
        price = 150;

    // if room is single bed price is 100
    else
        price = 100;

    // total price is price of the room per night multiplied by number of stays 
    total_price = price * hotel_rooms[room_index].night_stays;

    // print the bill
    cout << "\nBill:" << endl; 
    cout << "Amount to pay: " << total_price  << endl;
    cout << "------------------------------------------" << endl;

}