#include <cstdio>
#include "tracelib.h"
#include <iostream>
#include <chrono>

using namespace std;

void add(const int &, const int &);

int main(){
    char filename[10] = "test.json";
    trace_start(filename);

    for (int i = 0; i < 200; i++)
        add(40, 40);

    trace_end();
    return 0;
}

void add(const int &a, const int &b)
{
    char name[10] = "add";
    char cat[10] = "hero";
    trace_event_start(name,cat);
    int c = a+b;
    trace_event_end();
}