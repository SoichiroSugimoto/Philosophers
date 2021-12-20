#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void	print_test(struct timeval	time1)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	printf("   sec: %d, µsec: %d\n", (int)time.tv_sec, (int)time.tv_usec);
	printf("   sec: %d, µsec: %d\n", (int)time1.tv_sec, (int)time1.tv_usec);
}

int	main(void)
{
	struct timeval	time1;
	struct timeval	time2;
	float			diff_time;
	long long		ms;

	gettimeofday(&time1, NULL);
	printf("sec: %d, µsec: %d\n", (int)time1.tv_sec, (int)time1.tv_usec);
	sleep(1);
	print_test(time1);
	ms = (long long)time1.tv_sec * 1000 + (long long)time1.tv_usec / 1000;
	printf("ms :  %lld\n", ms);
	time2 = time1;
	// gettimeofday(&time2, NULL);
	printf("sec: %d, µsec: %d\n", (int)time2.tv_sec, (int)time2.tv_usec);
	diff_time = time2.tv_sec - time1.tv_sec
		+ (float)(time2.tv_usec - time1.tv_usec) / 1000000;
	printf("diff: %f[s]\n", diff_time);
	return (0);
}
