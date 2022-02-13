#include <iostream>
#include <bitset>
#include <iomanip>

// x & (x-1) == 0 : power of 2
// Can also be used to check one hot number
int power_of_two(int num)
{
    return (num & (num-1));
}

// Unset a given bit location
// AND with 1 retains the number, 0 makes the bit position 0.
int unset_bit(int num, int idx)
{
    int mask = ~(0x1 << idx);
    num = (num & mask);
    return num;
}

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

int main()
{
    int num = 32;
    int check;
    
    check = power_of_two(num);

    if (check == 0)
    {
        std::cout << "Perfect power of 2 " << std::endl;
    }
    else {
        std::cout << "Not a power of 2 " << std::endl;
    }

    //
    int num_unset = unset_bit(5,0);
    std::cout << num_unset << std::endl;

    //
    int rev_num = reverse_int(5);
    std::cout << std::bitset<32>(rev_num) << std::endl;

    //
    int n_set = count_set_bits(10);
    std::cout << n_set << std::endl;

    //
    int end_chng = ChangeEndianess(0x12345678);
    std::cout << std::hex << end_chng << std::endl;


    return 0;
}