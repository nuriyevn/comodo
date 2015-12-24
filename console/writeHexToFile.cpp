#include <iostream>
#include <fstream>

using namespace std;
const int BUFF_SIZE = 2048;

// hex[0] - most significant
// hex[1] - least significant

int getNibbleByte(unsigned char byte)
{
   int result = 0;
   if (byte >= 'A')
   {
      result = byte - 'A' + 10;  
   }
   else
   {
      result = byte - '0';
   }
//   cout << (int)result << endl;
   return result; 
}

inline unsigned char hexToByte(unsigned char hex[2])
{
   unsigned char result = 0;
   int ms = getNibbleByte(hex[0]);
   int ls = getNibbleByte(hex[1]);

   result = (ms << 4) | ls;
   //cout << (ms << 4)  << " " << ls << " " << (int)result << endl ; 
   return result;    
}

void printBytes(const char* data, int size)
{
   for (int i = 0; i < size / 2; i++)
   {
      unsigned char hex[2];
      hex[0] = data[2*i];
      hex[1] = data[2*i+1];
      cout << hexToByte(hex);
    //  cout << hex[0] << hex[1] << endl;
   }
}


int main()
{
   fstream f;
   f.open("../test/hex.txt");
   if (f.is_open())
   {
      char buffer[BUFF_SIZE];
      f.read(buffer, BUFF_SIZE);
      if (f)
      {
         std::cout << "all chars read successfully." << endl;
      }
      else
      {
         std::cout << "Only: " << f.gcount() << "is read" << endl;
      }
   
      printBytes(buffer, f.gcount());
       
      f.close();
   }
   else
      std::cout << "Cannot open file" << endl;
}
