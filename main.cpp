#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
typedef long long ll;
const int mod = 1000000007;
#define deb(x) cerr << #x << " is " << x << endl;
#define IOS ios:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(a) a.begin(), a.end()
using namespace std;

struct Room {
    int number;
    bool occupied;
    Room* next;
    Room* prev;
};

void insertRoom(Room*& head, Room*& tail, int number, bool occupied){
    Room* newRoom = new Room;
    newRoom->number = number;
    newRoom->occupied = occupied;
    newRoom->next = nullptr;
    newRoom->prev = nullptr;

    if (head == nullptr) {
        head = newRoom;
        tail = newRoom;
    } else {
        // Link the new node to the end of the list and update tail
        tail->next = newRoom;
        newRoom->prev = tail;
        tail = newRoom; // Update tail to point to the new last node
    }
}

void replaceNearestLeftZero(Room* head) {
    if (head == nullptr) {
        return;
    }

    Room* current = head;
    while (current != nullptr) {
        if (current->occupied == false) { // Encontramos un 0
            current->occupied = true; // Cambiamos el 0 por un 1
            break; // Salimos del bucle, ya hemos hecho el cambio
        }
        current = current->next;
    }
}

void replaceNearestRightZero(Room* tail) {
    Room* current = tail; // Comenzamos desde la cola (tail) y avanzamos hacia la cabeza (head)
    Room* nearestZero = nullptr; // Pista al nodo con el 0 más cercano

   while (current != nullptr) {
        if (current->occupied == false) { // Encontramos un 0
            current->occupied = true; // Cambiamos el 0 por un 1
            break; // Salimos del bucle, ya hemos hecho el cambio
        }
        current = current->prev;
    }

}

void replaceWithNumber(Room* head, int roomNumber) {
    Room* current = head;
    while (current != nullptr) {
        if (current->number == roomNumber) { 
            current->occupied = false; // Cambiamos el 0 por un 1
            break; // Salimos del bucle, ya hemos hecho el cambio
        }
        current = current->next;
    }

}

int main() {
     IOS;
            #ifndef ONLINE_JUDGE
                freopen("input.txt", "r", stdin);
                freopen("solution.txt", "w", stdout);
            #endif
 
    int input_actions; cin >> input_actions;
    string input_string; cin >> input_string;

    Room* head = nullptr;
    Room* tail = nullptr;

    for(int i = 0; i <= 9; i++)
    {
        insertRoom(head, tail,i, false);
    }
    

   for (int i = 0; i < input_actions; i++) {
    char value = input_string[i]; // Use char to store a single character
    if (value == 'L') {
        replaceNearestLeftZero(head);
    } else if (value == 'R') {
        replaceNearestRightZero(tail);
    } else { if (isdigit(value)) {
            int habitacion = value - '0'; // Convierte el carácter en un entero
            replaceWithNumber(head, habitacion);
        } 
    }   
}


    Room* current = head;
    while (current != nullptr) {
        cout << current->occupied;  // << " -> ";
        current = current->next;
    }
    //cout << "nullptr" << endl;


    while (head != nullptr) {
        Room* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
