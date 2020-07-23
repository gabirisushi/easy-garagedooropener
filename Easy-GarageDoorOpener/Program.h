#include <iostream>
#include <fstream>

using namespace std;

const int
CLOSED=0,
OPENING=1,
OPEN=2,
CLOSING=3,
STOPPED_OPENING=4,
STOPPED_CLOSING=5;

void printState(int state) {
	switch(state) {
	case CLOSED:
		cout<<"Door: CLOSED\n"; break;

	case OPENING:
		cout<<"Door: OPENING\n"; break;

	case OPEN:
		cout<<"Door: OPEN\n"; break;

	case CLOSING:
		cout<<"Door: CLOSING\n"; break;

	case STOPPED_OPENING:
		cout<<"Door: STOPPED_WHILE_OPENING\n"; break;

	case STOPPED_CLOSING:
		cout<<"Door: STOPPED_WHILE_CLOSING\n"; break;
	}
}

int main() {
	int dir; // direction where the door is going

	fstream f("input1.txt",ios::in);

	if(!f) {
		cout<<"File not found\n";
		return 1;
	}

      string cmd;
      int state=CLOSED;

      printState(state);

      while(!f.eof()) {
		f>>cmd;

		if(cmd=="button_clicked") {
			if(state==CLOSED) state=OPENING;
			else if(state==OPEN) state=CLOSING;
			else if(state==OPENING) state=STOPPED_OPENING;
			else if(state==CLOSING) state=STOPPED_CLOSING;
			else if(state==STOPPED_OPENING) state=CLOSING;
			else if(state==STOPPED_CLOSING) state=OPENING;
		} else if(cmd=="cycle_complete") {
			if(state==OPENING) state=OPEN;
			else if(state==CLOSING) state=CLOSED;
		}

		printState(state);
      }



      f.close();

	return 0;
}
