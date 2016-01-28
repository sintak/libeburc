#include "pch.h"
#include "eburc/Objects/EBPosition.h"

using namespace libeburc;

EBPosition::EBPosition( int Page, int Offset )
{
	page = Page;
	offset = Offset;
}
EBPosition::EBPosition()
{
	page = 0;
	offset = 0;
}