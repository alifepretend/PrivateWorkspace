#include "/data/data/com.termux/files/home/private_projects/PrivateWorkspace/testing/serialib.h"
#include <stdio.h>


#if defined (_WIN32) || defined(_WIN64)
   // for serial ports above "COM9", we must use this extended syntax of "\\.\COMx".
        //also works for COM0 to COM9.
            //https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-createfilea?redirectedfrom=MSDN#communications-resources
            #define SERIAL_PORT "\\\\.\\COM1"
            #endif
            #if defined (__linux__) || defined(__APPLE__)
            #define SERIAL_PORT "/dev/ttyACM0"
            #endif
    
            /*!
             * \brief main  Example of read and write string
               */
int main( /*int argc, char *argv[]*/) {
	serialib serial;

	return 0;
}
