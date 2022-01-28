# Telecom
Greeting to the reader!!

Our Project Of "Telecom Billing Management System" uses singly linked list data structure to create a database of our users and implements file handling to permanently store the data.
The program must be run in code::blocks on a windows OS for error-free execution as certain inbuilt functions used, differ on various operating systems.

The following steps should be followed for the successful execution of the project:

i) Unzip the "CSD201_PROJECT" folder in the documents folder of the pc.

ii) The folder contains 5 files including this "ReadMe" text:
    a)"Telecom_Final.c"  -containing the program code.
    b)"Telecom_Final.h"  -containing the user-defined struct "user" and functions used.
    c)"users.bin"        -containing the objects of struct "user" in binary format i.e. the permanent database.
    d)"ReadMe.txt"       -containing stepwise procedure for program execution.
    e)"AboutProgram.pdf" -containing information about the program.

iii) Open "Telecom_Final.c" using code::blocks.

iv) Since we are permanently storing data in "users.bin", the path/address of "users.bin" must be specified in lines 32 and 74 of the code in code::blocks. The address that you see in lines 32 and 74 is the address of the file "users.bin" in my pc. You need to replace that address with the address of "users.bin" in your pc. 
To do this, open the folder "CSD201_PROJECT" in documents. At the top you would see an address bar of the format "This PC > Documents > CSD201_PROJECT". Right click on it and select "copy address as text". Now when you paste this text in lines 32 and 74 in place of "C:\\Users\\hp\\Documents\\CSD201_PROJECT\\users.bin", it would appear as "C:\Users\hp\Documents\CSD201_PROJECT". Now, you need to replace the single backslash( \ ) with double backslash( \\ ) and type "\\users.bin" after "CSD201_PROJECT".

v) Once you are done with step (iv), now simply compile and run the program. You will encounter a "Welcome" screen followed by a "login" screen. Login details are as follows:
User ID: Employee1
Password: telecom123
On inputting the id and password you will encounter the "Main Menu" screen from where you may access the functions and perform various tasks. An advice for the reader, start from "Add  Records" to better understand the program.
You can perform any task mentioned in the "Main Menu" by simply inputting the serial no. of the task you wish to perform.
The following tasks can be performed:
1) Add Records- Simply input the details of the user and the record would be added.
2) Delete Records- Input the phone no. of the record you wish to delete and if the record is present, it would be deleted.
3) Display All Records- It would display the records of all the users existing in the linked list.
4) Modify Records- Enter the phone no. of the records you wish to modify and if the record is available, you can input new details in the record. Please note that in case the record is of postpaid type, you cannot edit the details unless the pending amount is settled which can be done using "Bills and Payments" option in "Main Menu".
5) Search Records- Input the phone no. of the record you wish to search and if it exists, it will be displayed.
6) Bills and Payments- You can print the bill and settle payments for postpaid users having pending amount. In case of prepaid users, the amount is already paid so only the bill is printed.
7) Avail services- you can recharge phone nos. using this option. In case of postpaid users with pending amounts, the previous amount needs to be settled in order to avail further services.
8) Delete Database- Deletes the records of all the users. Be careful with this function!
9) Exit- Terminates and exits from the program.   

vi) For your convenience, we have already stored the data of 4 users( the students in our group ) in "users.bin".

vii) Again, if at any given point you feel confused or stuck, feel free to contact the above mentioned person.

This is a fully functional program, so go through all the various options and explore the software thoroughly.

Enjoy!! 
