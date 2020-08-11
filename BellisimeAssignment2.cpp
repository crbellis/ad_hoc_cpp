/*
This program takes in 15 names and weights and places them in a doubly linked list. The weights and names are sorted as they are inserted into the list. The names and list are printed (in main) 
after each pair is entered. The doubly linked list is set up to first update the name pointers and then update the weight pointers
*/

#include<iostream>
#include<string>

using namespace std;

//Node class definition. Node class has two data members that store data and two data members that point to the next node.
class Node { 
    public:
        string name;
        int weight;
        Node *nextWeight;
        Node *nextName;
        Node(string uName, int uWeight, Node *nxtWeight = 0, Node *nxtName = 0);
};

//Node class constructor
Node::Node(string uName, int uWeight, Node *nxtWeight, Node *nxtName) {
    name = uName;
    weight = uWeight;
    nextWeight = nxtWeight;
    nextName = nxtName;
}

//Doubly linked list class definition. Two private data members to keep track of the front of the weights and front of the names
class dlList {
    private:
        Node *weightFront;
        Node *nameFront;
    public:
        dlList();
        ~dlList();
        bool isEmpty();
        void insert(string uName, int uWeight);
        void print(string sortType = "Name");
};

//Default constructor for doubly linked list
dlList::dlList() {
    weightFront = nameFront = 0;
}

//Deconstructor for doubly linked list
dlList::~dlList() {
    for (Node *p; !isEmpty(); )  {
        p = nameFront->nextName;
        delete nameFront;
        nameFront = p;
    }
    for (Node *p; !isEmpty(); )  {
        p = weightFront->nextWeight;
        delete weightFront;
        weightFront = p;
    }
}

//Doubly linked list method that checks if the list is empty
bool dlList::isEmpty() {
    return nameFront == 0;
}

//Doubly linked list to insert name and weight into list in sorted order
void dlList::insert(string uName, int uWeight) {
    //create the new node and a temp node pointing to the front of the names list
    Node *newNode = new Node(uName, uWeight);
    Node *temp = nameFront;

    //If first node is null then nameFront and weightFront are both updated to point at the newNode
    if (nameFront == 0) {
        nameFront = weightFront = newNode;
        return;
    }
    
    //Loop through list until the nextName name value is less than the uName, then update temp to the current node
    while (temp->nextName != 0 && temp->nextName->name < uName) {
        temp = temp->nextName;
    }

    //Checks to see if there is one node in the list, this if statement then updates the weight and name pointers
    if (nameFront == weightFront && (weightFront->nextWeight == 0 || nameFront->nextName == 0)) {
        //If uName is less than the name data member of current node
        if (uName <= temp->name) {
            //Update the pointer of newNode to point at the front then update the front of the list to point at the newNode
            newNode->nextName = nameFront;
            nameFront = newNode;
        }
        //Places he new node to after the first node
        else {
            nameFront->nextName = newNode;
        }
        //Places new node to the left of the current/temp node
        if (uWeight <= temp->weight) {
            newNode->nextWeight = weightFront;
            weightFront = newNode;
        }
        //Since this is in the test condition for the first node, if the weight is greater than the front of the list, it can be the next weight in the list
        else {
            weightFront->nextWeight = newNode;
        }
        return;
    }

    //Checks to see if the front of the names list has a name value less than the current input
    else if (temp == nameFront && temp->name > uName) {
        newNode->nextName = nameFront;
        nameFront = newNode;
    }

    //Middle case for name value
    else {
        if (temp->name < uName && temp->nextName->name > uName) {
            newNode->nextName = temp->nextName;
            temp->nextName = newNode;
        }
    }
    
    //This section inserts the weight input into the linked list. NOTE: case for the first node in a list is handled above

    //Set temp to the front of the weight list
    temp = weightFront;

    //Loops through the weight list until a value is found less than the current weight input
    while (temp->nextWeight != 0 && temp->nextWeight->weight < uWeight) {
        temp = temp->nextWeight;
    }

    //If the front of the weights list is greater than the weight input then move the weight into the front of the list
    if (temp == weightFront && temp->weight >= uWeight) {
        newNode->nextWeight = weightFront;
        weightFront = newNode;
        return;
    }
    //Middle case for weights, places the new weight value in between two nodes
    else {
        if(temp->weight < uWeight && temp->nextWeight->weight >= uWeight) {
            newNode->nextWeight = temp->nextWeight;
            temp->nextWeight = newNode;
            return;
        }
    }
}

//Class method to print the values of the list. Takes a string argument to choose which value is sorted. "Name" is default argument. Pass "Weight" as an argument to sort by weights
void dlList::print(string sortType) {
    //Sorting by name
    if (sortType == "Name") {
        for (Node *temp = nameFront; temp != 0; temp = temp->nextName) {
            if (temp->nextName != 0) {
                cout << temp->name << "-" << temp->weight << ", ";
            }
            else {
                cout << temp->name << "-" << temp->weight;
            }
        }
    }
    //Sorting by weight
    if (sortType == "Weight") {
        for (Node *temp = weightFront; temp != 0; temp = temp->nextWeight) {
            if (temp->nextName != 0) {
                cout << temp->name << "-" << temp->weight << ", ";
            }
            else {
                cout << temp->name << "-" << temp->weight;
            }
        }
    }
    cout << endl;
    return;
}

int main() {
    dlList peopleList;
    string name;
    int weight;
    for (int i = 0; i < 15; i++) {
        cout << "Insert name: ";
        getline(cin, name);
        cout << "Insert weight: ";
        cin >> weight;
        cin.ignore();
        peopleList.insert(name, weight);
        cout << "Names & weights sorted(ascending) by name: ";
        peopleList.print();
        cout << "Names & weights sorted(ascending) by weight: ";
        peopleList.print("Weight");
    }
    return 0;
}
/*
Sample output (after all input has been entered):
Insert name: Jim 
Insert weight: 150
Names & weights sorted(ascending) by name: Jim-150
Names & weights sorted(ascending) by weight: Jim-150
Insert name: Tom
Insert weight: 212
Names & weights sorted(ascending) by name: Jim-150, Tom-212
Names & weights sorted(ascending) by weight: Jim-150, Tom-212
Insert name: Michael
Insert weight: 174
Names & weights sorted(ascending) by name: Jim-150, Michael-174, Tom-212
Names & weights sorted(ascending) by weight: Jim-150, Michael-174, Tom-212
Insert name: Abe
Insert weight: 199
Names & weights sorted(ascending) by name: Abe-199, Jim-150, Michael-174, Tom-212
Names & weights sorted(ascending) by weight: Jim-150, Michael-174, Abe-199, Tom-212
Insert name: Richard
Insert weight: 200
Names & weights sorted(ascending) by name: Abe-199, Jim-150, Michael-174, Richard-200, Tom-212
Names & weights sorted(ascending) by weight: Jim-150, Michael-174, Abe-199, Richard-200, Tom-212
Insert name: April
Insert weight: 117
Names & weights sorted(ascending) by name: Abe-199, April-117, Jim-150, Michael-174, Richard-200, Tom-212
Names & weights sorted(ascending) by weight: April-117, Jim-150, Michael-174, Abe-199, Richard-200, Tom-212
Insert name: Claire
Insert weight: 124
Names & weights sorted(ascending) by name: Abe-199, April-117, Claire-124, Jim-150, Michael-174, Richard-200, Tom-212
Names & weights sorted(ascending) by weight: April-117, Claire-124, Jim-150, Michael-174, Abe-199, Richard-200, Tom-212
Insert name: Bobby
Insert weight: 109
Names & weights sorted(ascending) by name: Abe-199, April-117, Bobby-109, Claire-124, Jim-150, Michael-174, Richard-200, Tom-212
Names & weights sorted(ascending) by weight: Bobby-109, April-117, Claire-124, Jim-150, Michael-174, Abe-199, Richard-200, Tom-212
Insert name: Bob
Insert weight: 156
Names & weights sorted(ascending) by name: Abe-199, April-117, Bob-156, Bobby-109, Claire-124, Jim-150, Michael-174, Richard-200, Tom-212
Names & weights sorted(ascending) by weight: Bobby-109, April-117, Claire-124, Jim-150, Bob-156, Michael-174, Abe-199, Richard-200, Tom-212
Insert name: Kevin
Insert weight: 145
Names & weights sorted(ascending) by name: Abe-199, April-117, Bob-156, Bobby-109, Claire-124, Jim-150, Kevin-145, Michael-174, Richard-200, Tom-212
Names & weights sorted(ascending) by weight: Bobby-109, April-117, Claire-124, Kevin-145, Jim-150, Bob-156, Michael-174, Abe-199, Richard-200, Tom-212
Insert name: Jason
Insert weight: 182
Names & weights sorted(ascending) by name: Abe-199, April-117, Bob-156, Bobby-109, Claire-124, Jason-182, Jim-150, Kevin-145, Michael-174, Richard-200, Tom-212
Names & weights sorted(ascending) by weight: Bobby-109, April-117, Claire-124, Kevin-145, Jim-150, Bob-156, Michael-174, Jason-182, Abe-199, Richard-200, Tom-212
Insert name: Brian
Insert weight: 150
Names & weights sorted(ascending) by name: Abe-199, April-117, Bob-156, Bobby-109, Brian-150, Claire-124, Jason-182, Jim-150, Kevin-145, Michael-174, Richard-200, Tom-212
Names & weights sorted(ascending) by weight: Bobby-109, April-117, Claire-124, Kevin-145, Brian-150, Jim-150, Bob-156, Michael-174, Jason-182, Abe-199, Richard-200, Tom-212
Insert name: Chris
Insert weight: 175
Names & weights sorted(ascending) by name: Abe-199, April-117, Bob-156, Bobby-109, Brian-150, Chris-175, Claire-124, Jason-182, Jim-150, Kevin-145, Michael-174, Richard-200, Tom-212
Names & weights sorted(ascending) by weight: Bobby-109, April-117, Claire-124, Kevin-145, Brian-150, Jim-150, Bob-156, Michael-174, Chris-175, Jason-182, Abe-199, Richard-200, Tom-212
Insert name: Steven
Insert weight: 164
Names & weights sorted(ascending) by name: Abe-199, April-117, Bob-156, Bobby-109, Brian-150, Chris-175, Claire-124, Jason-182, Jim-150, Kevin-145, Michael-174, Richard-200, Steven-164, Tom-212
Names & weights sorted(ascending) by weight: Bobby-109, April-117, Claire-124, Kevin-145, Brian-150, Jim-150, Bob-156, Steven-164, Michael-174, Chris-175, Jason-182, Abe-199, Richard-200, Tom-212
Insert name: Annabelle
Insert weight: 99
Names & weights sorted(ascending) by name: Abe-199, Annabelle-99, April-117, Bob-156, Bobby-109, Brian-150, Chris-175, Claire-124, Jason-182, Jim-150, Kevin-145, Michael-174, Richard-200, Steven-164, Tom-212
Names & weights sorted(ascending) by weight: Annabelle-99, Bobby-109, April-117, Claire-124, Kevin-145, Brian-150, Jim-150, Bob-156, Steven-164, Michael-174, Chris-175, Jason-182, Abe-199, Richard-200, Tom-212
*/