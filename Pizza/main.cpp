#include<iostream>

int main()
{
	setlocale(LC_ALL, "ru");
	int perm = -1;
	int code;
	int quantity;
	float drinktotal = 0;
	float pizzatotal;
	float total = 0;
	int totalpizzas = 0;
	int pepper = 0;
	int bavar = 0;
	int grece = 0;
	int derev = 0;
	int freepepper = 0;
	int freebavar = 0;
	int freegrece = 0;
	int freederev = 0;
	int totalfree = 0;
	int cola = 0;
	int sprite = 0;
	int milk = 0;
	bool waszakaz = false;
	int freepizza = 0;
	int curdrink = 0;

	while (true)
	{
		do
		{
			if (perm == 1)
			{
				std::cout << "���������� ����� - 1: \n";
				std::cin >> perm;
			}
			else
			{
				std::cout << "����� ���������� � ��������!\n ������ ����� - 1: \n";
				std::cin >> perm;
			}

		} while (perm > 0 && perm < 1);

		if (perm == 1)
		{

			do
			{
				std::cout << "1 - ��������� - 1$ 5 - ���� - 1.2$\n2 - ��������� - 1.3$ 6 - ������ - 3$\n3 - ���������- 2.3$ 7 - �������� �������� - 5$\n4 - ����������� - 4.6$\n";
				std::cout << "������� ��� ��������: \n";
				std::cin >> code;
			} while (code > 7 && code < 1);

			do
			{
				std::cout << "������� ����������: \n";
				std::cin >> quantity;
			} while (quantity < 0);

			if (code == 1)
			{
				pepper += quantity;
				totalpizzas += quantity;
			}
			else if (code == 2)
			{
				bavar += quantity;
				totalpizzas += quantity;
			}
			else if (code == 3)
			{
				grece += quantity;
				totalpizzas += quantity;
			}
			else if (code == 4)
			{
				derev += quantity;
				totalpizzas += quantity;
			}
			else if (code == 5)
			{
				cola += quantity;
				curdrink += cola * quantity;
			}
			else if (code == 6)
			{
				sprite += quantity;
				if (quantity > 3)
				{
					curdrink += sprite * quantity / 100 * 85;
				}
				else
				{
					curdrink += sprite * quantity;
				}
			}
			else if (code == 7)
			{

				milk += quantity;
				if (quantity > 3)
				{
					curdrink += milk * quantity / 100 * 85;
				}
				else
				{
					curdrink += sprite * quantity;
				}
			}
			drinktotal += curdrink;
			curdrink = 0;
			do
			{
				std::cout << "���������� ����� - 1\n ��������� ����� - 0\n";
				std::cin >> perm;
			} while (perm > 0 && perm < 1);
			if (perm == 1)
			{
				std::cout << "����� ������������\n";
			}
			else
			{
				waszakaz = true;
				freepepper = pepper;
				freebavar = bavar;
				freegrece = grece;
				freederev = derev;
				totalfree = totalpizzas / 5;
				while (totalfree != 0)
				{
					if (freepepper > 0)
					{
						freepepper--;
					}
					else if (freebavar > 0)
					{
						freebavar--;
					}
					else if (freegrece > 0)
					{
						freegrece--;
					}
					else if (freederev > 0)
					{
						freederev--;
					}
					totalfree--;
				}



			}

		}
		else
		{
			total = 0;
		}

		if (waszakaz)
		{
			total = freepepper * 1 + freebavar * 1.3 + freegrece * 2.3 + freederev * 4.6 + drinktotal;
			if (total > 50)
			{
				total = total / 100 * 80;
			}
			std::cout << "��������� - " << pepper << ' ' << pepper * 1 << '$' << " ���� - " << cola << ' ' << cola * 1.2 << '$';
			std::cout << "\n��������� - " << bavar << ' ' << bavar * 1.3 << '$' << " ������ - " << sprite << ' ' << sprite * 3 << '$';
			std::cout << "\n��������� - " << grece << ' ' << grece * 2.3 << '$' << " �������� �������� - " << milk << ' ' << milk * 5 << '$';
			std::cout << "\n����������� - " << derev << ' ' << derev * 4.6 << "$\n";
			std::cout << "�������� ���� - " << total << "\n";
			waszakaz = false;
		}
	}


	return 0;
}