
#ifndef PROJECT_TRACELIB_H
#define PROJECT_TRACELIB_H

class traceEntry{
public:
    traceEntry() : name(""), cat(""), phase('\0'), ts(0), pid(0), tid(0) {}
    void WriteToFile();
private:
    char name[20];
    char cat[20];
    char phase;
    long long int ts;
    int pid;
    int tid;
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
