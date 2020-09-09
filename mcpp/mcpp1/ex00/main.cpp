#include "Pony.hpp"

void		ponyOnTheStack()
{
	Pony stackBoy("StackBoy", "Stack");

	stackBoy.talk_bb();
}

void		ponyOnTheHeap()
{
	Pony 	*heapBoy;
	heapBoy = new Pony("HeapBoy", "Heap");

	heapBoy->talk_bb();
	delete heapBoy;
}

int main(void)
{
	ponyOnTheStack();
	ponyOnTheHeap();
	return (0);
}
