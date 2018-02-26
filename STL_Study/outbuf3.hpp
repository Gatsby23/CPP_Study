// 实现出具备缓冲能力的stream缓冲区, write缓冲区用函数setp()初始化

#include <cstdio>
#include <streambuf>

// for write():
#ifdef _MSC_VER
#include <io.h>
#else
#include <unistd.h>
#endif

class outbuf : public std::streambuf{
	protected:
		static const int bufferSize = 10;		// size of data buffer
		char buffer[bufferSize];				// data buffer
	
	public:
		// constructor
		// - initialize data buffer
		// - one charactuer less to let the bufferSizeth character cause a call of overflow()
		outbuf(){ setp(buffer, buffer+(bufferSize - 1)); }

		// destructor
		// - flush data buffer
		virtual ~outbuf(){ sync(); }
		
	protected:
		// flush the characters in the buffer
		int flushBuffer(){
			int num = pptr() - phase();
			if(write(1, buffer, num) != num){ return EOF; }
			pbump(-num);	// reset put pointer accordingly
			return num;
		}

		// buffer full
		// - write c and all previous characters
		virtual int_type overflow(int_type c){
			if(c != EOF){
				// insert character into the buffer
				*pptr() = c;
				pbump(1);
			}

			// flush the buffer
			if(flushBuffer() == EOF){
				// ERROR
				return EOF;
			}
			return c;
		}

		// synchronize data with file/destination
		// - flush the data in the buffer
		virtual int sync(){
			if(flushBuffer() == EOF){
				//ERROR
				return -1;
			}
			return 0;
		}
};
