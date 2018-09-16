#include "tracelib.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <chrono>
using namespace std;

namespace {
    ofstream *fileStream;
}

// begins trace generation, opens write file, starts timer
void trace_start(char *filename) {
    fileStream = new ofstream();
    fileStream->open(filename, ofstream::out);
    *fileStream<<"["<<endl;
}



// writes event start trace to file
void trace_event_start(char *name, char *categories, char *arguments) {
    *fileStream << "{\"name\": \"" << name << "\", \"cat\": \"" << categories
               << "\", \"ph\": \"" << "B" <<"\", \"ts\": "<< arguments
               <<", \"pid\": "<< "2343"<< ", \"tid\": " << "2347" <<"}," << endl;
}

// writes event end trace to file
void trace_event_end(char *arguments) {
    *fileStream << "{\"ph\": \""<<"E"<<"\", \"ts\": "<< arguments
               <<", \"pid\": "<< "2343"<< ", \"tid\": "
               << "2347" <<"}," << endl;
}

// writes instant event trace to file
void trace_instant_global(char *name, char* arguments) {
    *fileStream << "{\"name\": \"" << name << "\", \"ph\": \"" << "i"
               <<"\", \"ts\": "<< arguments <<", \"pid\": "<< "2343"<< ", \"tid\": "
               << "2347" <<", \"s\": \"t\"}," << endl;
}

// writes object event creation trace to file
void trace_object_new(char *name, void *obj_pointer) {

}

// writes counter event to file
void trace_counter(char *name, char *key, char *value) {

}

// not sure what this is supposed to do...
void trace_flush() {

}

// signals the end of trace writing in the program, closes the write file
void trace_end(char* arguments) {
	
    *fileStream << "{\"name\": \"" << "TRACE_END" << "\", \"ph\": \"" << "i"
               <<"\", \"ts\": "<< arguments <<", \"pid\": "<< 1<< ", \"tid\": "
               << 1 <<", \"s\": \"t\"}" << endl;
    *fileStream<<"]"<<endl;
    fileStream->close();
    delete fileStream;
    fileStream = nullptr;
}

void traceEntry::printPhase(){
	cout << phase << endl;
}
void traceEntry::printName(){
	cout << name << endl;
}

// writes appropriate trace entry to file depending on event description variable values
void traceEntry::WriteToFile() {
    switch(phase)
    {
        case 'E':
            *fileStream << "{\"ph\": \""<<phase<<"\", \"ts\": "<< ts
                <<", \"pid\": "<< pid<< ", \"tid\": "
                << tid <<"}," << endl;
            break;
        case 'i':
            *fileStream << "{\"name\": \"" << name << "\", \"ph\": \"" << phase
            <<"\", \"ts\": "<< ts <<", \"pid\": "<< pid<< ", \"tid\": "
            << tid <<", \"s\": \"g\"}," << endl;
            break;
        case 'B':
            *fileStream << "{\"name\": \"" << name << "\", \"cat\": \"" << cat
            << "\", \"ph\": \"" << phase <<"\", \"ts\": "<< ts
            <<", \"pid\": "<< pid<< ", \"tid\": " << tid <<"}," << endl;
            break;
        default: assert(0);
    }
}
