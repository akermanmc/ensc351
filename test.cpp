#include <cstdio>
#include "tracelib.h"
#include <iostream>
#include <chrono>

using namespace std;

int main(){
	// initilize timer to start_time
	chrono::time_point<chrono::system_clock> start_time = chrono::system_clock::now();

    char filename[10] = "test.json";
    char name[10] = "test";
    char cat[10] = "hero";
    char arguments[2000] = {'\0'};
    trace_start(filename);

    // take duration since start_time and convert to char*
    chrono::time_point<chrono::system_clock> current_time = chrono::system_clock::now();
    long int time_stamp = chrono::duration_cast<chrono::microseconds>(current_time - start_time).count();
    sprintf(arguments, "%ld", time_stamp);
   
    trace_event_start(name, cat, arguments);

    current_time = chrono::system_clock::now();
    time_stamp = chrono::duration_cast<chrono::microseconds>(current_time - start_time).count();
    sprintf(arguments, "%ld", time_stamp);

    trace_instant_global(name, arguments);

    current_time = chrono::system_clock::now();
    time_stamp = chrono::duration_cast<chrono::microseconds>(current_time - start_time).count();
    sprintf(arguments, "%ld", time_stamp);

    trace_event_end(arguments);

    char happyName[20] = "poo";
    char happyCat[20] = "stuff";

    current_time = chrono::system_clock::now();
    time_stamp = chrono::duration_cast<chrono::microseconds>(current_time - start_time).count();
   
    traceEntry happyTrace(happyName,happyCat,'i',time_stamp,22,3);
    happyTrace.printName();
    happyTrace.printPhase();
    happyTrace.WriteToFile();
	
	current_time = chrono::system_clock::now();
    time_stamp = chrono::duration_cast<chrono::microseconds>(current_time - start_time).count();
    sprintf(arguments, "%ld", time_stamp);

    trace_end(arguments);
    return 0;
}