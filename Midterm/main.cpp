#include <cassert>
#include <iostream>
#include <iomanip>

int main()
{
    int nums[] = { 1, 2, 3, 4 };
    int* p = nums;

    int*& pRef = p;

    ++pRef;
    *pRef += 1;

    assert(*p == 3);
    assert(*p == *(nums + 1));

    for (size_t i = 0; i < 4; ++i)
    {
        printf("%d, ", nums[i]);
    }

    puts("");
    
    printf("No prob");
    return 0;
}