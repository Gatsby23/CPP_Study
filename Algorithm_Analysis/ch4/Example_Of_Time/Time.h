/*------------------Time.h--------------------------------------------------------*/

#include <iostream>
using namespace std;

#ifndef TIME
#define TIME

class Time{
	public:
		/**************Function Member****************/
		/**************Class constructors*************/
		Time();
		/*********************************************
		 Construct a class object(default).
		 
		 Precondition:	None.
		 Postcondition:	Time object is initialized to 12:00 A.M.;
			that is, myHours, myMinutes, and myAMorPM are initialized
		 	to 12, 0, 'A', respectively, and myMilTime to 0.
		--------------------------------------------*/
		
		Time(unsigned initHours, unsigned initMinutes, char initAMPM);
		/************************************************************
		Construct a class object(explicit value).
		
		Precondition: initHours, initMinutes and initAMPM are initial
			values for the data members; they must preserve the class
			invariant.
		Postcondition: Data members myHours, myMinutes, and myAMorPM
			have been initialized to initHours, initMinutes, and initAMPM,
			respectively, and myMilTime to the corresponding military time.
		************************************************************/
		
		/****Accessors******/
		unsigned getHours() const;
		/*-----------------------------------------------------------
		Retrieve the values stored in the myHours data member.
		
		Precondition:	None
		Postcondition:	Value stored in myHours is returned.
		-----------------------------------------------------------*/
		
		unsigned getMinutes() const;
		/*-----------------------------------------------------------
		Retrieve the value stored in the myMinutes data member.
		
		Precondition: 	None.
		Postcondition:	Value stored in myMinutes is returned
		-----------------------------------------------------------*/
		
		unsigned getAMPM() const;
		/*-----------------------------------------------------------
		Retreive the value stored in the myAMorPM data member.
		
		Precondition:	None.
		Postcondition:	Value stored in myAMorPM is returned
		-----------------------------------------------------------*/
		
		unsigned getMilTime() const;
		/*----------------------------------------------------------
		Retrieve the value stored in the my MilTime data member.
			
		Precondition:	None.
		Postcondition:	Value stored in myMilTime is returned.
		----------------------------------------------------------*/
		
		/**********Input/Output************/
		void display(ostream &out) const;
		/*---------------------------------------------------------
		Display time in standard and miltary format using output stream out
		
		Precondition:	The ostream is open.
		Postcondition:	The time represented by this Time object has been inserted into ostream out.
		-----------------------------------------------------------*/
		
		void read(isream &in);
		/*----------------------------------------------------------
		Read a time value from input stream in.
		
		Precondition:	The istream in is open; input from in has the form:
			hh:mm xM;	values hh, mm, and X satisfy the class invariant.
		Postcondition:	Input values have been removed from in and stored in the 
		data mebers.
		----------------------------------------------------------*/

		/****Set operation*********/
		void set(unsigned hours, unsigned minutes, char am_pm);
		/*---------------------------------------------------------
		Set the data members of a Time object to specified values.
		
		Preconditions:	1 <= hours <= 12.0 <= Minutes <= 59.
			and am_pm is either 'A' or 'P'.
		
		Postcondition:	Data members myHours, myMinutes, and myAMorPM
			are set to hours, minutes, and am_pm, respectively, and 
			myMilTime to the equivalent miltary time
		---------------------------------------------------------*/
		
		/******* Increment operation ********/
		void advance(unsigned hours, unsigned minutes);
		/*---------------------------------------------------------
		Increment a Time object by a specified value.
		
		Precondition:	hours is the number of hours to add and minutes is the number of minutes to add.
		Postcondition:	The time represented by this Time obejct had been incremented by this number of hours and minutes.
		---------------------------------------------------------*/
	private:
		/***************Data Members ****************************/
		unsigned myHours, myMinutes;
		char myAMorPM;			// 'A' or 'P'
		unsigned myMilTime;		// military time equivalent
};		// end of class declaration

//--------- << and >> operators

ostream &operator <<(ostream &out, const Time &t);
/*------------------------------------------------------------------------------
Overloaded output operator

Precondition:	The ostream out is open
Postcondition:	The time represented by this Time object has been inserted into ostream out(via display()); reference to out is returned.
---------------------------------------------------------------------------------*/

istream &operator >>(istream &in, Time &t);
/*--------------------------------------------------------------------------------
overloaded input operator

Precondition:	The istream in is open; input from in has the form hh:mm xM; values hh, mm, and X satisfy the class invariant.
Postcondition:	Values have been extracted from in (via read()) and stored in this Time object's data members; reference to in is returned.
---------------------------------------------------------------------------------*/

/******* Relational operators ***********/
bool operator<(const Time &t1, const Time &t2);
/*---------------------------------------------------------------------------------
Determine if one Time object is less tha(i.e., earlier than) another Time object.

Precondition:	None.
Postcondition:	true is retruned if t1 is less tha t2 and false otherwise.
---------------------------------------------------------------------------------*/

bool operator>(const Time &t1, const Time &t2);
/*---------------------------------------------------------------------------------
Determine if one Time object is greater than(i.e., later than)
another Time object.

Precondition:	None;
Postcondition:	true is returned if t1 is greater than t2 and false otherwise.
---------------------------------------------------------------------------------*/

bool operator==(const Time &t1, const Time &t2);
/*----------------------------------------------------------------------------------
Determine if one Time object is greater than(i.e., later than) another Time object.

Precondition:	None.
Postcondition:	true is returned if t1 is equal to t2 and false otherwise.
----------------------------------------------------------------------------------*/

bool operator>=(const Time &t1, const Time &t2);
/*---------------------------------------------------------------------------------
Determine if one Time object is greater than or equal to(i.e., later than or the same as ) another Time object.

Precondition:	None.
Postcondition:	true is returned if t1 is grater than or equal to t2 and false otherwise.
----------------------------------------------------------------------------------*/

//--------Definition of operator!=()---------------
bool operator!=(const Time &t1, const Time &t2);
/*----------------------------------------------------------------------------------
Determine if one Time object is not equal to another Time object.

Precondition: None.
Postcondition:	true is returned if t1 is not equal t2 and false otherwise.
----------------------------------------------------------------------------------*/
 
#endif


















































