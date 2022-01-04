#include <fstream>
#include <iostream>
#include <vector>
#include <iterator>
#include <iomanip>
#include <algorithm>
#include <sys/stat.h>

#define PUSH 0x50
#define POP 0x58
#define NOP 0x90

#define JUNK __asm__ __volatile__ ("PUSH %rax; NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP; POP %rax");

static constexpr auto JUNK_PATTERN = {PUSH, NOP, NOP, NOP, NOP, NOP, NOP, NOP, NOP, NOP, NOP, POP};

static constexpr auto JUNK_LEN = 10;
static constexpr auto OPE_LEN = 7;

std::vector<unsigned char> read_binary(const std::string &filename)
{
    JUNK;
    
    std::ifstream file(filename, std::ios::binary);
    
    JUNK;
    
    file.unsetf(std::ios::skipws);
    std::streampos fileSize;
    file.seekg(0, std::ios::end);
    fileSize = file.tellg();
    file.seekg(0, std::ios::beg);
    
    JUNK;
    
    std::vector<unsigned char> vec;
    vec.reserve(fileSize);
    vec.insert(vec.begin(), std::istream_iterator<unsigned char>(file), std::istream_iterator<unsigned char>());
    
    JUNK;
    
    return vec;
}

void write_binary(std::vector<unsigned char> &binary, const std::string &filename)
{
    JUNK;

    std::ofstream file(filename, std::ios::out|std::ios::binary);
    std::copy(binary.cbegin(), binary.cend(), std::ostream_iterator<unsigned char>(file));
    
    JUNK;
    
    chmod(filename.c_str(), S_IRWXU);
    
    JUNK;
}

void remplace_JUNK(std::vector<unsigned char> &binary)
{
    JUNK;
    
    auto res = std::begin(binary);
    
    while(true)
    {
        res = std::search(res, std::end(binary), std::begin(JUNK_PATTERN), std::end(JUNK_PATTERN));
    
        JUNK;
    
        if(res == std::end(binary))
        {
            JUNK;
            break;
        }

        unsigned int offset = std::rand() % (JUNK_LEN - OPE_LEN) + 1;
        
        JUNK;
        
        *(res + offset) = 0x48;
        *(res + offset + 1) = 0xc7;
        *(res + offset + 2) = 0xc0;
        *(res + offset + 3) = std::rand() % (0xff + 1);
        *(res + offset + 4) = std::rand() % (0xff + 1);
        *(res + offset + 5) = std::rand() % (0xff + 1);
        *(res + offset + 6) = 0x00;

        JUNK;
    }
}

int main()
{
    std::srand(std::time(nullptr));
    
    JUNK;
    
    std::vector<unsigned char> binary = read_binary("metamorphic");
    remplace_JUNK(binary);
    write_binary(binary, "metamorphic_child_" + std::to_string(rand() % 0xffffffff));

    JUNK;

    std::cout << "Hello world !\n";
    return 0;
}