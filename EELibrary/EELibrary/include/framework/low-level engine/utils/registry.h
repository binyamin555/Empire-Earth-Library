#pragma once

#include "pch.h"

#include "framework/low-level engine/.h"

#include "../string/wide-string.h"


class URegistry
{
public:
	IMPORT URegistry();
	IMPORT URegistry(URegistry const&);

	IMPORT virtual ~URegistry();

	IMPORT URegistry& operator=(class URegistry const&);

	IMPORT long CreateRegistryKey(long, UWideString& key);
	IMPORT long DeleteRegistryKey(long, UWideString& key);

	IMPORT long DeleteRegistryValue(long, class UWideString&, class UWideString&);
	IMPORT long CreateRegistryValue(long, class UWideString&, class UWideString&, class UWideString&);
	IMPORT long CreateRegistryValue(long, class UWideString&, class UWideString&, long&);

	IMPORT long GetRegistryValue(long, class UWideString&, class UWideString&, long&);
	IMPORT long GetRegistryValue(long, class UWideString&, class UWideString&, class UWideString&);
	IMPORT long SetRegistryValue(long, class UWideString&, class UWideString&, class UWideString&);
	IMPORT long SetRegistryValue(long, class UWideString&, class UWideString&, long);
};
