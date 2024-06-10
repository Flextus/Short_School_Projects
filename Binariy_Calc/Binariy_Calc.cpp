#include <iostream>
#include <thread>   
#include <chrono>
#include <string>
#include <algorithm>

int main()
{
	short int decimal = 0, binario[8], delay1 = 2, menu1;
	bool bitcheck = false, cont1 = false, pte = false, menu2 = 0;
	std::string binario1, binario2, ans;
	int tam1 = 0, tam2 = 0, bit1 = 0, bit2 = 0, suma = 0, resta = 0, pte2 = 0, mult = 0;
	
	do
	{
		do
		{
			bitcheck = false;

			std::cout << "Ingresa un valor decimal menor a 256\n";
			std::cin >> decimal;

			if (decimal < 256 && decimal >= 0)
			{
				bitcheck = true;
			}
			else
			{
				std::cout << "Por favor, ingresa un valor valido\n";
				std::this_thread::sleep_for(std::chrono::seconds(delay1));
				system("cls");

			}
		} while (!bitcheck);

		for (int i = 0; i < 8; i++)
		{
			binario[i] = decimal % 2;
			decimal /= 2;

		}
		std::cout << "El valor en binario es \n";
		for (int i = 7; i >= 0; i--)
		{
			std::cout << binario[i];
		}
		std::cout << std::endl;
		std::cout << "Presiona 1 para convertir otro Decimal y 0 para seguir con el resto del codigo\n";
		std::cin >> cont1;

	} while (cont1);

	do
	{
		std::cout << "Bien, Ahora selecciona la operacion a realizar\n";
		std::cout << "1) SUMA\n";
		std::cout << "2) RESTA\n";
		std::cout << "3) PRODUCTO\n";
		std::cin >> menu1;
	

		menu2 = false;
		switch (menu1)
		{	
		case 1:
			std::cout << "Ingresa el primer numero binario: ";
			std::cin >> binario1;

			std::cout << "Ingresa el segundo numero binario: ";
			std::cin >> binario2;

			ans = "";

				tam1 = binario1.size();
				tam2 = binario2.size();//da el tamaño string

					if (tam1 > tam2)
					{
						binario2.insert(0, tam1 - tam2, '0');
					}//iguala ambos string insertando ceros
					else if (tam2 > tam1)
					{
						binario1.insert(0, tam2 - tam1, '0');
					}

			pte = 0;
			
			for (int i = binario1.size() - 1; i >= 0; i--)
			{
				bit1 = binario1[i] - '0';
				bit2 = binario2[i] - '0';
				suma = bit1 + bit2 + pte;
				ans.insert(0, 1, (suma % 2) + '0');
				pte = suma / 2;
			}
			if (pte)
			{
				ans.insert(0, 1, '1');
			}
			std::cout << "La suma es " << ans << std::endl;
			break;

		case 2:
			std::cout << "Ingresa el primer numero binario: ";
			std::cin >> binario1;

			std::cout << "Ingresa el segundo numero binario: ";
			std::cin >> binario2;

			ans = "";

				tam1 = binario1.size();
				tam2 = binario2.size();

					if (tam1 > tam2)
					{
						binario2.insert(0, tam1 - tam2, '0');
					}
					else if (tam2 > tam1)
					{
						binario1.insert(0, tam2 - tam1, '0');
					}

			pte = 0;
			for (int i = binario1.size() - 1; i >= 0; i--)
			{
				bit1 = binario1[i] - '0';
				bit2 = binario2[i] - '0';
				resta = bit1 - bit2 - pte;
				if (resta < 0)
				{
					resta += 2;
					pte = 1;
				}
				else
				{
					pte = 0;
				}
				ans.insert(0, 1, resta + '0');
			}
			std::cout << "La resta es " << ans << std::endl;
			break;

		case 3:
			std::cout << "Ingresa el primer numero binario: ";
			std::cin >> binario1;

			std::cout << "Ingresa el segundo numero binario: ";
			std::cin >> binario2;

			tam1 = binario1.size();
			tam2 = binario2.size();

					if (tam1 > tam2)
					{
						binario2.insert(0, tam1 - tam2, '0');
					}
					else if (tam2 > tam1)
					{
				binario1.insert(0, tam2 - tam1, '0');
					}

			ans = std::string(binario1.size() + binario2.size(), '0');
			std::reverse(binario1.begin(), binario1.end());
			std::reverse(binario2.begin(), binario2.end());
			for (int i = 0; i < binario2.size(); i++)
			{
				if (binario2[i] == '1')
				{
					for (int j = 0; j < binario1.size(); j++)
					{
						int mult = (binario1[j] - '0') + (ans[i + j] - '0') + pte2;
						pte2 = mult / 2;
						ans[i + j] = (mult % 2) + '0';
					}
					if (pte2 > 0)
					{
						ans[i + binario1.size()] += pte2;
					}
				}
			}

		std::reverse(ans.begin(), ans.end());
		ans = ans.substr(ans.find('1'));

		std::cout << "El Producto es " << ans << std::endl;
		break;

		default:
			std::cout << "Por Favor Selecciona una Opcion Valida\n";
			menu2 = true;
			break;

		}
		
		std::cout << "Para Inicializar la calculadora de nuevo, presiona 1. Usa 0 para terminar la ejecucion\n";
		std::cin >> menu2;
	}
	while (menu2);
	 
}

