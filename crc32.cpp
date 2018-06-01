#include "crc32.h"

crc32::crc32() {
	const uint32_t CRC_POLY = 0xEDB88320;
	uint32_t i, j, r;
	for (i = 0; i < 256; i++) {
		for (r = i, j = 8; j; j--)
			r = r & 1 ? (r >> 1) ^ CRC_POLY : r >> 1;
		table[i] = r;
	}
	m_crc32 = 0;
}

void crc32::ProcessCRC(void* pData, register int nLen) {
	const uint32_t CRC_MASK = 0xD202EF8D;
	register unsigned char* pdata = reinterpret_cast<unsigned char*>(pData);
	register uint32_t crc = m_crc32;
	while (nLen--) {
		crc = table[static_cast<unsigned char>(crc) ^ *pdata++] ^ crc >> 8;
		crc ^= CRC_MASK;
	}
	m_crc32 = crc;
}
