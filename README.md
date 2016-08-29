# linked-list-assignment

Instructions
Write a C++ program that creates a linked list of Country data. Each entry in the list is to have a country name such as "United States", and its gold, silver, and bronze medal counts (three integers), and a pointer to the next country data. Then create a pointer (“head”) that points to the first element in the linked list (initially NULL). Also, you need to create the following methods in the LinkedList class (within LinkedList.h file):
 
 
bool LinkedList::addCountry(string countryName, int gold, int silver, int bronze) 
-          This method attempts to add a new country data into the linked list using the parameter values - country name, the number of gold medals, the number of silver medals, and the number of bronze medals. It needs to create an object/data of the struct Country and add it to the linked in a correct location. Each country should be added using their name in the alphabetical order. If there is no memory left to create a new object, the method should return false. The method should return true otherwise (the new country information was successfully added). 
-          
bool LinkedList::removeCountry(string countryName) 
-          This method attempts to remove the country with the parameter country name value and should return true if it can find and remove the country information. It should return false otherwise (the country with the name does not exists in the linked list). 
bool LinkedList::changeMedalCount(string countryName, string medal, int count) 
-          This method attempts to change the country with the parameter country name value with the parameter medal count and should return true if it can find and update the country information, by changing the corresponding medal count. The string parameter "medal" will be one of "gold", "silver", and "bronze"." It should return false otherwise (the country with the name does not exists in the linked list). 
-          
void LinkedList::printList( )
-           It prints all entries in the linked list in the following format (print "The list is empty\n" if the linked list is empty):
Country name: Hungary, Gold: 2, Silver: 3, Bronze: 0 
Country name: Italy, Gold: 2, Silver: 5, Bronze: 4 
Country name: South Korea, Gold: 3, Silver: 4, Bronze: 3 
Country name: United States, Gold: 3, Silver: 5, Bronze: 6 

Note that they are added using their country names in alphabetical order. 
 
LinkedList::~LinkedList( ) 
	- This is a destructor of the LinkedList class. It should remove all elements in the linked list and perform garbage collection (free their memory). At the end, it should print: "The number of deleted countries is: XXX\n" where XXX is the number of deleted countries in the linked list. 
 
 
int main()
	- The main function should start by displaying this menu in this format:
 
	Choice\t\t Action\n
	------\t\t ------\n
	A\t\t Add Country\n
	D\t\t Display Countries\n
            M\t\t Change Medal Count\n
	Q\t\t Quit\n
	R\t\t Remove Country\n
	? \t\t Display Help\n\n
 
 
 
Next, the following prompt should be displayed:
 
What action would you like to perform?\n
 
Read in the user input and execute the appropriate command. After the execution of each command, redisplay the prompt. Commands should be accepted in both lowercase and uppercase. 
The following is an example run (user input is in bold letter): 


Choice Action 
------ ------ 
A Add Country 
D Display Countries 
M Change Medal Count 
Q Quit 
R Remove Country 
? Display Help 


What action would you like to perform? 
A
Please enter some country information: 
Enter a country name: 
United States
Enter its number of gold medals: 
3
Enter its number of silver medals: 
5
Enter its number of bronze medals: 
4
The country United States added 


What action would you like to perform? 
D
Country name: United States, Gold: 3, Silver: 5, Bronze: 4 

What action would you like to perform? 
A
Please enter some country information: 
Enter a country name: 
China
Enter its number of gold medals: 
3
Enter its number of silver medals: 
2
Enter its number of bronze medals: 
3
The country China added 

What action would you like to perform? 
D
Country name: China, Gold: 3, Silver: 2, Bronze: 3 
Country name: United States, Gold: 3, Silver: 5, Bronze: 4 

What action would you like to perform? 
A
Please enter some country information: 
Enter a country name: 
Australia
Enter its number of gold medals: 
2
Enter its number of silver medals: 
0
Enter its number of bronze medals: 
3
The country Australia added 

What action would you like to perform? 
D
Country name: Australia, Gold: 2, Silver: 0, Bronze: 3 
Country name: China, Gold: 3, Silver: 2, Bronze: 3 
Country name: United States, Gold: 3, Silver: 5, Bronze: 4 

What action would you like to perform? 
M
Please enter a country to change its medal count: 
Hungary
Please enter a medal type (gold, silver, or bronze): 
bronze
Enter its new medal count: 
2
The country Hungary does not exist 

What action would you like to perform? 
D
Country name: Australia, Gold: 2, Silver: 0, Bronze: 3 
Country name: China, Gold: 3, Silver: 2, Bronze: 3 
Country name: United States, Gold: 3, Silver: 5, Bronze: 4 

What action would you like to perform? 
M
Please enter a country to change its medal count: 
Australia
Please enter a medal type (gold, silver, or bronze): 
gold
Enter its new medal count: 
3
The country Australia updated 

What action would you like to perform? 
D
Country name: Australia, Gold: 3, Silver: 0, Bronze: 3 
Country name: China, Gold: 3, Silver: 2, Bronze: 3 
Country name: United States, Gold: 3, Silver: 5, Bronze: 4 

What action would you like to perform? 
R
Please enter a country to remove: 
Russia
The country Russia does not exist 

What action would you like to perform? 
D
Country name: Australia, Gold: 3, Silver: 0, Bronze: 3 
Country name: China, Gold: 3, Silver: 2, Bronze: 3 
Country name: United States, Gold: 3, Silver: 5, Bronze: 4 

What action would you like to perform? 
R
Please enter a country to remove: 
United States
The country United States removed 

What action would you like to perform? 
D
Country name: Australia, Gold: 3, Silver: 0, Bronze: 3 
Country name: China, Gold: 3, Silver: 2, Bronze: 3 

What action would you like to perform? 
Q
The number of deleted countries is: 2 
 
 
Implementation/Documentation Requirements:
•	You need to implement this program using C++ and it has to read from the standard input (from a keyboard).
•	Your program needs to compile and execute in general.asu.edu.
•	You need to define addCountry, removeCountry, changeMedalCount, printList, the destructor methods of the LinkedList class 
•	Your code should be well documented and commented.
•	You must use the provided data sets. 
•	Also you are not allowed to use any predefined data structures (such as ones in the library, etc.) except arrays and strings, you need to build your own data structures and operations associated with them (such as add and remove).

