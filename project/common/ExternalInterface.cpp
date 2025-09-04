#ifndef STATIC_LINK
#define IMPLEMENT_API
#endif

#if defined(HX_WINDOWS) || defined(HX_MACOS) || defined(HX_LINUX)
#define NEKO_COMPATIBLE
#endif



#include <hx/CFFI.h>
#include <hx/CFFIPrime.h>
#include "hxprocessinfo.hpp"
#include <iostream>

static value processinfo_get_memory_usage () {
	return alloc_int(hxprocessinfo::getCurrentRSS());
}
DEFINE_PRIME0 (processinfo_get_memory_usage);

static value processinfo_get_memory_peak () {
	return alloc_int(hxprocessinfo::getPeakRSS());
}
DEFINE_PRIME0 (processinfo_get_memory_peak);

static value processinfo_get_cpu_usage () {
	return alloc_float(hxprocessinfo::getCpuUsage());
}
DEFINE_PRIME0 (processinfo_get_cpu_usage);


extern "C" void processinfo_main () {
	
	hxprocessinfo::init();
	val_int(0); // Fix Neko init
	
}
DEFINE_ENTRY_POINT (processinfo_main);



extern "C" int processinfo_register_prims () { return 0; }