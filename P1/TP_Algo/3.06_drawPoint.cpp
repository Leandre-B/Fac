#include <iostream>

int main()
{

    int longeur;
    int larg;

    std::cout << "longeur ? ";
    std::cin >> longeur;
    std::cout << "larg ? ";
    std::cin >> larg;

    // carre plein
    for (int i = 0; i < longeur; i++)
    {
        for (int j = 0; j < larg; j++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl
              << std::endl;

    // carre vide
    for (int i = 1; i <= longeur; i++)
    {
        std::cout << "*";
        for (int j = 1; j <= larg - 2; j++)
        {

            if (i == 1 or i == larg)
                std::cout << "*";
            else
                std::cout << " ";
        }
        std::cout << "*";
        std::cout << std::endl;
    }

    std::cout << std::endl
              << std::endl;

    // alterne (peut mieux faire)
    for (int i = 1; i <= longeur; i++)
    {
        for (int j = 1; j <= larg; j++)
        {
            if (i % 2 == 1)
            {
                if (j % 2 == 0)
                    std::cout << " ";
                else
                    std::cout << "*";
            }
            else
            {
                if (j % 2 == 0)
                    std::cout << "*";
                else
                    std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    std::cout << std::endl
              << std::endl;

    // escalier descendant
    for (int i = 1; i <= longeur; i++)
    {

        for (int k = 1; k <= i; k++)
        {
            std::cout << "*";
        }
        for (int l = 1; l <=larg-i; ++l)
            {
                std::cout << " ";
            }

        std::cout << std::endl;
    }

    std::cout << std::endl
              << std::endl;
    
    // escalier descendant inversé
    for (int i = longeur; i >= 1; --i)
    {

        for (int k = 1; k <= i; k++)
        {
            std::cout << "*";
        }
        for (int l = 1; l <=larg-i; ++l)
            {
                std::cout << " ";
            }

        std::cout << std::endl;
    }

    std::cout << std::endl
              << std::endl;

    // escalier montant
    for (int i = longeur; i >= 1; --i)
    {

        for (int k = 1; k <= i; k++)
        {
            std::cout << " ";
        }
        for (int l = 1; l <=larg-i; ++l)
            {
                std::cout << "*";
            }

        std::cout << std::endl;
    }

    std::cout << std::endl
              << std::endl;

    // escalier montant inversé
    for (int i = 1; i <= longeur; i++)
    {

        for (int k = 1; k <= i; k++)
        {
            std::cout << " ";
        }
        for (int l = 1; l <=larg-i; ++l)
            {
                std::cout << "*";
            }

        std::cout << std::endl;
    }

    std::cout << std::endl
              << std::endl;
    return 0;
}
