#include <cstdio>
#include "tracelib.h"
#include <iostream>
#include <sys/time.h>
#include <ctime>
#include <unistd.h>
using namespace std;


int main(){
    char filename[10] = "test.json";
    char name[10] = "test";
    char cat[10] = "hero";
    trace_start(filename);
    trace_event_start(name, cat);
    trace_instant_global(name);
    trace_event_end();

    struct timeval _timeNow;
    char happyName[20] = "poo";
    char happyCat[20] = "stuff";
    gettimeofday(&_timeNow, NULL);
    traceEntry happyTrace(happyName,happyCat,'i',_timeNow.tv_usec,22,3);
    happyTrace.printName();
    happyTrace.printPhase();
    happyTrace.WriteToFile();
	
    trace_end();
    return 0;
}