#include <iostream>
#include <new>
#include <cmath>
using namespace std;

#define ALLOCATE_SUCCESS	1
#define ALLOCATE_FAIL		0

bool allocation (long long memory_size);
void getrange (long long & low, long long & high);
long long getvalue (long long low, long long high);

long long Giga = pow (1024, 3);

int main ()
{
	long long memory_low, memory_high;
	getrange (memory_low, memory_high);
	long long largest_memory;
	largest_memory = getvalue(memory_low, memory_high);
	cout << "The largest memory can be allocated: " << endl;
	cout << largest_memory << " bytes" << endl;
	double largest_memory_g;
	largest_memory_g = (double) largest_memory / (double) Giga;
	cout << largest_memory_g << " GBs" << endl;

	return 0;
}

bool allocation (long long memory_size)
{
	memory_size /= sizeof(int);
	int * memory_block;
	memory_block = new (nothrow) int [memory_size];
	if (memory_block)
	{
		delete [] memory_block;
		return ALLOCATE_SUCCESS;
	}
	if (memory_block == nullptr)
		return ALLOCATE_FAIL;
}

void getrange (long long & low, long long & high)
{
	long long memory_size = 1 * Giga;
	while (1)
	{
		if (allocation(memory_size) == ALLOCATE_FAIL)
		{
			low = memory_size - Giga;
			high = memory_size;
			cout << "The largest memory can be allocated is between:" << endl;
			cout << low << " bytes ~ " << high << " bytes" << endl;
			cout << low / Giga << " GBs ~ " << high / Giga << " GBs" << endl;
			break;
		}
		memory_size += Giga;
	}
}

long long getvalue (long long low, long long high)
{
	long long mid;
	while(1)
	{
		mid = (low + high) / 2;
		if (allocation(mid) == ALLOCATE_SUCCESS)
		{
			low = mid;
		}
		else
		{
			high = mid;
		}
		if (high - low == 1)
			break;
	}
	return low;
}
