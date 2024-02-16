# Hotelbooker
This hotelroom booker was developed by me using C++ in Visual Studio

## How it works?
When opening reservation system program welcomes user and shows the menu where user 
can choose to register a room, search room by booking number, search room by name of 
the booker or exit the program (I included this last option so user can use the program as 
long as they want). Also if user presses for example 6, program tells that choice isn’t valid. 

If user wants to book a room program asks if they want single or double room(1 or 2) if user 
presses another number selection wont register and program asks user to select again. If 
user wants single room program checks if there are any available. If there is program calls 
function to register the room. Functions asks name and how many nights will they be 
spending.  

When these are done program tells user that the rooms is booked and shows the booking 
details(ID,room number, name of the booker, room type and nights) with different function 
and how much they have to pay with another function. All these same thing happen if user 
chooses double room. 

Options 2 and 3 search by booking number and search by name of the booker are simple for 
loops that check entered id or name from all the rooms and prints out rooms that are 
reserved with that.  

This program uses 5 functions besides main function. I have used both structures and arrays 
to store data. I have commented throughout the code so that everyone could understand 
what my code does
