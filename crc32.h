#pragma once
#include <stdint.h>

class crc32 {
protected:
	uint32_t table[256] = {0};
public:
	uint32_t m_crc32;
	crc32();
	void ProcessCRC(void* pData, int nLen);
};
