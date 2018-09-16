#ifndef PROJECT_TRACELIB_H
#define PROJECT_TRACELIB_H

#include <string>
using namespace std;

const int maxEntries = 10000;

// I think maybe are not supposed to allocate memory? but couldn't make this work without char*
// --- we are allowed to allocate memory in the trace_start function, so we can create 10,000 instances
// and reserve that memory in the beginning
class traceEntry{
public:
    traceEntry() : name(), cat(), phase('\0'), ts(0), pid(0), tid(0), arguments() {}
    traceEntry(const char* _name, const char* _cat, const char _phase, const long long int _ts,const int _pid,
            const int _tid,const  char* _arguments)
    : name(_name), cat(_cat), phase(_phase), ts(_ts), pid(_pid), tid(_tid), arguments(_arguments) {}

    //setters
    void setName(const char* _name) {name = string(_name);}
    void setCat(const char* _cat) {cat = string(_cat);}
    void setPhase(const char _phase) {phase = _phase;}
    void setTS(const long long int _ts) {ts = _ts;}
    void setPID(const int _pid = 1) {pid = _pid;}
    void setTID(const int _tid = 1) {tid = _tid;}
    void setArgs(const char* args) {arguments = string(args);}

    void printPhase();
    void printName();
    void WriteToFile();
private:
    string name;		// event name
    string cat;		    // event category
    string arguments;   // event arguments
    char phase;			// event phase (beginning, instant, end)
    long long int ts;	// trace event time stamp
    int pid;			// process ID
    int tid;			// thread ID
};

// --------------------------------------------------------------------------------

void trace_start(char* filename);

void trace_event_start(char* name, char* categories, char* arguments = nullptr);

void trace_event_end(char* arguments = nullptr);

void trace_instant_global(char* name);

void trace_object_new(char* name, void* obj_pointer);

void trace_counter(char* name, char* key, char* value);

void trace_flush();

void trace_end();

#endif //PROJECT_TRACELIB_H
