#include <cstdio>
#include "tracelib.h"
#include <iostream>
#include <chrono>

using namespace std;

int multiply(int, int);

int main(){
    char filename[10] = "test.json";
    trace_start(filename);
    int g = 40;
    int h = 40;
    for (int i =0; i< 5000; i++)
        multiply(g, h);

    trace_end();
    return 0;
}

int multiply(int a, int b)
{
    char name[10];
    char cat[10];
    sprintf(name, "multiply%d",b);
    sprintf(cat, "foo%d", b);
    trace_event_start(name,cat);
    trace_object_new("text", &name);
    if (b < 0)
    {
        trace_event_end();
        return a;
    }
    b--;
    int c = a + multiply(a,b);
    trace_object_gone("text", &name);
    trace_event_end();
    return c;
}