// LinkedListChallenge.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
#include<string>
#include <iomanip>

enum DaysOfWeek { MON, TUE, WED, THUR, FRI, SAT, SUN };
using namespace std;
using namespace std;


//1) Maintain linked list in ascending order (feel free to skip if you submitted this in previous assignment).

struct ListNode {
	string data;
	ListNode* next;

	ListNode(string s, ListNode* p = nullptr) {
		data = s; next = p;
	};
};


struct StringLinkedList {

	ListNode* head = nullptr;

	StringLinkedList(string s) {
		this->insertAscending(s);
	}

	ListNode* insertAscending(string s) {

		if (head == nullptr) {
			head = new ListNode(s);
		}
		else {
			if (s.compare(head->data) < 0) {
				//make s the new head
				ListNode* newNode = new ListNode(s);
				newNode->next = head;
				head = newNode;
			}
			else {
				//move forward through the list to find where the s should go 
				ListNode* prev = head;
				ListNode* curr = head->next;
				bool done = false;

				while (curr != nullptr) {
					if (s.compare(curr->data) < 0) {
						ListNode* newNode = new ListNode(s);
						prev->next = newNode;
						newNode->next = curr;
						done = true;
						break;
					}
					else {
						curr = curr->next;
						prev = prev->next;
					}
				}
				if (!done) {
					prev->next = new ListNode(s);
				}
			}
		}

		return head;
	}

	//2) Maintain linked list in descending order

	ListNode* insertDescending(string s) {

		if (head == nullptr) {
			head = new ListNode(s);
		}
		else {
			if (s.compare(head->data) > 0) {
				//make s the new head
				ListNode* newNode = new ListNode(s);
				newNode->next = head;
				head = newNode;
			}
			else {
				//move forward through the list to find where the s should go 
				ListNode* prev = head;
				ListNode* curr = head->next;
				bool done = false;

				while (curr != nullptr) {
					if (s.compare(curr->data) > 0) {
						ListNode* newNode = new ListNode(s);
						prev->next = newNode;
						newNode->next = curr;
						done = true;
						break;
					}
					else {
						curr = curr->next;
						prev = prev->next;
					}
				}
				if (!done) {
					prev->next = new ListNode(s);
				}
			}
		}

		return head;
	}

	void printResult() {
			while (head != nullptr) {
				cout << head->data << endl;
				head = head->next;
			}
	}
};

//3)Covert linked list to store integers| 4)Store even integers ascending, odd integers descending

struct IntNode {
	int data;
	IntNode* next;

	IntNode(int _data, IntNode * _next= nullptr) {
		data = _data;
		next = _next;
	}
};

struct IntLinkedList {
	IntNode* head;

	IntLinkedList(int value) {
		add(value);
	}
	void add(int value) {
		if (value % 2 == 0) {
			insertAscending(value);
		}
		else {
			insertDescending(value);
		}
	}

	IntNode* insertAscending(int v) {
		if (head == nullptr) {
			head = new IntNode(v);
		}
		else {
			if (v < head->data) {
				//make s the new head
				IntNode* newNode = new IntNode(v);
				newNode->next = head;
				head = newNode;
			}
			else {
				//move forward through the list to find where the s should go 
				IntNode *prev = head;
				IntNode* curr = head->next;
				bool done = false;

				while (curr != nullptr) {
					if (v < curr->data) {
						IntNode* newNode = new IntNode(v);
						prev->next = newNode;
						newNode->next = curr;
						done = true;
						break;
					}
					else {
						curr = curr->next;
						prev = prev->next;
					}
				}
				if (!done) {
					prev->next = new IntNode(v);
				}
			}
		}
		return head;
	}

	IntNode* insertDescending(int v) {
		if (head == nullptr) {
			head = new IntNode(v);
		}
		else {
			if (v > head->data) {
				//make s the new head
				IntNode* newNode = new IntNode(v);
				newNode->next = head;
				head = newNode;
			}
			else {
				//move forward through the list to find where the s should go 
				IntNode* prev = head;
				IntNode* curr = head->next;
				bool done = false;

				while (curr != nullptr) {
					if (v > curr->data) {
						IntNode* newNode = new IntNode(v);
						prev->next = newNode;
						newNode->next = curr;
						done = true;
						break;
					}
					else {
						curr = curr->next;
						prev = prev->next;
					}
				}
				if (!done) {
					prev->next = new IntNode(v);
				}
			}
		}
		return head;	
	}
};


//5)Store your calendar / schedule in a linked list indexed by weekly array

class WeekSchedule {
public:
	struct calendarNode {
		double _startTime;
		double _endTime;
		struct calendarNode* _next;
		string _name;

		calendarNode(double startTime, double endTime, string name, calendarNode* next = nullptr) {
			_startTime = startTime;
			_endTime = endTime;
			_next = next;
			_name = name;
		}

		~calendarNode() {
			delete _next;
		}
	};
	calendarNode* myWeek[SUN + 1] = { nullptr };

	void add(DaysOfWeek day, double startTime, double endTime, string name) {
		if (nullptr == myWeek[day]) {
			myWeek[day] = new calendarNode(startTime, endTime, name);
		}
		else { //find spot in order for new appointment 
			if (startTime < myWeek[day]->_startTime) {
				myWeek[day] = new calendarNode(startTime, endTime, name, myWeek[day]);
				return;
			}
			calendarNode* prev = myWeek[day];//head
			calendarNode* cur = prev->_next;
			while (cur != nullptr && startTime > cur->_startTime) {
				prev = cur;
				cur = cur->_next;
			}
			prev->_next = new calendarNode(startTime, endTime, name, cur);
		}
	}

	void print() {
		
		for (int i = MON; i <= SUN; i++) {
			DaysOfWeek day = static_cast<DaysOfWeek>(i);

			switch (day) {
				case MON:
					cout << "Monday" << endl;
					break;
				case TUE:		
					cout << "Tuesday" << endl;
					break;
				case WED:
					cout << "Wednesday" << endl;
					break;
				case THUR:
					cout << "Thursday" << endl;
					break;
				case FRI:
					cout << "Friday" << endl;
					break;
				case SAT:
					cout << "Saturday" << endl;
					break;
				case SUN:
					cout << "Sunday" << endl;
					break;
			}

			calendarNode* current = myWeek[day];
			while (current != nullptr) {
				// Convert start time and end time to 12-hour format with "am" or "pm"
				int startHour = static_cast<int>(current->_startTime);
				int endHour = static_cast<int>(current->_endTime);
				string startSuffix = (startHour >= 12) ? "pm" : "am";
				string endSuffix = (endHour >= 12) ? "pm" : "am";

				// Adjust hours for 12-hour format
				startHour = (startHour > 12) ? startHour - 12 : startHour;
				endHour = (endHour > 12) ? endHour - 12 : endHour;

				// Calculate and adjust minutes
				int startMinute = static_cast<int>((current->_startTime - static_cast<int>(current->_startTime)) * 60);
				int endMinute = static_cast<int>((current->_endTime - static_cast<int>(current->_endTime)) * 60);

				// Output in desired format
				cout << startHour << ":" << setw(2) << setfill('0') << startMinute
					<< startSuffix << " - " << endHour << ":" << setw(2) << setfill('0') << endMinute
					<< endSuffix << " " << current->_name << endl;

				current = current->_next;
			}
			cout << endl;
		}
	}
};

int main() {

	StringLinkedList* s = new StringLinkedList("Hello");
	/*s->insertAscending("Apple");
	s->insertAscending("Banana");
	s->insertAscending("World");
	s->printResult();*/

	/*s->insertDescending("Apple");
	s->insertDescending("Banana");
	s->insertDescending("World");
	s->printResult();
	IntLinkedList* i = new IntLinkedList(77);
	i->add(37);
	i->add(7);
	i->add(9);
	i->add(5);*/


	WeekSchedule ws;
	ws.add(MON, 18, 21, "C++ class");
	ws.add(MON,8,16, "Study time & homework assignments");

	ws.add(TUE, 9, 17, "work & meetings");
	ws.add(TUE,19,23, "homework assignments");
	

	ws.add(WED,9,15.5, "work & meetings");
	ws.add(WED, 17, 23, "study time & homework assignments");

	ws.add(THUR,7,9, "work out");
	ws.add(THUR, 10, 17, "work & meetings");
	ws.add(THUR, 18, 23, "study time & assignments");

	ws.add(FRI,7.5,15, "work and meetings");
	ws.add(FRI, 17, 21, "study time & assignments");

	ws.add(SAT, 8, 16, "work & meetings");
	ws.add(SAT,17,19, "study time");
	ws.add(SAT, 19.5, 22, "relaxing and family time");

	ws.add(SUN, 9, 12, "work out, family time");
	ws.add(SUN, 13, 18, "study time & assignments");
	ws.add(SUN, 18, 21, "relaxing, preparing for the next week");

	ws.print();
}