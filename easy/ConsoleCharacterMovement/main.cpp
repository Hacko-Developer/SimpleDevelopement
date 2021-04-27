#include <conio.h>
#include <iostream>
#include <windows.h>

using namespace std;
template<typename Char, typename Traits, typename Allocator>
std::basic_string<Char, Traits, Allocator> operator *
(const std::basic_string<Char, Traits, Allocator> s, size_t n)
{
    std::basic_string<Char, Traits, Allocator> tmp = s;
    for (size_t i = 0; i < n; ++i)
    {
        tmp += s;
    }
    return tmp;
}

template<typename Char, typename Traits, typename Allocator>
std::basic_string<Char, Traits, Allocator> operator *
(size_t n, const std::basic_string<Char, Traits, Allocator>& s)
{
    return s * n;
}

void movement(int speed)
{

    int position_z = 0;
    int position_x = 0;
    std::string vector_z = "\n";
    std::string vector_x = "  ";
    std::string hero = "(-_-)";
    std::string hero_back = "(   )";
    std::string hero_right = "( -_)";
    std::string hero_left = "(_- )";
    while (true) {
        if (GetAsyncKeyState(0x53) & 0x01)
        {
            system("cls");
            position_z = ++position_z;
            std::cout << (vector_z * position_z) * speed << (vector_x * position_x) * speed << hero << std::endl;
        }
        if (GetAsyncKeyState(0x57) & 0x01)
        {
            system("cls");
            position_z = --position_z;
            std::cout << (vector_z * position_z) * speed << (vector_x * position_x) * speed << hero_back << std::endl;
        }
        if (GetAsyncKeyState(0x44) & 0x01)
        {
            system("cls");
            position_x = ++position_x;
            std::cout << (vector_z * position_z) * speed << (vector_x * position_x) * speed << hero_right << std::endl;;
        }
        if (GetAsyncKeyState(0x41) & 0x01)
        {
            system("cls");
            position_x = --position_x;
            std::cout << (vector_z * position_z) * speed << (vector_x * position_x) * speed << hero_left << std::endl;
        }
    }
}

int main()
{
    movement(1);
}