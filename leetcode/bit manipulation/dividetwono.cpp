int divide(int dividend, int divisor)
{
	bool isNegative = false;

	if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
	{
		isNegative = true;
	}

	int quotient = 0;

	if (dividend == INT32_MIN && divisor == INT32_MIN)
	{
		return 1;
	}
	else if (divisor == INT32_MIN)
	{
		return 0;
	}
	else if (dividend == INT32_MIN)
	{
		if (divisor == -1)
		{
			return INT32_MAX;
		}

		if (divisor == 1)
		{
			return INT32_MIN;
		}

		if (divisor > 0)
		{
			dividend += divisor;
			quotient = 1;
		}
		else
		{
			dividend += abs(divisor);
			quotient = 1;
		}
	}

	dividend = abs(dividend);
	divisor = abs(divisor);

	int n = 1;
	int n_times_divisor = divisor;

	while (true)
	{
		if (dividend >= n_times_divisor)
		{
			dividend -= n_times_divisor;
			quotient += n;

			// Make sure n_times_divisor won't overflow
			if (n_times_divisor > INT32_MAX - n_times_divisor)
			{
				n_times_divisor = divisor;
				n = 1;
			}
			else
			{
				// double the numbers
				n_times_divisor = n_times_divisor << 1;
				n = n << 1;
			}
		}
		else if(dividend >= divisor)
		{
			// n_times_divisor gets too big, reset it

			n_times_divisor = divisor;
			n = 1;
		}
		else
		{
			break;
		}
	}

	return isNegative ? -quotient : quotient;
}
