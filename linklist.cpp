//
// Created by betod on 4/27/2020.
//
#include "linklist.h"
#include <iostream>
using namespace std;
// * Function Name: LinkList Default Constructor
// * Description: Constructor, Creates an empty link list with a dummy head and tail, sets the
//count to zero. head->next points to tail->prev point to head.
// * Parameter Description: none
// * Date: 4/27/2020
// * Author: Alberto De Saint Malo
// * References: Professor Gaitros
LinkList::LinkList() {
    count = 0;
    tail = new PieCake_struct;
    head = new PieCake_struct;
    head -> prev = nullptr;
    head -> next = tail;
    head -> lname = "            ";
    tail -> prev = head;
    tail -> next = nullptr;
    tail -> lname = "ZZZZZZZZZZZZZZZZZZZZZZZZZ";
    current = nullptr;
}
// * Function Name: LinkList Destructor
// * Description: Destructor, deletes the list, one record at a time and sets counter to zero.
// * Parameter Description: none
// * Date: 4/27/2020
// * Author: Alberto De Saint Malo
// * References: Professor Gaitros
LinkList::~LinkList() {
    PieCake_struct* search;
    search = head->next;
    while(search != tail){
        current = search;
        search = search -> next;
        delete current;
    }
    delete tail;
    delete current;
    delete head;
    count = 0;
}
// * Function Name: Empty
// * Description: Returns true if the head->next of the list points to the tail
// * Parameter Description: none
// * Date: 4/27/2020
// * Author: Alberto De Saint Malo
// * References: Professor Gaitros
bool LinkList::Empty() {
    if (head -> next == tail){
        return true;
    }
    else {
        return false;
    }
}
// * Function Name: Size
// * Description: Returns the number of records.
// * Parameter Description: none
// * Date: 4/27/2020
// * Author: Alberto De Saint Malo
// * References: Professor Gaitros
int LinkList::Size() {
    PieCake_struct* dumm;
    int counter = 0;
    dumm = head -> next;
    while (dumm != tail) {
        counter++;
        dumm = dumm -> next;
    }
    return counter;
}
// * Function Name: Find
// * Description: Finds the record with an id that matches the number past in with index. Sets the
//current pointer to that record. Returns true if found, false otherwise
// * Parameter Description: idnumber: the number of the id
// * Date: 4/27/2020
// * Author: Alberto De Saint Malo
// * References: Professor Gaitros
bool LinkList::Find(const int idnumber) {
    if (Empty()){
        return false;
    }
    current = head -> next;
    while (current != tail){
        if (current->id == idnumber){
            return true;
        }
        current = current -> next;
    }
    current = nullptr;
    return false;
}
// * Function Name: Insert
// * Description: Inserts the past in record alphabetically into the list by last name.
// * Parameter Description: none
// * Date: 4/27/2020
// * Author: Alberto De Saint Malo
// * References: Professor Gaitros
void LinkList::Insert(PieCake_struct *p) {
    PieCake_struct* prev;
    count++;
    current = head -> next;
    while ((p -> lname) > (current -> lname)){
        current = current -> next;
    }
    prev = current -> prev;
    p -> next = current;
    p -> prev = prev;
    prev -> next = p;
    current -> prev = p;
}
// * Function Name: Delete
// * Description: Deletes the record at the current pointer. Must use Find() first.
// * Parameter Description: none
// * Date: 4/27/2020
// * Author: Alberto De Saint Malo
// * References: Professor Gaitros
bool LinkList::Delete() {
    count--;
    current -> prev -> next = current -> next;
    current -> next -> prev = current -> prev;
    delete current;
    return true;
}
// * Function Name: Print
// * Description: Prints the report. Uses List(), CountPie(), and CountCake() methods. See the
//example output.
// * Parameter Description: none
// * Date: 4/27/2020
// * Author: Alberto De Saint Malo
// * References: Professor Gaitros
void LinkList::Print() {
    cout << " The CheeseCake Survey  \n" <<
         "Id Last Name First Name MI Sex Pie/Cake \n" <<
         "-- ---- ---- ----- ---- -- --- --------\n";
    List();
    cout << "Total Surveyed: " << Size() << endl;
    CountPie();
    CountCake();
    cout << "People who thought Cheesecake was Pie:  " << CountPie() << endl;
    cout << "People who thought Cheesecake was Cake: " << CountCake() << endl;
}
// * Function Name: List
// * Description: Prints the current record to standard output
// * Parameter Description: none
// * Date: 4/27/2020
// * Author: Alberto De Saint Malo
// * References: Professor Gaitros
void LinkList::List() {
    string sex, PoC;
    if(Empty()) { cout << "Empty List" << endl; }
    current = head -> next;
    while(tail != current){
        if (current -> sex == 'F'){ sex = "Female"; }
        else { sex = "Male"; }
        if (current -> pORc == 'C'){ PoC = "Cake"; }
        else{ PoC = "Pie"; }
        cout << current->id << "     " << current->lname << "     "
        << current->fname << "     " << current->mi << "     "
        << sex << "    " << PoC << "\n";
        current = current -> next;
    }
}
// * Function Name: Countpie
// * Description: Counts the records where the person thought Cheesecake is Pie.
// * Parameter Description: none
// * Date: 4/27/2020
// * Author: Alberto De Saint Malo
// * References: Professor Gaitros
int LinkList::CountPie() {
    int pie = 0;
    current = head->next;
    if (Empty() == true){
        return false;
    }
    while (current != tail){
        if (current -> pORc == 'P'){
            pie++;
        }
        current = current -> next;
    }
    return pie;
}
// * Function Name: CountCake
// * Description: Counts the records where the person thought Cheesecake is Cake.
// * Parameter Description: none
// * Date: 4/27/2020
// * Author: Alberto De Saint Malo
// * References: Professor Gaitros
int LinkList::CountCake() {
    int cake = 0;
    current = head -> next;
    if (Empty()){
        return false;
    }
    while (current != tail){
        if (current->pORc == 'C'){
            cake++;
        }
        current = current->next;
    }
    return cake;
}



