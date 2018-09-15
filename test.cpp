#include <cstdio>
#include "tracelib.h"
#include <iostream>
using namespace std;


int main(){
    char filename[10] = "test.json";
    char name[10] = "test";
    char cat[10] = "hero";
    trace_start(filename);
    trace_event_start(name, cat);
    trace_instant_global(name);
    trace_event_end();

    char happyName[20] = "poo";
    char happyCat[20] = "stuff";
    traceEntry happyTrace(happyName,happyCat,'i',30,22,3);
    happyTrace.printName();
    happyTrace.printPhase();
    happyTrace.WriteToFile();
	
    trace_end();
    return 0;
}