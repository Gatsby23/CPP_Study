// io/frac1in.hpp
//
/* #include <iostream>

inline std::istream& operator>>(std::istream& strm, Fraction& f){
	int n, d;
	strm >> n;		// read value of the numerator
	strm.ignore();	// skip '/'
	strm >> d;		// read value of the denominator

	f = Fraction(n, d);	// assign the whole fraction

	return strm;
}*/

// io/frac2in.hpp

#include <iostream>

template <typename charT, typename traits>
inline
std::basic_istream<charT, traits>&
operator >>(std::basic_istream<charT, traits>& strm, Fraction& f){
	int n, d;

	// read value of numerator
	strm >> n;

	// if available
	// -read '/' and value of demonimator
	if(strm.peek() == '/'){
		strm.ignore();
		strm >> d;
	}else{
		d = 1;
	}

	// if denominator is Zero
	// - set failbit as I/O format error
	if(d == 0){
		strm.setstate(std::ios::failbit);
		return strm;
	}

	// if everything is fine so far
	// - change the value of the fraction
	if(strm)
		f = Fraction(n, d);
	return strm;
}


