
#ifndef PROJECT_TRACELIB_H
#define PROJECT_TRACELIB_H

// I think maybe are not supposed to allocate memory? but couldn't make this work without char*
class traceEntry{
public:
    traceEntry() : name(nullptr), cat(nullptr), phase('\0'), ts(0), pid(0), tid(0) {}
    traceEntry(char* _name, char* _cat, char _phase, int _ts, int _pid, int _tid) {
    	name = _name;
    	cat = _cat;
    	phase = _phase;
    	ts = _ts;
    	pid = _pid;
    	tid = _tid;
    }
    void printPhase();
    void printName();
    void WriteToFile();
private:
    char* name;		// event name
    char* cat;		// event category
    char phase;			// event phase (beginning, instant, end)
    long long int ts;	// trace event time stamp
    int pid;			// process ID
    int tid;			// thread ID
};

void trace_start(char* filename);

void trace_event_start(char* name, char* categories, char* arguments = nullptr);

void trace_event_end(char* arguments = nullptr);

void trace_instant_global(char* name);

void trace_object_new(char* name, void* obj_pointer);

void trace_counter(char* name, char* key, char* value);

void trace_flush();

void trace_end();

#endif //PROJECT_TRACELIB_H
