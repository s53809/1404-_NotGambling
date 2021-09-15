#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct cardInfo {
	bool isPaper; //이게 같은숫자카드 2개중 구분하는거
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
		}//삼팔광땡
		if (PanstarBox[0].first == 1 && PanstarBox[0].second == false && PanstarBox[1].first == 3 && PanstarBox[1].second == false) {
			return 2;
		}//일삼광땡
		if (PanstarBox[0].first == 1 && PanstarBox[0].second == false && PanstarBox[1].first == 8 && PanstarBox[1].second == false) {
			return 2;
		}//일팔광땡
		if (PanstarBox[0].first == PanstarBox[1].first) {
			return 13 - PanstarBox[0].first;
		}//땡
		if (PanstarBox[0].first == 1 && PanstarBox[1].first == 2) {
			return 13;
		}//알리
		if (PanstarBox[0].first == 1 && PanstarBox[1].first == 10) {
			return 14;
		}//장삥
		if (PanstarBox[0].first == 1 && PanstarBox[1].first== 4) {
			return 15;
		}//독사
		if (PanstarBox[0].first == 4 && PanstarBox[1].first == 10) {
			return 16;
		}//장사
		if (PanstarBox[0].first == 1 && PanstarBox[1].first == 9) {
			return 17;
		}//구삥
		if (PanstarBox[0].first == 4 && PanstarBox[1].first == 6) {
			return 18;
		}//세륙
		if (PanstarBox[0].first == 4 && PanstarBox[1].first == 7) {
			return 88;
		}//암행어사
		if (PanstarBox[0].first == 3 && PanstarBox[1].first == 7) {
			return 90;
		}//땡잡이
		if (PanstarBox[0].first == 4 && PanstarBox[0].second == false && PanstarBox[1].first == 9 && PanstarBox[1].second == false) {
			return -100;
		}//멍텅구리 구사
		else if (PanstarBox[0].first == 4 && PanstarBox[1].first == 9) {
			return -99;
		}//구사
		else {
			int hap;
			if (PanstarBox[0].first + PanstarBox[1].first >= 10) {
				hap = PanstarBox[0].first + PanstarBox[1].first - 10;
			}
			else {
				hap = PanstarBox[0].first + PanstarBox[1].first;
			}
			return 28 - hap;
			//끗
		}
	}
};

string Paestr(int rank) {
	if (rank == 1) {
		return "삼팔광땡";
	}
	else if (rank == 2) {
		return "일삼광땡 혹은 일팔광땡";
	}
	else if (rank == 3) {
		return "장땡";
	}
	else if (rank == 4) {
		return "구땡";
	}
	else if (rank == 5) {
		return "팔땡";
	}
	else if (rank == 6) {
		return "칠땡";
	}
	else if (rank == 7) {
		return "육땡";
	}
	else if (rank == 8) {
		return "오땡";
	}
	else if (rank == 9) {
		return "사땡";
	}
	else if (rank == 10) {
		return "삼땡";
	}
	else if (rank == 11) {
		return "이땡";
	}
	else if (rank == 12) {
		return "일땡";
	}
	else if (rank == 13) {
		return "알리";
	}
	else if (rank == 14) {
		return "장삥";
	}
	else if (rank == 15) {
		return "독사";
	}
	else if (rank == 16) {
		return "장사";
	}
	else if (rank == 17) {
		return "구삥";
	}
	else if (rank == 18) {
		return "세륙";
	}
	else if (rank == 19) {
		return "갑오";
	}
	else if (rank == 20) {
		return "8끗";
	}
	else if (rank == 21) {
		return "7끗";
	}
	else if (rank == 22) {
		return "6끗";
	}
	else if (rank == 23) {
		return "5끗";
	}
	else if (rank == 24) {
		return "4끗";
	}
	else if (rank == 25) {
		return "3끗";
	}
	else if (rank == 26) {
		return "2끗";
	}
	else if (rank == 27) {
		return "1끗";
	}
	else if (rank ==28) {
		return "망통";
	}
	else if (rank == 88) {
		return "암행어사";
	}
	else if (rank == 90) {
		return "땡잡이";
	}
	else if (rank == -100) {
		return "멍텅구리 구사";
	}
	else if (rank == -99) {
		return "구사";
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
		cout << "\n\n\n\t\t나의 패: ";
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
		cout << "\n\n\n\t\t상대 패: ";
		for (int i = 0; i < Hwetsu; i++) {
			if (i == N) {
				cout << "\t\t" << Pae[i].num << ' ' << "type: " << Pae[i].isPaper;
			}
			else {
				cout << "\t\t(뒤집은 카드)";
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
	cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t카지노게임에 오신것을 환영합니다. 무슨 게임을 선택하시겠습니까?\n\t\t1. 섯다\n\t\t2. 섯다\n\t\t3. 섯다\n\t\t4. 섯다\n\t\t5. 블랙잭\n\t\t>> ";
	cin >> MeaninglessBox;
	cout << "\t\t섯다를 선택하셨습니다!\n";
	cout << "\t\t게임 룰 설명: 화투패 2장으로 족보를 만들어 더 높은 족보를 가진 플레이어가 승리하는 게임\n\t\t같은 숫자 2장중 그림에 부적이 그려져있는 카드는 type 1 부적이 안그려져있거나 광인 카드는 type 0으로 간주\n\t\t멍텅구리 구사 또는 구사 또는 무승부로 인한 재경기는 2장승부가 아닌 완전 처음부터 시작합니다.\n";
	cout << "\t\t규칙을 숙지했다면 아무키와 엔터키를 입력하십시오\n";
	cin >> MeaninglessBox;
	cout << "\t\t다른 플레이어와 매칭을 시작하겠습니다";
	Sleep(2000);
	system("cls");
	for (int i = 1; i <= 2; i++) {
		cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t플레이어와 비슷한 실력의 상대를 매칭중입니다 ";
		for (int j = 0; j < 3; j++) {
			cout << ". ";
			Sleep(1000);
		}
		system("cls");
	}
	cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t매칭 성공!\n\t\t닉네임: 민서한민서\n\t\t랭크: 첼린저\n\t\t승률: 87%";
	Sleep(2000);
	cout << "\n\t\t게임을 시작하겠습니다.";
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
				cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t당신은 파산하였습니다. 게임을 종료합니다.";
				break;
			}
			if (Minseo.Showtoken() <= 0) {
				cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t민서한민서은(는) 파산하였습니다. 게임을 종료합니다.";
				break;
			}
		}
		cout << "내 토큰: " << player.Showtoken() << " 상대 토큰: " << Minseo.Showtoken();
		cout << " 현재 걸려있는 토큰: " << GunToken;
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
		cout << "\n\t\t배팅(1) or 다이(2) >>";
		cin >> Dap;
		if (Dap == 2) {
			cout << "다이!\n";
			Minseo.PlusToken(GunToken);
			Sleep(1000);
			system("cls");
			Sleep(1000);
			for (int i = 0; i < 20; i++) {
				Card[i].visited = false;
			}
			continue;
		}
		cout << "\t\t얼마를 배팅하시겠습니까?\n\t\t";
		int Paytoken;
		while (true) {
			cin >> Paytoken;
			if (Paytoken > player.Showtoken()) {
				cout << "\n\t\t보유하고있는 토큰보다 많은 토큰을 배팅할 수 없습니다!\n\t\t";
				continue;
			}
			break;
		}
		if (Paytoken >= Minseo.Showtoken()) {
			cout << "\t\t민서한민서: 올인!\n";
			GunToken += Paytoken + Minseo.Showtoken();
			Minseo.MinusToken(Minseo.Showtoken());
		}
		else {
			cout << "\t\t민서한민서: 따라가겠습니다.\n";
			Minseo.MinusToken(Paytoken);
		}
		GunToken += Paytoken * 2;
		player.MinusToken(Paytoken);
		cout << "\t\t카드 한장을 더 드리겠습니다.\n";
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
		cout << "\n\t\t배팅(1) or 다이(2) >>";
		cin >> Dap;

		if (Dap == 2) {
			cout << "다이!\n";
			cout << "\t\t상대는 " << GunToken << "의 토큰을 가져갑니다!";
			Minseo.PlusToken(GunToken);
			Sleep(1000);
			system("cls");
			Sleep(1000);
			for (int i = 0; i < 20; i++) {
				Card[i].visited = false;
			}
			continue;
		}
		cout << "\t\t얼마를 배팅하시겠습니까?\n\t\t";
		while (true) {
			cin >> Paytoken;
			if (Paytoken > player.Showtoken()) {
				cout << "\n\t\t보유하고있는 토큰보다 많은 토큰을 배팅할 수 없습니다!\n\t\t";
				continue;
			}
			break;
		}
		if (Paytoken >= Minseo.Showtoken()) {
			cout << "\t\t민서한민서: 올인!\n";
			GunToken = Paytoken + Minseo.Showtoken();
			Minseo.MinusToken(Minseo.Showtoken());
		}
		else {
			cout << "\t\t민서한민서: 따라가겠습니다.\n";
			Minseo.MinusToken(Paytoken);
			GunToken += Paytoken * 2;
		}
		player.MinusToken(Paytoken);
		cout << "\t\t패를 선택해주세요>>";
		int Pae1, Pae2;
		cin >> Pae1 >> Pae2;
		player.pickPae(player.Pae[Pae1 - 1], player.Pae[Pae2 - 1]);
		int rank_Player = player.panstar();
		Minseo.pickPae(Minseo.Pae[0], Minseo.Pae[1]);//AI의 가장 높은 패를 고름
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
			cout << "\t\t암행어사! 승! 플레이어는 " << GunToken << " 만큼의 토큰을 가져갑니다.\n";
			player.PlusToken(GunToken);
		}
		else if (rank_Player == 90 && AI_LOW >= 3 && AI_LOW <= 12) {
			cout << "\t\t땡잡이! 승! 플레이어는 " << GunToken << " 만큼의 토큰을 가져갑니다.\n";
		}
		else if (rank_Player == -100 && AI_LOW != 1) {
			cout << "\t\t멍텅구리 구사 재경기!\n";
			Sleep(1000);
			system("cls");
			Sleep(1000);
			continue;
		}
		else if (AI_LOW == -100 && rank_Player != 1) {
			cout << "\t\t멍텅구리 구사 재경기!\n";
			Sleep(1000);
			system("cls");
			Sleep(1000);
			continue;
		}
		else if (rank_Player == -99 && AI_LOW >= 13) {
			cout << "\t\t구사 재경기!\n";
			Sleep(1000);
			system("cls");
			Sleep(1000);
			continue;
		}
		else if (AI_LOW == -99 && rank_Player >= 13) {
			cout << "\t\t구사 재경기!\n";
			Sleep(1000);
			system("cls");
			Sleep(1000);
			continue;
		}
		else {
			if (AI_LOW < rank_Player) {
				cout << "\t\t플레이어: " << Paestr(rank_Player) << "\n\t\tMinseo: " << Paestr(AI_LOW) << "\n\t\tMinseo 승리!";
				Minseo.PlusToken(GunToken);
			}
			else if (AI_LOW > rank_Player) {
				cout << "\t\t플레이어: " << Paestr(rank_Player) << "\n\t\tMinseo: " << Paestr(AI_LOW) << "\n\t\t플레이어 승리!";
				player.PlusToken(GunToken);
			}
			else {
				cout << "\t\t플레이어: " << Paestr(rank_Player) << "\n\t\tMinseo: " << Paestr(AI_LOW) << "\n\t\t재경기!";
				Sleep(4000);
				system("cls");
				continue;
			}
		}
		GunToken = 0;
		Sleep(4000);
		system("cls");
	}
	cout << "\n\t\t게임 종료";
	return 0;
}