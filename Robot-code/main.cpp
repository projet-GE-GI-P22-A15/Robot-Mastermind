#include <pid.h>

int main() {
	int distance = (int) (2.54 * 200);
	avancerDroit(1, distance, 100);

	return 0;
}
