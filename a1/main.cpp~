#include <fstream>          // Include to use ifstream
#include "ll.h"             // Include so can access our class
using namespace std;        // Include so we don't need to put std:: infront
                            // of cout and endl

int main()
{
	LL myList; //instance of linked list
	ifstream input;
	int cmd, argument, ret;
    node* searchResult = NULL;
	input.open("cmd.txt");

    // while there is something to read from the file, read
	while (input >> cmd)
	{
        // switch on the command we read from the file
		switch (cmd)
		{
        // if the cmd requires a parameter, read it from the file and call the 
        // associated function
		case 1:
			input >> argument;
			myList.prepend(argument);
            cout << "Prepended " << argument << endl;
			break;
		case 2:
			input >> argument;
			myList.append(argument);
            cout << "Apended " << argument << endl;
			break;
		case 3:
			if(myList.removeFront())
            {
                cout << "Succesfully removed the front of the list\n";
            }
            else
            {
                cout << "List is empty, nothing to remove\n";
            }
			break;
		case 4:
			if(myList.removeBack())
            {
                cout << "Succesfully removed the back of the list\n";
            }
            else
            {
                cout << "List is empty, nothing to remove\n";
            }
			break;
		case 5:
			input >> argument;
			searchResult = myList.search(argument);
			if(NULL != searchResult)
                cout << "Found " << searchResult->val <<" in list!"<<endl;
            else
                cout << "Did not find " << argument << " in the list"<<endl;
            break;
		case 6:
			myList.print();
			break;
        case 7:
            input >> argument;
            cout << "Attempting to remove " << argument << endl;
			if(myList.remove(argument))
            {
                cout << "Succesfully removed the element from the list\n";
            }
            else
            {
                cout << "Could not remove the element from the list\n";
            }
            break;
        }
	}
	input.close();

	return 0;
}
