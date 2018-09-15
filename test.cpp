#include <cstdio>
#include "tracelib.h"



int main(){
    char filename[10] = "test.json";
    char name[10] = "test";
    char cat[10] = "hero";
    trace_start(filename);
    trace_event_start(name, cat);
    trace_instant_global(name);
    trace_event_end();
    trace_end();
    return 0;
}