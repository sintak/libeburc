﻿#include "pch.h"
#include "EBInfo.h"
#include "EBBook.h"
#include "EBSubbook.h"

using namespace libeburc;

EBInfo::EBInfo() { }

String^ EBInfo::DiskType( EBBook^ Book )
{
	wchar_t * HStr = L"EPWING";
	if ( Book->disc_code == EBDiscCode::EB_DISC_EB )
	{
		HStr = L"EB/EBG/EBXA/EBXA-C/S-EBXA";
	}

	return ref new String( HStr );
}

String^ EBInfo::CharCode( EBBook^ Book )
{
	wchar_t * HStr;
	switch ( Book->character_code )
	{
	case EBCharCode::EB_CHARCODE_ISO8859_1:
		HStr = L"ISO 8859-1";
		break;
	case EBCharCode::EB_CHARCODE_JISX0208:
		HStr = L"JIS X 0208";
		break;
	case EBCharCode::EB_CHARCODE_JISX0208_GB2312:
		HStr = L"JIS X 0208 + GB 2312";
		break;
	case EBCharCode::EB_CHARCODE_UTF8:
		HStr = L"UTF-8";
		break;
	default:
		HStr = L"unknown";
		break;
	}

	return ref new String( HStr );
}

Array<String^>^ EBInfo::SearchMethods( EBSubbook^ Subbook )
{
	Vector<String^>^ methods = ref new Vector<String^>();

	if ( Subbook->have_word_search() )
	{
		methods->Append( ref new String( L"word" ) );
	}
	if ( Subbook->have_endword_search() )
	{
		methods->Append( ref new String( L"endword" ) );
	}
	if ( Subbook->have_cross_search() )
	{
		methods->Append( ref new String( L"cross" ) );
	}
	if ( Subbook->have_multi_search() )
	{
		methods->Append( ref new String( L"multi" ) );
	}
	if ( Subbook->have_menu() )
	{
		methods->Append( ref new String( L"menu" ) );
	}
	if ( Subbook->have_image_menu() )
	{
		methods->Append( ref new String( L"image-menu" ) );
	}
	if ( Subbook->have_copyright() )
	{
		methods->Append( ref new String( L"copyright" ) );
	}

	Array<String^>^ A = ref new Array<String^>( methods->Size );
	int i = 0;
	for_each( begin( methods ), end( methods ), [ & ] ( String^ s )
	{
		A->set( i++, s );
	} );

	return A;
}