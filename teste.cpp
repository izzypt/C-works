#include <iostream>

void PrintIntroduction(int Difficulty)
{
    std::cout << std::endl;
    std::cout << R"(
     0000             0000        7777777777777777/========___________
   00000000         00000000      7777^^^^^^^7777/ || ||   ___________
  000    000       000    000     777       7777/=========//
 000      000     000      000             7777// ((     //
0000      0000   0000      0000           7777//   \\   //
0000      0000   0000      0000          7777//========//
0000      0000   0000      0000         7777
0000      0000   0000      0000        7777
 000      000     000      000        7777
  000    000       000    000       77777
   00000000         00000000       7777777
     0000             0000        777777777
    )";
     

    std::cout << std::endl;
    std::cout << "Estas no nivel " << Difficulty << std::endl << std::endl;
    std::cout << "Es um agente infiltrado , a substituir o James Bond , numa missao em que deves roubar uma reliquia durante a inauguracao do Museu Nacional de Arquelogia...\n";
    std::cout << "Entre a multidao de smoking e vestidos elegantes, consegues contornar a seguranca e  entrar na sala que te da acesso a uma valiosa antiquidade...\n";
    std::cout << "Teras de inserir o codigo de seguranca para puder levar contigo a reliquia. O codigo tem 3 numeros.";
    std::cout << std::endl;
}

bool PlayGame(int Nivel)
{

    int CodeA = rand() % Nivel + 2;
    int CodeB = rand() % Nivel + 2;
    int CodeC = rand() % Nivel + 2;
    int digito1, digito2, digito3;
    int sumResult = CodeA + CodeB + CodeC;
    int multResult = CodeA*CodeB*CodeC;
    char Y;
    char N;
    int LevelDifficulty = Nivel;


    PrintIntroduction(Nivel);
    std::cout << std::endl;
    std::cout << "A soma dos numeros e igual a ";
    std::cout << sumResult << std::endl;
    std::cout << "A sua multiplicacao e igual a ";
    std::cout << multResult << std::endl;
    std::cout << std::endl;
    std::cout << "Tu inseres o codigo , com o primeiro digito : " << std::endl;

    std::cin >> digito1;

    std::cout << "Tu inseres o codigo , com o segundo digito : " << std::endl;

    std::cin >> digito2;

    std::cout << "Tu inseres o codigo , com o terceiro digito : " << std::endl;

    std::cin >> digito3;
    std::cout << "Inseriste a combinacao " << digito1 << digito2 << digito3 << std::endl << std::endl;

    int playerSum = digito1 + digito2 + digito3;
    int playerMultiplication = digito1*digito2*digito3;

    if ( playerSum == sumResult && playerMultiplication == multResult)
    {
        std::cout << "Conseguiste aceder ao sistema e a reliquia esta nas tuas maos. Agora temos de fugir daqui sem ninguem dar por nada.\n Queres prosseguir para o proximo nivel?\n\n Y para continuar. N para desistir.";
        std::cin >> Y;
         if ( Y == 'Y')
        {
            std::cout << "Nao falhes desta vez!! Estas quase a ser apanhado..";
            PlayGame(LevelDifficulty + 1);
        }
        if( N == 'N')
        {
            std::cout << "Ok , ate a proxima.";
        }

        return true;
    }
    else
    {
        std::cout << "Combinacao Incorrecta... Cuidado para nao disparar os alarmes.\n Queres Repetir? \n Y para continuar. N para desistir. ";
        std::cin >> Y;
        if ( Y == 'Y')
        {
            std::cout << "Nao falhes desta vez!! Estas quase a ser apanhado..";
            PlayGame(LevelDifficulty);
        }
            
        if ( Y == 'N')
            std::cout << "Falhaste a missao e fugiste com o rabo entre as pernas..";
        return false;
    }

}

int main()
{
    PlayGame(1);
    return 0;
}