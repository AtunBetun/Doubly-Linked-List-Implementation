# Doubly-Linked-List-Implementation
Programming II Object Oriented Programming
          Final Assignment: Develop a linkedlist.cpp implementation of a doubly linked list with dummy header and tail. The linked list will store statistical information concerning a survey on whether people believe whether “Cheese Cake” is a pie or cake. 
          
Functions Implemented:
          Empty()
          Size() - How many records are contained
          Find() - Find a specific record
          Insert() - Insert a node
          Delete() - Delete a node
          Print() - Print to standard output
          List() - List the current record to standard output
          CountPie() - Count the number of records that believe it is a Pie
          CountCake()- Count the number of records that believe it is a Cake
  
  
The file will contain an undisclosed number of records that contain the following fields, each
separated by at least one space.
a. id - An integer number that is unique for each person.
b. Last Name – Will not contain spaces or special characters.
c. First Name – Will not contain spaces or special characters.
d. Middle initial – A single Alphabetic character
e. Sex – A single Alphabetic character either M for Male, F for Female, O for Other
f. PIe or Cake – A single Alphabetic character C if the person believes Cheese Cake is a
Cake or P if the person believes that Cheese Cake is a Pie.
2. You will implement a doubly-linked list ( pointing to the previous and next record) with a
dummy head and tail.
a. The Head will have the last name with all blanks.
b. The Tail will have the last name with 25 upper case Z’s
c. An empty list will the the head->next point to the tail.
3. The linked list will be ordered alphabetically by last name.
4. The class that you provide (LinkedList) will be used to store and retrieve information and must
comply with the specifications within this document.
5. The main routine will be responsible for the following steps: (an example will be provided)
a. Ask for a file to be opened and be persistent in asking for a valid file.
b. Open the file and read the records, and (one at a time) add each record to the linked
list.
c. Print the report alphabetically to standard output using the List() and Print() member
functions.
d. Count the number of those who think that Cheese Cake is a Pie
e. Count the number of those who think that Cheese Cake is a Cake
f. Find a specific Record to test this function.
g. Look for a record that does not exist
h. Delete a records to test this function
6. Member Function specifications:
a. LinkList();
i. Constructor, Creates an empty link list with a dummy head and tail, sets the
count to zero. head->next points to tail->prev point to head.
b. ~LinkList();
i. Destructor, deletes the list, one record at a time and sets counter to zero.
c. bool Empty();
i. Returns true if the head->next of the list points to the tail
d. int Size();
i. Returns the number of records.
e. bool Find(const int index);
i. Finds the record with an id that matches the number past in with index. Sets the
current pointer to that record. Returns true if found, false otherwise.
f. void Insert( PieCake_struct * p);
i. Inserts the past in record alphabetically into the list by last name.
g. bool Delete();
i. Deletes the record at the current pointer. Must use Find() first.
h. void Print();
i. Prints the report. Uses List(), CountPie(), and CountCake() methods. See the
example output. 
COP3330 Programming II Object Oriented Programming
COP3330 Page 3
i. void List();
i. Prints the current record to standard output.
j. int CountPIe();
i. Counts the records where the person thought Cheesecake is Pie.
k. int CountCake();
i. Counts the records where the person thought Cheesecake is Cake. 
