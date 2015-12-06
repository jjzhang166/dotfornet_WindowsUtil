#pragma once
#include <Windows.h>
#include "../Common/Common.h"
#include "ImportDescriptorIterator.h"
namespace PE
{
	template<typename _PeDecoder>
	class ImportDirectory:
		public DataDirectory<_PeDecoder, PIMAGE_IMPORT_DESCRIPTOR, IMAGE_DIRECTORY_ENTRY_IMPORT>,
		public GetIterator<ImportDescriptorIterator<ImportDirectory<_PeDecoder>>, ImportDirectory<_PeDecoder>>
	{
	public:
		friend ImportDescriptorIterator<ImportDirectory<_PeDecoder>>;
		ImportDirectory(_PeDecoder& pe) :DataDirectory<_PeDecoder, PIMAGE_IMPORT_DESCRIPTOR, IMAGE_DIRECTORY_ENTRY_IMPORT>(pe)
		{
			//this->size
		}

		~ImportDirectory()
		{
		}
	};

}