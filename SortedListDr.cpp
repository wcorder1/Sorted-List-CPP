
// Test driver for the Sorted Linked List
#include <iostream>
#include <fstream>
#include <string>
#include "SortedList.cpp"
using namespace std;
void testIntegersList();
void testStudentsList();
int main()
{
	
int datatype;
// Prompt user to enter type of elements 
cout<< "Enter Elements Type\n1 for integer\n2 for Student\n";
cin>> datatype;
switch (datatype)
{ case 1: testIntegersList();
          break;
  case 2: 
        testStudentsList();
     break;
 }
return 0;
}


void testIntegersList()
{
	SortedList<int> list;
	string command;
	ifstream inFile;
	ofstream outFile;
	inFile.open("intcommands.txt");
	outFile.open("outFile.txt");
	int number;

	inFile >> command; // read commands from a text file
	while (command != "Quit")
	{
		try

		{

			if (command == "IsEmpty")
			{	outFile << "Testing isEmpty():\n";
				if (list.isEmpty())
				{
					outFile << "list is empty\n";

				}
				else
					outFile << "list is not empty\n";
			}
			else if (command == "PutItem")
			{
				inFile >> number;
				outFile << "Testing putItem("<<number<<"):\n";
				list.putItem(number);
			}
			else if (command == "DeleteItem")
			{
				inFile >> number;
				outFile << "Testing deleteItem(" << number << "):\n";

				list.deleteItem(number);
			}

			else if (command == "IsFull")
			{
				outFile << "Testing isFull():\n";

				if (list.isFull())
					outFile << "List is full\n";
				else
					outFile << "List is not full\n";
			}
			else if (command == "GetLength")
			{
				outFile << "Testing getLenth():\n";
				outFile << list.getLength() << "\n";
			}
			else if (command == "PrintList")
			{
				outFile << "Printing the list:\n";
				list.printList(outFile);
				outFile << "\n";
			}
			else
				if (command == "MakeEmpty")
				{
					outFile << "Testing makeEmpty():\n";
					list.makeEmpty();
				}
				else if (command == "GetAt")
				{
					inFile >> number;
					
					outFile << "Testing getAT(" << number << "):\n";
					outFile << "Value stored in node " << number << " is " << list.getAt(number) << "\n";

				}
				else if (command == "Merge")
				{
					outFile << "TESTING MERGE:\n";
					// define and initialize two sorted lists
					SortedList<int> list1;
					SortedList<int> list2;
					//Test case 1: Merge two empty lists
					list1.merge(list2);
					outFile << "Test case 1: Merging two empty lists\n";
					outFile << "Expected output: Both lists are empty\n";
					outFile << "list1 after merge: ";
					list1.printList(outFile); // expected: no items will be printed
					outFile << "list2 after merge: ";
					list2.printList(outFile); // expected: no items will be printed

					// test case 2: merge an empty list with a non empty list;
					outFile << "\nTest case 2: merging the empty list with 10->20->30->40 \n";
					list1.makeEmpty();
					list2.makeEmpty();
					//add items to list2
					list2.putItem(40);
					list2.putItem(20);
					list2.putItem(30);
					list2.putItem(10);
					// call merge
					list1.merge(list2);

					outFile << "expected output 10 -> 20 -> 30 -> 40\n";
					outFile << "Actual output:\n";
					outFile << "List1 after the merge\n";
					list1.printList(outFile);
					outFile << "List2 after the merge, Expected empty.\n";
					list2.printList(outFile);

					// Test case 3: Merge a none-empty list with an empty list;
					SortedList<int> list3;
					SortedList<int> list4;
					//add items to list1
					list3.putItem(40);
					list3.putItem(10);
					list3.putItem(20);
					list3.putItem(30);

					outFile << "\nTest case 3: Output of merging 10->20->30->40 with an empty list \n";
					outFile << "expected output 10-> 20 -> 30 -> 40\n";
					list3.merge(list4);
					outFile << "Actual output:\n";
					outFile << "list after the merge\n";
					list3.printList(outFile);
					outFile << "Other list after the merge, Expected empty.\n";
					outFile << "other list Actual\n";
					list4.printList(outFile);

					//Test case 4: Merge two none-empty lists, initially they have distinct items;
					SortedList<int> list5;
					SortedList<int> list6;
					//add items to list5
					list5.putItem(20);
					list5.putItem(40);
					list5.putItem(50);

					//add items to list6
					list6.putItem(10);
					list6.putItem(30);
					list6.putItem(60);
					list6.putItem(70);
					// call merge
					list5.merge(list6);
					outFile << "\nTest case 4: Output of merging two lists 20->40->50 WITH 10->30->60->70\n";
					outFile << "expected output 10->20->30->40->50->60->70->NULL\n";
					outFile << "Actual output:\n";
					outFile << "List after the merge\n";
					list5.printList(outFile);
					outFile << "Other list after the merge, expected empty\n";
					list6.printList(outFile);
				
					//Test case 5: Merge two lists and remove duplicates, lists with common items
					SortedList<int> list7;
					SortedList<int> list8;
					//add items to list1
					list7.putItem(20);
					list7.putItem(40);
					list7.putItem(50);

					//add items to list2
					list8.putItem(10);
					list8.putItem(20);
					list8.putItem(30);
					list8.putItem(40);
					list8.putItem(50);
					// call merge
					list7.merge(list8);
					outFile << "\nTest case 5: Remove Duplicates test, Output of merging two lists 20->40->50 WITH 10->20->30->40->50\n";
					outFile << "expected output 10->20->30->40->50->NULL\n";
					outFile << "Actual output:\n";
					outFile << "List after the merge\n";
					list7.printList(outFile);
					outFile << "Other list after the merge\n";
					list8.printList(outFile);
                                 
				}// endof test merge
					inFile >> command;
					
				} // try

			catch (FullList)
			{
				outFile << "List is full. FullList exception thrown." << endl;
				inFile >> command;
			}

			catch (EmptyList)
			{
				outFile << "List is empty. EmtpyList exception thrown." << endl;
				inFile >> command;
			}

			catch (DuplicateItem)
			{
				outFile << "Putting item failed. DuplicateItem exception thrown." << endl;
				inFile >> command;
			}

		catch (DeletingMissingItem)
			{
				outFile << "Item to be deleted is not in the list. Exception thrown." << endl;
				inFile >> command;
			}
		catch (OutOfBound)
		{
			outFile << "index is out of range. Exception thrown." << endl;
			inFile >> command;
		}

		} // while
	} // testIntegersList


void testStudentsList()
{
// If you are implementing the bonus
//add code like in testIntegerslist and
	//SUBMIT your Driver
}

