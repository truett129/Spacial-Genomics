#include <iostream>
#include <string>
#include <sstream>
#include "LinkedList.h"
#include "Node.h"
#include <cmath>

using std::cout;
using std::string;
using std::ostream;
using std::to_string;
using std::ostringstream;

LinkedList::LinkedList()
    : head(nullptr), tail(nullptr) {
	// Implement this function
}

LinkedList::~LinkedList() {
    clear();
	  // Implement this function
}

LinkedList::LinkedList(const LinkedList& source) {
    // Implement this function
    head = nullptr;
    tail = nullptr;
    Node* marker = source.head;
    while (!(marker == nullptr)) {
        Node* newNode = new Node(marker->data.id, marker->data.fov, marker->data.volume, marker->data.center_x, marker->data.center_y, marker->data.min_x, marker->data.max_x, marker->data.min_y, marker->data.max_y);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            tail->next = nullptr;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = nullptr;
        }
        marker = marker->next;
    }


}

LinkedList& LinkedList::operator=(const LinkedList& source) 
{

    clear();
    Node* marker = source.head;
    while (!(marker == nullptr)) {
        Node* newNode = new Node(marker->data.id, marker->data.fov, marker->data.volume, marker->data.center_x, marker->data.center_y, marker->data.min_x, marker->data.max_x, marker->data.min_y, marker->data.max_y);
        if (head == nullptr) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
        marker = marker->next;
    }
    return *this;
}

void LinkedList::insert(std::string id, int fov, double volume, double center_x, double center_y, double min_x, double max_x, double min_y, double max_y)
{
    Node* node = new Node(id, fov, volume, center_x, center_y, min_x, max_x, min_y, max_y);
    Node* marker = head;
    Node* prevNode = nullptr;
    if (marker == nullptr){
        head = node;
        tail = node;
    } else if (node->data < head->data) {
        node->next = head;
        head = node;
    } else {
        while(!(marker == nullptr)) {
            if (node->data < marker->data) {
                prevNode->next = node;
                node->next = marker;
                break;
            } 
            if (marker->next == nullptr) {
                marker->next = node;
                node->next = nullptr;
                tail = node;
            }

            prevNode = marker;
            marker = marker->next;

        }
    }
    

    // if marker is greater tha 
    //pttrev 2 nodes 
    // 
    
}

void LinkedList::remove(std::string id, int fov, double volume, double center_x, double center_y, double min_x, double max_x, double min_y, double max_y)
{
   Node* prev = nullptr;
   Node* marker = head;
    Node* node = new Node(id, fov, volume, center_x, center_y, min_x, max_x, min_y, max_y);

   while (!(marker == nullptr)) {
       if (marker->data == node->data) {
           break;
       }
       prev = marker;
       marker = marker->next;
   } 
   if(!(marker == nullptr)){
        if (marker->data == head->data && marker->data == tail->data) {
            head = nullptr;
            tail = nullptr;
        } else if (marker->data == head->data) {
            head = head->next;

        } else if (marker->data == tail->data) {
            prev->next = nullptr;
            tail = prev;
        } else {
            prev->next = marker->next;
            prev = nullptr;
        }
        marker->next = nullptr;

        delete marker;
        marker = nullptr;
   }

}


void LinkedList::clear() 
{	
    Node* marker = nullptr;
    while(!(head == nullptr)) {
        marker = head;
        head = head->next;
        marker->next = nullptr;
        delete marker;
    }
    head = nullptr;
    tail = nullptr;
    marker = nullptr;  
    // Implement this function
}

string LinkedList::print() const 
{
    ostringstream obj;
    Node* marker = head;
    string allNodes = "fov,volume,center_x,center_y,min_x,max_x,min_y,max_y\n";
    obj << allNodes;
    while (!(marker == nullptr)) {  
        obj << marker->data.id << "," << marker->data.fov << "," << marker->data.volume << "," << marker->data.center_x << "," << marker->data.center_y << "," << marker->data.min_x << "," << marker->data.max_x << "," << marker->data.min_y << "," << marker->data.max_y << "\n";
        marker = marker->next;
    }
    return obj.str();


}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	/* Do not modify this function */
	os << ll.print();
	return os;
}

// given a fov number, count the cells observed in that fov
int LinkedList::countN(int fov)
{
	/* Do not modify this function */
    int count = 0;
    Node* cur = head;
    while (cur)
    {
        if (cur->data.fov == fov)
            count++;
        cur = cur->next;
    }
    return count;
}

/* given a fov number, compute the average volume of all the cells observed in
 * that fov
 */
double LinkedList::average(int fov)
{
    double sum = 0;
    int count = countN(fov);
    Node* cur = head;
    if (count == 0) {
        return -1;
    }
    while (cur)
    {
        if (fov == cur->data.fov)
            sum += cur->data.volume;
        cur = cur->next;
    }
    return sum/count;


}

/* given a fov number, compute the variance volume of all the cells observed in
 * that fov
 */
double LinkedList::variance(int fov)
{
	/* Do not modify this function */
    double sum = 0;
    double avg = average(fov);
    int count = countN(fov);

    if (count == 0)
        return -1;

    Node* cur = head;
    while (cur)
    {
        if (fov == cur->data.fov)
            sum += (cur->data.volume - avg) * (cur->data.volume - avg);
        cur = cur->next;
    }

    return sum/count;
}

/* given a fov number, remove outliers
 */
string LinkedList::outliers(int fov, int k, int N)
{
    ostringstream obj;
    double delta;
    int count = 0;
    
    if (countN(k) < N) {
        obj << "Less than N cells in fov k";
    } else {
        delta = sqrt(variance(fov));
        Node* cur = head;
        while (cur)
        {
            if (cur->data.volume <= (average(fov) + (k * delta)) && cur->data.volume >= (average(fov) - (k * delta))) {
                remove(cur->data.id, cur->data.fov, cur->data.volume, cur->data.center_x, cur->data.center_y, cur->data.min_x, cur->data.max_x, cur->data.min_y, cur->data.max_y);
                count++;
            }
            cur = cur->next;
        }
        obj << count << " cells are removed.";
    }
    // Implement this function
    return obj.str();
}

