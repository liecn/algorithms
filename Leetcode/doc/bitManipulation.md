# Bit Manipuilation
`^`:remove even exactly same numbers and save the odd, or save the distinct bits and remove the same.
```
a^a=0;
a^0=a;
```
-  find the value representing the least significant bit 1.
`int bit = res & ~(res-1);`
- Count the number of ones in the binary representation of the given number
```
int hammingWeight(uint32_t n) {
	int count = 0;
	while(n) {
		n = n&(n-1);
		count++;
	}
	return count;
}
```
- Use `^` and `&` to add two integers
```
int getSum(int a, int b) {
    return b==0? a:getSum(a^b, (a&b)<<1); //be careful about the terminating condition;
}
```

[Reference](https://leetcode.com/problems/sum-of-two-integers/discuss/84278/A-summary%3A-how-to-use-bit-manipulation-to-solve-problems-easily-and-efficiently)

