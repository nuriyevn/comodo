#include <iostream>
#include <fstream>

using namespace std;

const int BUFF_SIZE = 2048;

char getNibbleChar(int hex)
{
   hex = ( 
           (hex >= 10) ? 
           ('A' - 10 + hex) : 
           ('0' + hex) 
         );  
   return (char)hex;
}

inline char* byteToHex(unsigned char ch, char *chex)
{
   int len = 0;
   //int hex[3] = {0};

   chex[2] = 0;   
   chex[1] = ch % 16;
   chex[0] = ch / 16 % 16;

   chex[1] = getNibbleChar(chex[1]);
   chex[0] = getNibbleChar(chex[0]);

   //cout << chex[0] << chex[1] << " ";  
   return chex;
}

void printHex(const char* data, int size)
{
   for (int i = 0; i < size; i++)
   {
      char hex[3];
      cout << byteToHex(data[i], &hex[0]);     
   }  
}

int main()
{
   fstream  f;
   f.open("../test/infected.1");
   if (f.is_open())
   {
      
      char buffer[BUFF_SIZE];
      f.read(buffer, BUFF_SIZE);
      
      if (f)
      {
         std::cout << "all characters read successfully." << endl;  
      }
      else
      {
         std::cout << "Only: " << f.gcount() << " is read" << endl;        
      }
      
      printHex(buffer, f.gcount());

      f.close();      
   }
}
