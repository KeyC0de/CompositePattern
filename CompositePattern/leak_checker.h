#pragma once

#ifdef _DEBUG
#	define _CRTDBG_MAP_ALLOC
#	define _CRTDBG_MAP_ALLOC_NEW
#	include <crtdbg.h>
#	include <cassert>

namespace debugLeak
{

bool anyMemoryLeaks()
{
	// confirms integrity of memory blocks allocated by debug heap
	assert( _CrtCheckMemory() == 1 && L"_CrtCheckMemory() assertion failed\n" );
	if ( _CrtDumpMemoryLeaks() )
	{
		return true;
	}
	else
	{
		return false;
	}
}

};// namespace debugLeak

#endif