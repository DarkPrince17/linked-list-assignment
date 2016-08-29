
//*******************************************************************
//  LinkedList.h
//  Assignment #1
//  Name:
//  ASU Email Address:
//  Created by Aniketh Sukhtankar on August 29, 2016.
//  This header file contains the LinkedList class declarations.
//*******************************************************************

#include <iostream> //to use cout
#include <iomanip> //to format output
#include <string> //to use strings
#include <stdlib.h>

using namespace std;

//struct Country represents some country information
struct Country
{
    string name;
    int gold;
    int silver;
    int bronze;
    struct Country * next;
};

//class LinkedList will contains a linked list of countries
class LinkedList
{
    private:
        struct Country * head;

    public:
        LinkedList();
        ~LinkedList();
        bool addCountry(string countryName, int gold, int silver, int bronze);
        bool removeCountry(string countryName);
        bool changeMedalCount(string countryName, string medal, int count);
        void printList();
};

//Constructor to initialize the linked list
LinkedList::LinkedList()
{
    head = NULL;
}

// Destructor de-allocates memory used by the list.

LinkedList::~LinkedList()
{
     Country * p = head;
     Country * q = head;
    while (q)
    {
        p = q;
        q = p -> next;
        if (q) delete p;
    }
}

/* function to insert a new_country in a list. Shell Note that this
  function uses memory allocation (malloc) to assign memory for the new node
  I have also included the stdlib.h header file so the program can use the malloc function*/

bool LinkedList::addCountry(string newName, int gold, int silver, int bronze)
 {
    struct Country** head_ref = &head;
    /* allocate node */
    struct Country* new_node = (struct Country*) malloc(sizeof(struct Country));

    /* put in the data  */
    new_node->name  = newName;
    new_node->gold  = gold;
    new_node->silver  = silver;
    new_node->bronze  = bronze;
    new_node->next =  NULL;

    struct Country* current;
    /* Special case for the head end */
    if (*head_ref == NULL || (*head_ref)->name >= new_node->name)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return true;
    }
    else
    {
        /* Locate the node before the point of insertion */
        current = *head_ref;
        while (current->next!=NULL &&
               current->next->name < new_node->name)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
        return true;
    }

 }

// Function removes a country node by searching for it and finding its position in the linked list.
// Returns true if the operation is successful.

bool LinkedList::removeCountry(string someName)
 {
    struct Country* temp1 = (struct Country*) malloc(sizeof(struct Country));  // allocate space for node
    temp1 = head;                  // transfer the address of 'head' to 'temp1'

    struct Country* old_temp = (struct Country*) malloc(sizeof(struct Country)); // allocate space for node
    old_temp = temp1;       // transfer the address of 'temp1' to 'old_temp'

    while( temp1!=NULL )
    {
         if(temp1->name == someName)
         {
            if(old_temp = temp1) // For when the country is located right at the start
                {
                    head = temp1->next;
                    free(temp1);
                    return true;
                }
            old_temp->next = temp1->next;  // transfer the address of 'temp1->next' to 'old_temp->next'
            free(temp1);
            return true;
         }
         old_temp = temp1;                    // store previous node
         temp1 = temp1->next;                 // store current node
    }
 }


bool LinkedList::changeMedalCount(string countryName, string medalType, int count)
{
    struct Country* temp1 = (struct Country*) malloc(sizeof(struct Country));  // allocate space for node
    temp1 = head;                  // transfer the address of 'head' to 'temp1'
    while( temp1!=NULL )
    {
         if(temp1->name == countryName)
         {
            if(medalType == "gold")
                {
                   temp1->gold = count;
                   return true;
                }
            else if(medalType == "silver")
                {
                   temp1->silver = count;
                   return true;
                }
            else if(medalType == "bronze")
                {
                   temp1->bronze = count;
                   return true;
                }
            else
                {
                    return false;
                }

         }
         else
            {
                return false;
            }
         temp1 = temp1->next;                 // store current node
    }
}

// Prints each country node in the list in consecutive order,
// starting at the head and ending at the tail.
// Prints the data to the console.

void LinkedList::printList()
{
    const char separator    = ' ';
    const int numWidth      = 14;
    struct Country *temp = head;

    cout << left << setw(numWidth) << setfill(separator) << "Country";
    cout << left << setw(numWidth) << setfill(separator) << "Gold";
    cout << left << setw(numWidth) << setfill(separator) << "Silver";
    cout << left << setw(numWidth) << setfill(separator) << "Bronze";
    cout << endl;

    while(temp != NULL)
    {
        cout << left << setw(numWidth) << setfill(separator) << temp->name;
        cout << left << setw(numWidth) << setfill(separator) << temp->gold;
        cout << left << setw(numWidth) << setfill(separator) << temp->silver;
        cout << left << setw(numWidth) << setfill(separator) << temp->bronze;
        cout << endl;
        temp = temp->next;
    }
}

