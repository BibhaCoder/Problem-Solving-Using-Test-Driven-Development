#include <stdio.h>
#include <stdint.h>

static void spin_lock(void);
static void spin_unlock(void);
static volatile uint32_t my_spin_lock = 0;

void spin_lock(void)
{
	while (__sync_lock_test_and_set(&my_spin_lock, 1)) 
		printf("keep spining as spin lock is not available\n");

	printf("stop spinning as spin lock is available and acquire it\n");
}

void spin_unlock(void)
{
	__sync_synchronize();
	my_spin_lock = 0;
	printf("release spin lock\n");
}

int main()
{
	spin_lock();
	spin_unlock();
	spin_lock();
	spin_unlock();
	spin_lock();
	spin_lock();

	return 0;
}
