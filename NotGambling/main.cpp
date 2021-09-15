#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct cardInfo {
	bool isPaper; //�̰� ��������ī�� 2���� �����ϴ°�
	int num;
	bool visited = false;
};

vector<cardInfo>Card;

class NotGambling {
private:
	vector<cardInfo>selectPae;
	vector<pair<int, bool>>PanstarBox;
public:	
	void pickPae(cardInfo pae1, cardInfo pae2) {
		selectPae.resize(2);
		selectPae[0].num = pae1.num;
		selectPae[0].isPaper = pae1.isPaper;
		selectPae[1].num = pae2.num;
		selectPae[1].isPaper = pae2.isPaper;
	}
	int panstar() {
		PanstarBox.resize(2);
		PanstarBox[0].first = selectPae[0].num;
		PanstarBox[0].second = selectPae[0].isPaper;
		PanstarBox[1].first = selectPae[1].num;
		PanstarBox[1].second = selectPae[1].isPaper;
		sort(PanstarBox.begin(), PanstarBox.end());
		if (PanstarBox[0].first == 3 && PanstarBox[0].second == false && PanstarBox[1].first == 8 && PanstarBox[1].second == false) {
			return 1;
		}//���ȱ���
		if (PanstarBox[0].first == 1 && PanstarBox[0].second == false && PanstarBox[1].first == 3 && PanstarBox[1].second == false) {
			return 2;
		}//�ϻﱤ��
		if (PanstarBox[0].first == 1 && PanstarBox[0].second == false && PanstarBox[1].first == 8 && PanstarBox[1].second == false) {
			return 2;
		}//���ȱ���
		if (PanstarBox[0].first == PanstarBox[1].first) {
			return 13 - PanstarBox[0].first;
		}//��
		if (PanstarBox[0].first == 1 && PanstarBox[1].first == 2) {
			return 13;
		}//�˸�
		if (PanstarBox[0].first == 1 && PanstarBox[1].first == 10) {
			return 14;
		}//���
		if (PanstarBox[0].first == 1 && PanstarBox[1].first== 4) {
			return 15;
		}//����
		if (PanstarBox[0].first == 4 && PanstarBox[1].first == 10) {
			return 16;
		}//���
		if (PanstarBox[0].first == 1 && PanstarBox[1].first == 9) {
			return 17;
		}//����
		if (PanstarBox[0].first == 4 && PanstarBox[1].first == 6) {
			return 18;
		}//����
		if (PanstarBox[0].first == 4 && PanstarBox[1].first == 7) {
			return 88;
		}//������
		if (PanstarBox[0].first == 3 && PanstarBox[1].first == 7) {
			return 90;
		}//������
		if (PanstarBox[0].first == 4 && PanstarBox[0].second == false && PanstarBox[1].first == 9 && PanstarBox[1].second == false) {
			return -100;
		}//���ֱ��� ����
		else if (PanstarBox[0].first == 4 && PanstarBox[1].first == 9) {
			return -99;
		}//����
		else {
			int hap;
			if (PanstarBox[0].first + PanstarBox[1].first >= 10) {
				hap = PanstarBox[0].first + PanstarBox[1].first - 10;
			}
			else {
				hap = PanstarBox[0].first + PanstarBox[1].first;
			}
			return 28 - hap;
			//��
		}
	}
};

string Paestr(int rank) {
	if (rank == 1) {
		return "���ȱ���";
	}
	else if (rank == 2) {
		return "�ϻﱤ�� Ȥ�� ���ȱ���";
	}
	else if (rank == 3) {
		return "�嶯";
	}
	else if (rank == 4) {
		return "����";
	}
	else if (rank == 5) {
		return "�ȶ�";
	}
	else if (rank == 6) {
		return "ĥ��";
	}
	else if (rank == 7) {
		return "����";
	}
	else if (rank == 8) {
		return "����";
	}
	else if (rank == 9) {
		return "�綯";
	}
	else if (rank == 10) {
		return "�ﶯ";
	}
	else if (rank == 11) {
		return "�̶�";
	}
	else if (rank == 12) {
		return "�϶�";
	}
	else if (rank == 13) {
		return "�˸�";
	}
	else if (rank == 14) {
		return "���";
	}
	else if (rank == 15) {
		return "����";
	}
	else if (rank == 16) {
		return "���";
	}
	else if (rank == 17) {
		return "����";
	}
	else if (rank == 18) {
		return "����";
	}
	else if (rank == 19) {
		return "����";
	}
	else if (rank == 20) {
		return "8��";
	}
	else if (rank == 21) {
		return "7��";
	}
	else if (rank == 22) {
		return "6��";
	}
	else if (rank == 23) {
		return "5��";
	}
	else if (rank == 24) {
		return "4��";
	}
	else if (rank == 25) {
		return "3��";
	}
	else if (rank == 26) {
		return "2��";
	}
	else if (rank == 27) {
		return "1��";
	}
	else if (rank ==28) {
		return "����";
	}
	else if (rank == 88) {
		return "������";
	}
	else if (rank == 90) {
		return "������";
	}
	else if (rank == -100) {
		return "���ֱ��� ����";
	}
	else if (rank == -99) {
		return "����";
	}
}

class Player :public NotGambling{
private:
	int token = 100;
public:
	cardInfo	 Pae[3];
	void PlusToken(int N) {	
		token = token + N;
	}
	void MinusToken(int N) {
		token = token - N;
	}
	int Showtoken() {
		return token;
	}
	void getPae(cardInfo x, int N) {
		Pae[N] = x;
	}
	void ShowPae(int Hwetsu) {
		cout << "\n\n\n\t\t���� ��: ";
		for (int i = 0; i < Hwetsu; i++) {
			cout << "\t\t" << Pae[i].num << ' ' << "type: " << Pae[i].isPaper;
		}
	}
};

class AI :public NotGambling {
private:
	int token = 100;
public:
	cardInfo Pae[3];
	void PlusToken(int N) {
		token = token + N;
	}
	void MinusToken(int N) {
		token = token - N;
	}
	void getPae(cardInfo x, int N) {
		Pae[N] = x;
	}
	int Showtoken() {
		return token;
	}
	void ShowPae(int Hwetsu, int N) {
		cout << "\n\n\n\t\t��� ��: ";
		for (int i = 0; i < Hwetsu; i++) {
			if (i == N) {
				cout << "\t\t" << Pae[i].num << ' ' << "type: " << Pae[i].isPaper;
			}
			else {
				cout << "\t\t(������ ī��)";
			}
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	srand(time(NULL));
	system("mode con: cols=200 lines=200");
	int count = 1;
	Card.resize(20);
	for (int i = 0; i < 20; i++) {
		if (i % 2) {
			Card[i].isPaper = true;
			Card[i].num = count;
		}
		else {
			Card[i].isPaper = false;
			Card[i].num = count;
		}
		if (i % 2 == 1 && i != 0) {
			count++;
		}
	}
	cout << "\n\n\n\n\n\n\n\n\n\n\n::::    :::  ::::::::  :::::::::::  ::::::::      :::     ::::    ::::  :::::::::  :::        ::::::::::: ::::    :::  ::::::::  \n";
	cout << ":+:+:   :+: :+:    :+:     :+:     :+:    :+:   :+: :+:   +:+:+: :+:+:+ :+:    :+: :+:            :+:     :+:+:   :+: :+:    :+: \n";
	cout << ":+:+:+  +:+ +:+    +:+     +:+     +:+         +:+   +:+  +:+ +:+:+ +:+ +:+    +:+ +:+            +:+     :+:+:+  +:+ +:+        \n";
	cout << "+#+ +:+ +#+ +#+    +:+     +#+     :#:        +#++:++#++: +#+  +:+  +#+ +#++:++#+  +#+            +#+     +#+ +:+ +#+ :#:        \n";
	cout << "+#+  +#+#+# +#+    +#+     +#+     +#+   +#+# +#+     +#+ +#+       +#+ +#+    +#+ +#+            +#+     +#+  +#+#+# +#+   +#+# \n";
	cout << "#+#   #+#+# #+#    #+#     #+#     #+#    #+# #+#     #+# #+#       #+# #+#    #+# #+#            #+#     #+#   #+#+# #+#    #+# \n";
	cout << "###    ####  ########      ###      ########  ###     ### ###       ### #########  ########## ########### ###    ####  ########  \n";
	Sleep(3000);
	system("cls");
	char MeaninglessBox;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\t\tī������ӿ� ���Ű��� ȯ���մϴ�. ���� ������ �����Ͻðڽ��ϱ�?\n\t\t1. ����\n\t\t2. ����\n\t\t3. ����\n\t\t4. ����\n\t\t5. ����\n\t\t>> ";
	cin >> MeaninglessBox;
	cout << "\t\t���ٸ� �����ϼ̽��ϴ�!\n";
	cout << "\t\t���� �� ����: ȭ���� 2������ ������ ����� �� ���� ������ ���� �÷��̾ �¸��ϴ� ����\n\t\t���� ���� 2���� �׸��� ������ �׷����ִ� ī��� type 1 ������ �ȱ׷����ְų� ���� ī��� type 0���� ����\n\t\t���ֱ��� ���� �Ǵ� ���� �Ǵ� ���ºη� ���� ����� 2��ºΰ� �ƴ� ���� ó������ �����մϴ�.\n";
	cout << "\t\t��Ģ�� �����ߴٸ� �ƹ�Ű�� ����Ű�� �Է��Ͻʽÿ�\n";
	cin >> MeaninglessBox;
	cout << "\t\t�ٸ� �÷��̾�� ��Ī�� �����ϰڽ��ϴ�";
	Sleep(2000);
	system("cls");
	for (int i = 1; i <= 2; i++) {
		cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t�÷��̾�� ����� �Ƿ��� ��븦 ��Ī���Դϴ� ";
		for (int j = 0; j < 3; j++) {
			cout << ". ";
			Sleep(1000);
		}
		system("cls");
	}
	cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t��Ī ����!\n\t\t�г���: �μ��ѹμ�\n\t\t��ũ: ÿ����\n\t\t�·�: 87%";
	Sleep(2000);
	cout << "\n\t\t������ �����ϰڽ��ϴ�.";
	Sleep(1000);
	system("cls");
	AI Minseo;
	Player player;
	int i = 1;
	int GunToken = 0;
	int Dap;
	while (true) {
		if (GunToken == 0) {
			if (player.Showtoken() <= 0) {
				cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t����� �Ļ��Ͽ����ϴ�. ������ �����մϴ�.";
				break;
			}
			if (Minseo.Showtoken() <= 0) {
				cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t�μ��ѹμ���(��) �Ļ��Ͽ����ϴ�. ������ �����մϴ�.";
				break;
			}
		}
		cout << "�� ��ū: " << player.Showtoken() << " ��� ��ū: " << Minseo.Showtoken();
		cout << " ���� �ɷ��ִ� ��ū: " << GunToken;
		while (i <= 4) {
			int N = rand() % 20;
			if (Card[N].visited == true) {
				continue;
			}
			if (i <= 2) {
				Minseo.getPae(Card[N], i - 1);
			}
			else {
				player.getPae(Card[N], i - 3);
			}
			Card[N].visited = true;
			i++;
		}
		int boyozugi = rand() % 2;
		Minseo.ShowPae(2, boyozugi);
		player.ShowPae(2);
		cout << "\n\t\t����(1) or ����(2) >>";
		cin >> Dap;
		if (Dap == 2) {
			cout << "����!\n";
			Minseo.PlusToken(GunToken);
			Sleep(1000);
			system("cls");
			Sleep(1000);
			for (int i = 0; i < 20; i++) {
				Card[i].visited = false;
			}
			continue;
		}
		cout << "\t\t�󸶸� �����Ͻðڽ��ϱ�?\n\t\t";
		int Paytoken;
		while (true) {
			cin >> Paytoken;
			if (Paytoken > player.Showtoken()) {
				cout << "\n\t\t�����ϰ��ִ� ��ū���� ���� ��ū�� ������ �� �����ϴ�!\n\t\t";
				continue;
			}
			break;
		}
		if (Paytoken >= Minseo.Showtoken()) {
			cout << "\t\t�μ��ѹμ�: ����!\n";
			GunToken += Paytoken + Minseo.Showtoken();
			Minseo.MinusToken(Minseo.Showtoken());
		}
		else {
			cout << "\t\t�μ��ѹμ�: ���󰡰ڽ��ϴ�.\n";
			Minseo.MinusToken(Paytoken);
		}
		GunToken += Paytoken * 2;
		player.MinusToken(Paytoken);
		cout << "\t\tī�� ������ �� �帮�ڽ��ϴ�.\n";
		i = 1;
		while (i <= 2) {
			int N = rand() % 20;
			if (Card[N].visited == true) {
				continue;
			}
			if (i == 1) {
				Minseo.getPae(Card[N], 2);
			}
			else {
				player.getPae(Card[N], 2);
			}
			i++;
		}
		Minseo.ShowPae(3, boyozugi);
		player.ShowPae(3);
		cout << "\n\t\t����(1) or ����(2) >>";
		cin >> Dap;

		if (Dap == 2) {
			cout << "����!\n";
			cout << "\t\t���� " << GunToken << "�� ��ū�� �������ϴ�!";
			Minseo.PlusToken(GunToken);
			Sleep(1000);
			system("cls");
			Sleep(1000);
			for (int i = 0; i < 20; i++) {
				Card[i].visited = false;
			}
			continue;
		}
		cout << "\t\t�󸶸� �����Ͻðڽ��ϱ�?\n\t\t";
		while (true) {
			cin >> Paytoken;
			if (Paytoken > player.Showtoken()) {
				cout << "\n\t\t�����ϰ��ִ� ��ū���� ���� ��ū�� ������ �� �����ϴ�!\n\t\t";
				continue;
			}
			break;
		}
		if (Paytoken >= Minseo.Showtoken()) {
			cout << "\t\t�μ��ѹμ�: ����!\n";
			GunToken = Paytoken + Minseo.Showtoken();
			Minseo.MinusToken(Minseo.Showtoken());
		}
		else {
			cout << "\t\t�μ��ѹμ�: ���󰡰ڽ��ϴ�.\n";
			Minseo.MinusToken(Paytoken);
			GunToken += Paytoken * 2;
		}
		player.MinusToken(Paytoken);
		cout << "\t\t�и� �������ּ���>>";
		int Pae1, Pae2;
		cin >> Pae1 >> Pae2;
		player.pickPae(player.Pae[Pae1 - 1], player.Pae[Pae2 - 1]);
		int rank_Player = player.panstar();
		Minseo.pickPae(Minseo.Pae[0], Minseo.Pae[1]);//AI�� ���� ���� �и� ��
		int rank_Minseo = Minseo.panstar();
		int AI_LOW = rank_Minseo;
		Minseo.pickPae(Minseo.Pae[0], Minseo.Pae[2]);
		rank_Minseo = Minseo.panstar();
		if (AI_LOW > rank_Minseo) {
			AI_LOW = rank_Minseo;
		}
		Minseo.pickPae(Minseo.Pae[1], Minseo.Pae[2]);
		rank_Minseo = Minseo.panstar();
		int whowin = 0;
		if (AI_LOW > rank_Minseo) {
			AI_LOW = rank_Minseo;
		}
		if (rank_Player == 88 && AI_LOW == 2) {
			cout << "\t\t������! ��! �÷��̾�� " << GunToken << " ��ŭ�� ��ū�� �������ϴ�.\n";
			player.PlusToken(GunToken);
		}
		else if (rank_Player == 90 && AI_LOW >= 3 && AI_LOW <= 12) {
			cout << "\t\t������! ��! �÷��̾�� " << GunToken << " ��ŭ�� ��ū�� �������ϴ�.\n";
		}
		else if (rank_Player == -100 && AI_LOW != 1) {
			cout << "\t\t���ֱ��� ���� ����!\n";
			Sleep(1000);
			system("cls");
			Sleep(1000);
			continue;
		}
		else if (AI_LOW == -100 && rank_Player != 1) {
			cout << "\t\t���ֱ��� ���� ����!\n";
			Sleep(1000);
			system("cls");
			Sleep(1000);
			continue;
		}
		else if (rank_Player == -99 && AI_LOW >= 13) {
			cout << "\t\t���� ����!\n";
			Sleep(1000);
			system("cls");
			Sleep(1000);
			continue;
		}
		else if (AI_LOW == -99 && rank_Player >= 13) {
			cout << "\t\t���� ����!\n";
			Sleep(1000);
			system("cls");
			Sleep(1000);
			continue;
		}
		else {
			if (AI_LOW < rank_Player) {
				cout << "\t\t�÷��̾�: " << Paestr(rank_Player) << "\n\t\tMinseo: " << Paestr(AI_LOW) << "\n\t\tMinseo �¸�!";
				Minseo.PlusToken(GunToken);
			}
			else if (AI_LOW > rank_Player) {
				cout << "\t\t�÷��̾�: " << Paestr(rank_Player) << "\n\t\tMinseo: " << Paestr(AI_LOW) << "\n\t\t�÷��̾� �¸�!";
				player.PlusToken(GunToken);
			}
			else {
				cout << "\t\t�÷��̾�: " << Paestr(rank_Player) << "\n\t\tMinseo: " << Paestr(AI_LOW) << "\n\t\t����!";
				Sleep(4000);
				system("cls");
				continue;
			}
		}
		GunToken = 0;
		Sleep(4000);
		system("cls");
	}
	cout << "\n\t\t���� ����";
	return 0;
}