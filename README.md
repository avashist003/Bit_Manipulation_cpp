# C++ implementation for useful bit manipulation logic

### Check if the given number is power of 2 (or one hot bit number)
```cpp
// x & (x-1) == 0 : power of 2
// Can also be used to check one hot number
int power_of_two(int num)
{
    return (num & (num-1));
}
```


### Unset given bit location in n-bit number
```cp
// Unset a given bit location
// AND with 1 retains the number, 0 makes the bit position 0.
int unset_bit(int num, int idx)
{
    int mask = ~(0x1 << idx);
    num = (num & mask);
    return num;
}
```
### Reverse a 32-bit integer
```cp
// reverse 32-bit number
// get bits starting from LSB and shift them acc to the position
int reverse_int(int num)
{
    int result = 0;
    int power = 31;

    while(num != 0)
    {
        result += (num & 0x1) << power;
        power --;
        num = num >> 1;
    }
    return result;
}
```
### Count number of set bits in a number
```cp
// Number of set bits
// get the LSBs one by one and add to a counter
int count_set_bits(int num)
{
    int result = 0;

    while(num != 0)
    {
        result += (num & 0x1);
        num = num >> 1;
    }
    return result;
}
```
### Change endianess of memory address
```cp
// swap bytes accordingly
// 0xaa_bb_cc_dd -> 0xdd_cc_bb_aa
int ChangeEndianess(int num)
{
    int byte1 = num & 0x000000ff;
    int byte2 = (num & 0x0000ff00) >> 8;
    int byte3 = (num & 0x00ff0000) >> 16;
    int byte4 = (num & 0xff000000) >> 24;

    byte1 = byte1 << 24;
    byte2 = byte2 << 16;
    byte3 = byte3 << 8;

    int result = byte1 | byte2 | byte3 | byte4;

    return result;
}
```
