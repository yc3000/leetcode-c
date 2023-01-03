
int reverse(int x)
{
	int next_x = x;
	int ret = 0;

	for (int i = 0;; ++i) {
		int high_val = next_x;
		int count = 0;
		while (high_val >= 10) {
			high_val /= 10;
			++count;
		}

		int k2 = 1;
		for (int j = 0; j < count; ++j)
			k2 *= 10;
		next_x = next_x / 10;

		int k = 1;
		for (int j = 0; j < i; ++j)
			k *= 10;
		ret += high_val * k;
	}

	return ret;
}
