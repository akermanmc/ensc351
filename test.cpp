#include <cstdio>
#include "tracelib.h"
#include <iostream>
#include <chrono>

using namespace std;

int multiply(int, int);

int add (int v1, int v2){
	trace_counter("counter", "add1", "100");
	int res = v1+v2;
	trace_counter("counter", "add1", "200");
	return res;
}

int main(){
    char filename[10] = "test.json";
    trace_start(filename);
    add(2,2);
    int g = 40;
    int h = 40;
    for (int i =0; i< 5000; i++)
        multiply(g, h);

    trace_end();
    //add(1, 1);
    return 0;
}

int multiply(int a, int b)
{
    char name[20];
    char cat[20];
    sprintf(name, "multiply%d",b);
    sprintf(cat, "foo%d", b);
    trace_event_start(name,cat, nullptr);
    trace_object_new("text", &name);
    if (b <= 0)
    {
        trace_event_end(nullptr);
        return a;
    }
    b--;
    int c = a + multiply(a,b);
    trace_object_gone("text", &name);
    trace_event_end(nullptr);
    return c;
}