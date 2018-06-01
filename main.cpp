#include "LinkedList.h"
#include "ArrayList.h"
#include "crc32.h"
#include <iostream>

int main() {
	int a_i = 8;
	LinkedList<int> a(a_i);
	int a_j = 12;
	int a_k = 25;
	a.add(a_j);
	a.push_forward(a_k);
	ArrayList<int> b(a_i);
	b.add(a_j);
	b.push_forward(a_k);
	int c = b[1];
	char dataset[] = "abcdefghijklmnopqrstuvwxyz****abcdefghijklmnopqrstuvwxyz****abcdefghijklmnopqrstuvwxyz****abcdefghijklmnopqrstuvwxyz****abcdefghijklmnopqrstuvwxyz****abcdefghijklmnopqrstuvwxyz****abcdefghijklmnopqrstuvwxyz****abcdefghijklmnopqrstuvwxyz****abcdefghijklmnopqrstuvwxyz****abcdefghijklmnopqrstuvwxyz****abcdefghijklmnopqrstuvwxyz****abcdefghijklmnopqrstuvwxyz****abcdefghijklmnopqrstuvwxyz****abcdefghijklmnopqrstuvwxyz****abcdefghijklmnopqrstuvwxyz****abcdefghijklmnopqrstuvwxyz****abcdefghijklmnopqrstuvwxyz****abcdefghijklmnopqrstuvwxyz****abcdefghijklmnopqrstuvwxyz****abcdefghijklmnopqrstuvwxyz****";
	crc32 crc;
	crc.ProcessCRC(dataset, sizeof(dataset));
	std::cout << crc.m_crc32;
	return 0;
}