#include <bitset>
#include <fstream>
#include <iostream>

std::string getFileContent(std::string file)
{

	std::ifstream fic(file);
	std::string ligne;
	std::string convertion;
	while (std::getline(fic, ligne))
		convertion += ligne;
	return convertion;
}

std::string latin1ToUTF8(std::string file)
{

	std::ifstream fic(file, std::ios::binary);
	char c;
	std::string convertion = "";
	if (fic.is_open())
	{
		while (fic.good())
		{

			fic.get(c);
			if ((c & 0x80) != 0x80)
			{
				convertion += c;
			}
			else
			{
				convertion += (0xC0 | ((c >> 6) & 0x03));
				convertion += (c & 0x3F) | 0x80;
				// std::cout<<std::bitset<8>(c)<<"\n";
				// std::cout<<std::bitset<8>(0xC0 | ((c>>6)&0x03))<<"\n";
				// std::cout<<std::bitset<8>((c&0x3F) | 0x80)<<"\n";
			}
		}
	}
	return convertion;
}

std::string UTF8ToLatin1(std::string file)
{

	std::ifstream fic(file, std::ios::binary);
	char c;
	std::string convertion = "";
	if (fic.is_open())
	{
		while (fic.good())
		{

			fic.get(c);
			if ((c & 0x80) != 0x80)
			{
				convertion += c;
			}
			else
			{
				int bit_to_ignore = 0;
				if ((c & 0xE0) == 0xC0) // 110xxxxx
				{
					// std::cout<<std::bitset<8>(c)<<"\n";
					char conv = ((c & 0x03) << 6);
					fic.get(c);
					// std::cout<<std::bitset<8>(c)<<"\n";

					conv |= (c & 0x3F);
					// std::cout<<std::bitset<8>(conv)<<"\n";

					convertion += conv;
				}

				else if ((c & 0xF0) == 0xE0) // 1110xxx
					bit_to_ignore = 1;

				else if ((c & 0xF8) == 0xF0) // 11110xxx
					bit_to_ignore = 2;
				for (int j = 0; j < bit_to_ignore; ++j)
				{
					fic.ignore();
					convertion += '?';
				}
			}
		}
	}
	return convertion;
}

int main(int argc, char** argv)
{

	if (argc != 4)
	{
		std::cerr << "Wrong usage.\n";
		return 0;
	}
	std::string from = argv[1];
	std::string to = argv[2];
	std::string file = argv[3];
	if (from == "utf8" && to == "latin1")
		std::cout << UTF8ToLatin1(file);
	else if (from == "latin1" && to == "utf8")
		std::cout << latin1ToUTF8(file);
	else if (from == to)
		std::cout << getFileContent(file);

	return 0;
}