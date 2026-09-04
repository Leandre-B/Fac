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
			if ((c & 0b10000000) != 0b10000000)
			{
				convertion += c;
			}
			else
			{
				convertion += (0b11000000 | ((c >> 6) & 0b00000011));
				convertion += (c & 0b00111111) | 0b10000000;
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
				if ((c & 0b11100000) == 0b11000000)
				{
					char conv = ((c & 0x03) << 6);
					fic.get(c);

					conv |= (c & 0b00111111);

					convertion += conv;
				}

				else if ((c & 0b11110000) == 0b11100000)
					bit_to_ignore = 1;

				else if ((c & 0b11111000) == 0b11110000)
					bit_to_ignore = 2;
				for (int j = 0; j < bit_to_ignore; ++j)
				{
					fic.ignore();
					convertion += '?';
				}
			}
		}
	}
	else
		std::cerr << "Erreur lors de l'ouverture de \"" << file << "\"\n";
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
		std::cout << UTF8ToLatin1(file) << "\n";
	else if (from == "latin1" && to == "utf8")
		std::cout << latin1ToUTF8(file) << "\n";
	else if (from == to)
		std::cout << getFileContent(file) << "\n";

	return 0;
}