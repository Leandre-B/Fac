#include <fstream>
#include <iostream>
#include <typeinfo>

enum class Encoding
{
	UNDETERMINDED,
	UTF8,
	LATIN1,
	ASCII
};

/*
	Determine l'encodage du fichier passé en paramètre.
	- ASCII : Si pas de caractères spéciaux
	— UTF-8 : Si on détecte un caractère sur 2, 3 ou 4 octets
	— latin-1 sinon
*/

Encoding getEncoding(std::string file)
{
	std::ifstream fic(file, std::ios::binary);
	char c;

	if (fic.is_open())
	{
		bool isUTF8 = false;
		while (fic.good())
		{
			fic.get(c);
			// si le bit de poid est à 1 -> pas ASCII
			if ((c & 0b10000000) == 0b10000000)
			{

				// On regarde le bit suivant pour déterminer si UTF-8
				char next_c;

				int bit_to_check = 0;
				if ((c & 0b11111000) == 0b11110000)
					bit_to_check = 3;
				else if ((c & 0b11110000) == 0b11100000)
					bit_to_check = 2;
				else if ((c & 0b11100000) == 0b11000000)
					bit_to_check = 1;
				else
					return Encoding::LATIN1;
				for (int j = 0; j < bit_to_check; ++j)
				{
					fic.get(next_c);
					if (!fic.eof() && (next_c & 0b11000000) == 0b10000000)
						isUTF8 = true;
					else
						return Encoding::LATIN1;
				}
			}
		}
		if (isUTF8)
			return Encoding::UTF8;
		else
			return Encoding::ASCII;
	}
	else
	{
		std::cerr << "Erreur lors de l'ouverture de \"" << file << "\"\n";
		return Encoding::UNDETERMINDED;
	}
}

int main(int argc, char** argv)
{
	if (argc == 1)
	{
		std::cout << "Besoin au moins d'un argument !\n.";
		return 0;
	}

	for (int i = 1; i < argc; ++i)
	{
		Encoding encoding = getEncoding(argv[i]);
		switch (encoding)
		{

			case Encoding::ASCII:
				std::cout << argv[i] << " est en ASCII\n";
				break;

			case Encoding::LATIN1:
				std::cout << argv[i] << " est en Latin-1\n";
				break;

			case Encoding::UTF8:
				std::cout << argv[i] << " est en UTF-8\n";
				break;

			case Encoding::UNDETERMINDED:
				std::cout << "N'a pas pu determiner l'encodage de \"" << argv[i] << "\"\n";
				break;
		}
	}

	return 0;
}