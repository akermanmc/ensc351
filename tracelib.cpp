#include "tracelib.h"
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

namespace {
    ofstream *fileStream;
}

void trace_start(char *filename) {
    fileStream = new ofstream();
    fileStream->open(filename, ofstream::out);
    *fileStream<<"["<<endl;
}

void trace_event_start(char *name, char *categories, char *arguments) {
    *fileStream << "{\"name\": \"" << name << "\", \"cat\": \"" << categories
               << "\", \"ph\": \"" << "B" <<"\", \"ts\": "<< "123"
               <<", \"pid\": "<< "2343"<< ", \"tid\": " << "2347" <<"}," << endl;
}

void trace_event_end(char *arguments) {
    *fileStream << "{\"ph\": \""<<"E"<<"\", \"ts\": "<< "143"
               <<", \"pid\": "<< "2343"<< ", \"tid\": "
               << "2347" <<"}," << endl;
}

void trace_instant_global(char *name) {
    *fileStream << "{\"name\": \"" << name << "\", \"ph\": \"" << "i"
               <<"\", \"ts\": "<< "136" <<", \"pid\": "<< "2343"<< ", \"tid\": "
               << "2347" <<", \"s\": \"t\"}," << endl;
}

void trace_object_new(char *name, void *obj_pointer) {

}

void trace_counter(char *name, char *key, char *value) {

}

void trace_flush() {

}

void trace_end() {
    *fileStream << "{\"name\": \"" << "DUMMY" << "\", \"ph\": \"" << "i"
               <<"\", \"ts\": "<< "1" <<", \"pid\": "<< 1<< ", \"tid\": "
               << 1 <<", \"s\": \"t\"}" << endl;
    *fileStream<<"]"<<endl;
    fileStream->close();
    delete fileStream;
    fileStream = nullptr;
}

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
