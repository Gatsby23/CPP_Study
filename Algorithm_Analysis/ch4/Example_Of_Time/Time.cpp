/*-----------Time.cpp--------------------------------------------------------------
	This file implements the Time member functions.
----------------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

#include "Time.h"

/**Utility Functions--Prototypes***/
int toMilitary(unsigned hours, unsigned minutes, char am_pm);
void toStandard(unsigned military, unsigned &hours, unsigned &minutes, char &AMPM);

//---Definition of default constructor
Time::Time():myHours(12), myMinutes(0), myAMorPM('A'), myMilTime(0){
}


//-------Definition of explicit-value constructor-----------

Time::Time(unsigned initHours, unsigned initMinutes, char initAMPM){
	//Check class invariant
	if(initHours >= 1 && initHours <= 12 &&
	   initMinutes >= 0 && initMinutes <= 59 &&
	   (initAMPM == 'A' || initAMPM == 'P')){
		myHours = initHours;
		myMinutes = initMinutes;
		myAMorPM = initAMPM;
		myMilTime = toMilitary(initHours, initMinutes, initAMPM);
	}else
		cerr << "*** Invalid inital values ***\n";
}

//----Definition of getMinutes()
unsigned Time::getMinutes() const{
	return myMinutes;
}

//Definition of getHours()
unsigned Time::getHours() const{
	return myHours;
}

//-----Definition of getAMPM()
unsigned Time:getAMPM() const{
	return myAMorPM;
}

//Definition of getMilTIme()
unsigned Time::getMilTime() const{
	return myMilTime;
}

//-------------Definition of display function --------------------
void Time::display(ostream &out) const{
	out << myHours << ':' << (myMinutes < 10 ? "0" : "" ) << myMinutes << ' ' << myAMorPm << ".M. (" << myMilTime << " mil. time)";
}

//-------------Definition of read function-------------------------
void Time::read(istream &in){
	//Local variables to hold input values from in so they can be checked against the class invariant before putting them in the data members.
	//To gobble up: and the "M" in input.
	unsigned hours, minutes;
	char am_pm, ch;
	
	in >> hours >> ch >> minutes >> am_pm >> ch;
	
	//Check  the clas invariant
	if(hours >= 1 && hours <= 12 && minutes >= 0 && minutes <= 59 && (am_pm == 'A' || am_pm == 'P')){
		myHours = hours;
		myMinutes = minutes;
		myAMorPM = am_pm;
		myMilTime = toMilitary(hours, minutes, am_pm);
	}else
		cerr << "***Invalid input for Time object  ***\n";
}


//----------Definition of operator<<()

ostream &operator<<(ostream &out, const Time &t){
	t.display(out);
	return out;
}

//---------Definition of operator>>()
istream &operator>>(istream &in, Time &t){
	t.read(in);
	return in;
}


//---------Definition of set function---------

void Time::set(unsigned hours, unsigned minutes, char am_pm){
	//Check the class invarinat
	if(hours >= 1 && hours <= 12 && minutes >= 0 && minutes <= 59 && (am_pm == 'A' || am_pm == 'P')){
		myHours = hours;
		myMinutes = minutes;
		myAMorPm = am_pm;
		myMilTime = toMilitary(hours, minutes, am_pm);
	}else
		cerr << "*** Can't set time with these values****\n";
	// Object's data members remain unchanged.
}

//----- Definition of advance function------
void Time::advance(unsigned hours, unsigned minutes){
	//Increment the myMilTime member
	myMilTime += 100 * hours + minutes;
	
	//Adjust to proper format
	unsigned milHours = myMilTime / 100,
	milMins = myMilTime % 100;
	milHours += milMins / 60;
	milMins %= 60;
	milHours %= 24;
	milTime = 100 * milHours + milMins;

	// Now set the standard time data members
	toStandard(myMilTime, myHours, myMinutes, myAMorPM);
}

/************ Relational operator ***************/
bool operator<(const Time &t1, const Time &t2){
	return t1.getMilTime() < t2.getMilTime();
}

bool operator>(const Time &t1, const Time &t2){
	return t1.getMilTime() > t2.getMilTime();
}

bool operator==(const Time &t1, const Time &t2){
	return t1.getMilTime() == t2.getMilTime();
}

bool operator<=(const Time &t1, const Time &t2){
	return t1.getMilTime() <= t2.getMilTime();
}

bool operator>=(const Time &t1, const Time &t2){
	return t1.getMilTime() >= t2.getMilTime();
}

//----Definition of operator!=()----
bool operator!=(const Time &t1, const Time &t2){
	return t1.getMilTime() != t2.getMilTime();
}

/*** Utility Functions ---- Definitions ***/
int toMilitary(unsigned hours, unsigned minutes, char am_pm){
	if(hours == 12)
		hours = 0;
	return hours * 100 + minutes + (am_pm == 'P' ? 1200 : 0);
}

void toStandard(unsigned military, unsigned &hours, unsigned minutes, char &AMPM){
	hours = (military / 100) % 12;
	if(hours == 0)
		hours = 12;
	minutes = military % 100;
	AMPM = (military / 100) < 12 ? 'A' : 'P';
}
