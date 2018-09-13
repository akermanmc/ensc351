#include "tracelib.h"
#include <iostream>
using namespace std;

void trace_start(char *filename) {
    cout<<"["<<endl;
}

void trace_event_start(char *name, char *categories, char *arguments) {

}

void trace_event_end(char *arguments) {

}

void trace_instant_global(char *name) {

}

void trace_object_new(char *name, void *obj_pointer) {

}

void trace_counter(char *name, char *key, char *value) {

}

void trace_flush() {

}

void trace_end() {
    cout<<"]"<<endl;
}

