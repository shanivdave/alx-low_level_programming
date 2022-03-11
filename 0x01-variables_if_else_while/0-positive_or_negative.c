#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/**
<<<<<<< HEAD
 *  * main - main block
 *   * Description: Get a random number and print the number
 *    * and if it is positive, negative, or zero
 *     * Return: 0
 *      */
=======
 * main - Entry point
 * Return:1
 */
>>>>>>> 5581c64ebbcddaab12a4bfe0bfd521f283b95397
int main(void)
{
		int n;

			srand(time(0));
				n = rand() - RAND_MAX / 2;
					if (n > 0)
								printf("%i is positive\n", n);
						else if (n < 0)
									printf("%i is negative\n", n);
							else
										printf("%i is zero\n", n);								return (0);
}
